Got it — you want **ALL stack operations from the PPT**, with the **algorithm + best/average/worst complexity + what to remember for the exam**.

# STACK — ALL OPERATIONS

## 1. PUSH — Array Stack ⭐⭐⭐

**Purpose:** Insert an element at TOP.

```text
PUSH(STACK, TOP, MAX, VALUE)

1. IF TOP = MAX - 1
      PRINT "Overflow Occurred"
      Goto Step 4
   [END IF]

2. SET TOP = TOP + 1

3. SET STACK[TOP] = VALUE

4. END
```

a5991f3a-67a1-402b-9cdf-0d0cd44…

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

**Look for:** `TOP == MAX-1` → **Overflow**

---

# 2. POP — Array Stack ⭐⭐⭐

**Purpose:** Remove the top element.

```text
POP(STACK, TOP)

1. IF TOP = NULL
      PRINT "Underflow Occurred"
      Goto Step 4
   [END IF]

2. SET VAL = STACK[TOP]

3. SET TOP = TOP - 1

4. END
```

a5991f3a-67a1-402b-9cdf-0d0cd44…

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

**Look for:** Empty stack → **Underflow**

---

# 3. PEEK — Array Stack ⭐⭐⭐

**Purpose:** Return TOP element **without deleting it**.

```text
PEEK(STACK, TOP)

1. IF TOP = NULL
      PRINT "Stack is Empty"
      Goto Step 3
   [END IF]

2. RETURN STACK[TOP]

3. END
```

a5991f3a-67a1-402b-9cdf-0d0cd44…

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

**Look for:** `PEEK` does **not change TOP**.

---

# 4. isEmpty() ⭐⭐

**Purpose:** Check whether stack contains no elements.

```text
isEmpty(STACK)

1. IF TOP = -1
      RETURN TRUE

2. ELSE
      RETURN FALSE

3. END
```

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

**Look for:**

```text
TOP == -1 → EMPTY
```

> Your PPT uses `TOP = NULL` conceptually for an empty stack, while your C array implementation may use `TOP = -1`. Follow the convention used in the question/code.

---

# 5. isFull() ⭐⭐

**Purpose:** Check whether array stack is full.

```text
isFull(STACK)

1. IF TOP = MAX - 1
      RETURN TRUE

2. ELSE
      RETURN FALSE

3. END
```

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

**Look for:**

```text
TOP == MAX - 1 → FULL
```

The PPT identifies `TOP = MAX−1` as the full-stack condition. a5991f3a-67a1-402b-9cdf-0d0cd44…

---

# 6. LINKED STACK — PUSH ⭐⭐⭐

**Purpose:** Insert a new node at TOP.

```text
PUSH_LINKED(VAL)

1. Allocate memory for NEW_NODE

2. SET NEW_NODE -> DATA = VAL

3. IF TOP = NULL
      SET NEW_NODE -> NEXT = NULL
      SET TOP = NEW_NODE

   ELSE
      SET NEW_NODE -> NEXT = TOP
      SET TOP = NEW_NODE
   [END IF]

4. END
```

a5991f3a-67a1-402b-9cdf-0d0cd44…

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

**Look for this sequence:**

```text
Create node
     ↓
Store data
     ↓
NEW_NODE → TOP
     ↓
TOP = NEW_NODE
```

---

# 7. LINKED STACK — POP ⭐⭐⭐

**Purpose:** Delete the node at TOP.

```text
POP_LINKED()

1. IF TOP = NULL
      PRINT "Underflow Condition"
      Goto Step 5
   [END IF]

2. SET PTR = TOP

3. SET TOP = TOP -> NEXT

4. FREE PTR

5. END
```

a5991f3a-67a1-402b-9cdf-0d0cd44…

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

**Look for this sequence:**

```text
PTR = TOP
    ↓
TOP = TOP → NEXT
    ↓
FREE PTR
```

---

# 8. PEEK — Linked Stack

The PPT explains that Peek returns the topmost value without deleting it. a5991f3a-67a1-402b-9cdf-0d0cd44…

For a linked implementation, the operation is:

```text
PEEK_LINKED()

1. IF TOP = NULL
      PRINT "Stack is Empty"
      Goto Step 3
   [END IF]

2. RETURN TOP -> DATA

3. END
```

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

---

