Absolutely. I’ll make these **exam-oriented notes directly from both QBs**, focusing on the exact cases the questions can test: **definition → internal working → operations → complexity → problems/pitfalls → solution → comparison → code patterns**.

The QB explicitly covers `array/vector/deque/list`, container adaptors, associative/unordered containers, iterator invalidation, and related operations. QB_UNIT1_Unit2-PPS QUESTION BANK 2

# STL CONTAINERS — COMPLETE EXAM NOTES

## 0. What is an STL Container?

**Definition:**  
An STL container is a class template provided by the C++ Standard Template Library that is used to **store and manage a collection of objects** efficiently.

Examples:

```cpp
vector<int> v;
list<int> l;
set<int> s;
map<int, string> m;
```

Containers differ mainly in:

- How data is stored
- How elements are accessed
- Insertion/deletion efficiency
- Ordering
- Memory usage
- Iterator support

### Main classification

```text
STL Containers
│
├── Sequence Containers
│   ├── array
│   ├── vector
│   ├── deque
│   ├── list
│   └── forward_list
│
├── Container Adaptors
│   ├── stack
│   ├── queue
│   └── priority_queue
│
└── Associative / Unordered Containers
    ├── set
    ├── map
    └── unordered_map
```

---

# 1. `std::array`

## Definition

`std::array` is a **fixed-size sequence container** that stores elements in **contiguous memory**.

```cpp
#include <array>
using namespace std;

array<int, 5> a = {10,20,30,40,50};
```

The size is decided at **compile time** and cannot change during execution.

### Important point

```cpp
array<int, 5>
```

means:

- Data type = `int`
- Number of elements = `5`

---

## Memory layout

```text
10 | 20 | 30 | 40 | 50
 ↑
contiguous memory
```

Unlike `vector`, it cannot grow or shrink.

---

## Important operations

```cpp
a.size();       // number of elements
a.at(2);        // bounds-checked access
a[2];           // unchecked access
a.front();      // first element
a.back();       // last element
a.fill(0);      // fills all elements with 0
```

---

## `at()` vs `[]`

### `[]`

```cpp
cout << a[10];
```

No bounds checking.

### `at()`

```cpp
cout << a.at(10);
```

Performs bounds checking and throws:

```cpp
std::out_of_range
```

### Exam case

**Q:** How does `std::array` provide safer access than a raw C-style array?

**Answer:** `std::array::at()` performs bounds checking and throws `std::out_of_range` for an invalid index.

QB2 specifically asks this comparison. QUESTION BANK 2

---

## Advantages

- Fixed-size
- Contiguous memory
- Fast random access: `O(1)`
- Works well with STL algorithms
- Provides `.size()`, `.at()`, `.front()`, `.back()`
- Safer than raw arrays

## Disadvantages

- Cannot resize
- Size must be known at compile time

---

# 2. `std::vector`

## Definition

`std::vector` is a **dynamic array** that stores elements in contiguous memory and can automatically grow or shrink.

```cpp
vector<int> v = {10,20,30};
```

---

# Most important vector concept: SIZE vs CAPACITY

This is directly asked in QB1. QB_UNIT1_Unit2-PPS

### `size()`

Number of elements currently stored.

### `capacity()`

Number of elements that can be stored in currently allocated memory without reallocation.

Example:

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

cout << v.size();
cout << v.capacity();
```

Possible output:

```text
size = 3
capacity = 4
```

**Important:** Capacity is implementation-dependent, so don't memorize a fixed growth value.

---

# Vector memory

Initially:

```text
[10][20][30][ ]
```

If capacity is full and another element is inserted:

```text
OLD MEMORY
[10][20][30][40]

       ↓ reallocation

