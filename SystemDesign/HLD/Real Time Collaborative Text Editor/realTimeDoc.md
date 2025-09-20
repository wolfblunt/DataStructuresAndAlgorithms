# Designing a Real-time Collaborative Text Editor like Google Docs 📝

### 1. Determine the Scope:

#### Functional Requirements:
* Users can **create, modify, or delete** documents.
* **Multiple or single users** can collaboratively or individually edit a document.
* Changes made by other users should be visible in **near real-time**.
* Users should be able to see the **cursor position** and presence of other active users.
* The system should support **document versioning**.

#### Non-Functional Requirements:
* **Scale:** Support millions of users and billions of documents.
* **Consistency vs. Availability (CAP Theorem):** The system should be **highly available** with **eventual consistency** for most operations. However, for **collaborative editing**, **high consistency** is prioritized to reflect changes in near real-time.
* **Latency:** Edit updates between users should have a **minimum latency of 100 milliseconds**.

---

### 2. Determine Core Entities:
The core entities identified for this system are:
* **User/Editor:** The individual interacting with and modifying documents.
* **Document:** The primary content unit that users create and edit.
* **Edit:** Represents the individual changes or operations performed on a document.
* **Cursor:** Tracks the position of each user's cursor within a document during collaborative editing.

---

### 3. Define a High-Level Design In-depth:

The system will leverage a **microservices architecture** to handle the massive scale.

#### Major Components and Interactions:

* **Clients (Users):** Interact with the system through web browsers or applications.
* **Load Balancer/API Gateway:** Handles incoming traffic, performs rate limiting, authentication, authorization, and distributes requests uniformly to backend services, potentially using a round-robin algorithm.
* **WebSocket Load Balancer:** A dedicated gateway for WebSocket connections, especially crucial for real-time collaborative editing due to its bidirectional, persistent nature.
* **Document Metadata Service:** Responsible for managing document metadata (title, creation time, creator, last modified, etc.). It handles `POST`, `GET`, `DELETE`, and `UPDATE` operations for document creation and metadata changes via RESTful APIs.
    * **Kafka Queue (Metadata):** Buffers metadata update requests to the database, especially under high write loads.
    * **Metadata Consumer Service:** Consumes events from the Kafka queue and updates the document metadata database.
    * **Document Database (Cassandra):** Stores document metadata. A Cassandra database is chosen for its write-heavy capabilities, suitable for the high volume of metadata operations.
* **Document Editor Service:** The "heart" of the application, responsible for handling real-time document editing and conflict resolution. It communicates with clients via WebSocket connections.
    * **Client-side OT/CRDT:** Performs operational transformation (OT) or Conflict-free Replicated Data Types (CRDT) on the client to prepare and reconcile changes.
    * **Server-side OT/CRDT:** The Document Editor Service also performs OT/CRDT to reconcile changes received from multiple clients.
    * **Kafka Queue (Operations):** Buffers individual edit operations (keystrokes) for durability and asynchronous processing.
    * **Operation Consumer Service:** Consumes edit events from the Kafka queue and persists them in the Operation Database.
    * **Operation Database:** Stores all micro-events (individual operations) for rollbacks and reconciliation.
    * **Redis Cluster:** Maintains a **canonical in-memory copy** of the document currently being edited for near real-time updates and efficient OT/CRDT operations. It uses a TTL (Time-To-Live) for documents no longer actively edited.
* **Blob Storage (S3 Bucket):** Stores the actual content of the documents. This is chosen for its ability to handle large files and historical versions efficiently.
* **CDN (Content Delivery Network):** Caches document content for faster read access, especially for documents viewed in read-only mode.
* **Reconciliation Job/Service:** Periodically runs in the background to consolidate minor versions from the Redis cluster and operation database into major versions, which are then persisted in the S3 bucket. This optimizes storage space by removing intermediate versions.

#### Data Flow for Key Operations:

1.  **Document Creation:** User makes a `POST` request to the API Gateway, routed to the Document Metadata Service. This service creates an entry in the Document DB and an empty file in the Blob Storage (S3), returning a `document_id`.
2.  **Document Viewing (Read-Only):** User sends a `GET` request for a `document_id`. The request goes through the API Gateway to the Document Metadata Service, which fetches the document URL from the Document DB. The document content is then retrieved from the CDN (or S3) and delivered to the client.
3.  **Collaborative Editing:**
    * A user requests to edit a document, establishing a **WebSocket connection** with the Document Editor Service via the WebSocket Load Balancer.
    * The Document Editor Service fetches the latest document version from S3 and loads it into the Redis Cluster as the canonical copy.
    * As users type (keystrokes), client-side OT/CRDT generates **edit events** (deltas, not the entire file).
    * These events are sent over the WebSocket connection to the Document Editor Service.
    * The Document Editor Service:
        * Applies server-side OT/CRDT to the canonical copy in Redis.
        * Pushes the edit events to a Kafka Queue for durable storage in the Operation DB.
        * Broadcasts the transformed changes back to all connected clients via their WebSocket connections.
    * Clients apply the received transformed changes to their local document copies, ensuring consistency.
