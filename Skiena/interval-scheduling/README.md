## **4️⃣ Interval Scheduling (Activity Selection)**

# Interval Scheduling (Activity Selection Problem)

Check whether the k-th smallest element in a binary heap is greater than or equal to a given number x, using **O(k) time** and pruning unneeded subtrees.

Select the maximum number of non-overlapping activities using a **greedy algorithm** (sort by finishing time).

- **Source:** Classic greedy algorithm exercise  
- **File:** [`main.cpp`](main.cpp)
- **Usage:** Compile and run the standalone C++ program.
- **Features:**
  - Sorts activities by earliest finishing time.
  - Selects the maximum number of compatible activities.
  - Outputs the total number and the selected intervals.

**Notes:**
- Input format: first n (number of activities), then n pairs of start and finish times.
- Output lists selected activities in order of selection.
