Yes. I’ll keep the same **exam-focused style as the container notes**, but here the key is to understand the **capability hierarchy**, what each iterator can do, which containers provide it, and **why particular algorithms require particular iterator categories**.

The QBs specifically ask the five classic categories, their operations, container examples, and why algorithms such as `sort()` and `find()` have different iterator requirements. QB_UNIT1_Unit2-PPS QB_UNIT1_Unit2-PPS QB2 reinforces this through algorithm requirements. QUESTION BANK 2

# STL ITERATORS — COMPLETE EXAM NOTES

---

# 1. What is an Iterator?

## Definition

An **iterator** is an object that is used to **traverse and access elements of an STL container**.

It behaves somewhat like a pointer.

Example:

```cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();

cout << *it;       // 10

++it;

cout << *it;       // 20
```

Here:

```text
it
↓
10 → 20 → 30
```

---

# Why are iterators called a generalization of pointers?

Because both can:

- Refer to an element
- Be dereferenced using `*`
- Be incremented
- Be used to traverse data

Example:

```cpp
int arr[] = {10,20,30};

int* p = arr;

cout << *p;
++p;
```

Iterator:

```cpp
vector<int> v = {10,20,30};

auto it = v.begin();

cout << *it;
++it;
```

So we can think:

```text
Pointer
   ↓
works mainly with memory arrays

Iterator
   ↓
generalized pointer
   ↓
works with many STL containers
```

---

# 2. Iterator Hierarchy

This is the **most important thing to memorize**.

```text
                 Random Access
                      ↑
                Bidirectional
                      ↑
                   Forward
                      ↑
                    Input
```

But remember:

**Output iterator is a separate write-oriented category**, not simply a stronger version of Input Iterator.

A useful capability view:

```text
Input
  ↓
Forward
  ↓
Bidirectional
  ↓
Random Access
```

Each step adds capabilities.

---

# 3. Input Iterator

## Definition

An **Input Iterator** is an iterator that can be used to **read elements sequentially**, generally in one direction.

Main operations:

```cpp
++it
*it
it == other
it != other
```

---

## Example

```cpp
vector<int> v = {10,20,30};

auto it = v.begin();

cout << *it;

++it;

cout << *it;
```

---

## Important characteristics

```text
Read → YES
Write → Not the defining capability
Forward movement → YES
Backward movement → NO
Random access → NO
```

---

## Typical container example

A `vector` iterator can support Input Iterator operations, although it is actually a much stronger **Random Access Iterator**.

The important point is:

> A stronger iterator category can satisfy the requirements of a weaker one.

---

## Algorithm example

`std::find()` requires only an **Input Iterator**.

```cpp
vector<int> v = {10,20,30};

auto it = find(v.begin(), v.end(), 20);

if (it != v.end())
    cout << "Found";
```

QB2 specifically asks why `find()` only needs Input Iterators. QUESTION BANK 2

---

# 4. Output Iterator

## Definition

An **Output Iterator** is used to **write values sequentially** to a destination.

Main operation:

```cpp
*it = value;
```

and:

```cpp
++it;
```

---

## Example

Conceptually:

```cpp
*it = 100;
++it;
```

It is mainly concerned with:

```text
Write → YES
Read → Not its defining purpose
Forward movement → YES
Backward → NO
Random access → NO
```

---

# Input vs Output Iterator

This is directly based on the QB short question. QB_UNIT1_Unit2-PPS

| Feature | Input Iterator | Output Iterator |
|---|---|---|
| Read | ✅ | ❌ defining capability |
| Write | ❌ defining capability | ✅ |
| `*it` | Read value | Write value |
| `++it` | Yes | Yes |
| Backward | No | No |
| Random access | No | No |

### Easy memory trick

```text
INPUT  → take data IN → READ
OUTPUT → send data OUT → WRITE
```

---

# 5. Forward Iterator

## Definition

A **Forward Iterator** supports reading/writing and allows **multiple passes through a range while moving only forward**.

It supports:

```cpp
*it
++it
== 
!=
```

and can be reused for multiple passes.

---

## Important difference from Input Iterator

Input iterators are generally **single-pass**.

Forward iterators support **multi-pass traversal**.

### Think:

```text
Input:
A → B → C
     cannot depend on going back

Forward:
A → B → C
A → B → C
```

You can traverse the same range again.

---

## Container example

`std::forward_list` provides Forward Iterators.

