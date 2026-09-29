# C++ STL — Full Overview

## 1. Overview

The teacher gives a basic overview of the **C++ STL (Standard Template Library)** and explains the major parts that will be covered in upcoming lectures.

The main parts discussed are:

1. Containers
2. Iterators
3. Algorithms
4. Comparators
5. Nested containers
6. Important STL functions and techniques

The teacher emphasizes that STL provides many **predefined and well-implemented components**, which can reduce a large amount of code to only a few lines.

---

## 2. Main Parts of STL

### 2.1 Containers

Containers are described as **data structures provided inside STL**.

The teacher divides the important containers into different categories.

### Sequence Containers

Examples mentioned include:

* `vector`
* Other sequence-container implementations

The teacher explains that these containers maintain elements in a sequential manner.

### Ordered Containers

The teacher discusses containers such as:

* `map`
* `multimap`
* `set`
* `multiset`

These containers maintain their values in an ordered manner, such as ascending or descending order.

### Unordered Containers

The teacher also mentions:

* `unordered_map`
* `unordered_set`

These are discussed as another category of containers.

### Important Point

The teacher makes it clear that STL contains many more containers, but the containers discussed in the course are the ones considered important from the programming perspective.

---

## 3. Nested Containers

STL containers can also be used inside other containers.

Examples mentioned by the teacher include:

* `vector` inside `map`
* `pair` inside `set`
* Nested combinations of containers

At first, these combinations may appear complicated, but the teacher explains that they become easier once the working of individual containers is understood.

### Teacher's Intuition

The important idea is to first understand how the individual containers work. Once that is clear, more complex combinations of containers can be used in programming problems.

---

## 4. Iterators

The teacher introduces **iterators** as something similar to pointers.

With ordinary pointers:

* A pointer can point to the address of a variable.
* It can be used to access another variable through its address.

For containers, iterators are used to point to elements of the container.

The teacher describes them as being similar to pointers, but specifically implemented for working with container elements.

### Pointer vs Iterator

| Concept  | Teacher's Explanation                                              |
| -------- | ------------------------------------------------------------------ |
| Pointer  | Used to point to the address of a variable.                        |
| Iterator | Similar to a pointer and used to point to elements of a container. |

---

## 5. Continuous and Non-Continuous Storage

The teacher discusses how different containers can have different ways of storing their elements.

Some containers have elements implemented in a continuous manner, while in other containers the elements may not be stored continuously.

The teacher states that this difference is important for understanding why operations such as insertion behave differently for different containers.

The upcoming lectures are intended to explain:

* Continuous vs. non-continuous storage
* Why insertion in `vector` has certain characteristics
* Why similar operations behave differently in other containers

---

## 6. Algorithms

Algorithms are presented as an important part of STL.

Many complex and commonly required algorithms have already been implemented inside C++ STL. Instead of writing the complete implementation manually, these predefined algorithms can be used directly.

The teacher emphasizes that these implementations are already optimized and can make programming problems easier.

---

## 7. Binary Search and Related Algorithms

The teacher mentions that STL contains implementations related to searching, including:

* Binary search
* Lower bound
* Upper bound

These algorithms are useful when working with containers and can provide efficient searching operations.

The teacher also connects these algorithms with time complexity and explains that their implementations are designed to be efficient.

---

## 8. Comparators

Comparators are introduced as an important STL concept, especially for sorting and other operations.

A comparator allows the programmer to define **how elements should be compared**.

The teacher explains that custom comparison can be used when the required ordering is more complicated than ordinary ascending or descending order.

### Custom Ordering

A comparator can be used to specify:

* Ascending order
* Descending order
* Ordering according to the first value
* Ordering according to the second value
* More complex ordering conditions

For example, when dealing with two values, the sorting condition can be based on either the first value or the second value.

---

## 9. Common STL Algorithms Mentioned

The teacher mentions several algorithms that can be directly used with containers.

### `max_element`

Used to find the maximum element.

### `min_element`

Used to find the minimum element.

### `reverse`

Used to reverse the elements.

### `count`

Used to count occurrences of an element inside a container.

The teacher emphasizes that instead of manually writing the logic for these operations, the predefined STL algorithms can be used directly.

---

## 10. Other Algorithmic Operations

The teacher also mentions operations such as:

* Finding maximum values
* Finding minimum values
* Reversing elements
* Counting elements
* Finding the position of an element
* Other predefined operations

The overall purpose is to avoid repeatedly writing implementations for common operations when STL already provides them.

---

## 11. STL as a Programming Tool

The teacher describes the predefined algorithms and containers as useful tools that can significantly reduce the amount of code required.

