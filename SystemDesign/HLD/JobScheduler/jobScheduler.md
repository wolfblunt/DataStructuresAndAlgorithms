# Job Scheduler - System Design

## 1\. Determine the Scope

### Functional Requirements (What the system *should* do) 🎯

  * **Job Creation & Scheduling:** Users must be able to create and schedule jobs. These jobs can be:
      * **Immediate:** Run right away.
      * **Future:** Run at a specific time in the future.
      * **Recurring (Cron Jobs):** Run repeatedly at defined intervals (e.g., daily, weekly).
  * **Job Monitoring:** Provide a dashboard for users to monitor the real-time status of their jobs (e.g., running, successful, failed). If a job fails, the system should provide the reason.
  * **Job Management:** Users should have the ability to:
      * **Cancel Jobs:** Stop scheduled or currently running jobs.
      * **Reschedule/Update Jobs:** Modify the schedule or metadata of existing jobs.
  * **Out of Scope:** The system will *not* handle jobs with dependencies on each other (e.g., Directed Acyclic Graphs - DAGs).

### Non-Functional Requirements (Goals for performance, reliability, and scalability) 📈

  * **Scalability:** The application must support a high volume, targeting around **10,000 concurrent scheduled jobs per second** at peak.
  * **Availability:** Prioritize **high availability** over strong consistency (eventual consistency is acceptable) based on the CAP theorem. For a job scheduler, it's more critical that the service is always accessible than having immediate consistency across all job states.
  * **Reliability:** Jobs must execute **at least once**. The system should be resilient to failures and ensure scheduled tasks are eventually run.
  * **Latency:** The system should execute or pick up jobs from the buffer with a maximum latency of **2 seconds** from their scheduled time.

-----

## 2\. Determine Core Entities

The primary entities in this distributed job scheduler system are:

  * **Job:** Represents the actual task or unit of work that needs to be executed. It includes metadata like the command to run, parameters, and scheduling information.
  * **Scheduler:** The component responsible for determining when a job should run based on its schedule and pushing it for execution.
  * **Executor:** The component that actually runs the job.

-----

## 3\. Define a High-Level Design In-Depth

The high-level design outlines the major components and their interactions to fulfill the requirements.

  * **Clients/Users:** The external interface through which users interact with the system to create, schedule, monitor, and manage jobs.
  * **Load Balancer & API Gateway:**
      * **Load Balancer:** Distributes incoming user requests across multiple instances of the Job Service to ensure high availability and scalability.
      * **API Gateway:** Acts as the entry point for all client requests, handling concerns like authentication, authorization, rate limiting, and routing requests to the appropriate microservices (Job Service, Job Search Service).
  * **Job Service:** A microservice responsible for handling all **write operations** related to jobs, such as:
      * Creating new jobs.
      * Updating job metadata or schedules.
      * Initiating immediate job runs.
      * It publishes job-related events (creation, updates) to a Kafka Broker.
  * **Job Search Service:** A microservice dedicated to handling all **read operations**, such as:
      * Retrieving job details by ID.
      * Fetching the real-time status of a job.
      * It queries the Job DB directly for this information.
  * **Kafka Broker (Streaming Platform):** Acts as a highly scalable and fault-tolerant message queue.
      * Used by the Job Service to asynchronously store `create` and `edit` job requests, decoupling the write operations from direct database updates.
      * Used by the Watcher Service to push jobs that are due for execution into a "run queue."
      * Used by the Executor Service to push job status updates.
      * Facilitates retry mechanisms by routing failed jobs to specific retry topics.
  * **Job Consumer Service (Writer/Updater):** Consumes messages from Kafka.
      * Reads `create` and `edit` job requests from Kafka and persists them into the Job DB.
      * Reads job status updates from Kafka (sent by Executor Service) and updates the `job_run` table in the Job DB.
  * **Job DB (PostgreSQL):** The primary persistence layer for storing all job-related metadata and execution history. Chosen for its ACID properties and strong querying capabilities.
  * **Redis Cache (Last Pull Time):** Stores the `last_pull_time` for the Watcher Service, enabling it to maintain state and recover efficiently in case of failure.
  * **Watcher Service:** A critical component that continuously monitors the `Job DB`:
      * Periodically (e.g., every 20 seconds) queries the `Job DB` to identify jobs scheduled to run within a near-future sliding window (e.g., next 5 minutes).
      * Pushes these upcoming jobs into the Kafka "run queue."
      * Also monitors the `job_run` table for jobs in a "running" state whose `modified_time` is unexpectedly old (e.g., \>15 seconds), indicating a potential executor failure. These jobs are then re-queued for retry.
  * **Job Consumer Service (Executor Dispatcher):** Consumes jobs from the Kafka "run queue." It dispatches these jobs to available Executor Services for execution.
  * **Executor Service (Worker Service):** The actual worker process that executes the jobs.
      * Pulls jobs from the `Job Consumer Service` (Executor Dispatcher).
      * Executes the defined task (e.g., run a script, make an API call).
      * Sends real-time status updates (e.g., running, success, failure) to a Kafka topic.
      * Continuously checks a local Redis cache for cancellation requests.
  * **Redis Cache (Cancellation):** A local cache (e.g., on each Executor Service or a shared cluster) used to quickly check if a currently executing job has been requested for cancellation. It has a TTL (Time-To-Live) for entries to prevent stale data.