```cpp
forward_list<int> f = {10,20,30};

for (auto it = f.begin(); it != f.end(); ++it)
    cout << *it << ' ';
```

---

## Operations

```text
*it
++it
it == other
it != other
```

No:

```cpp
--it       // ❌
it + 5     // ❌
it[5]      // ❌
```

---

# 6. Bidirectional Iterator

## Definition

A **Bidirectional Iterator** supports movement in **both forward and backward directions**.

It supports:

```cpp
++it
--it
*it
```

---

## Container examples

### `std::list`

```cpp
list<int> l = {10,20,30};

auto it = l.begin();

++it;       // 20
--it;       // 10
```

### `std::set`

`set` iterators are also bidirectional.

---

## What it cannot do

It cannot perform arbitrary jumps like:

```cpp
it += 5;    // ❌
it[5];      // ❌
```

because it doesn't support random access.

---

# 7. Random Access Iterator

## Definition

A **Random Access Iterator** supports all bidirectional operations plus **jumping directly to positions using arithmetic**.

This is the strongest of the five classic categories listed in your QB.

---

## Operations

```cpp
++it
--it

it + n
it - n

it += n
it -= n

it[n]

it1 - it2

it1 < it2
it1 > it2
it1 <= it2
it1 >= it2
```

---

## Example

```cpp
vector<int> v = {10,20,30,40,50};

auto it = v.begin();

cout << it[3];       // 40

it += 2;

cout << *it;         // 30
```

---

# Why is random access O(1)?

For contiguous structures such as `vector`, the address can be calculated directly.

Conceptually:

```text
address = start + index × element_size
```

So:

```cpp
v.begin() + 1000
```

doesn't need to move through 1000 elements one by one.

---

# Container examples

| Iterator Category | Example |
|---|---|
| Input | `istream_iterator` / stronger container iterators |
| Output | `ostream_iterator` |
| Forward | `forward_list` |
| Bidirectional | `list`, `set`, `map` |
| Random Access | `array`, `vector`, `deque` |

**Important:** Some containers provide a stronger category than the minimum category shown. For example, a `vector` iterator is Random Access, so it also satisfies algorithms requiring Input/Forward/Bidirectional capabilities.

---

# ⭐ ITERATOR CAPABILITY TABLE

Memorize this.

| Operation | Input | Output | Forward | Bidirectional | Random Access |
|---|:---:|:---:|:---:|:---:|:---:|
| Read `*it` | ✅ | — | ✅ | ✅ | ✅ |
| Write `*it = x` | — | ✅ | ✅ | ✅ | ✅ |
| `++it` | ✅ | ✅ | ✅ | ✅ | ✅ |
| `--it` | ❌ | ❌ | ❌ | ✅ | ✅ |
| `it + n` | ❌ | ❌ | ❌ | ❌ | ✅ |
| `it - n` | ❌ | ❌ | ❌ | ❌ | ✅ |
| `it[n]` | ❌ | ❌ | ❌ | ❌ | ✅ |
| `it1 - it2` | ❌ | ❌ | ❌ | ❌ | ✅ |
| `<`, `>` etc. | ❌ | ❌ | ❌ | ❌ | ✅ |

---

# ⭐ The Golden Hierarchy

Think of the categories as adding powers:

```text
INPUT
 │
 │ + multi-pass
 ↓
FORWARD
 │
 │ + backward movement
 ↓
BIDIRECTIONAL
 │
 │ + jumping / arithmetic
 ↓
RANDOM ACCESS
```

Output is separate because its defining role is **writing**.

---

# 8. Why does `std::sort()` require Random Access?

This is a **very important QB question**.

QB1 asks:

> Why cannot `std::list` iterators be passed to `std::sort()`? What is the alternative? QB_UNIT1_Unit2-PPS

And QB2 asks why `sort()` requires Random Access while `find()` only requires Input. QUESTION BANK 2

## `std::sort()`

```cpp
sort(v.begin(), v.end());
```

`std::sort()` requires Random Access Iterators.

Why?

Sorting algorithms such as the standard implementation of `std::sort` need efficient movement/jumping within the range.

It may need operations conceptually like:

```cpp
it + n
it - n
it[n]
```

Therefore:

```text
vector → Random Access → sort() works
array  → Random Access → sort() works
deque  → Random Access → sort() works

list → Bidirectional → std::sort() ❌
```

For `list`:

```cpp
list<int> l;

l.sort();       // ✅
```

---

# 9. Why does `find()` require only Input Iterator?

Consider:

```cpp
find(v.begin(), v.end(), 20);
```

The algorithm only needs to:

```text
read current element
      ↓
compare
      ↓
++
      ↓
read next
```

It doesn't need:

```cpp
it + 100
it[100]
it -= 50
```

Therefore Input Iterator is enough.

### Exam answer

> `std::find()` performs sequential traversal and only needs to read and increment through elements, so an Input Iterator is sufficient. `std::sort()` needs Random Access Iterator capabilities for efficient positional movement.

---

# 10. Container → Iterator Category

This is **very important for exams**.

## `vector`

```text
vector
 ↓
Random Access Iterator
```

Therefore:

```cpp
it + n       ✅
it[n]        ✅
--it         ✅
```

---

## `array`

```text
array
 ↓
Random Access Iterator
```

Same capabilities as vector iterators.

---

## `deque`

```text
deque
 ↓
Random Access Iterator
```

Random access is supported.

---

## `list`

```text
list
 ↓
Bidirectional Iterator
```

Therefore:

```cpp
++it     ✅
--it     ✅

it + 5   ❌
it[5]    ❌
```

---

## `forward_list`

```text
forward_list
 ↓
Forward Iterator
```

Therefore:

```cpp
++it     ✅

--it     ❌
it + 5   ❌
```

---

## `set`

```text
set
 ↓
Bidirectional Iterator
```

---

## `map`

```text
map
 ↓
Bidirectional Iterator
```

---

# 11. Iterator Category vs Container

### Quick table

| Container | Iterator |
|---|---|
| `array` | Random Access |
| `vector` | Random Access |
| `deque` | Random Access |
| `list` | Bidirectional |
| `forward_list` | Forward |
| `set` | Bidirectional |
| `map` | Bidirectional |

This table is worth memorizing.

---

# 12. `begin()` vs `end()`

Example:

```cpp
vector<int> v = {10,20,30};

auto start = v.begin();
auto finish = v.end();
```

Conceptually:

```text
begin()
  ↓
[10] [20] [30] [end]
                  ↑
                 end()
```

### Important

`end()` does **not** point to the last element.

It points **one position after the last element**.

Therefore:

```cpp
cout << *v.end();       // ❌
```

Correct:

```cpp
cout << *(v.end() - 1);    // for random access containers
```

or:

```cpp
cout << v.back();
```

---

# 13. `cbegin()` and `cend()`

QB2 asks this explicitly. QUESTION BANK 2

### `begin()`

Returns an iterator.

### `cbegin()`

Returns a **const iterator**.

Example:

```cpp
vector<int> v = {10,20,30};

auto it = v.begin();
*it = 100;              // ✅

auto cit = v.cbegin();
// *cit = 100;          // ❌ cannot modify
```

### Why useful?

When you only want to **read**, `cbegin()`/`cend()` make that intention explicit.

---

# 14. `next()` and `prev()`

Very useful because not every iterator supports:

```cpp
it + n
```

For example, `list` doesn't have random access.

Instead:

```cpp
auto it2 = next(it, 3);
```

works with appropriate iterator categories by advancing through the iterator.

Similarly:

```cpp
auto it3 = prev(it);
```

requires an iterator that supports moving backward.

### Important distinction

```cpp
it + 3
```

requires Random Access.

But:

```cpp
next(it, 3)
```

can work with weaker iterator categories by repeatedly advancing.

---

# 15. Iterator Invalidation

This connects directly to the container questions in your QB.

## Definition

**Iterator invalidation** means an iterator that previously referred to an element becomes unusable or no longer refers to the intended element after a container operation.

Example:

```cpp
vector<int> v = {10,20,30};

auto it = v.begin();

v.push_back(40);
```

If reallocation occurs:

```text
OLD MEMORY
it → [10][20][30]

        ↓ reallocation

NEW MEMORY
    [10][20][30][40]
```

The old iterator may no longer be valid.

---

# Vector vs List

## Vector

Insertion/reallocation can invalidate iterators.

```text
push_back
   ↓
reallocation?
   ↓
YES → old iterators invalid
```

## List

Nodes are separately linked.

Erasing one node generally invalidates only iterators referring to the erased node.

Iterators to other elements remain valid.

This comparison is explicitly asked in QB1. QB_UNIT1_Unit2-PPS

