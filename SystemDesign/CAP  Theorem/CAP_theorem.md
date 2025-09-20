# CAP Theorem

### 1. Consistency
A system is said to be **consistent** if all nodes see the same data at the same time. If we perform a read operation on a consistent system, it should return the value of the most recent write operation. This means that the read should cause all nodes to return the same data, i.e., the value of the most recent write. It is a system’s ability to maintain **ACID properties** of transactions.

### 2. Availability
**Availability** in a distributed system ensures that the system remains operational 100% of the time. Every request gets a (non-error) response regardless of the individual state of a node.

The formula for system availability is:

```
Availability = Uptime ÷ (Uptime + Downtime)
```

Note: This does not guarantee that the response contains the most recent write.

### 3. Partition Tolerance
Partition tolerance means that the system does not fail, even if the network between nodes breaks. Nodes might not be able to communicate, or delays between nodes shouldn’t affect the system. This doesn’t mean a node or nodes go down; they are up but can’t communicate. Partition tolerance has become more of a necessity than an option in distributed systems. It is made possible by sufficiently replicating records across combinations of nodes and networks.


## Applications in the Real World

- **CP Database**: 
  A CP database delivers **consistency** and **partition tolerance** at the expense of **availability**. When a partition occurs between any two nodes, the system has to shut down the non-consistent node until the partition is resolved. The system will return an error or time-out, making it unavailable.

- **AP Database**: 
  An AP database delivers **availability** and **partition tolerance** at the expense of **consistency**. When a partition occurs, all nodes remain available, but those at the wrong end of a partition might return an older version of data than others.

- **CA Database**: 
  This is not possible in any distributed architecture. It can be found only in some non-scalable monolithic architectures.