NEW MEMORY
[10][20][30][40][50][ ][ ]
```

Elements may be copied/moved to a new memory block.

---

# Vector operations

| Operation | Complexity |
|---|---:|
| Access `v[i]` | O(1) |
| `push_back()` | Amortized O(1) |
| `pop_back()` | O(1) |
| Insert at beginning | O(n) |
| Insert in middle | O(n) |
| Delete beginning | O(n) |
| Delete middle | O(n) |
| Search | O(n) |

---

# Why middle insertion is O(n)?

Suppose:

```text
10 20 30 40 50
```

Insert `25` at index 2:

```text
10 20 25 30 40 50
```

Elements after the insertion point must shift.

Therefore:

```text
O(n)
```

---

# Vector Iterator Invalidation

An iterator points to an element in a vector.

```cpp
vector<int> v = {10,20,30};
auto it = v.begin();   // points to 10

v.push_back(40);
```

### Main cases

**1. `push_back()` + reallocation**

```text
[10][20][30] → [10][20][30][40]
 ↑                 ↑
old it          new location
```

➡️ **All existing iterators become invalid.**

---

**2. `push_back()` without reallocation**

```text
[10][20][30][ ][ ]
 ↑
it

[10][20][30][40][ ]
 ↑
it
```

➡️ Existing iterators **remain valid**.

---

**3. `insert()` without reallocation**

```cpp
v.insert(v.begin() + 1, 99);
```

➡️ Iterators **at or after the insertion point become invalid**.  
➡️ Iterators **before it remain valid**.

---

**4. `erase()`**

```cpp
it = v.erase(it);
```

➡️ The old `it` becomes invalid.  
➡️ `erase()` returns an iterator to the **next valid element**.

❌ Don't:

```cpp
v.erase(it);
++it;
```

### ⭐ Remember

> **Reallocation → ALL invalid**  
> **Insert without reallocation → at/after insertion point invalid**  
> **Erase → use `it = v.erase(it)`**

# `push_back()` vs `emplace_back()`

QB2 asks this explicitly. QUESTION BANK 2

### `push_back()`

Adds an already-created object.

```cpp
v.push_back(10);
```

### `emplace_back()`

Constructs the object directly at the end.

```cpp
v.emplace_back(10);
```

For simple types like `int`, the practical difference is negligible.

For classes, `emplace_back()` can construct the object directly.

---

# 3. `std::deque`

## Definition

`deque` = **Double Ended Queue**.

It allows efficient insertion and deletion at **both beginning and end**.

```cpp
deque<int> d;

d.push_front(10);
d.push_back(20);
```

---

## Internal structure

Unlike vector, deque does **not require one single contiguous memory block**.

Conceptually:

```text
Block 1       Block 2       Block 3
[10][20]  →   [30][40]  →   [50][60]
```

A structure maintains pointers to these blocks.

---

## Why is deque O(1) at both ends?

Because it can add/remove elements from the front or back without shifting all existing elements.

QB1 directly asks about this internal storage architecture. QB_UNIT1_Unit2-PPS

---

## Operations

| Operation | Complexity |
|---|---:|
| Random access | O(1) |
| `push_front()` | O(1) |
| `push_back()` | O(1) |
| `pop_front()` | O(1) |
| `pop_back()` | O(1) |
| Middle insertion | O(n) |

---

## Vector vs deque

| Feature | Vector | Deque |
|---|---|---|
| Contiguous | Yes | No |
| Random access | O(1) | O(1) |
| Front insertion | O(n) | O(1) |
| Back insertion | Amortized O(1) | O(1) |
| Memory blocks | One contiguous block | Multiple blocks |

---

# 4. `std::list`

## Definition

`std::list` is a **doubly linked list** container.

Each node contains:

```text
[previous | data | next]
```

Example:

```text
NULL ← 10 ⇄ 20 ⇄ 30 → NULL
```

---

## Important property

Elements are **not stored contiguously**.

Therefore random access is not supported efficiently.

```cpp
list<int> l = {10,20,30};
```

You cannot efficiently do:

```cpp
l[2];   // ERROR
```

---

## Complexity

| Operation | Complexity |
|---|---:|
| Insert front | O(1) |
| Insert back | O(1) |
| Delete front | O(1) |
| Delete back | O(1) |
| Insert/delete with iterator | O(1) |
| Random access | O(n) |
| Search | O(n) |

---

# Why can't `std::list` be used with `std::sort()`?

QB1 asks this. QB_UNIT1_Unit2-PPS

`std::sort()` requires **Random Access Iterators**.

`list` provides **Bidirectional Iterators**, not Random Access Iterators.

Therefore:

```cpp
sort(l.begin(), l.end());   // ❌
```

### Correct solution

Use the container's own member function:

```cpp
l.sort();
```

---

# 5. `std::forward_list`

## Definition

`std::forward_list` is a **singly linked list**.

Each node contains:

```text
[data | next]
```

Example:

```text
10 → 20 → 30 → NULL
```

---

## Why is it more memory efficient than `list`?

QB1 explicitly asks this. QB_UNIT1_Unit2-PPS

`list` node:

```text
[prev | data | next]
```

`forward_list` node:

```text
[data | next]
```

Therefore it stores only **one pointer instead of two**.

---

## Important limitation

It supports movement only forward.

```cpp
++it;
```

But not:

```cpp
--it;   // ❌
```

---

## Complexity

| Operation | Complexity |
|---|---:|
| Insert after iterator | O(1) |
| Delete after iterator | O(1) |
| Search | O(n) |
| Random access | Not supported |
| Backward traversal | Not supported |

---

# 6. `std::stack`

## Definition

`stack` is a **container adaptor** that follows:

> **LIFO — Last In, First Out**

Example:

```text
push 10
push 20
push 30

