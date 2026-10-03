Absolutely. I’ll turn the uploaded **C++ STL lecture transcript** into **exam-ready notes**, keeping the concepts and examples from the source, but cleaning up the transcript errors and organizing everything so you can actually study from it. Pasted text

# C++ STL — Exam Notes with Examples

## 1. What is STL?

**STL = Standard Template Library**

STL is a collection of **ready-made, reusable components** in C++ that help us implement common data structures and algorithms without writing everything from scratch.

### Why use STL?

- Reduces the amount of code.
- Saves development time.
- Provides optimized implementations.
- Useful for competitive programming and interviews.
- Provides commonly used **containers, algorithms and iterators**.

### Main parts of STL

The lecture divides containers mainly into:

1. **Sequence Containers**
2. **Associative Containers**
3. **Unordered Associative Containers**
4. **Container Adaptors**

Pasted text

---

# 2. Array

An array stores multiple elements of the **same data type** in contiguous memory.

### Declaration

```cpp
int arr[4] = {10, 20, 30, 40};
```

Indexing starts from `0`.

```text
Index:   0   1   2   3
Value:  10  20  30  40
```

### Accessing an element

```cpp
cout << arr[2];
```

Output:

```text
30
```

### Size

```cpp
cout << sizeof(arr) / sizeof(arr[0]);
```

Output:

```text
4
```

### Time Complexity

| Operation | Complexity |
|---|---:|
| Random access | O(1) |
| Access by index | O(1) |
| Search | O(n) |
| Insertion | O(n) |
| Deletion | O(n) |

**Exam point:** Array provides **fast random access**, but its size is fixed.

---

# 3. Vector

A **vector** is a dynamic array provided by STL.

```cpp
#include <vector>
using namespace std;

vector<int> v;
```

Unlike an ordinary array, a vector can **grow and shrink dynamically**. Pasted text

## Creating a vector

```cpp
vector<int> v = {1, 2, 3, 4};
```

---

## `size()`

Returns the number of elements currently present.

```cpp
cout << v.size();
```

Output:

```text
4
```

---

## `capacity()`

Returns the amount of memory currently allocated for the vector.

```cpp
cout << v.capacity();
```

### Important difference

**size = number of elements currently stored**

**capacity = storage currently allocated**

Example:

```cpp
vector<int> v;

v.push_back(10);
```

Conceptually:

```text
size     = 1
capacity = allocated storage >= 1
```

Pasted text

---

# 4. `push_back()`

Adds an element at the **end** of the vector.

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);
```

Vector:

```text
10 20 30
```

### Example

```cpp
for(int i = 0; i < 5; i++)
{
    v.push_back(i);
}
```

Result:

```text
0 1 2 3 4
```

---

# 5. Vector Capacity Doubling

One important concept for exams:

When a vector's allocated capacity becomes insufficient, it generally:

1. Allocates a larger memory block.
2. Copies/moves the old elements.
3. Releases the old storage.
4. Continues using the new storage.

The lecture illustrates this with capacity growing as elements are inserted. Pasted text

Example:

```text
Initially:
size = 0
capacity = 0

After inserting:
size = 1
capacity = 1

More elements:
size = 2
capacity may become 2

Next expansion:
capacity may become 4
```

**Important:** The exact growth factor is implementation-dependent; don't treat "always doubles" as a C++ language guarantee.

---

# 6. `front()` and `back()`

### `front()`

Returns the first element.

```cpp
cout << v.front();
```

### `back()`

Returns the last element.

```cpp
cout << v.back();
```

Example:

```cpp
vector<int> v = {10,20,30,40};

cout << v.front(); // 10
cout << v.back();  // 40
```

---

# 7. Updating Vector Elements

You can directly access an element using its index.

```cpp
v[2] = 100;
```

Example:

```cpp
vector<int> v = {10,20,30};

