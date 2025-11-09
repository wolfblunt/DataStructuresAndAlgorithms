# E-Commerce Platform Design like Amazon/Flipkart

### 1. Determine the Scope:

* **Functional Requirements:**
    * **User Authentication:** Users should be able to log in and sign up for the application.
    * **Product Search:** Users can search and find products based on criteria like title or name. The search results should be paginated to optimize performance.
    * **Product Details:** Users can view detailed information about a product, including description, images, available quantity, and reviews.
    * **Cart Management:** Users can select quantities and add items to their shopping cart.
    * **Checkout and Payment:** Users can successfully make payments and complete the checkout process.
    * **Order Tracking:** Users can track the status of their orders.
    * **Limited Stock Handling:** The system must efficiently manage concurrent purchases of products with limited stock (e.g., flash sales).

* **Non-Functional Requirements:**
    * **Scale:** Support for 10 million monthly active users and 10 orders per second.
    * **Availability & Consistency (CAP Theorem):**
        * **High Availability:** The search module should be highly available to ensure users can always find products.
        * **High Consistency:** Payment, order management, and inventory management modules require high consistency to prevent data discrepancies.
    * **Low Latency:** The system aims for a latency of around 200 milliseconds, especially for search operations.

---

### 2. Determine Core Entities:

The primary core entities identified are:
* **User:** Represents a customer on the platform.
* **Product:** The items available for purchase.
* **Cart:** A collection of products a user intends to buy.
* **Order:** A record of a successful purchase.
* **Checkout:** The process of finalizing a purchase from the cart.
* **Inventory:** Tracks the available stock of products.

---

### 3. Define a High-Level Design In-Depth:


The system follows a **microservices architecture** to handle the high scale and traffic.

* **User Interaction:** Users interact with the system through an **API Gateway** and **Load Balancer**.
    * **Load Balancer:** Uses algorithms like Round Robin to distribute traffic among microservices.
    * **API Gateway:** Handles traffic routing, user authentication and authorization (e.g., JWT tokens), and rate limiting.

* **Core Microservices:**
    * **User Service:** Manages user login, signup, and stores user metadata.
    * **Product Service:** Manages product metadata (description, category, price, images).
    * **Search Service:** Handles product search queries efficiently.
    * **Cart Service:** Manages items added to a user's cart.
    * **Checkout Service:** Orchestrates the checkout process, including inventory checks and payment initiation.
    * **Payment Service:** Interfaces with a third-party payment gateway to process payments.
    * **Order Status Service:** Allows users to view the status and history of their orders.
    * **Inventory Service:** Manages product stock levels, ensuring consistency.
    * **Notification Service:** Sends notifications to users about order status and other events.

* **Data Flow for Key Operations:**
    1.  **User Authentication:** User signs up/logs in via API Gateway -> User Service -> User DB. JWT token is issued for subsequent requests.
    2.  **Product Search:** User search query via API Gateway -> Search Service -> Elastic Search (for optimized searching) -> Product DB (via CDC pipeline for real-time data sync). Search results (product IDs, partial metadata) are paginated.
    3.  **Viewing Product Details:** User selects a product ID via API Gateway -> Product Service -> Product DB (for metadata) and S3 bucket/CDN (for images).
    4.  **Add to Cart:** User adds product to cart via API Gateway -> Cart Service -> Cart DB. Cart service retrieves current product prices from Product DB to ensure up-to-date pricing.
    5.  **Checkout Process:**
        * User initiates checkout via API Gateway -> Checkout Service.
        * Checkout Service calls **Inventory Service** to verify stock availability in the Inventory DB.
        * If stock is available, Checkout Service calls **Payment Service**.
        * Payment Service interacts with a **Third-Party Payment Gateway**.
        * Upon successful payment, Payment Service updates the Payment DB.
        * Checkout Service then publishes an event to a **Kafka Broker** with payment status and cart details.
        * **Kafka Consumers** (Order Consumer, Inventory Manager, Notification Service) asynchronously process this event:
            * **Order Consumer:** Updates the Order DB with the new order status.
            * **Inventory Manager:** Decreases the product quantity in the Inventory DB.
            * **Notification Service:** Sends a notification to the user about the order status.

