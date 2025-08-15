## **5️⃣ Height-Balanced Binary Tree Checker**

# Determine if a binary tree is height-balanced in O(n) time
This C++ program checks whether a given binary tree is height-balanced.  
A tree is height-balanced if, for every node, the difference between the heights of its left and right subtrees is at most 1.

- **Source:** Problem 3-17, *The Algorithm Design Manual* by Steven S. Skiena (p. 104)
- **File:** [`main.cpp`](main.cpp)
- **Usage:** Compile and run the standalone C++ program.
- **Features:**
  - Checks balance of any binary tree in O(n) time using single post-order traversal.
  - Uses O(n) space for recursion stack.
  - Returns "Yes" if the tree is balanced, "No" otherwise.
  - Includes example trees in main() for quick testing.
  - Demonstrates both balanced and unbalanced cases.

**Notes:**
- The program uses a helper function height() that:
     - Returns the height of the subtree if balanced.
     - Returns -1 if the subtree is unbalanced (propagates the signal upward).
- The wrapper function isBalanced() interprets the result of height() to return a boolean.
- Dynamic memory allocated for the trees is cleaned up at the end of main()