v[1] = 50;
```

Now:

```text
10 50 30
```

Random access is **O(1)**.

---

# 8. `clear()`

Removes all elements from the vector.

```cpp
v.clear();
```

After:

```text
size = 0
```

### Important

`clear()` removes the elements, but it does **not necessarily reduce the capacity**.

So:

```text
Before clear:
size = 4
capacity = 4

After clear:
size = 0
capacity may still be 4
```

This distinction is specifically emphasized in the lecture. Pasted text

---

# 9. Initializing Vector with Size

You can create a vector with a specified size.

```cpp
vector<int> v(5);
```

This creates:

```text
0 0 0 0 0
```

You can also initialize all elements with a value:

```cpp
vector<int> v(5, 10);
```

Result:

```text
10 10 10 10 10
```

---

# 10. Copying a Vector

```cpp
vector<int> v1 = {1,2,3,4,5};

vector<int> v2(v1);
```

Now `v2` contains a copy of `v1`.

---

# 11. Deque

**Deque = Double Ended Queue**

It allows insertion and deletion from **both ends**.

```cpp
#include <deque>

deque<int> dq;
```

Pasted text

### Operations

```cpp
dq.push_back(10);
dq.push_front(20);
```

Now:

```text
20 10
```

Remove from back:

```cpp
dq.pop_back();
```

Remove from front:

```cpp
dq.pop_front();
```

### Access

```cpp
dq.front();
dq.back();
dq[1];
```

Deque also supports random access.

---

# 12. List

`list` is a **doubly linked list** in C++ STL.

```cpp
#include <list>

list<int> l;
```

The lecture describes it as using nodes connected through pointers. Pasted text

Conceptually:

```text
10 <-> 20 <-> 30 <-> 40
```

Each node contains:

```text
[data | previous | next]
```

---

## Important Properties of List

- Dynamic size.
- Efficient insertion/deletion when the position is known.
- No random access like an array/vector.
- Elements are not stored contiguously.

### Example

```cpp
list<int> l;

l.push_back(10);
l.push_back(20);
l.push_front(5);
```

Result:

```text
5 10 20
```

---

# 13. Vector vs List

| Feature | Vector | List |
|---|---|---|
| Structure | Dynamic array | Doubly linked list |
| Random access | Yes | No |
| Memory | Contiguous | Non-contiguous |
| `[]` operator | Yes | No |
| Insertion/deletion in middle | Costly | Efficient if iterator known |
| Cache performance | Generally better | Generally worse |

---

# 14. Stack

A **stack** follows:

## LIFO — Last In First Out

The element inserted **last** is removed **first**.

Think of a stack of plates.

```text
     30  ← TOP
     20
     10
```

If we remove one plate:

```text
30 is removed first
```

Pasted text

### Creating a stack

```cpp
#include <stack>

stack<int> st;
```

### `push()`

```cpp
st.push(10);
st.push(20);
st.push(30);
```

Stack:

```text
30 ← top
20
10
```

### `top()`

Returns the top element.

```cpp
cout << st.top();
```

Output:

```text
30
```

### `pop()`

Removes the top element.

```cpp
st.pop();
```

Now:

```text
20 ← top
10
```

### `empty()`

Checks whether stack is empty.

```cpp
if(st.empty())
    cout << "Empty";
```

### `size()`

```cpp
cout << st.size();
```

---

# 15. Stack Example

```cpp
stack<string> st;

st.push("A");
st.push("B");
st.push("C");

cout << st.top();
```

Output:

```text
C
```

Then:

```cpp
st.pop();

cout << st.top();
```

Output:

```text
B
```

### Stack operations

| Operation | Complexity |
|---|---:|
| push | O(1) |
| pop | O(1) |
| top | O(1) |
| empty | O(1) |
| size | O(1) |

---

# 16. Queue

A **queue** follows:

## FIFO — First In First Out

The element inserted **first** is removed first.

Real-life example:

```text
Person A → Person B → Person C
```

A came first, so A leaves first.

Pasted text

### Creating Queue

```cpp
#include <queue>