# 9. LINKED STACK — isEmpty()

```text
isEmpty()

1. IF TOP = NULL
      RETURN TRUE

2. ELSE
      RETURN FALSE

3. END
```

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

---

# 🔥 COMPLETE COMPLEXITY TABLE

| Operation | Array Stack | Linked Stack | Best | Average | Worst |
|---|---:|---:|---:|---:|---:|
| **Push** | O(1) | O(1) | O(1) | O(1) | O(1) |
| **Pop** | O(1) | O(1) | O(1) | O(1) | O(1) |
| **Peek** | O(1) | O(1) | O(1) | O(1) | O(1) |
| **isEmpty** | O(1) | O(1) | O(1) | O(1) | O(1) |
| **isFull** | O(1) | — | O(1) | O(1) | O(1) |

The PPT states that array stack operations at the top/back are O(1), and that linked-stack operations are typically O(1). a5991f3a-67a1-402b-9cdf-0d0cd44…

---

# 🧠 WHAT TO LOOK FOR IN EVERY ALGORITHM

### Array Stack

```text
PUSH
↓
Is FULL?
↓
TOP++
↓
STACK[TOP] = VALUE
```

```text
POP
↓
Is EMPTY?
↓
VAL = STACK[TOP]
↓
TOP--
```

```text
PEEK
↓
Is EMPTY?
↓
RETURN STACK[TOP]
```

### Linked Stack

```text
PUSH
↓
Create NEW_NODE
↓
DATA = VALUE
↓
NEW_NODE → NEXT = TOP
↓
TOP = NEW_NODE
```

```text
POP
↓
Is EMPTY?
↓
PTR = TOP
↓
TOP = TOP → NEXT
↓
FREE PTR
```

---

# 🚨 EXAM TRAPS

| If question says... | You should think... |
|---|---|
| Insert into stack | **PUSH** |
| Delete from stack | **POP** |
| View top | **PEEK** |
| Stack full | **OVERFLOW** |
| Stack empty + POP | **UNDERFLOW** |
| Array implementation | **TOP + MAX** |
| Linked implementation | **TOP + NEXT + PTR** |
| Check empty | **TOP = -1 / NULL** |
| Check full | **TOP = MAX-1** |
| Complexity of Push/Pop | **O(1)** |
| LIFO | **Last In, First Out** |


# QUEUE — ALL OPERATIONS + COMPLEXITY

## 1. ENQUEUE / INSERT — Linear Array Queue ⭐⭐⭐

**Purpose:** Insert an element at the **REAR**.

### Algorithm

```text
ENQUEUE(QUEUE, FRONT, REAR, MAX, NUM)

1. IF REAR = MAX - 1
      PRINT "Overflow Occurred"
      Goto Step 4
   [END IF]

2. IF FRONT = -1 AND REAR = -1
      SET FRONT = REAR = 0
   ELSE
      SET REAR = REAR + 1
   [END IF]

3. SET QUEUE[REAR] = NUM

4. EXIT
```

This is the insertion algorithm given in the PPT. 47aba15a-232b-4ea0-8969-97e7746…

### Complexity

| Case | Complexity |
|---|---:|
| Best | **O(1)** |
| Average | **O(1)** |
| Worst | **O(1)** |

### Look for

```text
REAR == MAX - 1
       ↓
   OVERFLOW
```

First element:

```text
FRONT = REAR = 0
```

Next elements:

```text
REAR++
```

---

# 2. DEQUEUE / DELETE — Linear Array Queue ⭐⭐⭐

**Purpose:** Remove an element from the **FRONT**.

### Algorithm

```text
DEQUEUE(QUEUE, FRONT, REAR)

1. IF FRONT = -1
      PRINT "Underflow Occurred"

   ELSE
      SET VAL = QUEUE[FRONT]
      SET FRONT = FRONT + 1
   [END OF ELSE]

2. EXIT
```

47aba15a-232b-4ea0-8969-97e7746…

### Complexity

The PPT's basic pointer-based deletion is:

| Case | Complexity |
|---|---:|
| Best | **O(1)** |
| Average | **O(1)** |
| Worst | **O(1)** |

### Look for

```text
FRONT == -1
      ↓
UNDERFLOW
```

Otherwise:

```text
VAL = QUEUE[FRONT]
FRONT++
```

---