**Data Flow for Key Operations:**

1.  **Job Creation/Update:**
      * User sends `POST /jobs` or `PUT /jobs/{jobId}` request to API Gateway.
      * API Gateway routes to Job Service.
      * Job Service validates and pushes the job details to a Kafka topic.
      * Job Consumer Service (Writer/Updater) consumes from Kafka and persists/updates the `Job DB`.
      * If the job is immediate, Job Service also directly pushes it to the Kafka "run queue."
2.  **Job Monitoring:**
      * User sends `GET /jobs/{jobId}` or `GET /jobs/{jobId}/status` request to API Gateway.
      * API Gateway routes to Job Search Service.
      * Job Search Service queries the `Job DB` (specifically the `job_run` table for status) and returns the information.
3.  **Job Execution:**
      * Watcher Service periodically scans `Job DB` for upcoming jobs.
      * Watcher Service pushes these jobs to Kafka "run queue" and updates `job_run` status to "queued."
      * Job Consumer Service (Executor Dispatcher) picks jobs from Kafka "run queue" and dispatches to Executor Service.
      * Executor Service runs the job, sends status updates to a Kafka topic.
      * Job Consumer Service (Writer/Updater) consumes status updates from Kafka and updates the `job_run` table in `Job DB`.
4.  **Job Cancellation:**
      * User sends `DELETE /jobs/{jobId}` to API Gateway.
      * API Gateway routes to Job Service.
      * Job Service updates the job status in `Job DB` (via Kafka pipeline) to "cancelled."
      * Job Service also publishes a cancellation event to a Redis Cache.
      * Executor Services (running a particular job) periodically check this Redis Cache. If a cancellation request for their job is found, they terminate the execution.

-----

## 4\. DB Schema and API Points

### Database Schema 📂

**Database Choice:** **PostgreSQL** (Relational Database - SQL).
**Justification:**

  * **ACID Compliance:** Essential for maintaining the integrity of job definitions and execution states.
  * **Structured Data:** Job metadata, schedules, and run details are highly structured and fit well into relational tables.
  * **Complex Queries:** Supports complex queries for filtering jobs by status, schedule time, and other attributes, which is crucial for the Watcher Service and monitoring dashboards.
  * **Indexing & Partitioning:** PostgreSQL offers robust features for indexing and partitioning, which are vital for performance at scale, especially for the high read volume from the Watcher Service and search operations.

#### **1. `jobs` Table (Metadata of Scheduled Jobs)**

