## **2️⃣ Heap k-th Smallest Comparison**

# Heap k-th Smallest Comparison

Check whether the k-th smallest element in a binary heap is greater than or equal to a given number x, using **O(k) time** and pruning unneeded subtrees.

- **Source:** Custom implementation inspired by advanced heap exercises
- **File:** [`main.cpp`](main.cpp)
- **Usage:** Compile and run the standalone C++ program.
- **Features:**
  - Efficient heap traversal without fully extracting elements.
  - Prunes subtrees that cannot contain relevant elements.
  - Outputs "YES" if the k-th smallest element is ≥ x, otherwise "NO".

**Notes:**
- Input: first n (heap size), then n heap elements, then k and x.
- Uses 0-based indexing for array-based heap representation.