TOP
 ↓
30
20
10
```

First element removed:

```text
30
```

---

## Default underlying container

QB1 asks this. QB_UNIT1_Unit2-PPS

By default:

```cpp
stack<int>
```

uses:

```cpp
deque<int>
```

internally.

---

## Main functions

```cpp
s.push(10);
s.pop();
s.top();
s.empty();
s.size();
```

### Important

`pop()` does **not return** the removed value.

Correct:

```cpp
int x = s.top();
s.pop();
```

---

# 7. `std::queue`

## Definition

`queue` follows:

> **FIFO — First In, First Out**

```text
FRONT                 BACK
 ↓                      ↓
10 → 20 → 30 → 40
```

First removed:

```text
10
```

---

## Default underlying container

```cpp
deque
```

---

## Operations

```cpp
q.push(10);
q.pop();
q.front();
q.back();
q.empty();
q.size();
```

---

# Stack vs Queue

| Feature | Stack | Queue |
|---|---|---|
| Principle | LIFO | FIFO |
| Insert | `push()` | `push()` |
| Remove | `pop()` | `pop()` |
| Access | `top()` | `front()`, `back()` |
| Default container | deque | deque |

---

# 8. `std::priority_queue`

## Definition

A `priority_queue` is a container adaptor where elements are removed according to **priority**, rather than insertion order.

By default it is a:

> **Max-Heap**

Example:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(20);
```

Top:

```text
50
```

---

## Default behavior

```text
Largest element
      ↓
     50
   /    \
 20      10
```

`top()` gives the highest-priority element.

---

# Min-heap

To make a min-heap:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Now:

```text
10
```

will be at the top.

---

# Custom priority queue

QB1 specifically asks for:

```cpp
struct Task {
    int id;
    int priority;
};
```

with a custom comparator and min-heap. QB_UNIT1_Unit2-PPS

### Exam code

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Task {
    int id;
    int priority;
};

struct Compare {
    bool operator()(Task a, Task b) {
        return a.priority > b.priority;
    }
};