Instead of implementing a commonly required operation manually, the programmer can use the corresponding STL implementation.

This is one of the major advantages emphasized throughout the lecture.

---

## 12. Topics to Be Covered in Upcoming Lectures

The teacher indicates that the upcoming lectures will go into more detail about:

* Containers
* Nested containers
* Iterators
* Continuous and non-continuous storage
* Insertion behavior
* Algorithms
* Comparators
* Searching-related algorithms
* Other important STL algorithms

These topics are intended to make programming problems easier to solve using STL.

---

## 13. Important Points

* STL provides predefined implementations that can reduce the amount of code required.
* Containers are an important part of STL.
* Containers can be divided into different categories.
* `vector`, `map`, `set`, `multimap`, `multiset`, `unordered_map`, and `unordered_set` are mentioned.
* Containers can be nested inside other containers.
* Iterators are similar to pointers and are used with container elements.
* STL provides many predefined algorithms.
* `lower_bound` and `upper_bound` are mentioned in relation to searching.
* Comparators can be used to define custom ordering.
* Algorithms such as maximum, minimum, reverse, and count operations can be directly used.
* The teacher emphasizes using the existing STL implementations instead of repeatedly writing common operations manually.

---

## 14. Quick Revision

### STL Main Components

```text
STL
│
├── Containers
│   ├── Sequence Containers
│   ├── Ordered Containers
│   └── Unordered Containers
│
├── Iterators
│
└── Algorithms
    └── Comparators / Custom Ordering
```

### Remember

* **Containers** → store/manage collections of elements.
* **Iterators** → used to point to elements of containers.
* **Algorithms** → predefined operations that can be applied to containers.
* **Comparators** → help define custom ordering.
* **Nested containers** → containers can be used inside other containers.
* STL can significantly reduce the amount of code required for common programming operations.








# C++ STL — Pairs and Vectors

## 1. `pair` in C++

A `pair` is an STL utility that stores **two related values together**.

The two values can have:

* The same data type
* Different data types
* User-defined types
* Other STL containers

For example:

```cpp
pair<int, string> p;
```

Here:

* `first` → stores the `int`
* `second` → stores the `string`

A `pair` is useful whenever two values logically belong together, such as:

```text
Student ID + Student Name
City + PIN Code
Index + Value
Key + Associated Value
```

The source emphasizes using `pair` to maintain a relationship between two pieces of data.

---

## 2. Declaring a `pair`

### Basic Syntax

```cpp
pair<data_type1, data_type2> variable_name;
```

Example:

```cpp
pair<int, string> p;
```

This creates a pair containing:

```text
first  → int
second → string
```

The two types do not have to be identical.

```cpp
pair<int, double> p1;
pair<string, int> p2;
pair<char, bool> p3;
```

A pair can also contain more complex types, including containers.

---

# 3. Initializing a `pair`

There are several ways to initialize a pair.

### Method 1 — Assignment

```cpp
pair<int, string> p;

p.first = 10;
p.second = "ABC";
```

### Method 2 — Brace Initialization

```cpp
pair<int, string> p = {10, "ABC"};
```

This is a concise and commonly used form.

### Method 3 — `make_pair()`

```cpp
pair<int, string> p;

p = make_pair(10, "ABC");
```

`make_pair()` constructs a pair from the supplied values.

---

# 4. Accessing Elements of a `pair`

A pair has two publicly accessible members:

```cpp
p.first
p.second
```

Example:

```cpp
#include <iostream>
#include <utility>
using namespace std;

int main()
{
    pair<int, string> p = {10, "ABC"};

    cout << p.first << endl;
    cout << p.second << endl;

    return 0;
}
```

Output:

```text
10
ABC
```

### Important

For a `pair`:

```text
first  → first stored value
second → second stored value
```

There is no indexing such as:

```cpp
p[0]   // Incorrect
p[1]   // Incorrect
```

Use `.first` and `.second`.

---

# 5. Modifying a `pair`

The values stored in a pair can be modified directly.

```cpp
pair<int, string> p = {10, "ABC"};

p.first = 20;
p.second = "XYZ";
```

Now:

```text
p.first  = 20
p.second = "XYZ"
```

---

# 6. Why Use `pair`?

Suppose an address consists of:

```text
City
PIN Code
```

These two values are related.

Instead of maintaining separate variables:

```cpp
string city;
int pin;
```

they can be grouped:

```cpp
pair<string, int> address;
```

Example:

```cpp
pair<string, int> address = {"Indore", 452001};
```

Now both pieces of information remain associated.

This becomes especially useful when storing many related records.

---

# 7. `pair` with Loops

A collection of pairs can be processed using a loop.

For example:

```cpp
vector<pair<int, string>> students = {
    {1, "Aman"},
    {2, "Riya"},
    {3, "Yanshika"}
};

for (int i = 0; i < students.size(); i++)
{
    cout << students[i].first << " "
         << students[i].second << endl;
}
```

Output:

```text
1 Aman
2 Riya
3 Yanshika
```

This demonstrates an important relationship:

```text
pair
   ↓
stores two related values

vector
   ↓
stores multiple elements

vector<pair<...>>
   ↓
stores multiple records, where each record contains two related values
```

---

# 8. Passing a `pair` to a Function

A pair can be passed to a function like any other object.

```cpp
void printPair(pair<int, string> p)
{
    cout << p.first << " " << p.second << endl;
}
```

Usage:

```cpp
pair<int, string> p = {10, "ABC"};

printPair(p);
```

However, passing by value creates a copy.

If copying should be avoided, pass the pair by reference:

```cpp
void printPair(const pair<int, string>& p)
{
    cout << p.first << " " << p.second << endl;
}
```

This is particularly useful when the object is large.

---

# 9. Copying a `pair`

A pair can be copied using assignment:

```cpp
pair<int, string> p1 = {10, "ABC"};

pair<int, string> p2 = p1;
```

Now `p2` contains its own values.

Changing `p2` does not change `p1`:

```cpp
p2.first = 50;
```

`p1.first` remains `10`.

---

# 10. Introduction to `vector`

A `vector` is an STL container that stores elements in a **dynamically sized sequence**.

Unlike a normal fixed-size array, a vector can automatically grow or shrink as elements are inserted or removed.

Basic declaration:

```cpp
vector<int> v;
```

This creates an empty vector of integers.

The source contrasts vectors with ordinary arrays and emphasizes that the vector's size can change dynamically.

---

# 11. Declaring a Vector

### Empty Vector

```cpp
vector<int> v;
```

### Vector with a Fixed Initial Size

```cpp
vector<int> v(5);
```

This creates a vector containing five `int` elements, value-initialized to `0`.

Conceptually:

```text
[0][0][0][0][0]
```

### Vector with Size and Initial Value

```cpp
vector<int> v(5, 10);
```

Conceptually:

```text
[10][10][10][10][10]
```

This is useful when the vector should initially contain repeated values.

---

# 12. Vector with an Initializer List

A vector can be initialized directly with values:

```cpp
vector<int> v = {10, 20, 30, 40, 50};
```

The vector initially contains:

```text
10 20 30 40 50
```

This provides a convenient way to create a vector with known initial elements.

---

# 13. Adding Elements — `push_back()`

The most basic way to add an element to the end of a vector is:

```cpp
push_back()
```

Example:

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);
```

The vector becomes:

```text
[10][20][30]
```

Each call adds a new element at the end.

### Syntax

```cpp
vector_name.push_back(value);
```

Example:

```cpp
v.push_back(40);
```

Result:

```text
[10][20][30][40]
```

---

# 14. Dynamic Growth of a Vector

One of the major advantages of a vector is that its number of elements can grow dynamically.

Example:

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);
v.push_back(40);
```

There is no need to manually maintain the number of currently stored elements.

The vector manages its storage internally.

---

# 15. `size()` Function

The `size()` function returns the **number of elements currently stored** in the vector.

Syntax:

```cpp
v.size();
```

Example:

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

cout << v.size();
```

Output:

```text
3
```

### Important

`size()` gives the number of actual elements currently present.

It does **not** give the amount of allocated memory/capacity.

The source specifically demonstrates obtaining the current number of elements using `size()`.

---

# 16. Accessing Vector Elements

Vector elements can be accessed using indexing:

```cpp
v[index]
```

Example:

```cpp
vector<int> v = {10, 20, 30, 40};

cout << v[0] << endl;
cout << v[1] << endl;
cout << v[2] << endl;
cout << v[3] << endl;
```

Output:

```text
10
20
30
40
```

The first element is at index `0`.

Therefore:

```text
Index:    0   1   2   3
Value:   10  20  30  40
```

---

# 17. Iterating Through a Vector

A vector can be traversed using a normal `for` loop.

```cpp
vector<int> v = {10, 20, 30, 40};

for (int i = 0; i < v.size(); i++)
{
    cout << v[i] << " ";
}
```

Output:

```text
10 20 30 40
```

The vector's current size can therefore be used as the loop boundary.

---

# 18. Removing the Last Element — `pop_back()`

The function:

```cpp
pop_back()
```

removes the **last element** from the vector.

Example:

```cpp
vector<int> v = {10, 20, 30, 40};