queue<int> q;
```

### Insertion

```cpp
q.push(10);
q.push(20);
q.push(30);
```

Queue:

```text
10 → 20 → 30
↑          ↑
front      back
```

### `front()`

```cpp
cout << q.front();
```

Output:

```text
10
```

### `back()`

```cpp
cout << q.back();
```

Output:

```text
30
```

### `pop()`

```cpp
q.pop();
```

Removes `10`.

Now:

```text
20 → 30
```

---

# 17. Stack vs Queue

| Stack | Queue |
|---|---|
| LIFO | FIFO |
| Last inserted removed first | First inserted removed first |
| `push()` | `push()` |
| `pop()` removes top | `pop()` removes front |
| `top()` | `front()` / `back()` |

### Easy memory trick

**Stack = Plates → LIFO**

**Queue = Line → FIFO**

---

# 18. Priority Queue

A **priority queue** removes elements according to their **priority**, rather than simply insertion order.

By default, C++ provides a **max-heap priority queue**.

That means the **largest element comes out first**. Pasted text

### Creating Max Heap

```cpp
priority_queue<int> pq;
```

Insert:

```cpp
pq.push(10);
pq.push(30);
pq.push(20);
```

Conceptually:

```text
30 ← highest priority
20
10
```

```cpp
cout << pq.top();
```

Output:

```text
30
```

Then:

```cpp
pq.pop();
```

Next top:

```text
20
```

---

# 19. Min Heap

For a **minimum priority queue**:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Example:

```cpp
pq.push(30);
pq.push(10);
pq.push(20);
```

Now:

```text
10 ← highest priority
20
30
```

```cpp
cout << pq.top();
```

Output:

```text
10
```

### Remember

```text
priority_queue<int>
        ↓
   MAX HEAP

priority_queue<int, vector<int>, greater<int>>
        ↓
   MIN HEAP
```

---

# 20. Set

A `set` stores **unique elements**.

If you insert the same element multiple times, it appears only once. Pasted text

```cpp
set<int> s;

s.insert(5);
s.insert(5);
s.insert(10);
```

Result:

```text
5 10
```

The duplicate `5` is ignored.

### Important properties

- Stores unique values.
- Elements are automatically sorted.
- Duplicate values are not stored.

---

# 21. Set Example

```cpp
set<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
s.insert(10);
```

Output:

```text
10 20 30
```

Even though `10` was inserted twice, it appears only once.

---

# 22. `find()` in Set

```cpp
auto it = s.find(20);
```

If `20` exists, iterator points to it.

If it doesn't exist:

```cpp
it == s.end()
```

Example:

```cpp
if(s.find(20) != s.end())
{
    cout << "Present";
}
else
{
    cout << "Not Present";
}
```

---

# 23. `count()` in Set

`count()` checks whether an element exists.

```cpp
if(s.count(20))
    cout << "Present";
```

For a normal `set`, the result is generally:

```text
0 → absent
1 → present
```

---

# 24. `erase()`

Removes an element.

```cpp
s.erase(20);
```

Example:

```text
Before:
10 20 30