int main() {
    priority_queue<Task, vector<Task>, Compare> pq;

    pq.push({1, 30});
    pq.push({2, 10});
    pq.push({3, 20});

    cout << pq.top().id;

    return 0;
}
```

Output:

```text
2
```

because priority `10` is smallest.

---

# 9. `std::set`

## Definition

`std::set` stores **unique elements in sorted order**.

```cpp
set<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
s.insert(10);
```

Result:

```text
10 20 30
```

Duplicate `10` is ignored.

---

## Internal data structure

According to the QB:

> `set` uses a **self-balancing Binary Search Tree**, commonly a Red-Black Tree.

QUESTION BANK 2

---

## Complexity

Search:

```text
O(log n)
```

Insert:

```text
O(log n)
```

Delete:

```text
O(log n)
```

---

## Important properties

```text
Unique
+
Sorted
+
O(log n)
```

---

# `set` vs `unordered_set`

| Feature | set | unordered_set |
|---|---|---|
| Structure | Balanced BST | Hash table |
| Ordering | Sorted | No guaranteed order |
| Average search | O(log n) | O(1) |
| Worst search | O(log n) | O(n) |
| Duplicate | No | No |

---

# 10. `std::map`

## Definition

`std::map` stores data as **key-value pairs**, where every key is unique and keys are maintained in sorted order.

```cpp
map<int,string> m;

m[1] = "Yanshika";
m[2] = "Rahul";
```

Conceptually:

```text
Key       Value

 1     →  Yanshika
 2     →  Rahul
```

---

## Internal structure

Self-balancing BST / Red-Black Tree.

Therefore:

```text
search = O(log n)
insert = O(log n)
delete = O(log n)
```

---

# IMPORTANT: `map::operator[]` problem

QB1 specifically asks why it should be used carefully for lookup. QB_UNIT1_Unit2-PPS

Suppose:

```cpp
map<int,string> m;

cout << m[100];
```

If key `100` doesn't exist, `operator[]` **creates the key** with a default value.

So lookup has modified the map.

### Bad lookup

```cpp
if (m[100] == "abc")
```

This can insert key `100`.

### Better solution

```cpp
auto it = m.find(100);

if (it != m.end())
    cout << it->second;
```

### Exam line

> Use `find()` for lookup when you do not want to accidentally insert a missing key.

---

# 11. `std::unordered_map`

## Definition

`unordered_map` stores key-value pairs using a **hash table**.

Unlike `map`, elements are **not maintained in sorted key order**.

```cpp
unordered_map<string,int> m;

m["apple"] = 5;
m["banana"] = 10;
```

---

# Internal working

```text
             Hash Function
                  ↓
               key
                  ↓
             bucket index
                  ↓
        ┌─────────┐
Bucket 0│         │
Bucket 1│ key     │
Bucket 2│ key → key
Bucket 3│         │
        └─────────┘
