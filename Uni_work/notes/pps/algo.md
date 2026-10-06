Absolutely. I checked the **QB you provided**, especially Unit 2 Section A and the 6-mark questions. The algorithm portion is heavily focused on **differences, preconditions, return values, complexity, and small code snippets**, not just definitions. QB_UNIT1_Unit2-PPS(1)

# STL Algorithms — Exam-Oriented Notes
### `sort()`, `stable_sort()`, `find()`, `find_if()`, `count()`, `transform()`, `for_each()`, `copy()`, `remove()`, `replace()`, `reverse()`, `rotate()`, `partition()`, `binary_search()`, `lower_bound()`, `upper_bound()`, `accumulate()`

---

# 1. What are STL Algorithms?

STL algorithms are **predefined generic functions** in the `<algorithm>` or `<numeric>` headers that operate on ranges using iterators.

Most algorithms work like:

```cpp
algorithm(begin, end, ...);
```

Example:

```cpp
sort(v.begin(), v.end());
```

Think:

> **Container stores data → Iterator gives access → Algorithm processes data**

---

# 2. `sort()`

### Definition

`std::sort()` arranges elements in a range in **ascending order by default**.

```cpp
sort(v.begin(), v.end());
```

Header:

```cpp
#include <algorithm>
```

### Example

```cpp
vector<int> v = {5, 2, 8, 1, 3};

sort(v.begin(), v.end());

// 1 2 3 5 8
```

### Descending order

```cpp
sort(v.begin(), v.end(), greater<int>());
```

or:

```cpp
sort(v.begin(), v.end(),
     [](int a, int b) {
         return a > b;
     });
```

### Complexity

**O(n log n)** average/intended complexity.

### VERY IMPORTANT QB POINT

`std::sort()` requires a **Random Access Iterator**.

Therefore:

```cpp
sort(vector.begin(), vector.end()); // ✅
sort(array.begin(), array.end());   // ✅
sort(deque.begin(), deque.end());   // ✅
```

But:

```cpp
sort(list.begin(), list.end());      // ❌
```

Why?

Because `list` provides **Bidirectional Iterators**, not Random Access Iterators.

### Alternative for `list`

```cpp
list<int> l = {5, 2, 8, 1};

l.sort();    // ✅
```

This is directly asked in your QB. QB_UNIT1_Unit2-PPS(1)

---

# 3. `stable_sort()`

`stable_sort()` sorts elements while **preserving the relative order of equivalent elements**.

This is the major difference from `sort()`.

Suppose:

```cpp
{id=1, marks=80}
{id=2, marks=70}
{id=3, marks=80}
```

Sorting by marks:

### `sort()`

The two 80-mark students may change relative order.

### `stable_sort()`

```text
id 1 → 80
id 3 → 80
```

Their original relative order remains.

### Example

```cpp
stable_sort(v.begin(), v.end());
```

### Exam answer

| `sort()` | `stable_sort()` |
|---|---|
| Sorts range | Sorts range |
| Not stable | Stable |
| Equivalent elements' order not guaranteed | Preserves relative order |
| Usually preferred when stability isn't needed | Used when original order of equal elements matters |

### QB focus

Your QB directly asks:

> Explain the difference between `std::sort()` and `std::stable_sort()`. QB_UNIT1_Unit2-PPS(1)

---

# 4. `find()`

### Purpose

Searches for a **specific value**.

```cpp
find(begin, end, value);
```

Example:

```cpp
vector<int> v = {10, 20, 30, 40};

auto it = find(v.begin(), v.end(), 30);
```

If found:

```cpp
if (it != v.end())
    cout << *it;
```

If not found:

```cpp
it == v.end()
```

### Return type

Returns an **iterator** to the first matching element.

### Complexity

**O(n)**

Because it may have to inspect every element.

### Important

`find()` searches by **value**.

---

# 5. `find_if()`

`find_if()` searches according to a **condition/predicate**.

Syntax:

```cpp
find_if(begin, end, condition);
```

### QB's important case: first even number

```cpp
vector<int> v = {3, 7, 9, 12, 15};

auto it = find_if(v.begin(), v.end(),
                  [](int x) {
                      return x % 2 == 0;
                  });

if (it != v.end())
    cout << "First even = " << *it;
```

Output:

```text
First even = 12
```

### Difference

