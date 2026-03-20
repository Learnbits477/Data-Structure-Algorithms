# Approach for Predecessor and Successor

## Intuition
The problem requires us to find the in-order predecessor and successor of a given key in a Binary Search Tree (BST). 
- The **in-order predecessor** is the largest value in the BST that is strictly less than the given key.
- The **in-order successor** is the smallest value in the BST that is strictly greater than the given key.

Because the given tree is a Binary Search Tree, we can efficiently find these values by traversing the tree symmetrically without needing to do a full in-order traversal.

## Algorithm
We can search for the predecessor and successor in two independent traversals or one single traversal. Doing it in two separate simple loops is clean and has the same time complexity \(O(H)\).

1. **Find Successor:**
   - Initialize `suc = NULL` and start `curr = root`.
   - While `curr` is not `NULL`:
     - If `curr->key > key`, it means the current node is a potential successor. We update `suc = curr` and search in the left subtree for a smaller, closer successor by moving `curr = curr->left`.
     - Else (`curr->key <= key`), the potential successor must be in the right subtree. Move `curr = curr->right`.

2. **Find Predecessor:**
   - Initialize `pre = NULL` and start `curr = root`.
   - While `curr` is not `NULL`:
     - If `curr->key < key`, it means the current node is a potential predecessor. We update `pre = curr` and search in the right subtree for a larger, closer predecessor by moving `curr = curr->right`.
     - Else (`curr->key >= key`), the potential predecessor must be in the left subtree. Move `curr = curr->left`.

## Complexity
- **Time Complexity:** $O(H)$, where $H$ is the height of the BST. In the worst case (skewed tree), it will be $O(N)$ where $N$ is the number of nodes. In average balanced trees, it's $O(\log N)$.
- **Space Complexity:** $O(1)$, since we traverse iteratively and only use a few pointers without any extra space or recursion stack.
