# Hotel Booking App like Airbnb/Booking.com

## 1. Determine the Scope:

### Functional Requirements:
* **User Management:** Users should be able to sign up, log in, log out, and update their profiles.
* **Hotel Search:** Users must be able to search for hotels based on criteria such as **location**, **hotel name**, and **dates of stay**. The search results should include partial hotel metadata (thumbnail, title, description, review summary). Search results should be paginated.
* **Hotel and Room Details:** After selecting a hotel, users should see detailed information including its description, amenities, reviews, and a list of **available rooms with prices for the selected dates**.
* **Room Booking:** Users should be able to **book a room** for specific dates. This involves a payment process.
* **Booking History:** Users should be able to view their **past bookings**.
* **Hotel Reviews:** Users should be able to submit **reviews and ratings** for hotels, potentially including images.

### Non-Functional Requirements:
* **Scalability:** The system must support a large user base (e.g., **50 million users**) and a significant number of hotel listings (e.g., **1 million hotels**). It should be designed with a microservices architecture to handle high traffic and load.
* **Availability:** The system should be **highly available**, especially for search operations, to ensure users can always find hotels.
* **Consistency:** The system must maintain **strong consistency for booking operations** to prevent double-booking of rooms. No two users should be able to book the same room for the same dates.
* **Low Latency:** Search operations should have low latency to provide a good user experience.
* **Security:** User data (e.g., payment information) must be handled securely.
* **Fault Tolerance:** The system should be resilient to failures in individual components.

---

## 2. Determine Core Entities:

Based on the functional requirements, the core entities of the system are:

* **User:** Represents individuals using the application.
* **Hotel:** Represents a property offering rooms.
* **Room:** Represents a specific type of accommodation within a hotel.
* **Booking:** Represents a confirmed reservation made by a user for a room in a hotel.
* **Review:** Represents feedback and ratings provided by users for hotels.
* **Payment:** Represents a financial transaction for a booking.

---

## 3. Define a High-Level Design In-Depth:

The system will leverage a **microservices architecture** to ensure scalability, availability, and maintainability.

### Major Components and Interactions:

1.  **Users:** Interact with the application via various client devices (web, mobile).
2.  **Load Balancer & API Gateway:**
    * **Load Balancer:** Distributes incoming user traffic evenly across multiple instances of API Gateway.
    * **API Gateway:** Acts as the single entry point for all client requests. It handles:
        * **Authentication and Authorization:** Verifies user identity and permissions.
        * **Request Routing:** Directs requests to the appropriate microservice based on the API endpoint.
        * **Rate Limiting:** Protects backend services from abuse and overload.
        * **SSL Termination:** Handles encrypted traffic.
3.  **Microservices:**
    * **User Service:** Manages user registration, login, profile updates, and stores user metadata in a **User DB**.
    * **Search Service:** Handles hotel search queries. It queries **Elasticsearch** for efficient text-based and geo-location searches. For detailed information after an initial search, it fetches data from a **Redis Cache** (for room availability and pricing) and the **Hotel DB**. It also interacts with an **S3 Bucket** for hotel images.
    * **Hotel Service (Implicit within Hotel DB and Search):** Manages hotel listings, room types, amenities, and their metadata.
    * **Booking Service:** Orchestrates the booking process. It checks room availability, interacts with the **Payment Service**, and publishes booking events to a **Kafka Broker**. Crucially, it uses a **Redis Lock** to prevent concurrent bookings of the same room.
    * **Payment Service:** Handles payment processing. It interacts with a **Third-Party Payment Gateway** for actual transactions and records payment details in a **Payment DB**.
    * **Review Service:** Manages user reviews and ratings for hotels, storing them in a **Review DB** and review-related images in the **S3 Bucket**.
    * **Booking Info Service:** Retrieves past and current booking details for a user from the **Booking DB**.
    * **Notification Service:** Consumes booking events from Kafka to send notifications (e.g., booking confirmation) to users.
    * **Availability Service (Consumer):** Consumes booking events from Kafka and updates the **Availability Table within Hotel DB** (or a dedicated Availability DB/Cache) to reflect room occupancy.
    * **CDC (Change Data Capture) Pipeline:** Continuously streams data changes from the Hotel DB to Elasticsearch. A **Consumer Service** within this pipeline denormalizes relational data from the Hotel DB before indexing it into Elasticsearch for efficient searching.