| Column Name      | Data Type | Constraints                               | Description                                                      |
| :--------------- | :-------- | :---------------------------------------- | :--------------------------------------------------------------- |
| `job_id`         | UUID      | PRIMARY KEY                               | Unique identifier for the job.                                   |
| `name`           | VARCHAR   | NOT NULL                                  | User-friendly name of the job.                                   |
| `schedule_type`  | VARCHAR   | NOT NULL (e.g., 'IMMEDIATE', 'FUTURE', 'CRON') | Type of job scheduling.                                          |
| `status`         | VARCHAR   | NOT NULL (e.g., 'SCHEDULED', 'PAUSED', 'CANCELLED') | Current status of the job definition.                            |
| `schedule_time`  | TIMESTAMP | NULLABLE                                  | Specific time for future jobs (UTC). Indexed for Watcher Service. |
| `cron_expression`| VARCHAR   | NULLABLE                                  | Cron string for recurring jobs.                                  |
| `payload`        | JSONB     | NULLABLE                                  | JSON data/parameters required by the job.                        |
| `max_retries`    | INT       | DEFAULT 3                                 | Maximum number of retries if a job fails.                        |
| `created_at`     | TIMESTAMP | NOT NULL DEFAULT NOW()                    | Timestamp when the job was created.                              |
| `updated_at`     | TIMESTAMP | NOT NULL DEFAULT NOW()                    | Last update timestamp for the job definition.                    |

**Indexes:**

  * `job_id` (Primary Key)
  * `schedule_time` (B-tree index for efficient range queries by Watcher Service)

**Partitioning (Optional but Recommended for Scale):**

  * Partition by `schedule_time` to manage large datasets and improve query performance for time-based lookups by the Watcher Service.

#### **2. `job_runs` Table (Execution History and Real-time Status)**

| Column Name       | Data Type | Constraints                               | Description                                                               |
| :---------------- | :-------- | :---------------------------------------- | :------------------------------------------------------------------------ |
| `run_id`          | UUID      | PRIMARY KEY                               | Unique identifier for each job execution attempt.                         |
| `job_id`          | UUID      | NOT NULL, FOREIGN KEY REFERENCES jobs(job\_id) | Foreign key linking to the `jobs` table.                                  |
| `status`          | VARCHAR   | NOT NULL (e.g., 'QUEUED', 'RUNNING', 'SUCCESS', 'FAILED') | Current status of this specific job run.                                  |
| `start_time`      | TIMESTAMP | NULLABLE                                  | Timestamp when the job execution started.                                 |
| `end_time`        | TIMESTAMP | NULLABLE                                  | Timestamp when the job execution finished.                                |
| `modified_time`   | TIMESTAMP | NOT NULL DEFAULT NOW()                    | Last timestamp when this run record was updated. Crucial for detecting crashed executors. |
| `executor_id`     | VARCHAR   | NULLABLE                                  | ID of the executor instance that ran the job.                             |
| `attempt_number`  | INT       | NOT NULL DEFAULT 1                        | Current retry attempt number for this job run.                            |
| `error_message`   | TEXT      | NULLABLE                                  | Detailed error message if the job failed.                                 |
| `log_url`         | TEXT      | NULLABLE                                  | URL to the detailed logs for this job run.                                |
| `created_at`      | TIMESTAMP | NOT NULL DEFAULT NOW()                    | Timestamp when the job run record was created.                            |

**Indexes:**

  * `run_id` (Primary Key)
  * `job_id` (Foreign Key Index)
  * Composite Index: `(status, modified_time)` (for Watcher Service to identify stale running jobs)

### API Endpoints 🌐

The system will expose RESTful APIs through the API Gateway.

#### **1. Job Management API (`/jobs`)**

  * **`POST /jobs`**
      * **Description:** Creates and schedules a new job.
      * **Request Body:**
        ```json
        {
          "name": "Daily Data Cleanup",
          "schedule_type": "CRON",
          "cron_expression": "0 0 * * *", // Every day at midnight UTC
          "payload": {
            "cleanup_target": "old_logs",
            "retention_days": 30
          },
          "max_retries": 2
        }
        ```
        (For `FUTURE` jobs, `schedule_time` would be provided instead of `cron_expression`. For `IMMEDIATE`, `schedule_type` would be `IMMEDIATE` and `schedule_time`/`cron_expression` would be omitted.)
      * **Response:**
        ```json
        {
          "job_id": "a1b2c3d4-e5f6-7890-1234-567890abcdef"
        }
        ```
  * **`PUT /jobs/{jobId}`**
      * **Description:** Updates an existing job's metadata or schedule.
      * **Request Body:** (Similar to `POST /jobs`, but only fields to be updated are required)
        ```json
        {
          "name": "Updated Data Cleanup",
          "schedule_time": "2025-09-25T10:00:00Z"
        }
        ```
      * **Response:** `200 OK` (or `204 No Content`)
  * **`DELETE /jobs/{jobId}`**
      * **Description:** Cancels a scheduled job or attempts to stop a running job.
      * **Response:** `200 OK` (or `204 No Content`)
  * **`POST /jobs/{jobId}/runNow`**
      * **Description:** Immediately triggers an execution of an existing job, bypassing its schedule.
      * **Response:** `202 Accepted`