---

### 5. DB Schema and API Points:

* **Database Choices:**
    * **User DB:** **MySQL** (Relational Database) is chosen for user data due to its need for high consistency and structured data like name, email, password, and addresses.
    * **Product DB:** **MongoDB** (Document Database) is selected because product details can vary significantly from product to product, requiring a flexible schema. It stores product ID, name, description, category, available quantity (initial), price, currency, and image URLs.
    * **Cart DB:** **PostgreSQL** (Relational Database) is used for cart information, providing consistency for mapping user IDs to their cart items. Schema includes `cart_id`, `user_id`, and a list of products (product_id, quantity).
    * **Inventory DB:** **PostgreSQL** (Relational Database) is critical for managing real-time stock and requires high consistency. It is indexed on `product_id` and is the single source of truth for available quantities.
    * **Payment DB:** **PostgreSQL** (Relational Database) to store payment transaction details, ensuring consistency.
    * **Order DB:** **MySQL** (Relational Database) for order details due to its requirement for high consistency. Schema includes `order_id`, `user_id`, `items` (product_id, quantity, price at purchase, currency), `total_valuation`, `payment_id`, and `status`.
    * **Elastic Search:** Utilized for fast and highly available product searching, replicating data from Product DB via a CDC (Change Data Capture) pipeline.
    * **Redis Cache:** Used in front of the Inventory DB to reduce read load and improve latency.
    * **S3 Bucket/CDN:** Stores product images efficiently. S3 serves as primary storage, and CDN caches images closer to users for faster delivery.

* **Key API Endpoints (RESTful):**
    * **Search Products:**
        * `GET /api/products/search?term={keyword}`
        * **Request:** Query parameter `term` (e.g., "iPhone").
        * **Response:** `List<ProductMetadata>` (paginated: `product_id`, `name`, `thumbnail_url`, `price`).
    * **View Product Details:**
        * `GET /api/products/{productId}`
        * **Request:** Path parameter `productId`.
        * **Response:** `ProductDetails` (JSON object with full product metadata, including image URLs).
    * **Add Item to Cart:**
        * `POST /api/cart/add`
        * **Request Body:** `{"productId": "...", "quantity": "..."}`
        * **Request Header:** `Authorization: Bearer <JWT Token>` (contains `userId`)
        * **Response:** `{"cartId": "..."}`
    * **Checkout:**
        * `POST /api/checkout`
        * **Request Body:** `{"cartId": "...", "products": [{"productId": "...", "quantity": "...", "price": "..."}]}`
        * **Request Header:** `Authorization: Bearer <JWT Token>`
        * **Response:** `{"orderId": "..."}`
    * **Make Payment:**
        * `POST /api/payment`
        * **Request Body:** `{"orderId": "...", "cardDetails": "...", "expirationDate": "...", "cvv": "..."}`
        * **Request Header:** `Authorization: Bearer <JWT Token>`
        * **Response:** `{"status": "CONFIRMED" | "FAILED"}`
    * **Get Order Status:**
        * `GET /api/orders/{orderId}/status`
        * **Request:** Path parameter `orderId`.
        * **Request Header:** `Authorization: Bearer <JWT Token>`
        * **Response:** `{"orderId": "...", "status": "PENDING" | "CONFIRMED" | "SHIPPED" | "DELIVERED"}`

---

### 6. Consider a Relevant DSA:

* **Problem:** Efficiently managing **limited stock during concurrent purchases** (e.g., flash sales). If multiple users try to buy the last item simultaneously, a naive check-and-decrement approach can lead to overselling (race condition).
* **Solution: Distributed Locking with Redis:**
    * **Mechanism:** Introduce a **Redis distributed lock** before the inventory check. When a user attempts to purchase a limited-stock item, the system first tries to acquire a lock on that `product_id` for the requested quantity and `user_id`.
    * **Process:**
        1.  User initiates purchase.
        2.  Checkout service attempts to acquire a lock on the `product_id` in Redis.
        3.  The lock includes a **TTL (Time To Live)** (e.g., 30-60 seconds) to ensure it expires if the user abandons the purchase or the payment fails.
        4.  If the lock is acquired, the system proceeds to check inventory and payment.
        5.  If the lock cannot be acquired (another user holds it), the request fails, and the user is notified that the item is out of stock.
        6.  Upon successful payment and inventory update, the lock is explicitly released (or expires naturally).
    * **Efficiency:** Redis is an in-memory data store, making lock acquisition and release very fast. This prevents multiple concurrent requests from accessing and modifying the inventory simultaneously, effectively solving the race condition for limited stock.

---

### 7. Describe the Trade-offs:

* **Microservices vs. Monolithic Architecture:**
    * **Trade-off:** Choosing **microservices** allows for better scalability, fault isolation, and independent deployment of components (e.g., Search Service can scale independently of Payment Service). However, it introduces increased complexity in terms of deployment, monitoring, distributed transactions, and inter-service communication. A **monolithic** architecture would be simpler to develop and deploy initially but would struggle with scalability and fault tolerance at Amazon's scale.
* **Consistency vs. Availability (CAP Theorem):**
    * **Trade-off:** The design prioritizes **availability for search** (using Elastic Search and CDN) and **consistency for critical operations** like payment, order, and inventory management (using relational databases like PostgreSQL/MySQL and distributed locks). This means that while search results might be eventually consistent (slight delay in new product listings appearing in search), financial transactions and stock counts are strongly consistent. There's an inherent trade-off; achieving both high consistency and high availability simultaneously in a distributed system is challenging.
* **Using a Cache (Redis) vs. Direct DB Access for Inventory:**
    * **Trade-off:** Introducing a **Redis cache** for inventory data significantly reduces the load on the Inventory Database, improving read latency and overall system responsiveness. However, it introduces a **consistency challenge**: ensuring the cache always reflects the most up-to-date information from the database. This is mitigated by implementing a **write-through caching mechanism** (updates both cache and DB) or a **CDC pipeline** to invalidate/update cache entries in near real-time, adding complexity to the system.
* **Asynchronous Processing with Kafka vs. Synchronous Calls for Post-Payment Updates:**
    * **Trade-off:** Using **Kafka for asynchronous event processing** after a successful payment (updating Order DB, Inventory DB, and sending notifications) decouples services, improves system resilience, and ensures high availability of the payment process. If a downstream service (e.g., Inventory Manager) is temporarily down, the event remains in Kafka and will be processed later, preventing payment failures due to transient issues in other services. The trade-off is that these updates become **eventually consistent**, meaning there might be a very short delay between payment confirmation and the order status or inventory level reflecting the change. A synchronous approach would ensure immediate consistency but would be more fragile and prone to cascade failures.
* **Database Choices (SQL vs. NoSQL):**
    * **Trade-off:** The design uses a mix: **SQL (MySQL/PostgreSQL)** for structured, highly consistent data (Users, Cart, Inventory, Orders, Payments) and **NoSQL (MongoDB)** for flexible, schema-less data (Product metadata) that may evolve frequently. This leverages the strengths of each database type. The trade-off is increased operational complexity due to managing multiple database technologies.
* **CDN for Images:**
    * **Trade-off:** Using a **CDN (Content Delivery Network)** for product images dramatically improves load times and user experience by caching static assets closer to the user. This reduces latency and offloads traffic from the main servers. The trade-off is the cost associated with CDN services and the need to manage cache invalidation if image assets change.