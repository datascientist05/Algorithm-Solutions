#include <iostream>
using namespace std;

/*
    PROBLEM 3-17:
    Give an O(n) algorithm that determines whether a given n-node
    binary tree is height-balanced.

    Approach:
    ---------
    - We perform a single post-order DFS traversal.
    - For each node, we compute the height of its left and right subtrees.
    - If at any point the height difference is more than 1, 
      we return a special value (-1) to signal that the tree is unbalanced.
    - Once this signal is returned, we propagate it upward immediately 
      without further checks.
    - This ensures that each node is visited exactly once, giving O(n) time.
*/

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
    Computes the height of the tree rooted at 'tree'.
    Returns:
      - height of the subtree if it is balanced
      - -1 if the subtree is unbalanced
*/
int height(TreeNode* tree) {
    if (!tree)
        return 0; // Base case: empty tree has height 0

    int hLeft = height(tree->left);
    int hRight = height(tree->right);

    if (hLeft == -1 || hRight == -1) // propagate unbalanced signal
        return -1;

    if (abs(hLeft - hRight) > 1) // check balance at current node
        return -1;

    return 1 + max(hLeft, hRight); // return height if balanced
}

/*
    Wrapper function to check if a tree is balanced.
    Calls the height() function and interprets -1 as "unbalanced".
*/
bool isBalanced(TreeNode* root) {
    return height(root) != -1;
}

/* Example usage */
int main() {
    // Create a simple balanced tree:
    //      1
    //     / \
    //    2   3
    TreeNode* balancedRoot = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    // Create an unbalanced tree:
    //      1
    //     /
    //    2
    //   /
    //  3
    TreeNode* unbalancedRoot = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);

    cout << "Balanced tree is balanced? " << (isBalanced(balancedRoot) ? "Yes" : "No") << endl;
    cout << "Unbalanced tree is balanced? " << (isBalanced(unbalancedRoot) ? "Yes" : "No") << endl;

    // Clean up dynamically allocated memory
    delete balancedRoot->left;
    delete balancedRoot->right;
    delete balancedRoot;
    delete unbalancedRoot->left->left;
    delete unbalancedRoot->left;
    delete unbalancedRoot;

    return 0;
}