# 3. ENQUEUE — Linked Queue ⭐⭐⭐

In a linked queue:

```text
FRONT → first node
REAR  → last node
```

The PPT states that `FRONT = REAR = NULL` means the queue is empty. 47aba15a-232b-4ea0-8969-97e7746…

### Algorithm

```text
1. Allocate memory for new node PTR

2. SET PTR -> DATA = VAL

3. IF FRONT = NULL
      SET FRONT = REAR = PTR
      SET FRONT -> NEXT = REAR -> NEXT = NULL

   ELSE
      SET REAR -> NEXT = PTR
      SET REAR = PTR
      SET REAR -> NEXT = NULL
   [END IF]

4. END
```

47aba15a-232b-4ea0-8969-97e7746…

### Complexity

| Case | Complexity |
|---|---:|
| Best | **O(1)** |
| Average | **O(1)** |
| Worst | **O(1)** |

### Look for

First node:

```text
FRONT = REAR = PTR
```

Later nodes:

```text
REAR->NEXT = PTR
REAR = PTR
```

---

# 4. DEQUEUE — Linked Queue ⭐⭐⭐

### Algorithm

```text
1. IF FRONT = NULL
      PRINT "Underflow Condition"
      Goto Step 5
   [END IF]

2. SET PTR = FRONT

3. SET FRONT = FRONT -> NEXT

4. FREE PTR

5. END
```

47aba15a-232b-4ea0-8969-97e7746…

### Complexity

| Case | Complexity |
|---|---:|
| Best | **O(1)** |
| Average | **O(1)** |
| Worst | **O(1)** |

### Look for

```text
PTR = FRONT
     ↓
FRONT = FRONT->NEXT
     ↓
FREE PTR
```

---

# 5. PEEK / FRONT ELEMENT

The PPT doesn't give a separate explicit `peek()` algorithm for queues.

But the concept is:

```text
RETURN QUEUE[FRONT]
```

or for linked queue:

```text
RETURN FRONT->DATA
```

### Complexity

**O(1)**

### Exam note

Don't confuse:

```text
FRONT → where deletion happens
REAR  → where insertion happens
```

The PPT explicitly defines FRONT as the removal end and REAR/TAIL as the insertion end. 47aba15a-232b-4ea0-8969-97e7746…

---

# 6. CIRCULAR QUEUE ⭐⭐⭐⭐

This is **very important**.

The purpose of a circular queue is to reuse empty spaces created at the beginning of the array instead of wasting them.

The PPT says the wrap-around is achieved using the **modulo `%` operator**. 47aba15a-232b-4ea0-8969-97e7746…

### Most important formula

```text
REAR = (REAR + 1) % MAX
```

and

```text
FRONT = (FRONT + 1) % MAX
```

Example:

```text
MAX = 5
REAR = 4

(REAR + 1) % 5
= (4 + 1) % 5
= 0
```

So REAR wraps back to index `0`. 47aba15a-232b-4ea0-8969-97e7746…

---

# 7. CIRCULAR QUEUE — ENQUEUE

The PPT identifies this as the circular-queue insertion operation. 47aba15a-232b-4ea0-8969-97e7746…

### Exam algorithm pattern

```text
ENQUEUE_CIRCULAR(QUEUE)

1. Check whether queue is FULL.
      If FULL → Overflow

2. If queue is EMPTY
      FRONT = REAR = 0

3. Else
      REAR = (REAR + 1) % MAX

4. QUEUE[REAR] = VALUE

5. END
```

### Complexity

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

### Look for ⭐

```text
REAR = (REAR + 1) % MAX
```

**NOT simply `REAR++`.**

---

# 8. CIRCULAR QUEUE — DEQUEUE

The PPT identifies circular deletion separately. 47aba15a-232b-4ea0-8969-97e7746…

### Exam algorithm pattern

```text
DEQUEUE_CIRCULAR(QUEUE)

1. Check whether queue is EMPTY.
      If EMPTY → Underflow

2. VAL = QUEUE[FRONT]

3. If FRONT == REAR
      FRONT = REAR = -1

4. Else
      FRONT = (FRONT + 1) % MAX

5. END
```

### Complexity

| Best | Average | Worst |
|---|---|---|
| O(1) | O(1) | O(1) |

### Look for