#### **2. Job Monitoring API (`/jobs/{jobId}/status` and `/jobs/{jobId}/runs`)**

  * **`GET /jobs/{jobId}`**
      * **Description:** Retrieves the full details and metadata of a specific job.
      * **Response:**
        ```json
        {
          "job_id": "a1b2c3d4-e5f6-7890-1234-567890abcdef",
          "name": "Daily Data Cleanup",
          "schedule_type": "CRON",
          "cron_expression": "0 0 * * *",
          "status": "SCHEDULED",
          "payload": { ... },
          "max_retries": 2,
          "created_at": "2025-09-24T08:00:00Z",
          "updated_at": "2025-09-24T08:00:00Z"
        }
        ```
  * **`GET /jobs/{jobId}/status`**
      * **Description:** Retrieves the current status of a job's latest run.
      * **Response:**
        ```json
        {
          "job_id": "a1b2c3d4-e5f6-7890-1234-567890abcdef",
          "latest_run": {
            "run_id": "f1g2h3i4-j5k6-7890-1234-567890mnopqr",
            "status": "RUNNING",
            "start_time": "2025-09-25T09:30:00Z",
            "modified_time": "2025-09-25T09:30:15Z",
            "attempt_number": 1,
            "executor_id": "executor-007"
          }
        }
        ```
  * **`GET /jobs/{jobId}/runs`**
      * **Description:** Retrieves a list of all past and current runs for a specific job.
      * **Response:**
        ```json
        [
          {
            "run_id": "f1g2h3i4-j5k6-7890-1234-567890mnopqr",
            "status": "SUCCESS",
            "start_time": "2025-09-24T08:00:00Z",
            "end_time": "2025-09-24T08:01:30Z",
            "modified_time": "2025-09-24T08:01:30Z",
            "attempt_number": 1,
            "log_url": "http://logs.example.com/run-f1g2h3i4"
          },
          {
            "run_id": "x1y2z3a4-b5c6-7890-1234-567890defghi",
            "status": "FAILED",
            "start_time": "2025-09-25T09:00:00Z",
            "end_time": "2025-09-25T09:00:10Z",
            "modified_time": "2025-09-25T09:00:10Z",
            "attempt_number": 1,
            "error_message": "Database connection failed",
            "log_url": "http://logs.example.com/run-x1y2z3a4"
          }
        ]
        ```

-----

## 5\. Consider a Relevant DSA

**Problem:** Efficiently finding the next jobs to execute from a large pool of scheduled jobs, especially when dealing with a `Watcher Service` that needs to pull jobs within a specific time window (`schedule_time`) every few seconds.

**Relevant DSA:** **Min-Heap (Priority Queue) combined with efficient database indexing.**

**Explanation and Solution:**

1.  **Database Indexing:** As discussed in the DB Schema, the `jobs` table should have an index on `schedule_time`. This allows for highly efficient range queries.
2.  **Watcher Service Logic:**
      * The `Watcher Service` periodically (e.g., every 20 seconds) queries the `Job DB` for jobs whose `schedule_time` falls within the next N minutes (e.g., 5 minutes) from the current time. The SQL query would leverage the `schedule_time` index.
      * Once these jobs are fetched, they are inserted into a **Min-Heap (Priority Queue)**. The priority of an element in the heap would be its `schedule_time`. This ensures that the job closest to its execution time is always at the top.
      * The `Watcher Service` would then push these jobs (in order of their `schedule_time`, retrieved from the min-heap) into the Kafka "run queue." This effectively orders the jobs within the queue for the `Job Consumer Service` to pick up.
      * A **Redis Sorted Set** is a more direct and scalable alternative to an in-memory Min-Heap for distributed systems as suggested in the video. When the Watcher Service pulls jobs, it adds them to the Redis Sorted Set, with `schedule_time` as the score. Redis automatically maintains the sorted order. The `Job Consumer Service` then pulls jobs from the sorted set based on their score (schedule time).