| `find()` | `find_if()` |
|---|---|
| Searches for value | Searches using condition |
| `find(..., 10)` | `find_if(..., x > 10)` |
| No predicate | Requires predicate |

QB specifically asks for `find_if()` with a lambda to find the first even number. QB_UNIT1_Unit2-PPS(1)

---

# 6. `count()`

Counts how many times a **specific value** occurs.

```cpp
count(begin, end, value);
```

Example:

```cpp
vector<int> v = {1, 2, 2, 3, 2};

int c = count(v.begin(), v.end(), 2);

cout << c;
```

Output:

```text
3
```

### Complexity

**O(n)**

---

# 7. `count_if()`

Counts elements satisfying a **condition**.

```cpp
int evenCount = count_if(
    v.begin(),
    v.end(),
    [](int x) {
        return x % 2 == 0;
    }
);
```

### Difference

| `count()` | `count_if()` |
|---|---|
| Counts exact value | Counts condition |
| `count(..., 5)` | `count_if(..., x > 5)` |

### Memory trick

> **find → value**  
> **find_if → condition**  
> **count → value**  
> **count_if → condition**

This distinction is directly in your QB. QB_UNIT1_Unit2-PPS(1)

---

# 8. `transform()`

This is one of the **most important algorithms in your QB**.

`transform()` applies an operation to elements and **stores the result**.

---

## Unary `transform()`

One input range.

Example: square every number.

```cpp
vector<int> v = {1, 2, 3, 4};
vector<int> result(4);

transform(v.begin(), v.end(),
          result.begin(),
          [](int x) {
              return x * x;
          });
```

Result:

```text
1 4 9 16
```

### Important

`transform()` normally **produces/transforms values into an output range**.

---

# 9. Binary `transform()`

Two input ranges.

Example:

```cpp
vector<int> a = {1, 2, 3};
vector<int> b = {10, 20, 30};

vector<int> result(3);

transform(a.begin(), a.end(),
          b.begin(),
          result.begin(),
          [](int x, int y) {
              return x + y;
          });
```

Result:

```text
11 22 33
```

### Formula

```text
result[i] = operation(a[i], b[i])
```

---

# 10. `for_each()`

`for_each()` executes a function on **every element**.

Example:

```cpp
vector<int> v = {1, 2, 3};

for_each(v.begin(), v.end(),
         [](int x) {
             cout << x << " ";
         });
```

Output:

```text
1 2 3
```

---

# `transform()` vs `for_each()`

This is a **6-mark QB question**. QB_UNIT1_Unit2-PPS(1)

| `transform()` | `for_each()` |
|---|---|
| Transforms/processes values | Executes an operation on each element |
| Usually produces output | Mainly performs side effects |
| Can use output iterator | Doesn't require separate output range |
| Unary or binary | One range |
| Excellent for creating modified data | Excellent for printing/actions |

### Easy memory trick

> `for_each` → **DO something**

> `transform` → **MAKE something**

---

# 11. `copy()`

Copies elements from one range to another.

```cpp
vector<int> a = {1, 2, 3, 4};
vector<int> b(4);

copy(a.begin(), a.end(), b.begin());
```

Now:

```text
b = 1 2 3 4
```

### Important

Destination must have enough space when using a normal iterator:

```cpp
vector<int> b(4);
```

Not:

```cpp
vector<int> b;

copy(a.begin(), a.end(), b.begin()); // ❌
```

Because `b` has no elements.

---

# `copy()` vs `copy_if()`

QB2 explicitly asks this distinction. QUESTION BANK 2(1)

### `copy()`

Copies **everything**.

```cpp
copy(v.begin(), v.end(), output);
```

### `copy_if()`

Copies only elements satisfying a condition.

```cpp
copy_if(v.begin(), v.end(),
        output,
        [](int x) {
            return x % 2 == 0;
        });
```

---

# 12. `remove()`

This is a **major exam trap**.

`remove()` does **NOT actually reduce the size of a vector**.

Example:

```cpp
vector<int> v = {1, 2, 2, 3, 2, 4};

remove(v.begin(), v.end(), 2);
```

Many students think the vector becomes:

```text
1 3 4
```

❌ Wrong.

`remove()` rearranges the elements and returns an iterator representing the new logical end.

---

# 13. Erase-Remove Idiom ⭐⭐⭐

This is directly asked as a **6-mark question** in your QB. QB_UNIT1_Unit2-PPS(1)

To actually delete all `2`s:

```cpp
v.erase(
    remove(v.begin(), v.end(), 2),
    v.end()
);
```

### What happens?

Suppose:

```text
1 2 2 3 2 4
```

After `remove()` conceptually:

```text
1 3 4 | ? ? ?
      ↑
   new logical end
```

Then:

```cpp
erase(new_end, v.end());
```

actually removes the unwanted tail.

### Remember

```text
remove() → rearranges
erase()   → actually removes
```

### C++20 alternative

```cpp
erase(v, 2);
```

Much simpler.

---

# 14. `replace()`

Replaces every occurrence of a specified value.

```cpp
replace(v.begin(), v.end(), 2, 99);
```

Example:

```text
Before:
1 2 3 2 4 2

After:
1 99 3 99 4 99
```

### Important difference

`replace()`:

> **changes values**

`remove()`:

> **logically removes values**

---

# 15. `reverse()`

Reverses the order of elements.

```cpp
vector<int> v = {1, 2, 3, 4, 5};

reverse(v.begin(), v.end());
```

Result:

```text
5 4 3 2 1
```

### Complexity

**O(n)**

### Use case

Reverse a sequence without manually swapping elements.

---

# 16. `rotate()`

`rotate()` shifts elements around a selected **middle/pivot position**.

Syntax:

```cpp
rotate(first, middle, last);
```

### Example

```cpp
vector<int> v = {1, 2, 3, 4, 5};

rotate(v.begin(),
       v.begin() + 2,
       v.end());
```

Result:

```text
3 4 5 1 2
```

### Visual understanding

Original:

```text
1 2 | 3 4 5
    ↑
  middle
```

After rotate:

```text
3 4 5 | 1 2
```

### Complexity

Generally **O(n)**.

### Practical use

Useful for:

- cyclic shifts
- moving elements to front
- circular scheduling
- rearranging sequences

Your QB specifically asks for the functionality, complexity and a code example showing rotation around a middle pivot. QB_UNIT1_Unit2-PPS(1)

---

# 17. `partition()`

`partition()` rearranges elements so that:

```text
elements satisfying condition
        ↓
elements not satisfying condition
```

are separated.

### Example

```cpp
vector<int> v = {1, 8, 3, 6, 2, 9};

auto it = partition(
    v.begin(),
    v.end(),
    [](int x) {
        return x % 2 == 0;
    }
);
```

After partition, all even numbers are before all odd numbers.

Possible result:

```text
2 8 6 | 3 1 9
```

**Exact order is not guaranteed.**

The returned iterator points to the first element of the second group.

### Important exam point

`partition()` does **not sort** the elements.

It only separates them according to a predicate.

---

# `partition()` vs `sort()`

```text
sort:
1 2 3 4 5 6

partition even:
2 4 6 | 1 3 5
```

Partition only cares about:

> **Which side does the element belong to?**

---

# 18. `binary_search()`

Checks whether a value exists in a **sorted range**.

```cpp
vector<int> v = {1, 3, 5, 7, 9};

bool found = binary_search(
    v.begin(),
    v.end(),
    5
);
```

Result:

```text
true
```

### Return type

```cpp
bool
```

It returns:

```text
true / false
```

### Complexity

**O(log n)** for random-access iterators.

### MOST IMPORTANT PRECONDITION

The range must already be **sorted according to the same ordering/comparator**.

QB explicitly asks this precondition. QB_UNIT1_Unit2-PPS(1)

---

# 19. `lower_bound()` ⭐⭐⭐

One of the most important algorithms in your QB.

For a sorted range:

> Returns iterator to the **first element ≥ value**.

Example:

```cpp
vector<int> v = {1, 2, 2, 2, 4, 5};

auto it = lower_bound(v.begin(), v.end(), 2);
```

Points to:

```text
1 2 2 2 4 5
  ↑
```

Index:

```text
1
```

### Think:

> **lower = first possible position**

---

# 20. `upper_bound()` ⭐⭐⭐

Returns iterator to the:

> **first element > value**

Example:

```cpp
auto it = upper_bound(v.begin(), v.end(), 2);
```

For:

```text
1 2 2 2 4 5
```

It points here:

```text
1 2 2 2 4 5
        ↑
```

Index:

```text
4
```

---

# 21. Lower vs Upper Bound

Suppose:

```text
Index:  0 1 2 3 4 5
Value:  1 2 2 2 4 5
```

For `2`:

```text
lower_bound(2) → index 1
upper_bound(2) → index 4
```

Therefore:

```text
[lower_bound, upper_bound)
```

contains all occurrences of `2`.

### Frequency

```cpp
frequency =
    upper_bound(...) - lower_bound(...);
```

So:

```text
4 - 1 = 3
```

### Duplicate index range

```text
first index = lower_bound - begin
last index  = upper_bound - begin - 1
```

Therefore:

```text
first = 1
last  = 3
```

This is **exactly the kind of analytical question your QB asks**. QB_UNIT1_Unit2-PPS(1)

---

# 22. `binary_search()` vs `lower_bound()`

Very important comparison:

| Algorithm | Returns | Purpose |
|---|---|---|
| `binary_search()` | `bool` | Is value present? |
| `lower_bound()` | iterator | First position ≥ value |
| `upper_bound()` | iterator | First position > value |

Memory trick:

```text
binary_search → YES / NO

lower_bound → first ≥ x

upper_bound → first > x
```

---

# 23. `accumulate()` ⭐⭐⭐

`accumulate()` is in:

```cpp
#include <numeric>
```

Not `<algorithm>`.

It performs aggregation over a range.

### Sum

```cpp
vector<int> v = {10, 20, 30, 40};

int sum = accumulate(
    v.begin(),
    v.end(),
    0
);
```

Result:

```text
100
```

---

# 24. How `accumulate()` works

Conceptually:

```text
initial = 0

0 + 10 = 10
10 + 20 = 30
30 + 30 = 60
60 + 40 = 100
```

So:

```cpp
accumulate(begin, end, initial);
```

means:

> Start with `initial` and repeatedly combine it with each element.

---

# 25. Custom operation with `accumulate()`

The fourth parameter is an optional **binary operation**.

```cpp
accumulate(
    begin,
    end,
    initial,
    operation
);
```

Example:

```cpp
vector<int> v = {1, 2, 3, 4};

int product = accumulate(
    v.begin(),
    v.end(),
    1,
    [](int a, int b) {
        return a * b;
    }
);
```

Result:

```text
24
```

Because:

```text
1 × 1 × 2 × 3 × 4 = 24
```

QB specifically asks what the fourth parameter represents. QB_UNIT1_Unit2-PPS(1)

---

# 26. String concatenation with `accumulate()`

Your 6-mark QB asks for string concatenation with custom delimiters. QB_UNIT1_Unit2-PPS(1)

Example:

```cpp
vector<string> names = {
    "Alice", "Bob", "Charlie"
};

string result = accumulate(
    names.begin(),
    names.end(),
    string(),
    [](string a, string b) {
        if (a.empty())
            return b;

        return a + ", " + b;
    }
);

cout << result;
```

Output:

```text
Alice, Bob, Charlie
```

---

# 27. Algorithm Complexity Cheat Sheet

| Algorithm | Typical Complexity | Main Purpose |
|---|---:|---|
| `sort()` | O(n log n) | Sort |
| `stable_sort()` | O(n log n) typical | Stable sorting |
| `find()` | O(n) | Find value |
| `find_if()` | O(n) | Find using condition |
| `count()` | O(n) | Count value |
| `count_if()` | O(n) | Count condition |
| `transform()` | O(n) | Transform elements |
| `for_each()` | O(n) | Execute operation |
| `copy()` | O(n) | Copy range |
| `remove()` | O(n) | Logical removal |
| `replace()` | O(n) | Replace values |
| `reverse()` | O(n) | Reverse |
| `rotate()` | O(n) | Rotate |
| `partition()` | O(n) | Separate by condition |
| `binary_search()` | O(log n)* | Search sorted range |
| `lower_bound()` | O(log n)* | First ≥ value |
| `upper_bound()` | O(log n)* | First > value |
| `accumulate()` | O(n) | Aggregate |

\*The classic complexity expectation is O(log n) for random-access iterators; iterator category matters.

---

# 28. The BIG Comparison Table for Exam

