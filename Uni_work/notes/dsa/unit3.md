Yes. I read the uploaded PPT. It is specifically on **Linked Lists**, covering **Singly Linked List, Doubly Linked List, Circular Linked List**, and their insertion, deletion, traversal, and related operations. 0024c16c-c9da-4282-9a3c-cb05c66…

Below is your **6-mark-answer format**. You can directly learn/write these in the exam.

# DATA STRUCTURES — LINKED LISTS
## 6-Mark Algorithms + Definitions

---

# 1. Linked List

### Definition
A **linked list** is a dynamic linear data structure consisting of a sequence of nodes, where each node contains **data** and a **link/pointer** to another node. The elements are connected using pointers rather than being stored in contiguous memory locations. 0024c16c-c9da-4282-9a3c-cb05c66…

### Structure

```text
HEAD
 ↓
[DATA | NEXT] → [DATA | NEXT] → [DATA | NULL]
```

Each node contains:
1. Data/element
2. Link/pointer to the next node

The last node contains a **NULL link**. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 2. Singly Linked List

### Definition
A **singly linked list (SLL)** is a sequence of nodes in which every node stores an element and a link to its **next node**. The last node points to `NULL`. 0024c16c-c9da-4282-9a3c-cb05c66…

```text
HEAD
 ↓
[A|•] → [B|•] → [C|•] → [D|NULL]
```

---

# 3. Traversal of Singly Linked List

### Definition
**Traversal** means visiting/accessing every node of the linked list sequentially, starting from the first node.

### Algorithm

**Algorithm: TraverseSLL(HEAD)**

1. Start from the first node:
   ```text
   TEMP = HEAD
   ```
2. Repeat while `TEMP != NULL`:
   - Visit/print `TEMP->data`
   - Move to the next node:
     ```text
     TEMP = TEMP->next
     ```
3. Stop when `TEMP == NULL`.

### Pseudocode

```text
TRAVERSE(HEAD)
    TEMP = HEAD

    WHILE TEMP != NULL
        PRINT TEMP->data
        TEMP = TEMP->next
    END WHILE
```

The PPT's traversal follows exactly this idea: print the current node and advance `n = n->next` until `NULL`. 0024c16c-c9da-4282-9a3c-cb05c66…

### Complexity

```text
Time  = O(n)
Space = O(1)
```

---

# 4. Insertion in Singly Linked List

The PPT identifies these major insertion cases: 0024c16c-c9da-4282-9a3c-cb05c66…

1. Insert as first element
2. Insert as last element
3. Insert before a given node
4. Insert after a given node
5. Insert before a given value
6. Insert after a given value

---

# 5. Insertion at Beginning in SLL

### Definition
Insertion at the beginning means adding a new node before the current first node.

### Algorithm

**Algorithm: InsertAtBeginning(HEAD, VALUE)**

1. Create a new node.
2. Store `VALUE` in the new node.
3. Make the new node point to the current first node:
   ```text
   NEW->next = HEAD
   ```
4. Update `HEAD`:
   ```text
   HEAD = NEW
   ```
5. Stop.

### Pseudocode

```text
INSERT_BEGINNING(HEAD, VALUE)

    NEW = create node
    NEW->data = VALUE
    NEW->next = HEAD
    HEAD = NEW

END
```

The PPT describes this as creating a new node with `oldFront` as its link and then making it the new list front. 0024c16c-c9da-4282-9a3c-cb05c66…

### Example

Before:

```text
HEAD → 10 → 20 → 30 → NULL
```

Insert `5`:

```text
HEAD → 5 → 10 → 20 → 30 → NULL
```

### Complexity

```text
Time = O(1)
```

---

# 6. Insertion After a Given Node in SLL

### Definition
Insertion after a given node means creating a new node immediately after the specified node.

### Algorithm

**Algorithm: InsertAfter(P, VALUE)**

1. Find the node `P` after which insertion is required.
2. Create a new node `NEW`.
3. Store `VALUE` in `NEW`.
4. Copy the link of `P`:
   ```text
   NEW->next = P->next
   ```
5. Connect `P` to the new node:
   ```text
   P->next = NEW
   ```
6. Stop.

### Pseudocode

```text
INSERT_AFTER(P, VALUE)

    NEW = create node
    NEW->data = VALUE

    NEW->next = P->next
    P->next = NEW

END
```