```text
FRONT = (FRONT + 1) % MAX
```

The PPT itself illustrates this wrap-around operation. 47aba15a-232b-4ea0-8969-97e7746…

---

# 9. DEQUE — DOUBLE ENDED QUEUE ⭐⭐⭐

A **Deque** allows insertion and deletion at **both FRONT and REAR**. 47aba15a-232b-4ea0-8969-97e7746…

```text
       INSERT
         ↓
FRONT ← [ QUEUE ] → REAR
  ↑                    ↑
DELETE               DELETE
  ↑                    ↑
INSERT               INSERT
```

### Operations

```text
Insert Front
Insert Rear

Delete Front
Delete Rear
```

### Complexity

With an appropriate deque implementation:

```text
Insert Front  → O(1)
Insert Rear   → O(1)
Delete Front  → O(1)
Delete Rear   → O(1)
```

### Two variants ⭐

**Input Restricted Deque**

```text
Insertion → ONE END ONLY
Deletion  → BOTH ENDS
```

**Output Restricted Deque**

```text
Insertion → BOTH ENDS
Deletion  → ONE END ONLY
```

These definitions are directly in the PPT. 47aba15a-232b-4ea0-8969-97e7746…

---

# 10. PRIORITY QUEUE ⭐⭐⭐⭐

In a priority queue, each element has a **priority**.

Higher-priority elements are processed before lower-priority elements.

If two elements have the same priority:

```text
FCFS
```

is followed. 47aba15a-232b-4ea0-8969-97e7746…

### Important point

In this PPT:

> **Lower priority number = higher priority**

Example:

```text
Priority 1 → A
Priority 2 → B
Priority 3 → C
Priority 5 → E
```

Processing order:

```text
A → B → C → E
```

47aba15a-232b-4ea0-8969-97e7746…

---

# 11. PRIORITY QUEUE — SORTED LIST

Elements are maintained in priority order.

### Insertion

Find the correct position and insert.

```text
Complexity = O(n)
```

### Deletion

Highest-priority element is already at the front.

```text
Complexity = O(1)
```

The PPT explicitly gives these complexities. 47aba15a-232b-4ea0-8969-97e7746…

### Remember

```text
SORTED PQ

Insertion → O(n)
Deletion  → O(1)
```

---

# 12. PRIORITY QUEUE — UNSORTED LIST

Elements are inserted without maintaining priority order.

### Insertion

Simply add at the end:

```text
O(1)
```

### Deletion

Search for highest-priority element:

```text
O(n)
```

The PPT explicitly states this. 47aba15a-232b-4ea0-8969-97e7746…

### Remember

```text
UNSORTED PQ

Insertion → O(1)
Deletion  → O(n)
```

---

# 13. PRIORITY QUEUE — LINKED LIST INSERTION

For a sorted linked priority queue:

1. Traverse the list.
2. Find a node having lower priority than the new element.
3. Insert the new node **before** that node. 47aba15a-232b-4ea0-8969-97e7746…

### Complexity

```text
Insertion → O(n)
```

---

# 14. PRIORITY QUEUE — LINKED LIST DELETION

Deletion is simple because the highest-priority element is at the beginning.

```text
1. Delete first node
2. Process its data
```

The PPT describes the first node as being deleted and processed first. 47aba15a-232b-4ea0-8969-97e7746…

### Complexity

```text
Deletion → O(1)
```

---

# 15. PRIORITY QUEUE — ARRAY IMPLEMENTATION

The PPT uses a **separate queue for each priority**.

Each queue uses:

```text
Circular Queue
```

and has its own:

```text
FRONT[K]
REAR[K]
```

47aba15a-232b-4ea0-8969-97e7746…

### Insertion

Insert into the rear of the queue corresponding to priority `K`.

```text
O(1)
```

### Deletion

Find the **first non-empty queue**, then remove its front element. 47aba15a-232b-4ea0-8969-97e7746…

If there are `P` priority levels:

```text
O(P)
```

for searching priority levels.

---

# 16. MULTIPLE QUEUES

Multiple queues can share the same array.

The purpose is to balance:

```text
Too little memory
       ↓
Frequent Overflow

Too much memory
       ↓
Memory Wastage
```

The PPT presents multiple queues as a solution to this trade-off. 47aba15a-232b-4ea0-8969-97e7746…