```

Collisions can occur when different keys map to the same bucket.

The QB specifically asks about:

- hashing
- buckets
- collision handling
- chaining
- load factor
- rehashing

QUESTION BANK 2

---

# Hash collision

Suppose:

```text
hash("A") → bucket 2
hash("B") → bucket 2
```

Both keys want the same bucket.

This is a collision.

A common implementation strategy is **chaining**, where multiple elements are associated with the same bucket.

---

# Load factor

Conceptually:

```text
load factor = number of elements / number of buckets
```

A high load factor means more elements per bucket, potentially increasing collisions and reducing performance.

When the container needs more buckets, it can **rehash**.

---

# Complexity

| Operation | Average | Worst |
|---|---:|---:|
| Search | O(1) | O(n) |
| Insert | O(1) | O(n) |
| Delete | O(1) | O(n) |

---

# `map` vs `unordered_map`

This is a **VERY IMPORTANT 6-mark question**.

QB1 explicitly asks for underlying structure, complexity, ordering and key requirements. QB_UNIT1_Unit2-PPS

| Feature | `map` | `unordered_map` |
|---|---|---|
| Structure | Self-balancing BST | Hash table |
| Ordering | Sorted | No guaranteed ordering |
| Search average | O(log n) | O(1) |
| Search worst | O(log n) | O(n) |
| Insert average | O(log n) | O(1) |
| Delete average | O(log n) | O(1) |
| Key requirement | Ordering comparison | Hash + equality |
| Best use | Need sorted keys | Fast lookup |

### When choose `map`?

Use it when:

- sorted order matters
- range queries are needed
- predictable `O(log n)` behavior is desired

### When choose `unordered_map`?

Use it when:

- fast average lookup matters
- ordering doesn't matter

---

# ⭐ COMPLETE CONTAINER COMPARISON

This is extremely useful for a 6-mark question.

| Container | Structure | Ordered? | Duplicate? | Random Access | Main Strength |
|---|---|---|---|---|---|
| `array` | Contiguous | Yes | Yes | O(1) | Fixed size |
| `vector` | Dynamic contiguous | Yes | Yes | O(1) | Fast general-purpose sequence |
| `deque` | Multiple blocks | Yes | Yes | O(1) | Fast front + back |
| `list` | Doubly linked | Yes | Yes | No | Fast insertion/deletion |
| `forward_list` | Singly linked | Yes | Yes | No | Low memory linked list |
| `stack` | Adaptor | — | Yes | No | LIFO |
| `queue` | Adaptor | — | Yes | No | FIFO |
| `priority_queue` | Heap-based adaptor | Priority | Yes | No | Highest/lowest priority |
| `set` | Balanced BST | Sorted | **No** | No | Unique sorted values |
| `map` | Balanced BST | Sorted by key | Unique keys | No | Sorted key-value data |
| `unordered_map` | Hash table | No | Unique keys | No | Fast average lookup |

---

# ⭐ MOST IMPORTANT EXAM CASES

Based on the two QBs, these are the cases you **must know**.

## Case 1 — Fixed vs Dynamic

### Question

> Differentiate `std::array` and `std::vector`.

Remember:

```text
array  → fixed
vector → dynamic
```

---

# Case 2 — Size vs Capacity

```cpp
v.size()
```

= elements currently present.

```cpp
v.capacity()
```

= storage available before reallocation.

---

# Case 3 — Front insertion

### Vector

```text
O(n)
```

because elements shift.

### Deque

```text
O(1)
```

### List

```text
O(1)
```

---

# Case 4 — Random access

```text
array   → O(1)
vector  → O(1)
deque   → O(1)

list           → O(n)
forward_list   → not supported directly
```

This is a very common MCQ/2-mark area.

---

# Case 5 — Need frequent insertion/deletion in middle

Prefer:

```cpp
list
```

provided you already have an iterator to the location.

Don't say `list` makes finding the location O(1). **Searching for the location is still O(n).**

---

# Case 6 — Need both front and back insertion

Use:

```cpp
deque
```

---

# Case 7 — Need LIFO

Use:

```cpp
stack
```

Example:

```text
Undo operation
Function call stack
Browser backtracking
```

---

# Case 8 — Need FIFO

Use:

```cpp
queue
```

Example:

```text
Printer queue
CPU scheduling
BFS
```

---

# Case 9 — Need highest priority first

Use:

```cpp
priority_queue
```

Default:

```text
Max heap
```

---

# Case 10 — Need unique + sorted values

Use:

```cpp
set
```

Example:

```cpp
set<int> s = {30,10,20,10};
```

Result:

```text
10 20 30
```

---

# Case 11 — Need sorted key-value pairs

Use:

```cpp
map
```

---

# Case 12 — Need fastest average key lookup

Use:

```cpp
unordered_map
```

provided ordering is not required.

---

# Case 13 — `map[]` lookup problem

Don't do:

```cpp
m[key]
```

just to check existence.

Use:

```cpp
m.find(key)
```

---

# Case 14 — List + sort

Wrong:

```cpp
sort(l.begin(), l.end());  // ❌
```

Correct:

```cpp
l.sort();                  // ✅
```

Because `std::sort()` requires random-access iterators. QB_UNIT1_Unit2-PPS

---

# Case 15 — Vector deletion during traversal

Potentially dangerous:

```cpp
for (auto it = v.begin(); it != v.end(); ++it) {
    if (*it == 20)
        v.erase(it);
}
```

Why?

`erase()` invalidates the erased iterator and potentially subsequent iterators.

### Correct pattern

```cpp
for (auto it = v.begin(); it != v.end(); ) {
    if (*it == 20)
        it = v.erase(it);
    else
        ++it;
}
```

This is an important safe-deletion pattern.

---

# Case 16 — `list` deletion during traversal

```cpp
for (auto it = l.begin(); it != l.end(); ) {
    if (*it == 20)
        it = l.erase(it);
    else
        ++it;
}
```

This pattern is also clean and safe.

Unlike vector, erasing one list node does not invalidate iterators to other nodes.

QB1 specifically compares iterator invalidation behavior between vector and list. QB_UNIT1_Unit2-PPS

---

# Case 17 — Duplicate values

| Need | Container |
|---|---|
| Unique + sorted | `set` |
| Duplicate + sorted | `multiset` |
| Unique keys + sorted values | `map` |
| Duplicate keys + sorted values | `multimap` |
| Unique keys + fast average lookup | `unordered_map` |

QB2 specifically adds `multiset`/`multimap` as an extension of this area. QUESTION BANK 2

---

# Case 18 — Hashing

If examiner asks:

> Why is unordered_map generally faster than map?

Answer:

```text
map
→ balanced BST
→ O(log n)

