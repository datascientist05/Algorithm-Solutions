# Skiena Exercises

This repository contains solutions to exercises from *The Algorithm Design Manual* by Steven Skiena.  
All exercises are organized in separate subfolders for clarity.

---

## Folder Structure

- `interactive_tic_tac_toe/`  
  **Interactive Tic-Tac-Toe (n × n board)**  
  - Implements an n × n Tic-Tac-Toe game using O(n) space and O(1) time per move.  
  - Ensures safe input and interactive board display.  
  - [File: main.cpp](interactive_tic_tac_toe/main.cpp)

- `heap-kth-smallest/`  
  **Heap k-th Smallest**  
  - Determines if the k-th smallest element in a min-heap is ≥ x using efficient recursive traversal.  
  - [File: main.cpp](heap-kth-smallest/main.cpp)

- `interval-scheduling/`  
  **Interval Scheduling (Activity Selection)**  
  - Greedy algorithm to select the maximum number of non-overlapping intervals.  
  - [File: main.cpp](interval-scheduling/main.cpp)

- `graph-traversal/`  
  **Graph Traversal: BFS & DFS**  
  - BFS and DFS traversal of graphs, with cycle detection for directed graphs.  
  - Adjacency list representation.  
  - [File: main.cpp](graph-trasversal/main.cpp)

- `height-balanced-tree/`  
  **Height-Balanced Binary Tree Checker**  
  - Determines whether a binary tree is height-balanced in O(n) time using a single post-order traversal.  
  - Includes example balanced and unbalanced trees for demonstration.   
  - [File: main.cpp](height-balanced-tree/main.cpp)

---

## Usage

1. Navigate to the folder of the exercise you want to run.  
2. Compile the C++ code, for example:
   ```bash
   g++ main.cpp -o program
   ./program
3. Follow the input instructions in each program.