After erase(20):
10 30
```

---

# 25. Set vs Unordered Set

### `set`

- Unique elements.
- Sorted order.
- Usually implemented using a balanced tree.
- Operations are generally **O(log n)**.

### `unordered_set`

- Unique elements.
- No sorted-order guarantee.
- Hash-table based.
- Average insertion/search/deletion: **O(1)**.

Pasted text

### Exam table

| Feature | set | unordered_set |
|---|---|---|
| Duplicate | No | No |
| Order | Sorted | No guaranteed order |
| Typical implementation | Balanced BST | Hash table |
| Search | O(log n) | O(1) average |

---

# 26. Map

A `map` stores data in **key-value pairs**.

Think:

```text
Key → Value
```

Example:

```text
1 → Yanshika
2 → Rahul
3 → Aman
```

Pasted text

### Creating a map

```cpp
map<int, string> m;
```

### Inserting

```cpp
m[1] = "Yanshika";
m[2] = "Rahul";
m[3] = "Aman";
```

---

# 27. Important Property of Map

**Every key is unique.**

Example:

```cpp
m[1] = "A";
m[1] = "B";
```

The second assignment changes the value associated with key `1`.

Final:

```text
1 → B
```

A key cannot map to multiple different values in a normal `map`.

However, **different keys can have the same value**.

Example:

```text
1 → Apple
2 → Apple
```

is valid.

---

# 28. Accessing Map

```cpp
cout << m[1];
```

Output:

```text
Yanshika
```

You can also iterate:

```cpp
for(auto x : m)
{
    cout << x.first << " " << x.second << endl;
}
```

Here:

```text
x.first  = key
x.second = value
```

---

# 29. Map is Ordered

A normal `map` keeps its keys in **sorted order**.

Example:

```cpp
map<int,string> m;

m[3] = "C";
m[1] = "A";
m[2] = "B";
```

Iteration gives:

```text
1 A
2 B
3 C
```

---

# 30. Unordered Map

`unordered_map` stores key-value pairs using hashing.

```cpp
unordered_map<int,string> m;
```

Properties:

- Unique keys.
- No guaranteed sorted order.
- Average search/insertion/deletion: **O(1)**.

---

# 31. Map vs Unordered Map

| Feature | map | unordered_map |
|---|---|---|
| Key uniqueness | Yes | Yes |
| Order | Sorted by key | No guaranteed order |
| Implementation | Balanced tree | Hash table |
| Search | O(log n) | O(1) average |
| Insertion | O(log n) | O(1) average |
| Deletion | O(log n) | O(1) average |

---

# 32. STL Algorithms

STL also provides ready-made algorithms.

To use many standard algorithms:

```cpp
#include <algorithm>
```

The lecture introduces algorithms such as sorting, reversing, swapping, rotating and searching. Pasted text

---

# 33. `sort()`

Sorts elements.

```cpp
vector<int> v = {5,2,7,1,3};

sort(v.begin(), v.end());
```

Result:

```text
1 2 3 5 7
```

### Complexity

```text
O(n log n)
```

---

# 34. `reverse()`

Reverses a range.

```cpp
reverse(v.begin(), v.end());
```

Example:

```text
Before:
1 2 3 4 5

After:
5 4 3 2 1
```

---

# 35. `swap()`

Swaps two values.

```cpp
int a = 10;
int b = 20;

swap(a,b);
```

After:

```text
a = 20
b = 10
```

---

# 36. `rotate()`

Rotates elements within a range.

Example:

```text
Before:
1 2 3 4 5
```

Rotate left by one:

```text
2 3 4 5 1
```

Example:

```cpp
rotate(v.begin(), v.begin()+1, v.end());
```

---

# 37. `binary_search()`

Checks whether an element exists in a **sorted range**.

```cpp
vector<int> v = {1,2,3,4,5,6,7};

bool found = binary_search(v.begin(), v.end(), 6);
```

Result:

```text
true
```

### Important

The range must be sorted for `binary_search()` to give the intended result.

Complexity:

```text
O(log n)
```

---

# 38. `find()`

Searches for an element.

```cpp
auto it = find(v.begin(), v.end(), 5);
```

If found:

```cpp
it != v.end()
```

If not found:

```cpp
it == v.end()
```

Example:

```cpp
if(find(v.begin(), v.end(), 5) != v.end())
    cout << "Found";
```

---

# 39. `max_element()` and `min_element()`

### Maximum

```cpp
auto it = max_element(v.begin(), v.end());
```

### Minimum

```cpp
auto it = min_element(v.begin(), v.end());
```

To print:

```cpp
cout << *max_element(v.begin(), v.end());
```

The `*` dereferences the iterator.

---

# 40. `count()`

Counts how many times a value appears in a range.

```cpp
vector<int> v = {1,2,2,3,2,4};