4.  **Saving/Versioning:**
    * **Auto-save:** Periodically (e.g., every 10-20 seconds), the Document Editor Service takes a snapshot of the canonical document from Redis and saves it as a new version in the S3 bucket. It also notifies the Document Metadata Service (via Kafka) to update the document's latest version URL and record the version in the Version Table.
    * **Reconciliation Job:** After an editing session ends (e.g., no active users for a duration), this job fetches the initial major version, applies all intermediate operations from the Operation DB, creates a new major version in S3, and then deletes all intermediate minor versions and operations from the databases to optimize storage.

#### Architecture Diagram:


---

### 5. DB Schema and API Points:

#### Database Schema:

* **Document Metadata Database (Cassandra):**
    * `document_id` (UUID, Primary Key)
    * `title` (Text)
    * `created_by` (User ID)
    * `created_time` (Timestamp)
    * `last_modified_by` (User ID)
    * `last_modified_time` (Timestamp)
    * `latest_blob_url` (Text - URL to the latest content in S3)
    * `status` (Text - e.g., 'active', 'archived')
    * *Justification:* Cassandra is chosen for its **high write throughput**, essential for storing and updating metadata for billions of documents, and its **eventual consistency** model aligns with the overall system's availability preference.

* **Operation Database (NoSQL - e.g., Cassandra or similar distributed key-value store suitable for time-series data):**
    * `op_id` (UUID, Primary Key)
    * `document_id` (UUID)
    * `timestamp` (Timestamp)
    * `user_id` (User ID - who performed the operation)
    * `event_type` (Text - e.g., 'insert', 'delete', 'update')
    * `position` (Integer - where the change occurred)
    * `data` (Text - the actual characters inserted/deleted)
    * `version_before` (Integer - version of document before this operation)
    * `version_after` (Integer - version of document after this operation)
    * *Justification:* A NoSQL database is ideal for storing a **massive stream of individual operations**, as it offers high write scalability and flexible schema to handle diverse event types.

* **Version Table (NoSQL - e.g., Cassandra):**
    * `version_id` (UUID, Primary Key)
    * `document_id` (UUID)
    * `version_number` (Integer/Decimal - e.g., 10, 10.1)
    * `created_by` (User ID)
    * `created_time` (Timestamp)
    * `blob_url` (Text - URL to this specific version in S3)
    * *Justification:* Similar to the Document Metadata DB, Cassandra provides the **scalability** for storing numerous document versions.

#### API Endpoints (RESTful for document management, WebSockets for real-time editing):

* **Document Management (RESTful):**
    * `POST /documents`
        * **Request:** `{"title": "My New Document", "created_by": "user_id"}`
        * **Response:** `{"document_id": "uuid_of_document"}`
        * *Function:* Creates a new document.
    * `GET /documents/{document_id}`
        * **Response:** `{"document_id": "uuid", "title": "...", "content": "..."}`
        * *Function:* Retrieves document content in read-only mode.
    * `PUT /documents/{document_id}`
        * **Request:** `{"title": "Updated Title"}`
        * **Response:** `{"status": "success"}`
        * *Function:* Updates document metadata (e.g., title).
    * `DELETE /documents/{document_id}`
        * **Response:** `{"status": "success"}`
        * *Function:* Deletes a document.
    * `GET /documents/{document_id}/versions`
        * **Response:** `[{"version_id": "uuid", "version_number": 10.0, "created_time": "..."}]`
        * *Function:* Fetches all available versions of a document.
    * `GET /documents/{document_id}/versions/{version_id}`
        * **Response:** `{"document_id": "uuid", "version_id": "uuid", "content": "..."}`
        * *Function:* Fetches a specific version of a document.

* **Real-time Editing (WebSocket):**
    * `WS /documents/{document_id}/edit`
        * **Client Sends:** `{"op_type": "insert", "position": 5, "char": "A", "client_id": "user_id"}`
        * **Server Broadcasts:** `{"op_type": "insert", "position": 5, "char": "A", "client_id": "user_id", "transformed_by": "server"}` (after OT)
        * *Function:* Establishes a bidirectional connection for real-time document modifications and cursor position updates.
        * **Client Sends (Cursor Update):** `{"event_type": "cursor_update", "position": 120, "client_id": "user_id"}`
        * **Server Broadcasts (Cursor Update):** `{"event_type": "cursor_update", "position": 120, "client_id": "user_id"}`
        * *Function:* Updates and broadcasts cursor positions of active users.

---

### 6. Consider a Relevant DSA:

* **Problem:** **Conflict Resolution in Concurrent Editing.** When multiple users modify the same document simultaneously, their operations can conflict (e.g., User A inserts character 'X' at position 5, while User B deletes character at position 5). Without proper handling, this leads to **inconsistent document states** across clients.

* **Data Structures and Algorithms:**
    * **Operational Transformation (OT)**:
        * **Concept:** OT transforms concurrent operations to ensure their effects are maintained correctly despite interleaved execution. It **adjusts an operation** based on changes made by another concurrent operation that has already been applied.
        * **Example:** If Alice inserts 'A' at position 0 (turning "BC" into "ABC") and Bob inserts 'D' at position 2 (turning "BC" into "BCD"), the OT algorithm would transform Bob's "insert D at position 2" instruction when applying it to Alice's document, recognizing that Alice's insertion shifted the original position 2 to position 3. Thus, Alice's client would apply "insert D at position 3" to "ABC", resulting in "ABDC". Similarly, Alice's operation would be transformed for Bob's client. The goal is to reach a **consistent final state** (e.g., "ABDC") on all clients.
        * **Why efficient:** OT ensures a globally consistent document state, allowing for true concurrent editing without explicit locking. It operates on *deltas* (changes) rather than entire document states, minimizing network payload. The transformations are deterministic and applied on both client and server sides to maintain synchronization.
    * **Conflict-free Replicated Data Types (CRDTs)**:
        * **Concept:** CRDTs are data structures that can be replicated across multiple machines, allowing concurrent updates without coordination, and always **converge to a consistent state**. They achieve this by defining operations that are commutative, associative, and idempotent.
        * **Example:** For a text editor, a CRDT might assign unique, globally ordered identifiers (like fractional indices) to each character. If Alice inserts 'A' between characters with indices `i1` and `i2`, 'A' gets an index `idx_A` such that `i1 < idx_A < i2`. If Bob concurrently inserts 'D' at another location, 'D' gets `idx_D`. When these changes are merged, characters are simply ordered by their indices, inherently resolving conflicts without complex transformations.
        * **Why efficient:** CRDTs are highly resilient to **network partitions and latency**, as operations can be applied locally and asynchronously merged. They simplify the server logic by shifting conflict resolution to the data structure itself.
        * **Trade-off:** Google Docs primarily uses OT due to the complexities of CRDT implementation for text editing and specific requirements.

---

### 7. Describe the Trade-offs:

* **OT vs. CRDT**:
    * **OT:** Offers **fine-grained control** over transformation logic, potentially leading to a more intuitive user experience for conflict resolution. However, it requires a **centralized server** to coordinate transformations and can be highly **complex to implement** correctly (limiting scalability if not carefully designed). All operations must go through a single server for a specific document.
    * **CRDT:** Simpler to implement in a distributed environment (no central server for conflict resolution), inherently resilient to network issues, and guarantees eventual consistency. However, the specific UI outcome of merges might be less predictable or harder to control compared to OT, and might require more memory for character metadata.

* **Monolithic vs. Microservices**:
    * **Microservices (Chosen):** Provides **high scalability**, **fault isolation**, and **independent deployment** of components (e.g., metadata service, editor service). This is crucial for handling millions of users and billions of documents.
    * **Trade-off:** Adds **operational complexity** (e.g., distributed tracing, inter-service communication, data consistency across services) compared to a monolithic application.

* **Using a Cache (Redis) vs. Direct DB Access (S3)**:
    * **Cache (Redis):** Provides extremely **low-latency access** to the canonical copy of actively edited documents, essential for real-time responsiveness. This significantly reduces the load on the Blob Storage (S3) and improves user experience.
    * **Trade-off:** Introduces **cache invalidation challenges** and requires managing data consistency between the cache and persistent storage. Data in Redis is temporary, requiring periodic persistence to S3.

* **Eventual Consistency (Metadata) vs. Strong Consistency (Collaborative Edits)**:
    * **Eventual Consistency (Document Metadata, e.g., Cassandra):** Favored for **high availability and scalability** of document metadata, as minor delays in metadata synchronization are acceptable.
    * **Strong Consistency (Collaborative Edits):** Prioritized for the active editing experience (using OT/CRDT and WebSockets) to ensure all users see a **consistent view** of the document in near real-time.
    * **Trade-off:** This **hybrid approach** balances the need for high availability across the system with the critical requirement for real-time consistency during active collaboration, leveraging different technologies and strategies for different parts of the system.

* **Saving Entire File vs. Sending Deltas**:
    * **Sending Deltas (Chosen):** Drastically **reduces network bandwidth** and server processing for each keystroke, making real-time collaboration feasible and efficient.
    * **Trade-off:** Requires a more complex client-side and server-side logic (OT/CRDT) to track and apply changes correctly, handle out-of-order operations, and reconcile conflicts. Sending entire files would be simpler but impractical for real-time, large-scale systems.