unordered_map
→ hash table
→ average O(1)
```

But `unordered_map` can degrade to **O(n) worst-case**.

---

# Case 19 — Custom priority

For:

```cpp
Task {
    id;
    priority;
}
```

remember:

```cpp
priority_queue<Task, vector<Task>, Compare>
```

The comparator decides which element appears at `top()`.

---

# Case 20 — Choosing the right container

### Question:

> You need a container for a browser's back button.

Answer:

```cpp
stack
```

because LIFO.

### Printer waiting line:

```cpp
queue
```

because FIFO.

### Sorted unique student IDs:

```cpp
set
```

### Student ID → student name:

```cpp
map
```

### Massive key-value lookup where ordering doesn't matter:

```cpp
unordered_map
```

### Frequent insertion/deletion at both ends:

```cpp
deque
```

### Fixed number of values:

```cpp
array
```

### Dynamic array with fast indexing:

```cpp
vector
```

### Frequent insertion/deletion using known positions:

```cpp
list
```

---

# 🔥 ONE-PAGE MEMORY TRICK

Remember the containers like this:

```text
ARRAY
Fixed size
↓
VECTOR
Dynamic + contiguous
↓
DEQUE
Fast front + back
↓
LIST
Doubly linked
↓
FORWARD_LIST
Singly linked
↓
STACK
LIFO
↓
QUEUE
FIFO
↓
PRIORITY_QUEUE
Priority
↓
SET
Unique + sorted
↓
MAP
Key + value + sorted key
↓
UNORDERED_MAP
Key + value + hashing
```

## The 5 things to ask yourself in the exam

Whenever they give you a situation, ask:

**1. Fixed or dynamic?**

```text
Fixed → array
Dynamic → vector
```

**2. Need front insertion?**

```text
deque / list
```

**3. Need LIFO/FIFO?**

```text
LIFO → stack
FIFO → queue
```

**4. Need sorted unique data?**

```text
set
```

**5. Need key-value lookup?**

```text
Sorted → map
Fast average lookup → unordered_map
```

### Most important 6-mark comparisons to prepare

1. **`vector` vs `deque` vs `list`** — memory layout, insertion/deletion, iterator invalidation. QB_UNIT1_Unit2-PPS
2. **`map` vs `unordered_map`** — structure, complexity, ordering, key requirements. QB_UNIT1_Unit2-PPS
3. **`stack` vs `queue` vs `priority_queue`** — adaptor, underlying container, interface. QUESTION BANK 2
4. **`array` vs raw C array** — safety, algorithms, `size()`, `at()`. QUESTION BANK 2
5. **Vector iterator invalidation vs list**. QB_UNIT1_Unit2-PPS

These are the **core container notes**. The next layer in your QB is **iterators + STL algorithms** (`find`, `sort`, `remove`, `transform`, `lower_bound`, `accumulate`, etc.), which should be studied separately because they form another major Unit-2 question cluster.