v.pop_back();
```

Now:

```text
10 20 30
```

### Important

`pop_back()`:

* Removes the last element.
* Does not take an argument.
* Does not return the removed element.

If you need the last value before removing it:

```cpp
int x = v.back();
v.pop_back();
```

---

# 19. `push_back()` vs `pop_back()`

| Function       | Purpose                    | Typical Complexity |
| -------------- | -------------------------- | -----------------: |
| `push_back(x)` | Adds `x` at the end        |   Amortized `O(1)` |
| `pop_back()`   | Removes last element       |             `O(1)` |
| `size()`       | Returns number of elements |             `O(1)` |

These are fundamental vector operations.

---

# 20. Copying a Vector

A vector can be copied directly:

```cpp
vector<int> v1 = {10, 20, 30};

vector<int> v2 = v1;
```

Now `v2` contains the same elements:

```text
v1 → [10][20][30]

v2 → [10][20][30]
```

But they are **independent vectors**.

If:

```cpp
v2.push_back(40);
```

then:

```text
v1 → [10][20][30]

v2 → [10][20][30][40]
```

Changing `v2` does not modify `v1`.

The source explicitly highlights this distinction between copying a vector and sharing the same underlying object.

---

# 21. Vector Copying Has a Cost

Although vector assignment is convenient:

```cpp
vector<int> v2 = v1;
```

it is **not an `O(1)` operation** when copying `n` elements.

The elements have to be copied into the new vector.

Therefore:

```text
Copying n elements → O(n)
```

This matters when vectors are large.

The source specifically warns that copying a vector is an operation with a time cost and should not be treated like a simple constant-time assignment.

---

# 22. Passing a Vector to a Function

Consider:

```cpp
void print(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
}
```

Calling:

```cpp
vector<int> v = {10, 20, 30};

print(v);
```

passes the vector **by value**.

This means a copy of the vector is created.

For a large vector, this can unnecessarily increase time and memory usage.

---

# 23. Passing a Vector by Reference

If the function only needs to read the vector, use a constant reference:

```cpp
void print(const vector<int>& v)
{
    for (int x : v)
        cout << x << " ";
}
```

Now the vector is not copied.

The function receives a reference to the original vector.

This is especially important when working with large vectors.

The source emphasizes that passing a vector by reference avoids the expensive copy operation.

---

# 24. Modifying a Vector Through Reference

If a function receives a non-const reference:

```cpp
void modify(vector<int>& v)
{
    v.push_back(100);
}
```

then modifications made inside the function affect the original vector.

Example:

```cpp
vector<int> v = {10, 20, 30};

modify(v);
```

After the function call:

```text
v → [10][20][30][100]
```

### Comparison

```cpp
vector<int> v
```

→ copy is created.

```cpp
vector<int>& v
```

→ original vector is accessed directly.

```cpp
const vector<int>& v
```

→ original vector is accessed without copying, but the function cannot modify it through that reference.

---

# 25. Vector with `pair`

A particularly useful combination is:

```cpp
vector<pair<int, string>>
```

This represents a dynamic sequence where every element contains two related values.

Example:

```cpp
vector<pair<int, string>> students;

