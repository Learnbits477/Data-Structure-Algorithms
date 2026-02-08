# Approach: Balanced Binary Tree

## Intuition

A binary tree is balanced if, for every node, the height difference between its left and right subtrees is at most 1.

We can optimize the height calculation by checking for balance during the same traversal. Instead of just returning the height, we can return a pair containing both the height and a boolean indicating if the subtree is balanced. This allows us to propagate the balance status up the tree.

## Algorithm

1. Define a helper function `isBalancedHelper(node)` that returns `pair<int, bool>`.
    - **First element (int):** The height of the subtree rooted at `node`.
    - **Second element (bool):** Whether the subtree rooted at `node` is balanced.
2. **Base Case:** If `node` is `NULL`, return `{0, true}` (height 0, balanced).
3. **Recursive Step:**
    - Call `isBalancedHelper` on the left child to get `leftSubtree`.
    - Call `isBalancedHelper` on the right child to get `rightSubtree`.
4. **Calculations:**
    - `height = max(leftSubtree.first, rightSubtree.first) + 1`
    - `isBalanced = leftSubtree.second && rightSubtree.second && abs(leftSubtree.first - rightSubtree.first) <= 1`
5. Return `{height, isBalanced}`.
6. The main function `isBalanced(root)` simply calls the helper and returns the boolean part of the pair.

## Time Complexity

- **O(N)**: We visit every node exactly once.

## Space Complexity

- **O(N)**: Stack space for recursion in the worst case (skewed tree). O(log N) for a balanced tree.