---

# 🔥 COMPLETE COMPLEXITY TABLE

| Operation | Best | Average | Worst |
|---|---:|---:|---:|
| **Linear Queue Enqueue** | O(1) | O(1) | O(1) |
| **Linear Queue Dequeue** | O(1) | O(1) | O(1) |
| **Linked Queue Enqueue** | O(1) | O(1) | O(1) |
| **Linked Queue Dequeue** | O(1) | O(1) | O(1) |
| **Circular Enqueue** | O(1) | O(1) | O(1) |
| **Circular Dequeue** | O(1) | O(1) | O(1) |
| **Deque Insert/Delete** | O(1) | O(1) | O(1) |
| **Priority Queue — Sorted Insert** | O(n) | O(n) | O(n) |
| **Priority Queue — Sorted Delete** | O(1) | O(1) | O(1) |
| **Priority Queue — Unsorted Insert** | O(1) | O(1) | O(1) |
| **Priority Queue — Unsorted Delete** | O(n) | O(n) | O(n) |

**Important:** The PPT specifically gives the priority-queue sorted/unsorted tradeoff as `O(n)/O(1)` and `O(1)/O(n)` respectively. 47aba15a-232b-4ea0-8969-97e7746…

---

# 🚨 WHAT YOU SHOULD LOOK FOR IN THE EXAM

## 🔴 MUST MEMORIZE

### 1. Simple Queue

```text
ENQUEUE
DEQUEUE
```

### 2. Linked Queue

```text
INSERT
DELETE
```

### 3. Circular Queue

```text
ENQUEUE
DEQUEUE

(rear + 1) % MAX
(front + 1) % MAX
```

### 4. Deque

Know:

```text
Insert Front
Insert Rear
Delete Front
Delete Rear
```

and the two variants.

### 5. Priority Queue

**Most important complexity question:**

```text
Sorted:
Insert = O(n)
Delete = O(1)

Unsorted:
Insert = O(1)
Delete = O(n)
```

---
Got it. **Only the algorithms + extra things you should look for + complexity**, nothing else.

# QUEUE — ALGORITHMS + COMPLEXITY

## 1. Simple Queue — INSERT / ENQUEUE

```text
1. IF REAR = MAX - 1
      PRINT "Overflow Occurred"
      Goto Step 4

2. IF FRONT = -1 AND REAR = -1
      FRONT = REAR = 0
   ELSE
      REAR = REAR + 1

3. QUEUE[REAR] = NUM

4. EXIT
```

47aba15a-232b-4ea0-8969-97e7746…

**Complexity:** `O(1)` best / average / worst.

---

## 2. Simple Queue — DELETE / DEQUEUE

```text
1. IF FRONT = -1
      PRINT "Underflow Occurred"
   ELSE
      VAL = QUEUE[FRONT]
      FRONT = FRONT + 1

2. EXIT
```

47aba15a-232b-4ea0-8969-97e7746…

**Complexity:** `O(1)` best / average / worst.

---

## 3. Linked Queue — INSERT

```text
1. Allocate memory for PTR

2. PTR->DATA = VAL

3. IF FRONT = NULL
      FRONT = REAR = PTR
      FRONT->NEXT = REAR->NEXT = NULL
   ELSE
      REAR->NEXT = PTR
      REAR = PTR
      REAR->NEXT = NULL

4. END
```

47aba15a-232b-4ea0-8969-97e7746…

**Complexity:** `O(1)` best / average / worst.

---

## 4. Linked Queue — DELETE

```text
1. IF FRONT = NULL
      PRINT "Underflow Condition"
      Goto Step 5

2. PTR = FRONT

3. FRONT = FRONT->NEXT

4. FREE PTR

5. END
```

47aba15a-232b-4ea0-8969-97e7746…

**Complexity:** `O(1)` best / average / worst.

---

# 5. Circular Queue — ENQUEUE ⭐

```text
1. Check if Queue is FULL
      If FULL → Overflow

2. IF Queue is EMPTY
      FRONT = REAR = 0
   ELSE
      REAR = (REAR + 1) % MAX

3. QUEUE[REAR] = VALUE

4. END
```

**Complexity:** `O(1)` best / average / worst.

### Must remember:

```text
REAR = (REAR + 1) % MAX
```