The PPT specifically says to first copy the existing link and then change the existing node's link. 0024c16c-c9da-4282-9a3c-cb05c66…

### Example

```text
Before:

10 → 20 → 30 → NULL
     ↑
     P
```

Insert `25` after `20`:

```text
10 → 20 → 25 → 30 → NULL
```

### Complexity

```text
O(1)
```

if the required node is already known.

---

# 7. Insertion After a Given Value in SLL

### Algorithm

**Algorithm: InsertAfterValue(HEAD, TARGET, VALUE)**

1. Start from `HEAD`.
2. Traverse the list.
3. Compare current node's data with `TARGET`.
4. If the target is found:
   - Create a new node.
   - Store `VALUE`.
   - Set:
     ```text
     NEW->next = CURRENT->next
     ```
   - Set:
     ```text
     CURRENT->next = NEW
     ```
5. Stop.
6. If the target is not found, report failure.

### Pseudocode

```text
INSERT_AFTER_VALUE(HEAD, TARGET, VALUE)

    CURRENT = HEAD

    WHILE CURRENT != NULL

        IF CURRENT->data == TARGET

            NEW = create node
            NEW->data = VALUE

            NEW->next = CURRENT->next
            CURRENT->next = NEW

            RETURN
        END IF

        CURRENT = CURRENT->next

    END WHILE

    PRINT "Target not found"
```

This follows the PPT's `insertAfter(Object target, Object value)` algorithm. 0024c16c-c9da-4282-9a3c-cb05c66…

### Complexity

```text
Worst case = O(n)
```

---

# 8. Insertion at End in SLL

### Definition
Insertion at the end means adding a new node after the current last node.

### Algorithm

1. Create a new node.
2. Store the required data.
3. Set:
   ```text
   NEW->next = NULL
   ```
4. Traverse to the last node.
5. Make the last node point to `NEW`.
6. Update `TAIL` if a tail pointer is maintained.

The PPT gives these essential steps: allocate a node, insert the element, make the new node point to `NULL`, make the old last node point to it, and update `tail`. 0024c16c-c9da-4282-9a3c-cb05c66…

### Pseudocode

```text
INSERT_END(HEAD, VALUE)

    NEW = create node
    NEW->data = VALUE
    NEW->next = NULL

    IF HEAD == NULL
        HEAD = NEW
        RETURN
    END IF

    TEMP = HEAD

    WHILE TEMP->next != NULL
        TEMP = TEMP->next
    END WHILE

    TEMP->next = NEW

END
```

### Complexity

Without a tail pointer:

```text
O(n)
```

With a tail pointer:

```text
O(1)
```

---

# 9. Deletion in Singly Linked List

### Definition
Deletion means removing a node from the linked list and adjusting the links so that the remaining nodes stay connected.

In an SLL, deletion is slightly tricky because we cannot directly move backward; we generally need the **predecessor** of the node being deleted. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 10. Delete First Node in SLL

### Algorithm

1. Check whether the list is empty.
2. If empty, report underflow/empty list.
3. Store the current head temporarily.
4. Move `HEAD` to the second node:
   ```text
   HEAD = HEAD->next
   ```
5. Delete/free the old first node.

### Pseudocode

```text
DELETE_BEGINNING(HEAD)

    IF HEAD == NULL
        PRINT "List is empty"
        RETURN
    END IF

    TEMP = HEAD
    HEAD = HEAD->next
    DELETE TEMP

END
```

The PPT describes deleting the first element by changing the link in the header. 0024c16c-c9da-4282-9a3c-cb05c66…

### Complexity

```text
O(1)
```

---

# 11. Delete a Given Node in SLL

### Algorithm

**Algorithm: DeleteNode(HEAD, VALUE)**

1. Start from `HEAD`.
2. Maintain two pointers:
   ```text
   PREV
   CURRENT
   ```
3. Search for the node containing `VALUE`.
4. If found:
   ```text
   PREV->next = CURRENT->next
   ```
5. Delete/free `CURRENT`.
6. Stop.

### Pseudocode

```text
DELETE_NODE(HEAD, VALUE)

    CURRENT = HEAD
    PREV = NULL

    WHILE CURRENT != NULL

        IF CURRENT->data == VALUE
            IF PREV == NULL
                HEAD = CURRENT->next
            ELSE
                PREV->next = CURRENT->next
            END IF

            DELETE CURRENT
            RETURN
        END IF

        PREV = CURRENT
        CURRENT = CURRENT->next

    END WHILE

    PRINT "Node not found"
```