---

# 16. Safe Erase Pattern

## Vector

```cpp
vector<int> v = {10,20,30,20};

for (auto it = v.begin(); it != v.end(); ) {

    if (*it == 20)
        it = v.erase(it);

    else
        ++it;
}
```

Why?

Because:

```cpp
erase(it)
```

returns an iterator pointing to the element after the erased element.

---

# 17. Common Exam Trick

### Question:

Which iterator supports:

```cpp
it += n;
it[n];
```

### Answer:

**Random Access Iterator**

QB1 directly asks this. QB_UNIT1_Unit2-PPS

Examples:

```text
vector
array
deque
```

---

# 18. Common Exam Trick

### Question:

Why can't we use `--it` with `forward_list`?

Because:

```text
forward_list
↓
singly linked
↓
only next pointer
↓
cannot move backward
```

Therefore:

```cpp
++it;       // ✅
--it;       // ❌
```

---

# 19. Common Exam Trick

### Question:

Why is `list` not Random Access?

Because its nodes are not stored contiguously.

Suppose:

```text
10 → 20 → 30 → 40
```

To reach `40`, you generally have to follow:

```text
10 → 20 → 30 → 40
```

So arbitrary indexing is not O(1).

---

# 20. Common Exam Trick

### Question:

Why can `vector` provide Random Access?

Because its elements are stored contiguously.

Conceptually:

```text
1000   1004   1008   1012
 ↓      ↓      ↓      ↓
[10]   [20]   [30]   [40]
```

Address of an element can be calculated directly.

---

# ⭐ Iterator Categories — Final Comparison

| Category | Read | Write | Forward | Backward | Jump | Example |
|---|---|---|---|---|---|---|
| Input | ✅ | — | ✅ | ❌ | ❌ | `istream_iterator` |
| Output | — | ✅ | ✅ | ❌ | ❌ | `ostream_iterator` |
| Forward | ✅ | ✅ | ✅ | ❌ | ❌ | `forward_list` |
| Bidirectional | ✅ | ✅ | ✅ | ✅ | ❌ | `list`, `set`, `map` |
| Random Access | ✅ | ✅ | ✅ | ✅ | ✅ | `vector`, `array`, `deque` |

---

# 🔥 EXAM QUESTIONS YOU SHOULD PREPARE

From your QB, these are the highest-priority iterator questions:

### 2 Marks

**1.** Differentiate Input Iterator and Output Iterator. QB_UNIT1_Unit2-PPS

**2.** Which iterator supports `it += n` and `it[n]`?  
→ Random Access Iterator. QB_UNIT1_Unit2-PPS

**3.** Why can't `list` iterators be passed to `std::sort()`?  
→ `list` provides Bidirectional, while `sort()` requires Random Access. QB_UNIT1_Unit2-PPS

**4.** What is an iterator? Why is it a generalization of a pointer? QUESTION BANK 2

**5.** Difference between `begin()/end()` and `cbegin()/cend()`. QUESTION BANK 2

---

# 🔥 6-MARK QUESTIONS

### 1. Iterator Category Hierarchy

Explain:

```text
Input
Output
Forward
Bidirectional
Random Access
```

with:

- capabilities
- operations
- container examples

This is directly in QB1. QB_UNIT1_Unit2-PPS

---

### 2. Why do algorithms require different iterators?

Explain:

```text
find()
↓
Input Iterator
```

versus:

```text
sort()
↓
Random Access Iterator
```

QB2 explicitly asks this comparison. QUESTION BANK 2

---

### 3. Iterator invalidation

Compare:

```text
vector
vs
list
```

and show safe deletion during traversal. QB_UNIT1_Unit2-PPS

---

# 🧠 SUPER-FAST MEMORY METHOD

Remember:

```text
INPUT
→ Read

OUTPUT
→ Write

FORWARD
→ Read/Write + Forward + Multi-pass

BIDIRECTIONAL
→ Forward + Backward

RANDOM ACCESS
→ Bidirectional + Jump
```

And containers:

```text
array        → RANDOM
vector       → RANDOM
deque        → RANDOM

list         → BIDIRECTIONAL
set          → BIDIRECTIONAL
map          → BIDIRECTIONAL

forward_list → FORWARD
```

And algorithms:

```text
find()
↓
Input is enough

sort()
↓
Random Access required
```

That last distinction is **one of the most likely conceptual questions from your QB**.