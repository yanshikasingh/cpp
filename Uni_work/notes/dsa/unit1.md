Yes — if your exam topic is specifically **“Linear Search and Binary Search Techniques and their Complexity Analysis”**, then you should focus on the **definition, algorithm/working, example, complexity, and comparison** rather than the extra coding details.

# Linear Search and Binary Search Techniques & Complexity Analysis

## 1. Linear Search

### Definition
**Linear Search** is a searching technique in which each element of an array is compared sequentially with the target element until the element is found or the entire array is checked.

It is also called **Sequential Search**.

### Example

Array:

```text
10   25   40   55   70
```

Search for `55`:

```text
10 ≠ 55
25 ≠ 55
40 ≠ 55
55 = 55 → Found
```

So, the element is found at **index 3**.

### Algorithm

1. Start from the first element.
2. Compare the current element with the target.
3. If they are equal, return the position.
4. Otherwise, move to the next element.
5. Repeat until the element is found or the array ends.
6. If the element is not found, report unsuccessful search.

### Important Feature

Linear search **does not require the array to be sorted**.

---

## Complexity Analysis of Linear Search

For `n` elements:

### Best Case — O(1)

The element is found at the first position.

```text
[50, 20, 30, 40, 60]
 ↑
Target
```

Only **1 comparison** is required.

**Best Case = O(1)**

### Worst Case — O(n)

The element is at the last position or is not present.

```text
[10, 20, 30, 40, 50]
                 ↑
              Target
```

All `n` elements may need to be checked.

**Worst Case = O(n)**

### Average Case — O(n)

On average, approximately `n/2` elements are checked.

Since constants are ignored:

**Average Case = O(n)**

### Space Complexity

Only a few variables are required.

**Space Complexity = O(1)**

---

# 2. Binary Search

### Definition

**Binary Search** is a searching technique that repeatedly divides a **sorted array into two halves** and determines which half may contain the target element.

### Main Condition ⭐

> **The array must be sorted before applying Binary Search.**

---

## Example

Array:

```text
10   20   30   40   50   60   70
```

Search for `60`.

Initially:

```text
low = 0
high = 6
```

Calculate:

```text
mid = (low + high) / 2
    = (0 + 6) / 2
    = 3
```

`arr[3] = 40`

Since:

```text
60 > 40
```

The target must be in the **right half**.

So:

```text
low = mid + 1
```

Now search:

```text
50   60   70
```

Again calculate `mid`.

Eventually:

```text
arr[mid] = 60
```

Therefore, **element found**.

---

# Binary Search Algorithm

1. Set `low = 0`.
2. Set `high = n - 1`.
3. Calculate:

```text
mid = (low + high) / 2
```

4. Compare `arr[mid]` with the target.

### If:

```text
arr[mid] == target
```

→ Element found.

### If:

```text
target > arr[mid]
```

Search the right half:

```text
low = mid + 1
```

### If:

```text
target < arr[mid]
```

Search the left half:

```text
high = mid - 1
```

5. Continue while:

```text
low <= high
```

6. If `low > high`, the element is not present.

---

# Complexity Analysis of Binary Search

The important idea is that the search space is **halved after every comparison**.

For example:

```text
n → n/2 → n/4 → n/8 → n/16 → ...
```

Therefore:

### Best Case — O(1)

The target is found at the first `mid`.

### Worst Case — O(log n)

The array keeps getting divided into halves until the element is found or the search space becomes empty.

### Average Case — O(log n)

The search generally requires logarithmic comparisons.

### Space Complexity

For **iterative binary search**:

**O(1)**

---

# 3. Linear vs Binary Search

| Feature | Linear Search | Binary Search |
|---|---|---|
| Searching method | Sequentially checks elements | Repeatedly divides array |
| Sorted array required | **No** | **Yes** |
| Best Case | O(1) | O(1) |
| Average Case | O(n) | O(log n) |
| Worst Case | O(n) | O(log n) |
| Space | O(1) | O(1) iterative |
| Suitable for | Small/unsorted data | Large/sorted data |

---

## ⭐ Exam-Focused Summary

### Linear Search
> Linear search checks each element one by one until the required element is found or the entire array is traversed.

**Requirement:** No sorting required  
**Best:** O(1)  
**Average:** O(n)  
**Worst:** O(n)  
**Space:** O(1)

### Binary Search
> Binary search repeatedly divides a sorted array into two halves and continues searching only in the half that can contain the target.

**Requirement:** Array must be sorted  
**Best:** O(1)  
**Average:** O(log n)  
**Worst:** O(log n)  
**Space:** O(1) iterative

### 🔥 Remember

```text
Linear  → One by one → O(n)

Binary  → Half by half → O(log n)
```

**Most important exam point:**  
If the array is **unsorted → Linear Search**.  
If the array is **sorted and fast searching is needed → Binary Search**.