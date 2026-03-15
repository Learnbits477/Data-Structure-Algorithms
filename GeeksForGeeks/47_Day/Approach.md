# Vertical Tree Traversal

## Approach: Breadth-First Search (BFS) with Unordered Map (Optimized)

### Intuition
To traverse the tree vertically, we assign a horizontal distance (HD) to each node. The root node has an HD of 0. Moving to the left child decreases the HD by 1, and moving to the right child increases the HD by 1. Since nodes at the same HD should be ordered as they appear in the level order traversal, doing a BFS (Level Order Traversal) ensures that nodes higher up in the tree are visited first.

To prevent **Time Limit Exceeded (TLE)** on strict test cases, we avoid using a `std::map` which inserts entries in $O(\log N)$ time and adds extra overhead. Instead, we use a `std::unordered_map` which provides $O(1)$ average time complexity for insertions. We keep track of the `min_hd` and `max_hd` during our traversal so we can iterate sequentially from the leftmost vertical line to the rightmost vertical line in $O(N)$ time.

We also use memory optimizations by pre-allocating memory and `std::move`ing data, avoiding expensive unnecessary vector copies which can easily cause TLE for trees with $10^5$ nodes.

### Steps
1. Create an `unordered_map<int, vector<int>> mp` to group node values by their HD.
2. Maintain two variables, `min_hd` and `max_hd`, initialized to 0, to track the bounds of the horizontal distances.
3. Create a queue `q` for level order traversal, pushing the root node with HD 0.
4. While the queue is not empty:
   - Pop the front element `(node, hd)`.
   - Update `min_hd = min(min_hd, hd)` and `max_hd = max(max_hd, hd)`.
   - Insert `node->data` into `mp[hd]`.
   - If `node->left` exists, push `(node->left, hd - 1)`.
   - If `node->right` exists, push `(node->right, hd + 1)`.
5. Iterate from `min_hd` to `max_hd` and move the `vector<int>` from the map to our final answer.

### Complexity
- **Time Complexity:** $O(N)$ average time. The BFS takes $O(N)$ time. Map insertions are $O(1)$ on average. Iterating from `min_hd` to `max_hd` takes $O(N)$ time.
- **Space Complexity:** $O(N)$ to store nodes in the queue for BFS and to store all nodes inside the hash map.