The PPT specifically identifies `%` as the wrap-around mechanism. 47aba15a-232b-4ea0-8969-97e7746…

---

# 6. Circular Queue — DEQUEUE ⭐

```text
1. IF Queue is EMPTY
      PRINT "Underflow"

2. VAL = QUEUE[FRONT]

3. IF FRONT == REAR
      FRONT = REAR = -1
   ELSE
      FRONT = (FRONT + 1) % MAX

4. END
```

**Complexity:** `O(1)` best / average / worst.

### Must remember:

```text
FRONT = (FRONT + 1) % MAX
```

---

# 7. DEQUE — Operations

### Insert Front

```text
1. Check if FULL
2. Move FRONT backward
3. Insert element at FRONT
```

**Complexity:** `O(1)`

### Insert Rear

```text
1. Check if FULL
2. Move REAR forward
3. Insert element at REAR
```

**Complexity:** `O(1)`

### Delete Front

```text
1. Check if EMPTY
2. Remove FRONT element
3. Move FRONT forward
```

**Complexity:** `O(1)`

### Delete Rear

```text
1. Check if EMPTY
2. Remove REAR element
3. Move REAR backward
```

**Complexity:** `O(1)`

### Extra to remember

```text
Input Restricted Deque
→ Insert at ONE end
→ Delete at BOTH ends

Output Restricted Deque
→ Insert at BOTH ends
→ Delete at ONE end
```

47aba15a-232b-4ea0-8969-97e7746…

---

# 8. Priority Queue — Sorted List ⭐⭐⭐

### Insertion

```text
1. Traverse the list
2. Find correct priority position
3. Insert before lower-priority element
```

**Complexity:** `O(n)`

47aba15a-232b-4ea0-8969-97e7746…

### Deletion

```text
1. Delete first node
2. Process its data
```

**Complexity:** `O(1)`

47aba15a-232b-4ea0-8969-97e7746…

---

# 9. Priority Queue — Unsorted List

### Insertion

```text
1. Insert element at end
```

**Complexity:** `O(1)`

### Deletion

```text
1. Search for highest-priority element
2. Delete it
```

**Complexity:** `O(n)`

The PPT gives exactly this sorted/unsorted trade-off. 47aba15a-232b-4ea0-8969-97e7746…

---

# 🔥 COMPLEXITY — MEMORIZE

| Operation | Complexity |
|---|---:|
| Simple Queue Enqueue | **O(1)** |
| Simple Queue Dequeue | **O(1)** |
| Linked Queue Insert | **O(1)** |
| Linked Queue Delete | **O(1)** |
| Circular Enqueue | **O(1)** |
| Circular Dequeue | **O(1)** |
| Deque Insert Front | **O(1)** |
| Deque Insert Rear | **O(1)** |
| Deque Delete Front | **O(1)** |
| Deque Delete Rear | **O(1)** |
| Priority Sorted Insert | **O(n)** |
| Priority Sorted Delete | **O(1)** |
| Priority Unsorted Insert | **O(1)** |
| Priority Unsorted Delete | **O(n)** |

# 👀 EXTRA THINGS TO LOOK FOR

- **FIFO** → Queue
- **Enqueue** → Rear
- **Dequeue** → Front
- **Overflow** → Full queue
- **Underflow** → Empty queue
- **Circular Queue** → `%`
- **Deque** → Both ends
- **Input restricted** → Insert one end, delete both
- **Output restricted** → Insert both, delete one
- **Priority Queue** → Priority decides deletion
- **Same priority** → **FCFS**
- **Lower priority number = higher priority** in this PPT. 47aba15a-232b-4ea0-8969-97e7746…
- **BFS** → Queue
- **Round Robin** → Queue. 47aba15a-232b-4ea0-8969-97e7746…

# LINKED LIST — ALGORITHMS + COMPLEXITY + EXTRA THINGS

## 1. Singly Linked List — Traversal ⭐⭐⭐

```text id="q5f0c8"
1. SET PTR = HEAD

2. WHILE PTR != NULL
      VISIT / PRINT PTR->DATA
      PTR = PTR->NEXT

3. END
```

The PPT's C implementation uses `while (n != NULL)`, prints the data, then moves `n = n->next`. 0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:**  
Best: **O(n)** | Average: **O(n)** | Worst: **O(n)**

---