### Key exam point

> To delete a node in SLL, the link of its **predecessor** must be changed.

This is directly emphasized in the PPT. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 12. Delete Last Node in SLL

### Algorithm

1. Check whether the list is empty.
2. If only one node exists:
   - Delete it.
   - Set `HEAD = NULL`.
3. Otherwise traverse until the last node.
4. Keep track of the previous node.
5. Set:
   ```text
   PREV->next = NULL
   ```
6. Delete the last node.

### Pseudocode

```text
DELETE_END(HEAD)

    IF HEAD == NULL
        PRINT "List is empty"
        RETURN
    END IF

    IF HEAD->next == NULL
        DELETE HEAD
        HEAD = NULL
        RETURN
    END IF

    PREV = NULL
    CURRENT = HEAD

    WHILE CURRENT->next != NULL
        PREV = CURRENT
        CURRENT = CURRENT->next
    END WHILE

    PREV->next = NULL
    DELETE CURRENT

END
```

### Complexity

```text
O(n)
```

---

# 13. Doubly Linked List

### Definition

A **doubly linked list (DLL)** is a linked list in which every node contains:

1. Data
2. Pointer to the previous node
3. Pointer to the next node

The PPT also uses special **header and trailer nodes**. 0024c16c-c9da-4282-9a3c-cb05c66…

```text
NULL ← [prev|A|next] ⇄ [prev|B|next] ⇄ [prev|C|next] → NULL
```

### Advantages

- Can be traversed in both directions.
- Insertion before a node is easier.
- Deletion becomes easier because the predecessor can be accessed directly. 0024c16c-c9da-4282-9a3c-cb05c66…

### Disadvantages

- Requires extra memory.
- More links must be changed.
- Greater possibility of pointer-related bugs. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 14. Traversal of Doubly Linked List

### Forward Traversal

```text
TRAVERSE_FORWARD(HEAD)

    TEMP = HEAD

    WHILE TEMP != NULL
        PRINT TEMP->data
        TEMP = TEMP->next
    END WHILE
```

### Backward Traversal

Start from the last node:

```text
TRAVERSE_BACKWARD(TAIL)

    TEMP = TAIL

    WHILE TEMP != NULL
        PRINT TEMP->data
        TEMP = TEMP->prev
    END WHILE
```

### Important point

DLL allows traversal in **both directions**, which is one of its major advantages. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 15. Insertion After a Given Node in DLL ⭐

This is an important **6-mark algorithm** from your PPT.

### Algorithm: `insertAfter(p,e)`

1. Create a new node `v`.
2. Store element `e` in `v`.
3. Set `v.prev = p`.
4. Set `v.next = p.next`.
5. Set the old successor's previous pointer to `v`.
6. Set `p.next = v`.
7. Return `v`.

### Pseudocode

```text
INSERT_AFTER(P, E)

    V = create new node

    V.element = E
    V.prev = P
    V.next = P.next

    P.next.prev = V
    P.next = V

    RETURN V
```

This is the exact logical sequence presented in the PPT. 0024c16c-c9da-4282-9a3c-cb05c66…

### Diagram

Before:

```text
A ⇄ B ⇄ C
    ↑
    P
```

Insert `X`:

```text
A ⇄ B ⇄ X ⇄ C
```

### Complexity

```text
O(1)
```

when `P` is already known.

---

# 16. Insertion Before a Given Node in DLL

Because DLL has a `prev` pointer, insertion before a node is straightforward.

### Algorithm

1. Create new node `NEW`.
2. Store the data.
3. Set:
   ```text
   NEW->next = P
   ```
4. Set:
   ```text
   NEW->prev = P->prev
   ```
5. Make previous node point to `NEW`:
   ```text
   P->prev->next = NEW
   ```
6. Make `P` point backward to `NEW`:
   ```text
   P->prev = NEW
   ```

### Pseudocode

```text
INSERT_BEFORE(P, VALUE)

    NEW = create node
    NEW->data = VALUE

    NEW->next = P
    NEW->prev = P->prev

    P->prev->next = NEW
    P->prev = NEW

END
```

---

# 17. Deletion in DLL ⭐

### Definition

Deletion of a node from a DLL requires changing **two links**: the link of its predecessor and the link of its successor. 0024c16c-c9da-4282-9a3c-cb05c66…

Suppose:

```text
A ⇄ B ⇄ C
```

Delete `B`.

### Algorithm

1. Let `P` be the node to delete.
2. Connect its predecessor to its successor:
   ```text
   P->prev->next = P->next
   ```
3. Connect its successor to its predecessor:
   ```text
   P->next->prev = P->prev
   ```
4. Delete/free `P`.

### Pseudocode

```text
DELETE_NODE(P)

    P->prev->next = P->next
    P->next->prev = P->prev

    DELETE P

END
```

### Diagram

Before:

```text
A ⇄ B ⇄ C
```

After:

```text
A ⇄ C
```

### Exam point

> In DLL deletion, **two links are changed**, unlike the usual SLL deletion where the predecessor's next link is changed.

---

# 18. Circular Linked List

### Definition

A **circular linked list** is a linked list in which the **last node points back to the first node instead of NULL**. 0024c16c-c9da-4282-9a3c-cb05c66…

```text
       ┌──────────────────────┐
       ↓                      │
10 → 20 → 30 → 40 ────────────┘
```

The PPT commonly uses a **Rear pointer**.

```text
Rear
 ↓
[40]
 ↑
 |
[10] → [20] → [30] → [40]
```

`Rear->next` points to the first node.

---

# 19. Traversal of Circular Linked List ⭐

### Important difference

In a normal SLL:

```text
while(current != NULL)
```

In a circular linked list, there is **no NULL at the end**, so we stop when we reach the starting node again.

The PPT checks:

```text
Cur == Rear->next
```

after completing a cycle. 0024c16c-c9da-4282-9a3c-cb05c66…

### Algorithm

1. Check whether `Rear == NULL`.
2. Set:
   ```text
   CUR = Rear->next
   ```
3. Visit/print `CUR`.
4. Move:
   ```text
   CUR = CUR->next
   ```
5. Continue until:
   ```text
   CUR == Rear->next
   ```
6. Stop.

### Pseudocode

```text
TRAVERSE_CLL(REAR)

    IF REAR == NULL
        RETURN
    END IF

    CUR = REAR->next

    DO
        PRINT CUR->data
        CUR = CUR->next
    WHILE CUR != REAR->next

END
```

### Complexity

```text
O(n)
```

---

# 20. Insert into Empty Circular Linked List ⭐

### Algorithm

1. Create a new node.
2. Store data.
3. Set:
   ```text
   REAR = NEW
   ```
4. Make the node point to itself:
   ```text
   REAR->next = REAR
   ```

The PPT gives exactly this case. 0024c16c-c9da-4282-9a3c-cb05c66…

### Pseudocode

```text
INSERT_EMPTY(REAR, VALUE)

    NEW = create node
    NEW->data = VALUE

    REAR = NEW
    REAR->next = REAR

END
```

### Diagram

```text
       ┌───────┐
       ↓       │
      [10] ────┘
       ↑
      REAR
```

---

# 21. Insert at Beginning/Head of Circular Linked List

Remember:

```text
HEAD = REAR->next
```

### Algorithm

1. Create `NEW`.
2. Store data.
3. Set:
   ```text
   NEW->next = REAR->next
   ```
4. Set:
   ```text
   REAR->next = NEW
   ```
5. `REAR` does not change.

The PPT describes this as inserting between `Prev = Rear` and `Cur = Rear->next`. 0024c16c-c9da-4282-9a3c-cb05c66…

### Pseudocode

```text
INSERT_HEAD(REAR, VALUE)

    NEW = create node
    NEW->data = VALUE

    NEW->next = REAR->next
    REAR->next = NEW

END
```

---

# 22. Insert in Middle of Circular Linked List

### Algorithm

Suppose insertion is between `PREV` and `CUR`.

1. Create new node.
2. Store data.
3. Set:
   ```text
   NEW->next = CUR
   ```
4. Set:
   ```text
   PREV->next = NEW
   ```

The PPT gives exactly these two pointer changes. 0024c16c-c9da-4282-9a3c-cb05c66…

### Pseudocode

```text
INSERT_MIDDLE(PREV, CUR, VALUE)

    NEW = create node
    NEW->data = VALUE

    NEW->next = CUR
    PREV->next = NEW

END
```

---

# 23. Insert at End of Circular Linked List ⭐

### Algorithm

1. Create new node.
2. Store data.
3. Set:
   ```text
   NEW->next = REAR->next
   ```
