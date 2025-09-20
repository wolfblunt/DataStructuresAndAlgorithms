## CDN Design Overview

### Clarifications
- Clarify with the interviewer whether it will be a **Pull-CDN**, **Push-CDN**, or **both**.
- Clarify the average file sizes we expect to be stored and approximately how many files, to estimate **storage capacity** and **bandwidth**.

### Define Your APIs
- **readfile(url)**: `bytes`. Each file to have a unique URL. We can have an auxiliary service used to randomly generate unique URLs, probably based on **UUID** or something.
- **uploadfile(bytes)**: `url`, `file_id`
- **updatefile(file_id, bytes)**
- **deletefile(file_id)**

### CDN Structure
Divide your CDN into two sites:
- **Master Site**: The source of truth.
- **Edge Sites**: The file cache for regions.

The edge sites will handle cache misses by routing requests to the master site.

### Object Storage and Key-Value Store
Each site will have:
- **Object Storage**: For storing files.
- **Key-Value Store**: To map the URL to the internal object storage URL.

For reads:
- A machine will retrieve the URL, use the key-value store to pick the internal object storage URL, and transfer the bytes to the user.

### Sharding and Replication
- **Sharding**: Shard the key-value store by the file URL using **consistent hashing**.
- **Replication**: Have about 3 replicas of the shards at the site they are located.
- Depending on user behavior, choose between **strong consistency** and **eventual consistency** between replicas.

### Eviction Policy
- Decide between **LFU (Least Frequently Used)** or **LRU (Least Recently Used)** as an eviction policy.
- Include a **TTL (Time-To-Live)** for cache entries.

### Load Balancer and Cluster Setup
- Each site will have:
  - A cluster of machines behind load balancers to serve **reads** and **uploads**.
- There will be a global-level load balancer cluster.

### Workflow for File Operations
1. **Upload File**:
   - A user uploads a file from wherever they are.
   - The global load balancers route the request to the master site.
   - A unique URL is generated for the file.
   - The file is stored on the master object storage.
   - The URL is stored in the key-value store and returned to the user.
   - For a **push CDN**, replicate the file to the edge sites using a **peer-to-peer** network efficiently.

2. **Read File**:
   - A user requests a file via its URL.
   - The global load balancers route the request to the nearest edge site.
   - The edge site checks if the URL is stored locally.
     - If it exists, the file is read and returned to the user.
     - If not, the edge site contacts the master site for the file.
       - The edge site stores the file locally and sends the bytes to the user.
     - The next request for the same file will result in a **cache hit**.

3. **Update or Delete File**:
   - When a user updates or deletes a file, an **event message** is sent to the edge sites with the file URL.
   - The edge sites should **invalidate** the file in their locations.
     - If the file was updated, the next read request will result in a **cache miss**.