students.push_back({1, "Aman"});
students.push_back({2, "Riya"});
students.push_back({3, "Yanshika"});
```

Conceptually:

```text
[
    {1, "Aman"},
    {2, "Riya"},
    {3, "Yanshika"}
]
```

Access:

```cpp
cout << students[0].first << endl;
cout << students[0].second << endl;
```

Output:

```text
1
Aman
```

This combination is extremely useful for representing records consisting of two related values.

---

# 26. Vector of Pairs — Traversal

Using indexing:

```cpp
for (int i = 0; i < students.size(); i++)
{
    cout << students[i].first << " "
         << students[i].second << endl;
}
```

Or using a range-based loop:

```cpp
for (const auto& student : students)
{
    cout << student.first << " "
         << student.second << endl;
}
```

---

# 27. Choosing Between Array and Vector

| Feature                     | Array   | Vector    |
| --------------------------- | ------- | --------- |
| Size                        | Fixed   | Dynamic   |
| Automatic growth            | No      | Yes       |
| `push_back()`               | No      | Yes       |
| `pop_back()`                | No      | Yes       |
| `size()` member function    | No      | Yes       |
| STL container               | No      | Yes       |
| Easy copying                | Yes     | Yes       |
| Dynamic sequence management | Limited | Excellent |

A vector is particularly useful when the number of elements is not known in advance or may change during program execution.

---

# 28. Important Vector Functions

| Function       | Purpose                               |
| -------------- | ------------------------------------- |
| `push_back(x)` | Adds `x` at the end                   |
| `pop_back()`   | Removes the last element              |
| `size()`       | Returns current number of elements    |
| `front()`      | Returns the first element             |
| `back()`       | Returns the last element              |
| `empty()`      | Checks whether the vector is empty    |
| `clear()`      | Removes all elements                  |
| `at(i)`        | Accesses element with bounds checking |

The fundamental operations emphasized here are `push_back()`, `pop_back()`, `size()`, and element access.

---

# 29. Complexity Summary

For the basic operations discussed:

| Operation                |                      Complexity |
| ------------------------ | ------------------------------: |
| Access by index `v[i]`   |                          `O(1)` |
| `size()`                 |                          `O(1)` |
| `push_back()`            |                Amortized `O(1)` |
| `pop_back()`             |                          `O(1)` |
| Copy vector              |                          `O(n)` |
| Pass vector by value     |              `O(n)` due to copy |
| Pass vector by reference | `O(1)` for the reference itself |

### Why is `push_back()` amortized `O(1)`?

Most insertions at the end are constant time. Occasionally, if the vector needs more storage, it reallocates and moves/copies its existing elements. Over many insertions, the average cost per insertion is amortized `O(1)`.

---

# 30. Important Memory Point

A vector manages its storage dynamically, but the amount of memory available to a program is still limited.

Therefore, a vector is **not unlimited**.

Its practical maximum depends on:

* Available memory
* System architecture
* Program environment
* Allocation limits
* Container implementation

Do not treat implementation-specific memory limits mentioned for a particular environment as universal C++ rules.

---

# 31. Common Mistakes

### Mistake 1 — Using indexing with `pair`

Incorrect:

```cpp
p[0]
p[1]
```

Correct:

```cpp
p.first
p.second
```

---

### Mistake 2 — Assuming `pop_back()` returns the removed value

Incorrect:

```cpp
int x = v.pop_back();
```

Correct:

```cpp
int x = v.back();
v.pop_back();
```

---

### Mistake 3 — Passing a large vector by value unnecessarily

Avoid:

```cpp
void process(vector<int> v)
```

when the function only needs to read it.

Prefer:

```cpp
void process(const vector<int>& v)
```

---

### Mistake 4 — Assuming vector copies share data

```cpp
vector<int> a = {1, 2, 3};
vector<int> b = a;
```

`a` and `b` are independent vectors.

Changing `b` does not modify `a`.

---

# 32. Pair vs Vector

These two solve different problems.

| `pair`                                       | `vector`                             |
| -------------------------------------------- | ------------------------------------ |
| Stores exactly two values                    | Stores a dynamic sequence of values  |
| Values may have different types              | Elements normally have the same type |
| Access using `.first` and `.second`          | Access using index or iterators      |
| Represents a relationship between two values | Represents a collection              |
| Example: `{ID, Name}`                        | Example: `{10, 20, 30, 40}`          |

They can also be combined:

```cpp
vector<pair<int, string>>
```

which means:

> A dynamic collection of two-value records.

---

# 33. Complete Example

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printStudents(const vector<pair<int, string>>& students)
{
    for (const auto& student : students)
    {
        cout << student.first << " "
             << student.second << endl;
    }
}

int main()
{
    vector<pair<int, string>> students;

    students.push_back({1, "Aman"});
    students.push_back({2, "Riya"});
    students.push_back({3, "Yanshika"});

    cout << "Number of students: "
         << students.size() << endl;

    printStudents(students);

    students.pop_back();

    cout << "\nAfter removing the last student:\n";

    printStudents(students);

    return 0;
}
```

### Concept demonstrated

```text
pair
  ↓
stores ID + Name

vector
  ↓
stores multiple pairs

push_back()
  ↓
adds a new record

size()
  ↓
gives number of records

pop_back()
  ↓
removes the last record

const reference
  ↓
avoids copying the vector while printing
```

---

# Quick Revision

## `pair`

```cpp
pair<int, string> p;
```

Access:

```cpp
p.first
p.second
```

Initialization:

```cpp
pair<int, string> p = {10, "ABC"};
```

or:

```cpp
p = make_pair(10, "ABC");
```

### Remember

* Stores exactly **two values**.
* The two values can have different types.
* Use `.first` and `.second`.
* Useful for maintaining relationships between two values.

---

## `vector`

Declaration:

```cpp
vector<int> v;
```

Initialization:

```cpp
vector<int> v = {10, 20, 30};
```

Add:

```cpp
v.push_back(40);
```

Remove last:

```cpp
v.pop_back();
```

Number of elements:

```cpp
v.size();
```

Access:

```cpp
v[0]
```

Copy:

```cpp
vector<int> b = a;
```

Read-only function parameter:

```cpp
void f(const vector<int>& v);
```

### Remember

* Vector is dynamically sized.
* Elements are stored in sequence.
* Random access using `v[i]` is `O(1)`.
* `push_back()` is amortized `O(1)`.
* `pop_back()` is `O(1)`.
* Copying a vector is `O(n)`.
* Passing a vector by reference avoids copying.

---

## Concept Relationship

```text
C++ STL
│
├── pair
│   └── stores two related values
│
├── vector
│   └── stores a dynamically sized sequence
│
└── vector<pair<...>>
    └── stores multiple records,
        each containing two related values
```

### One-Line Memory Trick

> **`pair` groups two related values; `vector` manages a dynamic sequence; `vector<pair<...>>` combines both to store multiple two-value records.**













# C++ STL — Nesting in Vectors

## 1. What Is a Nested Vector?

A **nested vector** is a vector whose elements are themselves vectors.

For example:

```cpp
vector<vector<int>> v;
```

Here:

* The outer `vector` stores multiple elements.
* Each element of the outer vector is another `vector<int>`.
* Therefore, each inner vector can contain a different number of integers.

Conceptually:

```text
v
│
├── [10, 20]
├── [30, 40, 50]
└── [60]
```

The important idea is:

```text
vector
   ↓
contains vectors
   ↓
vector<vector<int>>
```

The source introduces nested vectors as a natural extension of using `pair` and vectors together.

---

# 2. Declaring a Nested Vector

### Basic Syntax

```cpp
vector<vector<int>> v;
```

This initially creates an **empty outer vector**.

It does not yet contain any inner vectors.

You can think of it as:

```text
v → [ ]
```

---

# 3. Adding Inner Vectors

An entire vector can be inserted into the outer vector.

For example:

```cpp
vector<vector<int>> v;

v.push_back({1, 2});
v.push_back({3, 4, 5});
v.push_back({6});
```

Now:

```text
v
│
├── [1, 2]
├── [3, 4, 5]
└── [6]
```

Each element of the outer vector is itself a vector.

The source demonstrates inserting vectors into the outer vector using `push_back()`.

---

# 4. Initializing a Nested Vector Directly

A nested vector can also be initialized directly:

```cpp
vector<vector<int>> v =
{
    {1, 2},
    {3, 4, 5},
    {6}
};
```

This creates three inner vectors:

```text
Index 0 → [1, 2]
Index 1 → [3, 4, 5]
Index 2 → [6]
```

Notice that the inner vectors **do not need to have the same size**.

This is one of the useful properties of a nested `vector`.

---

# 5. Accessing Elements of a Nested Vector

Because there are two levels of vectors, two indices are required.

Suppose:

```cpp
vector<vector<int>> v =
{
    {10, 20},
    {30, 40, 50}
};
```

To access `30`:

```cpp
v[1][0]
```

To access `50`:

```cpp
v[1][2]
```

Conceptually:

```text
v
│
├── index 0 → [10, 20]
│              0   1
│
└── index 1 → [30, 40, 50]
               0   1   2
```

Therefore:

```text
v[outer_index][inner_index]
```

---

# 6. Understanding the Two Levels

Consider:

```cpp
vector<vector<int>> v =
{
    {1, 2},
    {3, 4, 5},
    {6, 7, 8, 9}
};
```

### First level

```cpp
v[0]
```

returns the first inner vector:

```text
[1, 2]
```

### Second level

```cpp
v[0][1]
```

returns the element at index `1` inside that inner vector:

```text
2
```

Similarly:

```cpp
v[2]
```

represents:

```text
[6, 7, 8, 9]
```

and:

```cpp
v[2][3]
```

represents:

```text
9
```

---

# 7. Printing a Nested Vector

A nested vector requires a loop for each level.

Example:

```cpp
vector<vector<int>> v =
{
    {1, 2},
    {3, 4, 5},
    {6, 7, 8}
};

for (int i = 0; i < v.size(); i++)
{
    for (int j = 0; j < v[i].size(); j++)
    {
        cout << v[i][j] << " ";
    }

    cout << endl;
}
```

Output:

```text
1 2
3 4 5
6 7 8
```

### Why are two loops required?

The outer loop moves through the **inner vectors**.

The inner loop moves through the **elements of the current inner vector**.

```text
Outer loop
    ↓
selects a vector

Inner loop
    ↓
selects elements inside that vector
```

The source demonstrates printing nested vector elements by accessing the inner vector and then its individual elements.

---

# 8. Nested Vectors with `push_back()`

A nested vector is particularly useful because inner vectors can be built dynamically.

Example:

```cpp
vector<vector<int>> v;

vector<int> a;
a.push_back(10);
a.push_back(20);

v.push_back(a);
```

Now:

```text
v
└── [10, 20]
```

Another vector can then be created:

```cpp
vector<int> b;

b.push_back(30);
b.push_back(40);
b.push_back(50);

v.push_back(b);
```

Now:

```text
v
├── [10, 20]
└── [30, 40, 50]
```

---

# 9. Taking Input for a Nested Vector

Nested vectors are useful when the number of inner vectors and their sizes are provided as input.

Suppose the input describes several vectors.

A general approach is:

```cpp
int n;
cin >> n;

vector<vector<int>> v(n);

for (int i = 0; i < n; i++)
{
    int size;
    cin >> size;

    for (int j = 0; j < size; j++)
    {
        int x;
        cin >> x;

        v[i].push_back(x);
    }
}
```

Here:

1. `n` determines the number of inner vectors.
2. Each inner vector can have its own size.
3. Values are inserted using `push_back()`.

For example, conceptually:

```text
3
2  10 20
3  30 40 50
1  60
```

produces:

```text
v
├── [10, 20]
├── [30, 40, 50]
└── [60]
```

The source specifically discusses taking the number of vectors, then taking the size and elements of each individual vector.

---

# 10. Printing Nested Vectors Using a Function

A nested vector can be passed to a function.

```cpp
void printVector(const vector<vector<int>>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }

        cout << endl;
    }
}
```

Call it using:

```cpp
printVector(v);
```

The parameter:

```cpp
const vector<vector<int>>& v
```

allows the function to access the original nested vector without making a copy.

---

# 11. Nested Vector vs Fixed-Size 2D Array

A normal two-dimensional array generally has a fixed structure:

```cpp
int arr[3][4];
```

This represents:

```text
3 rows × 4 columns
```

Every row has the same number of elements.

A nested vector:

```cpp
vector<vector<int>> v;
```

can represent:

```text
[1, 2]
[3, 4, 5]
[6]
```

The rows can have different lengths.

Therefore, a nested vector is useful when the structure is **not necessarily rectangular**.

---

# 12. Vector of Pairs

Another important nested/compound STL structure is:

```cpp
vector<pair<int, int>> v;
```

Here:

* The outer container is a vector.
* Every element of the vector is a pair.
* Each pair contains two values.

Example:

```cpp
vector<pair<int, int>> v =
{
    {1, 2},
    {3, 4},
    {5, 6}
};
```

Conceptually:

```text
v
├── pair {1, 2}
├── pair {3, 4}
└── pair {5, 6}
```

Access:

```cpp
v[0].first
v[0].second
```

The source connects vectors and pairs and emphasizes that each element can itself be a compound object.

---

# 13. Vector of Vectors of Pairs

C++ allows multiple levels of nesting.

For example:

```cpp
vector<vector<pair<int, int>>> v;
```

The structure becomes:

```text
vector
│
├── vector
│   ├── pair
│   ├── pair
│   └── pair
│
└── vector
    ├── pair
    └── pair
```

Accessing an element requires following the structure step by step.

For example:

```cpp
v[0][1].first
```

means:

1. Select the first outer vector.
2. Select the second pair inside it.
3. Select the `first` value of that pair.

The key principle is:

> **Always determine what type each level represents before deciding which operation or member to use.**

---

# 14. Choosing the Correct Operation at Each Level

Consider:

```cpp
vector<vector<int>> v;
```

Then:

```cpp
v[i]
```

is a:

```cpp
vector<int>
```

Therefore, you can use vector operations on it:

```cpp
v[i].size();
v[i].push_back(10);
v[i].pop_back();
```

But:

```cpp
v[i][j]
```

is an:

```cpp
int
```

So you cannot use vector functions on `v[i][j]`.

For example:

```cpp
v[i][j].push_back(10);   // Incorrect
```

because `v[i][j]` is an integer, not a vector.

---

# 15. The Most Important Concept: Understand the Type

For:

```cpp
vector<vector<int>> v;
```

the types at each level are:

```text
v
↓
vector<vector<int>>

v[i]
↓
vector<int>

v[i][j]
↓
int
```

For:

```cpp
vector<pair<int, int>> v;
```

the types are:

```text
v
↓
vector<pair<int, int>>

v[i]
↓
pair<int, int>

v[i].first
↓
int

v[i].second
↓
int
```

This makes nested STL structures much easier to understand.

---

# 16. Different Inner Vector Sizes

One major advantage of nested vectors is that the inner vectors can have different sizes.

Example:

```cpp
vector<vector<int>> v =
{
    {1, 2, 3},
    {4},
    {5, 6},
    {},
    {7, 8, 9, 10}
};
```