cout << count(v.begin(), v.end(), 2);
```

Output:

```text
3
```

---

# 41. `lower_bound()`

Returns an iterator pointing to the **first position where the value can be inserted without violating sorted order**.

For a sorted vector:

```cpp
vector<int> v = {1,2,4,4,6,8};

auto it = lower_bound(v.begin(), v.end(), 4);
```

It points to the **first `4`**.

---

# 42. `upper_bound()`

Returns an iterator pointing to the **first element greater than the given value**.

```cpp
auto it = upper_bound(v.begin(), v.end(), 4);
```

For:

```text
1 2 4 4 6 8
```

it points to:

```text
6
```

### Easy difference

```text
lower_bound(x)
↓
first element >= x

upper_bound(x)
↓
first element > x
```

---

# 43. Important Complexity Table

| Data Structure / Operation | Complexity |
|---|---:|
| Array random access | O(1) |
| Vector random access | O(1) |
| Vector `push_back()` | O(1) amortized |
| Stack push | O(1) |
| Stack pop | O(1) |
| Stack top | O(1) |
| Queue push | O(1) |
| Queue pop | O(1) |
| Set search | O(log n) |
| Set insert | O(log n) |
| Set erase | O(log n) |
| Map search | O(log n) |
| Map insert | O(log n) |
| Map erase | O(log n) |
| Unordered set search | O(1) average |
| Unordered map search | O(1) average |
| `sort()` | O(n log n) |
| `binary_search()` | O(log n) |

---

# 44. Most Important Exam Differences

### Array vs Vector

```text
Array  → fixed size
Vector → dynamic size
```

### Vector vs List

```text
Vector → contiguous memory + random access
List   → linked nodes + no random access
```

### Stack vs Queue

```text
Stack → LIFO
Queue → FIFO
```

### Queue vs Deque

```text
Queue → insertion generally at back, removal from front
Deque  → insertion/removal from both ends
```

### Set vs Map

```text
Set → stores unique values

Map → stores unique keys + associated values
```

### Set vs Unordered Set

```text
Set → sorted
Unordered set → no guaranteed order
```

### Map vs Unordered Map

```text
Map → sorted keys
Unordered map → no guaranteed order
```

### Max Heap vs Min Heap

```text
Max Heap → largest element has highest priority
Min Heap → smallest element has highest priority
```

---

# 45. One Complete STL Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {5, 2, 8, 1, 3};

    sort(v.begin(), v.end());

    cout << "Sorted: ";

    for(int x : v)
        cout << x << " ";

    cout << endl;

    if(binary_search(v.begin(), v.end(), 3))
        cout << "3 Found";

    return 0;
}
```

### Output

```text
Sorted: 1 2 3 5 8
3 Found
```

---

## ⭐ Last-Minute Revision Sheet

Memorize these before the exam:

```text
STL
│
├── Containers
│   │
│   ├── Sequence
│   │   ├── Array
│   │   ├── Vector
│   │   ├── Deque
│   │   └── List
│   │
│   ├── Container Adaptors
│   │   ├── Stack
│   │   ├── Queue
│   │   └── Priority Queue
│   │
│   └── Associative
│       ├── Set
│       └── Map
│
└── Algorithms
    ├── sort()
    ├── reverse()
    ├── swap()
    ├── find()
    ├── count()
    ├── binary_search()
    ├── min_element()
    ├── max_element()
    ├── lower_bound()
    ├── upper_bound()
    └── rotate()
```

**Most important concepts to practice:** `vector`, `deque`, `list`, `stack`, `queue`, `priority_queue`, `set`, `map`, and the common STL algorithms. The uploaded lecture specifically covers these structures and their common operations. Pasted text Pasted text Pasted text Pasted text

If you're preparing for a **C++ exam**, these are the definitions + examples + differences I'd prioritize memorizing.