**Why this approach is efficient:**

  * **Efficient Retrieval (Database):** The `schedule_time` index allows the database to quickly identify all jobs within the specified time window without scanning the entire table.
  * **Efficient Ordering (Min-Heap/Redis Sorted Set):**
      * A Min-Heap allows for `O(log N)` insertion and `O(1)` retrieval of the minimum element (the next job to run).
      * A Redis Sorted Set provides similar efficiency for distributed scenarios, automatically maintaining order and offering fast retrieval of elements within a score range (time window).
  * **Reduced Polling Load:** Instead of continuously polling for *all* jobs, the `Watcher Service` polls for a manageable subset within a future window, then orders them, reducing the immediate load on the database for real-time scheduling.
  * **Scalability:** Both database indexing and Redis Sorted Sets are designed for high-performance and scalability in distributed environments.

-----

## 6\. Describe the Trade-offs

  * **Availability vs. Consistency (Eventual Consistency):**

      * **Choice:** Prioritize Availability.
      * **Trade-off:** The system may exhibit slight delays in reflecting the absolute latest state of a job across all components. For example, a job might be created, but due to asynchronous processing through Kafka, it might take a few milliseconds or seconds for its status to be consistently updated in all dashboards.
      * **Justification:** For a job scheduler, ensuring jobs are executed reliably (availability) is generally more critical than immediate global consistency of job status. A brief delay in status reflection is acceptable.

  * **Monolithic vs. Microservices Architecture:**

      * **Choice:** Microservices.
      * **Trade-off:** Increased operational complexity (managing multiple services, deployments, inter-service communication), higher latency for complex operations spanning multiple services, and potential data consistency challenges across services.
      * **Justification:** Required for high scalability, fault isolation (failure in one service doesn't bring down the whole system), independent deployment, and better team organization. The system targets 10,000 jobs/sec, necessitating a distributed approach.

  * **Direct DB Access vs. Kafka for Writes:**

      * **Choice:** Kafka for write operations (asynchronous processing).
      * **Trade-off:** Adds complexity with an additional component (Kafka) to manage, potential for increased latency for "write" acknowledgments if the client needs confirmation that the data is persisted to the DB, and eventual consistency for write operations.
      * **Justification:** Essential for handling high write throughput (10,000 jobs/sec). Kafka acts as a buffer, decoupling the Job Service from direct DB writes, preventing the database from becoming a bottleneck under heavy load, and providing resilience against database downtime.

  * **Polling (Watcher Service) vs. Event-Driven Scheduling:**

      * **Choice:** Polling `Job DB` by `Watcher Service` with a time window.
      * **Trade-off:** Can lead to a slight delay (up to the polling interval) for newly scheduled jobs to be picked up. Requires careful tuning of the polling interval and time window to balance freshness with database load.
      * **Justification:** Simpler to implement than a complex event-driven system that would require changing the database (e.g., using change data capture). By polling a future window and using a Redis Sorted Set, we achieve acceptable latency (within 2 seconds) while managing database load.

  * **Redis Cache for Cancellation vs. Direct DB Check:**

      * **Choice:** Redis Cache for immediate cancellation signals.
      * **Trade-off:** Cache invalidation strategies are needed (TTL helps). Potential for stale data if the cache isn't updated correctly, or if the `Executor Service` doesn't check frequently enough. Adds another component to the architecture.
      * **Justification:** Provides very low-latency lookup for cancellation requests by the `Executor Service`. A direct database lookup for every job to check for cancellation would be prohibitively expensive and add significant latency to job execution, failing the low-latency requirement for stopping running jobs.