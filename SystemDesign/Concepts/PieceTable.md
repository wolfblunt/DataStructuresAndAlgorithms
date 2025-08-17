# Piece Table Memory Management and Operations

A **Piece Table** is a data structure used in text editors (like Microsoft Word, VS Code, Sublime Text) to efficiently handle **insertions**, **deletions**, and **search operations** without rewriting the entire file in memory.

It is built on the idea that instead of modifying the original file buffer, we keep track of changes as **pieces** that reference parts of either:

* **Original buffer (ORIG BUFFER)**: The original read-only content of the file loaded into memory.
* **Add buffer (ADD BUFFER)**: A dynamic buffer that stores newly inserted text.

The editor maintains a **piece table**: an ordered list of *pieces*, each containing:

1. **Buffer type**: Origin of the text (ORIG or ADD buffer)
2. **Start position**: Offset within the buffer
3. **Length**: Number of characters in the piece

<br>
<br>

# Piece Table with example
Example of a file containing 10 sentences, each on a new line.
We’ll simulate how an editor like VS Code loads it, edits it, and saves it — to see exactly how this works internally.

## **1. Initial State — Opening the File**

**File on disk** (`file.txt`):

```
(1) The sky is blue.
(2) Birds are singing.
(3) The sun is shining.
(4) Trees are green.
(5) The river flows gently.
(6) Flowers bloom in spring.
(7) Stars twinkle at night.
(8) The moon is bright.
(9) Rain falls softly.
(10) Snow covers the ground.
```

### When Loaded:

### **Original Buffer (ORIG)**

Immutable — contains the file exactly as read.
(Here, `\n` is newline, positions are indexed **0-based**)

```
ORIG:
0:   (1) The sky is blue.\n
25:  (2) Birds are singing.\n
51:  (3) The sun is shining.\n
77:  (4) Trees are green.\n
101: (5) The river flows gently.\n
132: (6) Flowers bloom in spring.\n
163: (7) Stars twinkle at night.\n
193: (8) The moon is bright.\n
222: (9) Rain falls softly.\n
247: (10) Snow covers the ground.
LEN: 283
```

---

### **Add Buffer (ADD)**

Empty at first:

```
ADD: ""  (LEN: 0)
```

---

### **Piece Table**

Initial single entry referencing the whole original file:

```
[ (ORIG, 0, 283) ]
```

* `Buffer` → `ORIG` or `ADD`
* `Start` → index in that buffer
* `Length` → number of characters from that position

---

## **2. First Edit — Insert `" and calm"` after line 5**

Line 5 ends at ORIG position **132** (just after `"The river flows gently."`).

**Steps**:

1. Append `" and calm"` to ADD:

   ```
   ADD: " and calm"   (LEN: 9)
   ```
2. Split piece table into **three**:

   * Text before insertion (ORIG: 0 → 132)
   * Inserted text (ADD: 0 → 9)
   * Text after insertion (ORIG: 132 → rest)

**Piece Table now**:

```
[ (ORIG, 0, 132),
  (ADD, 0, 9),
  (ORIG, 132, 283 - 132) ]
```

**Rendering**:

* Take 0–132 chars from ORIG
* Take 0–9 chars from ADD
* Take 132–283 chars from ORIG

---

## **3. Second Edit — Delete Line 3**

Line 3 is `"The sun is shining.\n"` starting at ORIG index 51 and ending at 77.
To delete:

* Remove its **reference** from the piece table (do not touch ORIG or ADD).

Current table before deletion:

```
[ (ORIG, 0, 132), (ADD, 0, 9), (ORIG, 132, 151) ]
```

After deletion:

* We skip that range from ORIG when building the table.

New **Piece Table**:

```
[ (ORIG, 0, 51),
  (ORIG, 77, 132 - 77),
  (ADD, 0, 9),
  (ORIG, 132, 151) ]
```

(Notice we broke the first ORIG segment into two around the deleted region.)

---

## **4. Third Edit — Replace `"Birds are singing."` with `"Birds are flying high."`**

Line 2 starts at ORIG index 25 and ends at 51.

**Steps**:

1. Add `"Birds are flying high."` to ADD:

   ```
   ADD: " and calmBirds are flying high."
   ```

   * `" and calm"` = first 9 chars
   * `"Birds are flying high."` starts at ADD index 9

2. Replace in Piece Table:

   * Remove (ORIG, 25, 26) → `"Birds are singing.\n"`
   * Insert (ADD, 9, 24) in that position

New **Piece Table**:

```
[ (ORIG, 0, 25),
  (ADD, 9, 24),
  (ORIG, 51, 77 - 51),
  (ORIG, 77, 132 - 77),
  (ADD, 0, 9),
  (ORIG, 132, 151) ]
```

---

## **5. Fourth Edit — Append `" 🌙"` to `"The moon is bright."`**

Line 8 starts at ORIG index 193 and ends at 222.

**Steps**:

1. Append `" 🌙"` to ADD:

   ```
   ADD: " and calmBirds are flying high. 🌙"
   ```

   * `" 🌙"` starts at ADD index 33

2. Modify Piece Table:

   * Split ORIG segment containing line 8
   * Insert (ADD, 33, 3) after that line

New **Piece Table**:

```
[ (ORIG, 0, 25),
  (ADD, 9, 24),
  (ORIG, 51, 77 - 51),
  (ORIG, 77, 132 - 77),
  (ADD, 0, 9),
  (ORIG, 132, 193 - 132),
  (ORIG, 193, 222 - 193),
  (ADD, 33, 3),
  (ORIG, 222, 283 - 222) ]
```

---

## **6. Key Observations**

* **ORIG** never changes — all original data stays intact.
* **ADD** only grows — no text is removed.
* **Piece Table** is the *real* document — changing it changes the document view instantly.
* **Undo/Redo** = swap between piece table snapshots.
* Insertion/Deletion = **O(1)** to O(log n) depending on table size.
* File saving = walk the piece table, copy referenced slices to output file.

---

## **7. Visual Diagram**

```
ORIG BUFFER (immutable):
[The sky is blue.\n|Birds are singing.\n|The sun is shining.\n|Trees are green.\n|The river flows gently.\n|Flowers bloom in spring.\n|Stars twinkle at night.\n|The moon is bright.\n|Rain falls softly.\n|Snow covers the ground.]

ADD BUFFER (append-only):
[ and calm|Birds are flying high.| 🌙]
 0        9                      33

PIECE TABLE (final state):
1. (ORIG, 0, 25)                  → "The sky is blue.\n"
2. (ADD, 9, 24)                   → "Birds are flying high."
3. (ORIG, 51, 26)                 → "\n" (part after replaced text till before line 3)
4. (ORIG, 77, 55)                 → "Trees are green.\nThe river flows gently."
5. (ADD, 0, 9)                    → " and calm"
6. (ORIG, 132, 61)                → "\nFlowers bloom in spring.\nStars twinkle at night."
7. (ORIG, 193, 29)                → "The moon is bright."
8. (ADD, 33, 3)                   → " 🌙"
9. (ORIG, 222, 61)                → "\nRain falls softly.\nSnow covers the ground."
```

When the editor displays the file, it just walks through this list and concatenates.


<br>
<br>

## **How searching works in a Piece Table**

## **1. Searching in a Piece Table**

A Piece Table stores the document as a **sequence of pieces**, each piece being a reference to either the Original Buffer (immutable) or the Add Buffer (append-only).
When you want to insert or delete at a certain position (say "character 350"), you need to figure out:

* **Which piece** contains that position
* **Where** inside that piece it lands

---

### **Step-by-step Search Process**

Let’s say our piece table is:

```
[ (ORIG, 0, 100),    # Piece 0: 0-99
  (ADD, 0, 20),      # Piece 1: 100-119
  (ORIG, 200, 150) ] # Piece 2: 120-269
```

We want to insert at **position 110** (document coordinates, not buffer coordinates):

1. **Iterate pieces, summing lengths** until cumulative length >= target position.
2. When you reach the piece containing the position:

   * Calculate offset inside that piece:

     ```
     piece_offset = target_position - chars_seen_so_far
     ```
   * This offset + piece’s start index in buffer gives the **buffer index**.
3. For insertion:

   * **Split** the piece into two at that offset.
   * Insert new piece(s) in between.

---

### **Example — Insert at Position 110**

Given above table:

* Piece 0 → length 100 (cumulative = 100)
* Piece 1 → length 20 (cumulative = 120) → Position 110 is in this piece.
* Offset in piece = 110 - 100 = 10
* Buffer index = ADD start (0) + 10 = 10

---

### **For Deletion**

* Search for **start position** and **end position** of deletion range.
* May split up to **two pieces** at boundaries.
* Remove any pieces fully inside the range.

---

## **2. Search Time Complexity**

Searching requires walking through the piece list **from the start** — if stored as a simple array/list:

* **O(p)** where `p = number of pieces`.

For a large number of edits, `p` can grow — which is why **balanced trees** (e.g., Red-Black Tree, B-Tree) are often used instead of a plain array:

* **With tree:** Search, insert, delete = **O(log p)**.
* VS Code actually uses a **balanced tree implementation** for its piece table to keep this efficient.

---

## **3. Time Complexity of Core Operations**

| Operation                  | Array-based Piece Table        | Tree-based Piece Table |
| -------------------------- | ------------------------------ | ---------------------- |
| **Search (find position)** | O(p)                           | O(log p)               |
| **Insert**                 | O(p) (split + insert)          | O(log p + k), k = length of inserted text          |
| **Delete**                 | O(p) (find start/end + split)  | O(log p)               |
| **Append (at end)**        | O(1)                           | O(log p)               |
| **Undo/Redo**              | O(1) (swap table snapshot)     | O(1)                   |
| **Save to disk**           | O(total text length)           | O(total text length)   |
| **Memory usage**           | ORIG + ADD + O(p) for metadata | ORIG + ADD + O(p)      |

---

## **4. Why Tree Structure is Better**

If you store the piece table in a **balanced binary tree**:

* Nodes contain:

  * `piece info` (buffer, start, length)
  * `subtree length` (total length of text in this node’s subtree)
* Searching for a position becomes **tree traversal** using subtree lengths → O(log p)
* Insertions and deletions become **split/rebalance operations** → O(log p)

---

## **5. Searching During Continuous Edits**

When adding/deleting repeatedly:

* Every time, search for position → split piece → insert new piece → merge adjacent pieces if same buffer.
* Tree-based piece table avoids the O(n) scanning cost, so editors remain smooth even with **millions of characters**.

<br><br>

## **Piece Table Memory Storage and Buffer Management**

## **1. Are ORIG and ADD Buffers Just Arrays?**

**Conceptually:**

* Yes, both **ORIG BUFFER** and **ADD BUFFER** are treated as arrays of bytes (or characters) storing text.

**Physically in Memory:**

* For small to medium-sized files, the OS will likely store them in a single contiguous allocation.
* For very large files, editors avoid allocating a single giant array. Instead, they use techniques like memory mapping (paged storage) or chunked storage.


## **2. How ORIG BUFFER is stored in memory?**

### **Small/Medium Files**

* File is read into one `malloc` or `new` allocation.
  ```c
  char* orig_buffer = (char*) malloc(file_size);
  fread(orig_buffer, 1, file_size, file);
  ```
* This is fine because OS virtual memory handles the mapping and the allocation appears contiguous in virtual address space.

### **Large Files**

For gigabyte-scale files, a few optimizations happen:

#### **Option A — Memory Mapping (mmap)**

* The file on disk is mapped into process's virtual address space.
* You can treat it like a contiguous array, but OS loads pages into RAM **on demand**.
* No need for physically contiguous memory in RAM — only virtually contiguous in the address space.
* This is common for large read-only data (great for ORIG buffer since it’s immutable).
* **Example:**

  ```c
  int fd = open("file.txt", O_RDONLY);
  char* orig_buffer = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
  ```

#### **Option B — Chunked Storage**

* Store file in **fixed-size blocks** (e.g., 4 KB or 8 KB chunks).
* Maintain an array/vector of chunk pointers.
* Piece Table pieces reference `(chunk_id, offset, length)` instead of `(start, length)` directly.
* Example structure:

  ```c
  struct Chunk {
      char data[4096];
  };

  Chunk* chunks[num_chunks];
  ```
* Avoids needing a huge contiguous block in memory.
* Allows partial loading.


## **3. How ADD BUFFER is stored?**

* Since ADD buffer grows over time, it’s often implemented as:

  * **Gap buffer inside a chunk** (for small changes), OR
  * **Append-only array of chunks** (for large editing sessions)
* Even if implemented as an array, it can be reallocated in bigger chunks when needed (like `std::vector` growth in C++).
* In some editors, ADD buffer is also backed by **chunks** to avoid memory copy during large expansions.

* Example:

  ```c
  std::vector<std::string> add_chunks;
  add_chunks.push_back("newly added text");
  ```


## **4. Why Continuous Space Isn’t a Problem?**

Modern OSes use **virtual memory**, meaning:

* Even if physical RAM is fragmented, virtual address space can appear contiguous to the program.
* For huge files, **mmap** maps file content into virtual memory.
* Physically, data is stored in discrete pages (e.g., 4 KB each).

Example:

* Virtual address space: `0x1000` to `0x9000` (appears contiguous)
* Physical memory: pages scattered across RAM and even swapped to disk.


## **5. Data Structures for Storing Buffers?**

### For ORIG buffer:

* **Small files** → contiguous byte array (char\[] or std::string-like)
* **Large files** → memory-mapped file OR chunked blocks

### For ADD buffer:

* **Small edits** → simple contiguous growable array (gap buffer internally)
* **Large edits** → chunked append-only store (linked blocks or vector of blocks)

<br>
<br>

# **Internal memory layout diagram for a **Piece Table** where:**

* **ORIG Buffer** → Stored as **memory-mapped pages**
* **ADD Buffer** → Stored as **chunked append-only blocks**

---

## **1. ORIG BUFFER (Memory-Mapped Pages)**

**Purpose:** Holds the original file content (read-only).
Instead of reading the whole file into one contiguous array (which may be impossible if memory is fragmented), we **memory-map** the file into **fixed-size pages**.

### Layout in Memory:

```
+--------------------+
| Page 0 (4KB)       | → points to part of the file on disk
+--------------------+
| Page 1 (4KB)       |
+--------------------+
| Page 2 (4KB)       |
+--------------------+
| ...                |
+--------------------+
```

* Each page contains a **pointer** to the corresponding file region on disk.
* Accessing a character at position `x` → **OS page fault** may occur → OS loads the required page into RAM.
* Pages can be **non-contiguous** in memory — the OS maintains a **page table** that maps virtual addresses to actual disk-backed storage.
* **No copying** of the whole file; editing happens in the **ADD buffer**.

---

## **2. ADD BUFFER (Chunked Append-Only Blocks)**

**Purpose:** Stores all newly inserted text.

* Implemented as a list of **fixed-size chunks** (e.g., 4 KB each).
* New text is always **appended** to the end of the current chunk until full.
* If a chunk is full, a **new chunk** is allocated.

### Layout in Memory:

```
ADD Buffer (Chunk Pool):
[Chunk 0] → "Hello "
[Chunk 1] → "world!"
[Chunk 2] → " New text here..."
...
```

* Each chunk is **contiguous** within itself, but **chunks** can be **scattered** in memory.
* Piece Table entries reference ranges within these chunks.

---

In a **Piece Table**, the file’s text is **never edited in place**.
Instead, text comes from **two immutable storage areas**:

| Symbol | Name                | What it Contains                            |
| ------ | ------------------- | ------------------------------------------- |
| **O**  | **Original Buffer** | The text from the original file (read-only) |
| **A**  | **Add Buffer**      | All inserted text since the file was opened |

So:

* `"O"` means *"this piece points to a range of characters in the original file"*
* `"A"` means *"this piece points to a range of characters in the new inserted text buffer"*

#### The **Piece Table** is just a sequence of **references** that, when read in order, reconstruct the current version of the file.

The columns mean:

* **Source** → `"O"` or `"A"`
* **Start** → Where in that buffer this piece begins
* **Length** → How many characters it spans

---

### Example Table You Provided

| Source | Start | Length |
| ------ | ----- | ------ |
| O      | 0     | 50     |
| A      | 0     | 6      |
| O      | 50    | 100    |
| A      | 6     | 13     |

---

**How to read this:**

1. Take **50 chars** from `Original Buffer` starting at position **0**.
2. Then take **6 chars** from `Add Buffer` starting at position **0**.
3. Then take **100 chars** from `Original Buffer` starting at position **50**.
4. Then take **13 chars** from `Add Buffer` starting at position **6**.

Concatenate them in that order → that’s your **current file content**.

---

#### **Why This is Useful**

* **Insertions** don’t require moving text → just append to `Add Buffer` and insert a new entry in the table.
* **Deletions** → just remove or shorten an entry in the table.
* **Undo/Redo** → just reorder or restore old table entries, buffers stay untouched.

---

#### **Small Visual**

Imagine the original file:

```
[O] = "The quick brown fox jumps over the lazy dog."
```

You insert `"fast "` after `"The "`.

* Append `"fast "` to **Add Buffer**:

```
Add Buffer: [A] = "fast "
```

* Update Piece Table:
  | Source | Start | Length | 
  |--------|-------|--------|
  | O      | 0     | 4    → "The "|
  | A      | 0     | 5    → "fast "|
  | O      | 4     | rest  → "quick brown fox..."|

The file is now `"The fast quick brown fox..."` without touching the original buffer.

#### **Why This Works Well**

* **Insertions**: Just append to ADD buffer, update Piece Table (O(1) amortized).
* **Deletions**: Adjust piece boundaries (no memory moving).
* **Large files**: ORIG buffer is page-mapped, so no huge RAM requirement.
* **Scattered memory**: Both ORIG and ADD buffers can live in non-contiguous memory, making them memory-efficient.
---