4. Set:
   ```text
   REAR->next = NEW
   ```
5. Update:
   ```text
   REAR = NEW
   ```

The PPT explicitly gives these pointer changes. 0024c16c-c9da-4282-9a3c-cb05c66…

### Pseudocode

```text
INSERT_END(REAR, VALUE)

    NEW = create node
    NEW->data = VALUE

    NEW->next = REAR->next
    REAR->next = NEW

    REAR = NEW

END
```

---

# 24. Ordered Insertion in Circular Linked List ⭐⭐⭐

Your PPT actually gives a complete algorithm for this, so **learn this one carefully**.

### Algorithm

1. Create `NEW`.
2. Store `ITEM`.
3. If list is empty:
   ```text
   REAR = NEW
   REAR->next = REAR
   ```
4. Otherwise:
   ```text
   PREV = REAR
   CUR = REAR->next
   ```
5. Traverse until the correct position is found.
6. Insert between `PREV` and `CUR`.
7. If inserted at the end, update `REAR`.

### Pseudocode

```text
INSERT_NODE(REAR, ITEM)

    NEW = create node
    NEW->data = ITEM

    IF REAR == NULL
        REAR = NEW
        REAR->next = REAR
        RETURN
    END IF

    PREV = REAR
    CUR = REAR->next

    DO
        IF ITEM <= CUR->data
            BREAK
        END IF

        PREV = CUR
        CUR = CUR->next

    WHILE CUR != REAR->next

    NEW->next = CUR
    PREV->next = NEW

    IF ITEM > REAR->data
        REAR = NEW
    END IF

END
```

This is based directly on the PPT's `insertNode(NodePtr& Rear, int item)` implementation. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 25. Delete from Empty Circular Linked List

### Algorithm

1. Check:
   ```text
   REAR == NULL
   ```
2. If true, display:
   ```text
   "Trying to delete empty list"
   ```
3. Return.

The PPT explicitly includes this condition. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 26. Delete Single Node from Circular Linked List

### Algorithm

If there is only one node:

```text
REAR == CUR
```

Then:

1. Set:
   ```text
   REAR = NULL
   ```
2. Delete `CUR`.

The PPT shows this as the single-node deletion case. 0024c16c-c9da-4282-9a3c-cb05c66…

### Pseudocode

```text
IF REAR == CUR

    REAR = NULL
    DELETE CUR

END IF
```

---

# 27. Delete Head Node from Circular Linked List

Remember:

```text
HEAD = REAR->next
```

### Algorithm

1. Set:
   ```text
   CUR = REAR->next
   ```
2. Find/maintain `PREV = REAR`.
3. Connect `PREV` to the node after `CUR`:
   ```text
   PREV->next = CUR->next
   ```
4. Delete `CUR`.

The PPT gives `Prev->next = Cur->next`, which is also `Rear->next = Cur->next`. 0024c16c-c9da-4282-9a3c-cb05c66…

### Pseudocode

```text
DELETE_HEAD(REAR)

    CUR = REAR->next

    REAR->next = CUR->next

    DELETE CUR

END
```

---

# 28. Delete Middle Node from Circular Linked List

### Algorithm

Suppose `CUR` is the node to delete.

1. Find `PREV`, the node immediately before `CUR`.
2. Change:
   ```text
   PREV->next = CUR->next
   ```
3. Delete `CUR`.

The PPT uses exactly these operations. 0024c16c-c9da-4282-9a3c-cb05c66…

### Pseudocode

```text
DELETE_MIDDLE(PREV, CUR)

    PREV->next = CUR->next
    DELETE CUR

END
```

---

# 29. Delete End Node from Circular Linked List

### Algorithm

1. Find the last node `CUR`.
2. Find its predecessor `PREV`.
3. Connect `PREV` to the first node:
   ```text
   PREV->next = CUR->next
   ```
4. Delete `CUR`.
5. Update:
   ```text
   REAR = PREV
   ```

The PPT explicitly shows these operations. 0024c16c-c9da-4282-9a3c-cb05c66…

### Pseudocode

```text
DELETE_END(REAR)

    Find PREV and CUR

    PREV->next = CUR->next
    DELETE CUR

    REAR = PREV

END
```

---

# 30. Complete Delete Operation in Circular Linked List ⭐⭐⭐

This is another **very important 6-mark question**, because the PPT provides the complete algorithm.

### Algorithm

