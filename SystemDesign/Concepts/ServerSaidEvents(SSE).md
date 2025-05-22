**SSE (Server-Sent Events)** is a web technology that allows a server to push real-time updates to a client over a single, long-lived HTTP connection. The client establishes a connection, and the server sends data as "events" in a `text/event-stream` format whenever new information is available.

**Key Points:**
- Uses HTTP/1.1 or HTTP/2 protocols.
- Lightweight and simple, built on standard HTTP.
- Events are plain text with fields like `data`, `event`, and `id`.
- Supports automatic reconnection if the connection drops.

**Use Cases:**
- Live notifications (e.g., social media alerts).
- Real-time data feeds (e.g., stock prices, sports scores).
- Chat or messaging app updates.

**Example**: A news website uses SSE to push breaking news alerts to users’ browsers without requiring them to refresh the page.

SSE is ideal for one-way, server-to-client communication, but for bidirectional communication, WebSockets may be preferred.


Which protocol SSE uses?

**SSE (Server-Sent Events)** uses the **HTTP/1.1** or **HTTP/2** protocol, depending on the server and client capabilities. It relies on a persistent HTTP connection where the server pushes data to the client over a single, long-lived connection using the `text/event-stream` MIME type.

- **How it works**: The client initiates an HTTP request, and the server keeps the connection open, sending data as "events" whenever updates occur, without requiring the client to repeatedly poll.
- **Key requirement**: SSE requires the HTTP protocol to support persistent connections, which both HTTP/1.1 and HTTP/2 provide.
- **Common usage**: Real-time updates like live notifications, stock tickers, or chat messages.

While HTTP/2 can optimize SSE with features like multiplexing, HTTP/1.1 is still widely used for its simplicity and compatibility.