4.  **Databases:**
    * **User DB (MySQL/PostgreSQL):** Stores user registration details.
    * **Hotel DB (PostgreSQL):** Stores relational data about hotels, rooms, and potentially availability/pricing.
    * **Review DB (MySQL/PostgreSQL/Cassandra):** Stores hotel reviews and ratings.
    * **Payment DB (MySQL):** Stores payment transaction details.
    * **Booking DB (PostgreSQL/MySQL):** Stores booking records.
5.  **Caches:**
    * **Elasticsearch:** Used for fast and efficient textual and geospatial search queries for hotels.
    * **Redis Cache (Radius Cache):** Used by the Search Service to cache room availability, pricing, and for **Redis Lock** in the Booking Service to handle concurrency control during bookings.
6.  **Storage:**
    * **S3 Bucket (Blob Storage):** Stores all static assets like hotel images and user-uploaded review images.
7.  **Message Broker:**
    * **Kafka Broker:** Facilitates asynchronous communication between services, especially for booking events, ensuring loose coupling and resilience.

### Data Flow for Key Operations:

1.  **User Search for Hotel:**
    * User sends a search request (location, name, dates) to API Gateway.
    * API Gateway routes it to the Search Service.
    * Search Service queries **Elasticsearch** (fed by a CDC pipeline from Hotel DB) for hotels matching location and name.
    * Elasticsearch returns a list of relevant `hotel_id`s and partial metadata.
    * Search Service then uses these `hotel_id`s to query the **Redis Cache** (or Hotel DB's availability/price tables) for room availability and pricing on the specified dates.
    * Search Service fetches hotel images from the **S3 Bucket**.
    * Search Service aggregates data and returns paginated results to the user.

2.  **User Books a Room:**
    * User selects a room and confirms booking, sending a request to API Gateway.
    * API Gateway routes it to the Booking Service.
    * **Concurrency Control (Redis Lock):** The Booking Service first attempts to acquire a **Redis Lock** on the specific `room_id` for the given dates, with a TTL (Time To Live).
    * **Availability Check:** If the lock is acquired, Booking Service calls the Availability Service to confirm the room is still available in the Hotel DB.
    * **Payment Process:** If available, Booking Service initiates a call to the Payment Service.
    * Payment Service interacts with the **Third-Party Payment Gateway** and updates the **Payment DB**.
    * On successful payment, Payment Service informs Booking Service.
    * Booking Service releases the Redis Lock and publishes a "Booking Confirmed" event to the **Kafka Broker**.
    * **Asynchronous Updates:**
        * The **Consumer Service** (for bookings) consumes the Kafka event and updates the **Booking DB**.
        * The **Availability Service** consumes the Kafka event and updates the `availability` table in the **Hotel DB** (marking the room as occupied).
        * The **Notification Service** consumes the Kafka event and sends a confirmation notification to the user.

### Architecture Diagram:


---

## 4. DB Schema and API Points:

### Database Schema:

We will primarily use **PostgreSQL** for relational data due to its strong consistency, ACID properties, and support for complex queries, including geospatial extensions (which can be a fallback for proximity search if Elasticsearch isn't used). For key-value caching and locking, **Redis** is used. Elasticsearch is used for specialized search.

1.  **`users` Table (PostgreSQL)**
    * `user_id` (PK, UUID)
    * `email` (VARCHAR, UNIQUE)
    * `password_hash` (VARCHAR)
    * `name` (VARCHAR)
    * `phone_number` (VARCHAR)
    * `created_at` (TIMESTAMP)
    * `updated_at` (TIMESTAMP)

2.  **`hotels` Table (PostgreSQL)**
    * `hotel_id` (PK, UUID)
    * `name` (VARCHAR)
    * `address` (VARCHAR)
    * `latitude` (DECIMAL)
    * `longitude` (DECIMAL)
    * `description` (TEXT)
    * `amenities` (JSONB) - e.g., `{"wifi": true, "pool": false}`
    * `avg_rating` (DECIMAL)
    * `image_urls` (ARRAY of VARCHAR) - URLs to S3 bucket
    * `created_at` (TIMESTAMP)
    * `updated_at` (TIMESTAMP)

3.  **`rooms` Table (PostgreSQL)**
    * `room_id` (PK, UUID)
    * `hotel_id` (FK to `hotels.hotel_id`)
    * `room_type` (VARCHAR) - e.g., 'Deluxe', 'Standard'
    * `capacity` (INT)
    * `description` (TEXT)
    * `base_price` (DECIMAL)
    * `created_at` (TIMESTAMP)
    * `updated_at` (TIMESTAMP)

4.  **`room_prices` Table (PostgreSQL)**
    * `price_id` (PK, UUID)
    * `room_id` (FK to `rooms.room_id`)
    * `start_date` (DATE)
    * `end_date` (DATE)
    * `price` (DECIMAL)
    * `currency` (VARCHAR)
    * `created_at` (TIMESTAMP)
    * `updated_at` (TIMESTAMP)
    * *Justification:* Stores dynamic pricing based on date ranges, allowing for seasonal or event-based price changes without daily entries.

5.  **`room_availability` Table (PostgreSQL)**
    * `availability_id` (PK, UUID)
    * `room_id` (FK to `rooms.room_id`)
    * `date` (DATE)
    * `is_available` (BOOLEAN) - true if available, false if booked
    * *Justification:* While storing each day's availability for every room can be data-intensive, it simplifies search queries significantly, especially when combining with date range searches. The video discusses a range-based approach as well, which reduces data volume but complicates updates. For high search efficiency and clear status, a daily entry per room per date is often preferred for booking systems, and horizontally scaling the database can handle the volume.

6.  **`bookings` Table (PostgreSQL)**
    * `booking_id` (PK, UUID)
    * `user_id` (FK to `users.user_id`)
    * `hotel_id` (FK to `hotels.hotel_id`)
    * `room_ids` (ARRAY of UUID) - Can book multiple rooms
    * `start_date` (DATE)
    * `end_date` (DATE)
    * `total_amount` (DECIMAL)
    * `currency` (VARCHAR)
    * `status` (ENUM: 'PENDING', 'CONFIRMED', 'CANCELLED', 'FAILED')
    * `payment_id` (FK to `payments.payment_id`, NULLABLE)
    * `created_at` (TIMESTAMP)
    * `updated_at` (TIMESTAMP)

7.  **`payments` Table (MySQL/PostgreSQL)**
    * `payment_id` (PK, UUID)
    * `user_id` (FK to `users.user_id`)
    * `booking_id` (FK to `bookings.booking_id`)
    * `amount` (DECIMAL)
    * `currency` (VARCHAR)
    * `transaction_id` (VARCHAR, UNIQUE) - From payment gateway
    * `status` (ENUM: 'SUCCESS', 'FAILED', 'PENDING')
    * `payment_method` (VARCHAR)
    * `created_at` (TIMESTAMP)
    * `updated_at` (TIMESTAMP)

8.  **`reviews` Table (PostgreSQL)**
    * `review_id` (PK, UUID)
    * `hotel_id` (FK to `hotels.hotel_id`)
    * `user_id` (FK to `users.user_id`)
    * `rating` (INT, 1-5)
    * `comment` (TEXT)
    * `image_urls` (ARRAY of VARCHAR) - URLs to S3 bucket
    * `created_at` (TIMESTAMP)

### API Endpoints:

**User Management:**
* `POST /api/v1/auth/register`
    * **Payload:** `{ "email": "user@example.com", "password": "...", "name": "..." }`
    * **Response:** `{ "user_id": "...", "message": "User registered successfully" }`
* `POST /api/v1/auth/login`
    * **Payload:** `{ "email": "user@example.com", "password": "..." }`
    * **Response:** `{ "token": "jwt_token", "user_id": "..." }`
* `PUT /api/v1/users/{user_id}`
    * **Payload:** `{ "name": "New Name", "phone_number": "..." }`
    * **Response:** `{ "user_id": "...", "message": "Profile updated" }`

**Hotel Search & Details:**
* `GET /api/v1/hotels/search`
    * **Query Params:** `location=<city_name>`, `name=<hotel_name>`, `check_in=<YYYY-MM-DD>`, `check_out=<YYYY-MM-DD>`, `page=1`, `size=10`
    * **Response (Paginated):** `[ { "hotel_id": "...", "name": "...", "address": "...", "avg_rating": "...", "thumbnail_url": "...", "available_rooms_count": 5 }, ... ]`
* `GET /api/v1/hotels/{hotel_id}`
    * **Query Params:** `check_in=<YYYY-MM-DD>`, `check_out=<YYYY-MM-DD>`
    * **Response:** `{ "hotel_id": "...", "name": "...", "description": "...", "amenities": [...], "reviews_summary": {...}, "rooms_available": [ { "room_id": "...", "room_type": "...", "capacity": ..., "price": ..., "currency": "..." } ] }`

**Booking:**
* `POST /api/v1/bookings`
    * **Headers:** `Authorization: Bearer <jwt_token>`
    * **Payload:** `{ "hotel_id": "...", "room_id": "...", "start_date": "YYYY-MM-DD", "end_date": "YYYY-MM-DD" }`
    * **Response:** `{ "booking_id": "...", "payment_url": "...", "status": "PENDING" }`
        * *Note:* This might redirect to a payment gateway URL.

**Booking History:**
* `GET /api/v1/users/{user_id}/bookings`
    * **Headers:** `Authorization: Bearer <jwt_token>`
    * **Response (Paginated):** `[ { "booking_id": "...", "hotel_name": "...", "room_type": "...", "start_date": "...", "end_date": "...", "total_amount": "...", "status": "..." }, ... ]`

**Reviews:**
* `POST /api/v1/hotels/{hotel_id}/reviews`
    * **Headers:** `Authorization: Bearer <jwt_token>`
    * **Payload:** `{ "rating": 5, "comment": "Great stay!", "image_urls": ["s3_url1", "s3_url2"] }`
    * **Response:** `{ "review_id": "...", "message": "Review submitted" }`

---

## 5. Consider a Relevant DSA:

A relevant DSA problem encountered during the implementation of this system is **Concurrency Control for Room Booking**.

* **Problem:** Multiple users might try to book the same room for the same dates simultaneously. Without proper handling, this could lead to an inconsistent state (double-booking).

* **Solution Approach (Optimistic Locking with Distributed Lock):**
    1.  **Distributed Lock (Redis Lock):** When a user initiates a booking for a specific `room_id` and `date_range`, the **Booking Service** attempts to acquire a distributed lock using **Redis**. The key for the lock could be `room_id:YYYY-MM-DD_start:YYYY-MM-DD_end`. This lock would have a **Time To Live (TTL)** of, say, 5-10 minutes, giving the user enough time to complete payment.
    2.  **Availability Check:** After acquiring the lock, the Booking Service performs a final check on the `room_availability` table in the **Hotel DB** to ensure the room is still available for the desired dates. This is crucial because even with a lock, the availability status might have changed if a previous lock holder failed to complete the booking and its lock expired.
    3.  **Payment Processing:** If the room is confirmed available, the system proceeds with payment via the Payment Service.
    4.  **Transaction Completion:**
        * **Success:** If payment is successful, the lock is explicitly released, and a "Booking Confirmed" event is published to Kafka. Consumers update the `bookings` and `room_availability` tables.
        * **Failure/Timeout:** If payment fails or the lock's TTL expires before payment is confirmed, the lock automatically releases, and the room becomes available again. The user receives an error.

* **Why this approach is efficient:**
    * **Prevents Double Booking:** The Redis lock ensures that only one user can proceed with the payment for a specific room at a given time.
    * **High Availability (Optimistic):** By using optimistic locking (checking availability *after* acquiring a temporary lock and before final confirmation), the system avoids holding locks for extended periods unnecessarily, reducing contention.
    * **Scalability:** Redis, being an in-memory data store, provides fast lock acquisition/release operations, which is critical in a high-concurrency environment.
    * **Fault Tolerance:** The TTL on the Redis lock ensures that if a user's session crashes or they abandon the booking, the lock will eventually expire, preventing indefinite unavailability of the room.

---

## 6. Describe the Trade-offs:

1.  **Consistency vs. Availability (CAP Theorem):**
    * **Trade-off:** For search, the system prioritizes **Availability** (AP) to ensure users can always find hotels, even if the search results are eventually consistent. For booking, it prioritizes **Consistency** (CP) to prevent double-bookings, meaning a temporary unavailability for a specific room might occur during a booking transaction.
    * **Design Choice:** Using Elasticsearch for search (AP) and a combination of PostgreSQL with Redis locks and event-driven updates for booking (CP).
    * **Pros:** Provides a good balance, offering a responsive search experience while ensuring booking integrity.
    * **Cons:** The search results might be slightly stale compared to the real-time availability in the database, requiring the final availability check during booking.

2.  **Monolithic vs. Microservices Architecture:**
    * **Trade-off:** Complexity and operational overhead vs. scalability and flexibility.
    * **Design Choice:** Microservices.
    * **Pros:**
        * **Scalability:** Individual services can be scaled independently based on their load.
        * **Resilience:** Failure in one service does not bring down the entire system.
        * **Flexibility:** Different services can use different technologies/databases.
        * **Maintainability:** Smaller codebases are easier to develop and deploy.
    * **Cons:**
        * **Increased Complexity:** More services mean more operational overhead, distributed transactions, and inter-service communication challenges.
        * **Debugging:** Tracing issues across multiple services can be harder.
        * **Deployment:** More components to deploy and manage.

3.  **Using a Cache (Elasticsearch/Redis) vs. Direct DB Access:**
    * **Trade-off:** Data freshness and consistency vs. performance.
    * **Design Choice:** Elasticsearch for search and Redis for temporary data and locking.
    * **Pros:**
        * **Performance:** Caches significantly reduce read latency and database load for frequently accessed data (search queries, room availability lookups).
        * **Scalability:** Caches can handle a much higher read throughput than traditional databases.
    * **Cons:**
        * **Data Stale-ness:** Data in caches might not be immediately consistent with the primary database, requiring mechanisms like CDC to keep them updated (Elasticsearch) or a tolerance for eventual consistency.
        * **Cache Invalidation:** Managing cache invalidation is a hard problem, especially in a distributed system.

4.  **Denormalized Data (for Search) vs. Normalized Data (for Transactions):**
    * **Trade-off:** Query performance vs. data integrity/storage efficiency.
    * **Design Choice:** Store normalized data in PostgreSQL for transactional integrity, and denormalize it into Elasticsearch for optimal search performance.
    * **Pros:**
        * **Optimized Search:** Elasticsearch performs complex queries (full-text, geospatial) very efficiently on denormalized data.
        * **Transactional Integrity:** Normalized PostgreSQL ensures ACID properties for critical operations like booking.
    * **Cons:**
        * **Data Duplication:** Denormalization involves duplicating data, increasing storage needs.
        * **ETL/CDC Overhead:** A pipeline (CDC + Consumer Service) is required to transform and sync data between the normalized and denormalized stores, adding complexity.

5.  **Event-Driven Architecture (Kafka) vs. Direct Service Calls:**
    * **Trade-off:** Real-time processing and complexity vs. tight coupling and simpler flow.
    * **Design Choice:** Kafka for critical post-booking updates.
    * **Pros:**
        * **Loose Coupling:** Services don't directly depend on each other, improving resilience.
        * **Scalability:** Events can be processed by multiple consumers, enabling parallel processing.
        * **Resilience:** If a consumer is down, events are persisted in Kafka and can be processed later.
        * **Auditing/Replay:** Kafka provides a durable log of events.
    * **Cons:**
        * **Increased Complexity:** Eventual consistency, message ordering, and error handling in a distributed messaging system are complex.
        * **Debugging:** Tracing event flows across multiple services and topics can be challenging.