# 2. Insert at Beginning — SLL ⭐⭐⭐

```text id="a7c1d3"
1. CREATE NEW_NODE

2. NEW_NODE->DATA = VALUE

3. NEW_NODE->NEXT = HEAD

4. HEAD = NEW_NODE

5. END
```

The PPT shows `newNode = new Node(value, oldFront)` and returns the new node as the front. 0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:**  
Best: **O(1)** | Average: **O(1)** | Worst: **O(1)**

---

# 3. Insert After a Given Node — SLL ⭐⭐⭐

```text id="m1x5w8"
1. FIND the node after which insertion is required

2. CREATE NEW_NODE

3. NEW_NODE->NEXT = CURRENT->NEXT

4. CURRENT->NEXT = NEW_NODE

5. END
```

The key idea in the PPT is to first copy the existing link and then change the existing node's link. 0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:**

- If node/reference is already given: **O(1)**
- If searching is required: **O(n)**

---

# 4. Insert After a Given Value — SLL ⭐⭐⭐

```text id="v6p8k2"
1. SET PTR = HEAD

2. WHILE PTR != NULL
      IF PTR->DATA == TARGET
          CREATE NEW_NODE
          NEW_NODE->NEXT = PTR->NEXT
          PTR->NEXT = NEW_NODE
          RETURN
      PTR = PTR->NEXT

3. END
```

This follows the PPT's `insertAfter(target, value)` logic. 0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:**

Best: **O(1)**  
Average: **O(n)**  
Worst: **O(n)**

---

# 5. Insert at End / Tail — SLL ⭐⭐⭐

```text id="k2r4p1"
1. CREATE NEW_NODE

2. NEW_NODE->DATA = VALUE

3. NEW_NODE->NEXT = NULL

4. Find the last node

5. LAST->NEXT = NEW_NODE

6. UPDATE TAIL = NEW_NODE

7. END
```

The PPT lists allocation, insertion, setting the new node to `NULL`, linking the old last node, and updating tail. 0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:**

Without tail pointer:

- Best: **O(n)**
- Average: **O(n)**
- Worst: **O(n)**

With tail pointer:

- **O(1)**

---

# 6. Delete First Node — SLL ⭐⭐⭐

```text id="x8k3n4"
1. IF HEAD = NULL
      LIST IS EMPTY
      STOP

2. PTR = HEAD

3. HEAD = HEAD->NEXT

4. FREE PTR

5. END
```

The PPT identifies deletion of the first node as a special case where the header link is changed. 0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)**

---

# 7. Delete a Given Node / Value — SLL ⭐⭐⭐

```text id="n4c7z1"
1. Find the node to be deleted

2. Find its PREDECESSOR

3. PREDECESSOR->NEXT = NODE->NEXT

4. FREE NODE

5. END
```

The PPT emphasizes that the predecessor's link must be changed because a singly linked list cannot move backward. 0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:**

Best: **O(1)** if predecessor/reference is already known  
Average: **O(n)**  
Worst: **O(n)**

---

# 8. Delete at Tail — SLL ⭐⭐⭐

```text id="r9f3m2"
1. Find the last node

2. Find its predecessor

3. PREDECESSOR->NEXT = NULL

4. UPDATE TAIL

5. FREE LAST NODE

6. END
```

**Complexity:**

Best: **O(n)**  
Average: **O(n)**  
Worst: **O(n)**

---

# 9. Doubly Linked List — Insert After Node ⭐⭐⭐

```text id="z2k6p9"
INSERT_AFTER(P, E)

1. Create new node V

2. V->DATA = E

3. V->PREV = P

4. V->NEXT = P->NEXT

5. P->NEXT->PREV = V

6. P->NEXT = V

7. Return V
```

This is the algorithm given in the PPT. 0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)** if `P` is already known.

---

# 10. Doubly Linked List — Delete Node ⭐⭐⭐

```text id="c5m8r2"
1. Let NODE be the node to delete

2. NODE->PREV->NEXT = NODE->NEXT

3. NODE->NEXT->PREV = NODE->PREV

4. FREE NODE

5. END
```

A DLL deletion requires changing **two links**. 0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)** if node is already known.

If searching for the node is required: **O(n)**.

---

# 11. Circular Linked List — Traversal ⭐⭐⭐