| Algorithm | Searches? | Changes data? | Condition? | Return |
|---|---|---|---|---|
| `find()` | ✅ | ❌ | ❌ | Iterator |
| `find_if()` | ✅ | ❌ | ✅ | Iterator |
| `count()` | ✅ | ❌ | ❌ | Count |
| `count_if()` | ✅ | ❌ | ✅ | Count |
| `transform()` | ❌ | Creates output | Function | Output iterator |
| `for_each()` | ❌ | Can perform side effects | Function | Iterator |
| `copy()` | ❌ | Creates copy | ❌ | Output iterator |
| `remove()` | ❌ | Rearranges | Value | New logical end |
| `replace()` | ❌ | ✅ | Value | `void` |
| `reverse()` | ❌ | ✅ | ❌ | `void` |
| `rotate()` | ❌ | ✅ | ❌ | Iterator |
| `partition()` | ❌ | Rearranges | Predicate | Partition point |
| `binary_search()` | ✅ | ❌ | Sorted | `bool` |
| `lower_bound()` | ✅ | ❌ | Sorted | Iterator |
| `upper_bound()` | ✅ | ❌ | Sorted | Iterator |
| `accumulate()` | ❌ | ❌ | Optional operation | Accumulated value |

---

# 29. The Most Important Exam Traps 🚨

### Trap 1 — `remove()` doesn't reduce vector size

```cpp
remove(v.begin(), v.end(), x);
```

❌ Not enough.

Correct:

```cpp
v.erase(remove(v.begin(), v.end(), x), v.end());
```

Or C++20:

```cpp
erase(v, x);
```

---

### Trap 2 — `sort()` cannot sort `list`

```cpp
sort(l.begin(), l.end()); // ❌
```

Use:

```cpp
l.sort();                 // ✅
```

Because `sort()` requires Random Access Iterator. QB_UNIT1_Unit2-PPS(1)

---

### Trap 3 — Binary search algorithms need sorted data

```cpp
binary_search(...)
lower_bound(...)
upper_bound(...)
```

require the range to be appropriately sorted.

---

### Trap 4 — `lower_bound()` is NOT "equal to"

It means:

```text
first element >= x
```

---

### Trap 5 — `upper_bound()` is NOT "greater than or equal"

It means:

```text
first element > x
```

---

### Trap 6 — `find()` vs `find_if()`

```cpp
find(..., 10);        // value
find_if(..., x > 10); // condition
```

---

### Trap 7 — `count()` vs `count_if()`

```cpp
count(..., 10);        // value
count_if(..., x > 10); // condition
```

---

### Trap 8 — `transform()` vs `for_each()`

```text
transform → produce transformed output
for_each  → perform an action
```

---

### Trap 9 — `accumulate()` header

```cpp
#include <numeric>
```

not:

```cpp
#include <algorithm>
```

---

# 30. QB Priority — What You Should Definitely Prepare

Based on the questions in your QB, I'd rank these:

### 🔥🔥🔥 VERY HIGH PRIORITY

1. **`lower_bound()` + `upper_bound()`**
2. **Erase-Remove Idiom**
3. **`transform()` vs `for_each()`**
4. **`sort()` vs `stable_sort()`**
5. **`sort()` and iterator requirement**
6. **`binary_search()` precondition**
7. **`accumulate()`**
8. **`reverse()` + `rotate()` + `partition()`**

These appear directly in the 6-mark questions. QB_UNIT1_Unit2-PPS(1)

### 🔥 HIGH PRIORITY

9. `find()` vs `find_if()`
10. `count()` vs `count_if()`
11. `copy()` vs `copy_if()`
12. `remove()` vs `replace()`

### 🟡 Also know

13. Return types
14. Complexity
15. Which algorithms require sorted data
16. Which algorithms modify the original range

---

# 31. One-Line Memory Map 🧠

```text
SORT
sort        → sort
stable_sort → sort + preserve equal-element order

SEARCH
find        → find VALUE
find_if     → find CONDITION

COUNT
count       → count VALUE
count_if    → count CONDITION

MODIFY
transform   → transform values
for_each    → perform action
copy        → copy
remove      → logical removal
replace     → replace value
reverse     → reverse
rotate      → shift around pivot
partition   → separate by condition

SORTED SEARCH
binary_search → bool
lower_bound   → first >= x
upper_bound   → first > x

AGGREGATION
accumulate → combine everything
```

### The single most useful mental model:

> **`_if` = condition**  
> **`find` = locate**  
> **`count` = count**  
> **`transform` = produce modified values**  
> **`for_each` = do something**  
> **`remove` = rearrange, not erase**  
> **`lower_bound` = ≥**  
> **`upper_bound` = >**  
> **`accumulate` = combine**

This covers the algorithm questions that are actually present in your QB, including the Section A 2-mark questions and Section B 6-mark coding/analytical questions.