```text
DELETE_NODE(REAR, ITEM)

    IF REAR == NULL
        PRINT "Trying to delete empty list"
        RETURN
    END IF

    PREV = REAR
    CUR = REAR->next

    DO

        IF ITEM <= CUR->data
            BREAK
        END IF

        PREV = CUR
        CUR = CUR->next

    WHILE CUR != REAR->next

    IF CUR->data != ITEM
        PRINT "Data Not Found"
        RETURN
    END IF

    IF CUR == PREV
        REAR = NULL
        DELETE CUR
        RETURN
    END IF

    IF CUR == REAR
        REAR = PREV
    END IF

    PREV->next = CUR->next
    DELETE CUR

END
```

This follows the complete deletion implementation in your PPT, including **empty list, searching, data-not-found, single-node deletion, deleting rear, pointer adjustment, and memory deletion**. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 31. Searching in Linked List

### Definition

**Searching** means finding whether a particular element/value exists in the linked list.

### Algorithm

```text
SEARCH(HEAD, VALUE)

    TEMP = HEAD

    WHILE TEMP != NULL

        IF TEMP->data == VALUE
            RETURN "Found"
        END IF

        TEMP = TEMP->next

    END WHILE

    RETURN "Not Found"

END
```

### Complexity

```text
Best case  = O(1)
Worst case = O(n)
```

### Important PPT point

Linked lists do **not provide random access**, so elements must generally be accessed sequentially. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 32. Array vs Linked List — 6-Mark Theory

| Array | Linked List |
|---|---|
| Fixed size | Dynamic size |
| Contiguous memory | Nodes can be dynamically allocated |
| Random access possible | Sequential access |
| Insertion/deletion may require shifting | Insertion/deletion mainly changes links |
| Better cache locality | Not cache friendly |
| No pointer overhead | Extra pointer memory required |

The PPT emphasizes that linked lists can grow/shrink dynamically and allow easy insertion/deletion without moving other nodes. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 33. Circular Linked List vs Linear Linked List

### Linear Linked List

```text
A → B → C → NULL
```

### Circular Linked List

```text
A → B → C
↑       ↓
└───────┘
```

### Differences

| Linear Linked List | Circular Linked List |
|---|---|
| Last node points to `NULL` | Last node points to first node |
| Traversal ends at `NULL` | Traversal ends when starting node is reached again |
| Usually uses `HEAD` | PPT commonly uses `REAR` |
| Cannot directly continue from last to first | Can repeatedly traverse the list |

The PPT notes that a circular list allows repeated traversal because the last node points to the first node. 0024c16c-c9da-4282-9a3c-cb05c66…

---

# 🔥 MOST IMPORTANT 6-MARK QUESTIONS FROM YOUR PPT

If your exam asks **"Write algorithm"**, prioritize these:

### ⭐⭐⭐ Must learn

1. **Traversal of Singly Linked List**
2. **Insertion at beginning in SLL**
3. **Insertion after a given node/value in SLL**
4. **Insertion at end in SLL**
5. **Deletion of a node in SLL**
6. **Insertion after a given node in DLL**
7. **Deletion of a node in DLL**
8. **Traversal of Circular Linked List**
9. **Insertion in Circular Linked List**
   - Empty
   - Beginning
   - Middle
   - End
10. **Deletion in Circular Linked List**
   - Single node
   - Head
   - Middle
   - End
11. **Complete `insertNode()` for ordered CLL**
12. **Complete `deleteNode()` for ordered CLL**

---

# 🧠 How to Write Any 6-Mark Algorithm

For your exam, use this structure:

### 1 Mark — Definition

> Define the operation in 2–3 lines.

### 3 Marks — Algorithm

Write numbered steps:

```text
1. Create/initialize required pointers.
2. Check special condition.
3. Traverse/search if required.
4. Perform pointer changes.
5. Update HEAD/REAR if required.
6. Delete/insert node.
7. Stop.
```

### 1 Mark — Diagram

Always draw:

```text
BEFORE                 AFTER

A → B → C              A → B → X → C
```

### 1 Mark — Complexity

```text
Traversal       O(n)
Search          O(n)
Beginning       O(1)
Known-node DLL  O(1)
End insertion   O(n) without tail
End deletion    O(n)
```

**Most important rule:** in linked-list algorithms, don't just memorize the code. Memorize **which pointer changes to which pointer**. That's what makes the algorithm easy to reconstruct in a 6-mark question.