Their sizes are:

```text
v[0].size() → 3
v[1].size() → 1
v[2].size() → 2
v[3].size() → 0
v[4].size() → 4
```

Therefore, when traversing a nested vector, use:

```cpp
v[i].size()
```

for the inner loop rather than assuming every inner vector has the same size.

---

# 17. Empty Inner Vectors

An inner vector can also be empty:

```cpp
vector<vector<int>> v =
{
    {1, 2},
    {},
    {3, 4}
};
```

Here:

```cpp
v[1].size()
```

is:

```text
0
```

A loop such as:

```cpp
for (int j = 0; j < v[i].size(); j++)
```

simply executes zero times for that empty vector.

This is one reason nested vectors are flexible.

---

# 18. Adding Elements to a Specific Inner Vector

Suppose:

```cpp
vector<vector<int>> v(3);
```

This creates three empty inner vectors:

```text
v
├── []
├── []
└── []
```

You can add values independently:

```cpp
v[0].push_back(10);
v[0].push_back(20);

v[1].push_back(30);

v[2].push_back(40);
v[2].push_back(50);
v[2].push_back(60);
```

Result:

```text
v
├── [10, 20]
├── [30]
└── [40, 50, 60]
```

This demonstrates the independent dynamic nature of each inner vector.

---

# 19. Practical Uses

Nested vectors are useful when data naturally has multiple levels.

Examples include:

* Graph adjacency lists
* Rows with different numbers of elements
* Grouped data
* Dynamic matrices
* Lists of lists
* Problems where each query contains a different number of values

A common competitive-programming representation is:

```cpp
vector<vector<int>> graph;
```

where:

```text
graph[i]
```

can represent the list of elements connected to or associated with `i`.

---

# 20. Common Mistakes

### Mistake 1 — Treating a nested vector like a normal integer vector

For:

```cpp
vector<vector<int>> v;
```

this:

```cpp
cout << v[i];
```

does not print the individual integers inside the inner vector.

You need another level of traversal.

---

### Mistake 2 — Using the wrong `.size()`

For:

```cpp
vector<vector<int>> v;
```

these represent different things:

```cpp
v.size()
```

→ number of inner vectors.

```cpp
v[i].size()
```

→ number of elements inside the `i`-th inner vector.

---

### Mistake 3 — Assuming all inner vectors have equal size

This is not required:

```text
[1, 2]
[3, 4, 5]
[6]
```

Therefore, use:

```cpp
v[i].size()
```

when traversing each row.

---

### Mistake 4 — Applying an operation to the wrong level

For:

```cpp
vector<vector<int>> v;
```

`v[i]` is a vector, while `v[i][j]` is an integer.

Always identify the type before applying an operation.

---

# 21. Complete Example

```cpp
#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<vector<int>>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    vector<vector<int>> v;

    v.push_back({1, 2});
    v.push_back({3, 4, 5});
    v.push_back({6, 7, 8});

    printVector(v);

    return 0;
}
```

Output:

```text
1 2
3 4 5
6 7 8
```

---

# Quick Revision

## Nested Vector

```cpp
vector<vector<int>> v;
```

means:

> A vector whose elements are vectors of integers.

### Add an inner vector

```cpp
v.push_back({1, 2, 3});
```

### Access an inner vector

```cpp
v[i]
```

### Access an individual element

```cpp
v[i][j]
```

### Number of inner vectors

```cpp
v.size()
```

### Number of elements in the `i`-th inner vector

```cpp
v[i].size()
```

### Add to a particular inner vector

```cpp
v[i].push_back(x);
```

### Remove from a particular inner vector

```cpp
v[i].pop_back();
```

---

## Important Type Relationship

```text
vector<vector<int>> v
        │
        ├── v[i]
        │     ↓
        │   vector<int>
        │
        └── v[i][j]
              ↓
             int
```

For a vector of pairs:

```text
vector<pair<int,int>> v
        │
        └── v[i]
              ↓
           pair<int,int>
              │
          ┌───┴───┐
          ↓       ↓
       .first   .second
          ↓       ↓
         int     int
```

---

# Concept Relationship Summary

```text
STL
│
├── pair
│   └── stores two related values
│
├── vector
│   └── stores a dynamic sequence
│
├── vector<pair<...>>
│   └── dynamic sequence of pairs
│
└── vector<vector<...>>
    └── dynamic sequence of vectors
        │
        ├── each inner vector can have
        │   a different size
        │
        └── each level requires the
            appropriate access operation
```

### One-Line Memory Trick

> **In a nested vector, `v[i]` gives an inner vector, while `v[i][j]` gives an element inside that inner vector.**