```text id="u8n2k5"
1. IF REAR = NULL
      STOP

2. CUR = REAR->NEXT

3. DO
      PRINT CUR->DATA
      CUR = CUR->NEXT
   WHILE CUR != REAR->NEXT

4. END
```

The PPT uses a `do...while` loop and stops when `Cur == Rear->next`. 0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(n)**

### ⭐ Important

Normal linked list:

```text
last->next = NULL
```

Circular linked list:

```text
last->next = HEAD
```

0024c16c-c9da-4282-9a3c-cb05c66…

---

# 12. Circular Linked List — Insert ⭐⭐⭐⭐

### Empty List

```text id="n7x4p2"
1. CREATE NEW

2. NEW->DATA = VALUE

3. REAR = NEW

4. REAR->NEXT = REAR
```

0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)**

### Insert at Beginning

```text id="f2c9k6"
1. NEW->NEXT = REAR->NEXT

2. REAR->NEXT = NEW
```

0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)**

### Insert in Middle

```text id="v4m8s1"
1. NEW->NEXT = CUR

2. PREV->NEXT = NEW
```

0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)** if position is known; **O(n)** if searching.

### Insert at End

```text id="p6r1x8"
1. NEW->NEXT = REAR->NEXT

2. REAR->NEXT = NEW

3. REAR = NEW
```

0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)**

---

# 13. Circular Linked List — Delete ⭐⭐⭐⭐

### Delete Single Node

```text id="d8q3m7"
1. REAR = NULL

2. DELETE CUR
```

0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)**

### Delete Head

```text id="e5k9p2"
1. PREV->NEXT = CUR->NEXT

2. DELETE CUR
```

0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)** if node/predecessor is known.

### Delete Middle

```text id="q3m7v1"
1. PREV->NEXT = CUR->NEXT

2. DELETE CUR
```

0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)** if position is known; otherwise **O(n)**.

### Delete End

```text id="w6r2k9"
1. PREV->NEXT = CUR->NEXT

2. DELETE CUR

3. REAR = PREV
```

0024c16c-c9da-4282-9a3c-cb05c66…

**Complexity:** **O(1)** if predecessor is known; otherwise **O(n)**.

---

# 🔥 COMPLEXITY TABLE

| Operation | Best | Average | Worst |
|---|---:|---:|---:|
| SLL Traversal | O(n) | O(n) | O(n) |
| SLL Search | O(1) | O(n) | O(n) |
| SLL Insert Beginning | O(1) | O(1) | O(1) |
| SLL Insert After Node | O(1) | O(1) | O(1) |
| SLL Insert After Value | O(1) | O(n) | O(n) |
| SLL Insert End* | O(1) | O(n) | O(n) |
| SLL Delete Beginning | O(1) | O(1) | O(1) |
| SLL Delete Given Value | O(1) | O(n) | O(n) |
| SLL Delete End | O(n) | O(n) | O(n) |
| DLL Insert After Node | O(1) | O(1) | O(1) |
| DLL Delete Given Node | O(1) | O(1) | O(1) |
| Circular Traversal | O(n) | O(n) | O(n) |
| Circular Insert Beginning | O(1) | O(1) | O(1) |
| Circular Insert End | O(1) | O(1) | O(1) |
| Circular Delete | O(1)** | O(n) | O(n) |

\* **Without a tail pointer.**  
\** If the required node/predecessor is already known.

---

# 👀 EXTRA THINGS TO LOOK FOR

- **SLL:** `DATA + NEXT`
- **DLL:** `DATA + PREV + NEXT`
- **Circular LL:** `LAST->NEXT = HEAD`
- **Header node:** special initial node at front
- **SLL cannot move backward**
- **DLL can move both directions**
- **Traversal:** SLL ends at `NULL`
- **Circular traversal:** stops when pointer reaches `HEAD` again
- **Insertion:** change links
- **Deletion:** change predecessor's link
- **DLL deletion:** change **two links**
- **Linked list:** dynamic size
- **Linked list:** no random access
- **Binary search:** not efficient on normal linked lists because access is sequential. 0024c16c-c9da-4282-9a3c-cb05c66…

### ⭐ Most important for exam

**Traversal → Insert beginning/end/after → Delete beginning/end/given node → DLL insertion/deletion → Circular LL traversal/insertion/deletion → complexities.**