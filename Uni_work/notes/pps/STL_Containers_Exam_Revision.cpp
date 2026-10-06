/*
===============================================================
STL CONTAINERS - EXAM REVISION FILE
Based on Question Bank 1 + Question Bank 2
===============================================================

Containers covered:
1. std::array
2. std::vector
3. std::deque
4. std::list
5. std::forward_list
6. std::stack
7. std::queue
8. std::priority_queue
9. std::set
10. std::map
11. std::unordered_map

NOTE:
- This is a REVISION file, not a collection of separate programs.
- Uncomment/run the relevant sections while revising.
- Complexity comments are included for exam revision.
===============================================================
*/

#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <stdexcept>
using namespace std;

int main()
{
    // =========================================================
    // 1. std::array
    // =========================================================
    /*
       DEFINITION:
       std::array is a fixed-size sequence container.
       Its elements are stored contiguously.

       array<int, 5>:
       - size fixed at compile time
       - random access O(1)
       - duplicates allowed
       - cannot resize
    */

    array<int, 5> a = {10, 20, 30, 40, 50};

    cout << "ARRAY\n";
    cout << a[2] << '\n';      // O(1), no bounds checking
    cout << a.at(2) << '\n';   // O(1), bounds checked
    cout << a.front() << '\n'; // first element
    cout << a.back() << '\n';  // last element
    cout << a.size() << '\n';  // fixed number of elements

    a.fill(0); // fill every element with 0

    // IMPORTANT EXAM CASE:
    // a[100] -> no bounds checking (undefined behavior if invalid)
    // a.at(100) -> throws std::out_of_range

    try
    {
        cout << a.at(100);
    }
    catch (const out_of_range &e)
    {
        cout << "Invalid array index\n";
    }

    // =========================================================
    // 2. std::vector
    // =========================================================
    /*
       DEFINITION:
       vector is a dynamic array with contiguous storage.

       BEST WHEN:
       - dynamic size is required
       - fast random access is required

       IMPORTANT:
       size()     = number of elements currently stored
       capacity() = allocated storage available before reallocation

       Access: O(1)
       push_back: amortized O(1)
       pop_back: O(1)
       middle/front insert/delete: O(n)
    */

    vector<int> v = {10, 20, 30};

    cout << "\nVECTOR\n";
    cout << "size = " << v.size() << '\n';
    cout << "capacity = " << v.capacity() << '\n';

    v.push_back(40);    // add at end
    v.emplace_back(50); // construct/add at end

    cout << v[2] << '\n';    // O(1)
    cout << v.at(2) << '\n'; // O(1), bounds checked

    v.insert(v.begin() + 1, 15); // middle insertion -> O(n)
    v.erase(v.begin() + 1);      // erase one element -> O(n) in general
    v.pop_back();                // remove last -> O(1)

    /*
       EXAM CASE: push_back() vs emplace_back()

       push_back(obj)
       -> adds an already-created object.

       emplace_back(args...)
       -> constructs the object directly at the end.

       For int, practical difference is tiny.
       For user-defined objects, emplace_back can avoid an
       extra temporary construction.
    */

    /*
       EXAM CASE: VECTOR ITERATOR INVALIDATION

       If push_back() causes reallocation:
           old iterators/references/pointers become invalid.

       Insertion/erase can also invalidate iterators at/after
       the affected position.

       SAFE ERASE PATTERN:
    */

    vector<int> nums = {10, 20, 30, 20, 40};

    for (auto it = nums.begin(); it != nums.end();)
    {
        if (*it == 20)
            it = nums.erase(it); // erase returns next valid iterator
        else
            ++it;
    }

    /*
       DO NOT do this blindly:

       for (auto it = v.begin(); it != v.end(); ++it)
           if (...) v.erase(it);

       because erase invalidates the erased iterator.
    */

    // =========================================================
    // 3. std::deque
    // =========================================================
    /*
       DEFINITION:
       deque = double-ended queue.

       It supports efficient insertion/deletion at BOTH ends.

       Random access: O(1)
       push_front: O(1)
       push_back: O(1)
       pop_front: O(1)
       pop_back: O(1)
       middle insertion: O(n)

       INTERNAL IDEA:
       Unlike vector, deque does not require one single
       contiguous memory block. It generally manages multiple
       memory blocks internally.

       EXAM CASE:
       Why front insertion is O(1)?
       -> No need to shift all existing elements like vector.
    */

    deque<int> d = {20, 30, 40};

    cout << "\nDEQUE\n";

    d.push_front(10); // O(1)
    d.push_back(50);  // O(1)

    cout << d.front() << '\n';
    cout << d.back() << '\n';
    cout << d[2] << '\n'; // random access O(1)

    d.pop_front(); // O(1)
    d.pop_back();  // O(1)

    // =========================================================
    // 4. std::list
    // =========================================================
    /*
       DEFINITION:
       list is a DOUBLY LINKED LIST.

       Concept:
       [prev | data | next] <-> [prev | data | next]

       Elements are NOT contiguous.

       Random access: not O(1)
       Search: O(n)
       Insert/delete using a valid iterator: O(1)

       BEST WHEN:
       - frequent insertion/deletion
       - iterator to position is already available

       IMPORTANT:
       Finding the position may still take O(n).
    */

    list<int> l = {10, 20, 30};

    cout << "\nLIST\n";

    l.push_front(5); // O(1)
    l.push_back(40); // O(1)

    auto lit = l.begin();
    ++lit; // points to 10

    l.insert(lit, 7); // O(1) once iterator is known

    /*
       EXAM CASE:
       std::sort(l.begin(), l.end()) is INVALID.

       Why?
       std::sort requires Random Access Iterators.
       list provides Bidirectional Iterators.

       Correct:
           l.sort();
    */

    l.sort(); // list's own sorting function

    // SAFE LIST ERASE
    for (auto it = l.begin(); it != l.end();)
    {
        if (*it == 20)
            it = l.erase(it);
        else
            ++it;
    }

    // =========================================================
    // 5. std::forward_list
    // =========================================================
    /*
       DEFINITION:
       forward_list is a SINGLY LINKED LIST.

       Node:
       [data | next]

       Compared with list:
       list       -> prev + data + next
       forward_list -> data + next

       Therefore forward_list can use less memory per node.

       It supports forward traversal only.
       No operator[].
       No backward traversal.

       Insert/delete after a known position: O(1)
       Search: O(n)
    */

    forward_list<int> fl = {10, 20, 30};

    cout << "\nFORWARD_LIST\n";

    fl.push_front(5); // O(1)

    auto fit = fl.before_begin();

    // Insert after before_begin(), i.e. at the front.
    fl.insert_after(fit, 1); // O(1)

    // Erase after a known iterator.
    fl.erase_after(fit); // O(1)

    // =========================================================
    // 6. std::stack
    // =========================================================
    /*
       DEFINITION:
       stack is a CONTAINER ADAPTOR following LIFO:
       Last In, First Out.

       Default underlying container:
       std::deque

       Main functions:
       push(), pop(), top(), empty(), size()

       IMPORTANT:
       pop() does NOT return the removed element.
       Use top() first, then pop().
    */

    stack<int> st;

    cout << "\nSTACK\n";

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top = " << st.top() << '\n'; // 30

    int topValue = st.top();
    st.pop();

    cout << "Removed = " << topValue << '\n';

    /*
       LIFO EXAMPLES:
       - Undo operations
       - Function call stack
       - Backtracking
    */

    // =========================================================
    // 7. std::queue
    // =========================================================
    /*
       DEFINITION:
       queue is a CONTAINER ADAPTOR following FIFO:
       First In, First Out.

       Default underlying container:
       std::deque

       Main functions:
       push(), pop(), front(), back(), empty(), size()
    */

    queue<int> q;

    cout << "\nQUEUE\n";

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front = " << q.front() << '\n'; // 10
    cout << "Back  = " << q.back() << '\n';  // 30

    q.pop(); // removes 10

    /*
       FIFO EXAMPLES:
       - Printer queue
       - Waiting line
       - BFS
    */

    // =========================================================
    // 8. std::priority_queue
    // =========================================================
    /*
       DEFINITION:
       priority_queue is a container adaptor where the element
       with highest priority is available at top().

       DEFAULT:
       max-heap

       priority_queue<int>:
       largest element appears at top.

       Main functions:
       push(), pop(), top(), empty(), size()
    */

    priority_queue<int> maxPQ;

    cout << "\nPRIORITY_QUEUE - MAX HEAP\n";

    maxPQ.push(10);
    maxPQ.push(50);
    maxPQ.push(20);

    cout << "Top = " << maxPQ.top() << '\n'; // 50

    /*
       MIN-HEAP CASE:

       priority_queue<int, vector<int>, greater<int>>

       Smallest element becomes top().
    */

    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(20);

    cout << "Min-heap top = " << minPQ.top() << '\n'; // 10

    /*
       CUSTOM PRIORITY QUEUE - QB STYLE

       Task with id and priority.
       Here smaller priority number = higher priority.
    */

    struct Task
    {
        int id;
        int priority;
    };

    struct CompareTask
    {
        bool operator()(const Task &a, const Task &b) const
        {
            return a.priority > b.priority;
        }
    };

    priority_queue<Task, vector<Task>, CompareTask> tasks;

    tasks.push({1, 30});
    tasks.push({2, 10});
    tasks.push({3, 20});

    cout << "Highest priority task ID = "
         << tasks.top().id << '\n'; // 2

    // =========================================================
    // 9. std::set
    // =========================================================
    /*
       DEFINITION:
       set stores UNIQUE elements in SORTED ORDER.

       Common implementation:
       self-balancing BST (commonly Red-Black Tree).

       Search: O(log n)
       Insert: O(log n)
       Delete: O(log n)

       Duplicate insertions are ignored.
    */

    set<int> s;

    cout << "\nSET\n";

    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10); // duplicate -> ignored

    for (int x : s)
        cout << x << ' '; // 10 20 30

    cout << '\n';

    /*
       LOOKUP:
       find() returns iterator to element or end().
    */

    auto sit = s.find(20);

    if (sit != s.end())
        cout << "20 found\n";

    /*
       SET CASE:
       Need unique + sorted data?
       -> set

       Need duplicate + sorted data?
       -> multiset (not required in this main list, but
          commonly asked as an extension in QB2).
    */

    // =========================================================
    // 10. std::map
    // =========================================================
    /*
       DEFINITION:
       map stores KEY-VALUE pairs.

       Keys are UNIQUE and maintained in SORTED ORDER.

       Common implementation:
       self-balancing BST (commonly Red-Black Tree).

       Search/insert/delete: O(log n)
    */

    map<int, string> m;

    cout << "\nMAP\n";

    m[101] = "Yanshika";
    m[102] = "Aman";
    m[103] = "Riya";

    for (const auto &p : m)
        cout << p.first << " -> " << p.second << '\n';

    /*
       IMPORTANT EXAM TRAP:

       map::operator[] can INSERT a missing key.

       Example:

           map<int,string> m;
           cout << m[500];

       If 500 doesn't exist, m[500] creates it with
       the default value of string (empty string).

       Therefore DON'T use operator[] just to check existence.

       BAD lookup:
           if (m[key] == "abc") ...

       BETTER:
           auto it = m.find(key);
           if (it != m.end()) ...
    */

    if (m.find(500) == m.end())
        cout << "500 does not exist\n";

    /*
       operator[] IS appropriate when you intentionally want
       insertion/update, for example:

           m[104] = "Neha";
    */

    m[104] = "Neha";

    // =========================================================
    // 11. std::unordered_map
    // =========================================================
    /*
       DEFINITION:
       unordered_map stores KEY-VALUE pairs using a HASH TABLE.

       Keys are unique.
       No sorted-order guarantee.

       Average:
       search  -> O(1)
       insert  -> O(1)
       delete  -> O(1)

       Worst case:
       O(n)

       Why?
       Hash collisions can cause many elements to end up in
       the same bucket.

       Important terms:
       - hash function
       - bucket
       - collision
       - load factor
       - rehashing
    */

    unordered_map<string, int> um;

    cout << "\nUNORDERED_MAP\n";

    um["apple"] = 5;
    um["banana"] = 10;
    um["orange"] = 7;

    cout << um["apple"] << '\n';

    /*
       HASH COLLISION IDEA:

       Different keys can produce the same bucket index.

       key A -> hash -> bucket 2
       key B -> hash -> bucket 2

       This is called a collision.

       A common collision-handling approach is chaining.
    */

    /*
       LOAD FACTOR:

       Rough idea:
           load factor = number of elements / number of buckets

       Higher load factor -> more collisions can occur.

       Rehashing creates/uses a new bucket arrangement to keep
       the hash table efficient.
    */

    /*
       IMPORTANT:
       unordered_map does NOT maintain sorted key order.

       If sorted keys are required:
           use map

       If fast average lookup is more important and ordering
       is unnecessary:
           use unordered_map
    */

    // =========================================================
    // FINAL EXAM CHEAT SHEET
    // =========================================================
    /*
    =============================================================
    CONTAINER CHOICE
    =============================================================

    Fixed-size array
        -> std::array

    Dynamic array + fast random access
        -> std::vector

    Fast insertion/deletion at BOTH ends + random access
        -> std::deque

    Frequent insertion/deletion + bidirectional traversal
        -> std::list

    Singly linked list + lower node memory
        -> std::forward_list

    LIFO
        -> std::stack

    FIFO
        -> std::queue

    Highest/lowest priority first
        -> std::priority_queue

    Unique + sorted values
        -> std::set

    Unique keys + sorted key-value pairs
        -> std::map

    Unique keys + fast average lookup + no sorting requirement
        -> std::unordered_map


    =============================================================
    IMPORTANT COMPLEXITIES
    =============================================================

    array:
        random access                 O(1)

    vector:
        random access                 O(1)
        push_back                     amortized O(1)
        front/middle insert           O(n)

    deque:
        random access                 O(1)
        push_front / push_back        O(1)

    list:
        insert/delete with iterator   O(1)
        search                        O(n)
        random access                 NOT O(1)

    forward_list:
        insert/delete after iterator  O(1)
        search                        O(n)
        random access                 NOT supported

    set:
        search/insert/delete          O(log n)

    map:
        search/insert/delete          O(log n)

    unordered_map:
        average search/insert/delete  O(1)
        worst case                    O(n)


    =============================================================
    MOST IMPORTANT EXAM TRAPS
    =============================================================

    1. vector::size() != vector::capacity()

       size     = elements currently stored
       capacity = allocated storage

    2. list cannot use std::sort()

       std::sort needs Random Access Iterator.
       list has Bidirectional Iterator.

       Use:
           list.sort();

    3. map[key] can INSERT a missing key.

       For lookup:
           map.find(key)

    4. priority_queue is MAX-HEAP by default.

       Min-heap:
           priority_queue<int, vector<int>, greater<int>>

    5. stack::pop() does NOT return the removed value.

       Correct:
           int x = st.top();
           st.pop();

    6. vector insertion/erase can invalidate iterators.

       Safe erase:
           it = v.erase(it);

    7. list is NOT random access.

       No:
           l[3]

    8. forward_list is singly linked.

       No backward traversal.

    9. set:
           unique + sorted

       map:
           unique keys + sorted keys

       unordered_map:
           hash table + no ordering guarantee

    10. deque is NOT the same as vector.
        deque supports efficient insertion/deletion at both ends.
    */

    // =========================================================
    // QUICK COMPARISON TABLE (as comments for revision)
    // =========================================================
    /*
    Container          Main idea
    -------------------------------------------------------------
    array              fixed + contiguous
    vector             dynamic + contiguous
    deque              double-ended + random access
    list               doubly linked list
    forward_list       singly linked list
    stack              LIFO adaptor
    queue              FIFO adaptor
    priority_queue     priority/max-heap adaptor
    set                unique + sorted
    map                unique key + sorted key/value
    unordered_map      hash table + average O(1) lookup
    */

    return 0;
}
