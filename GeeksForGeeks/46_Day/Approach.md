# Approach for Top View of Binary Tree

## Problem Understanding
We need to find the nodes visible when looking at a binary tree from the top. For nodes that overlap at the same horizontal distance, only the one closest to the root (highest level) should be visible. We need to print them ordered from leftmost to rightmost.

## Algorithm
1. This problem can be solved effectively using Breadth-First Search (BFS) combined with a map.
2. We keep track of the horizontal distance (HD) of each node from the root. 
   - Root has HD = 0.
   - For a left child, its HD will be `parent's HD - 1`.
   - For a right child, its HD will be `parent's HD + 1`.
3. We use a queue to perform BFS since BFS guarantees that we encounter nodes level by level (top to bottom).
4. The queue will store pairs of `(Node*, int hd)`.
5. We use a map, say `std::map<int, int>`, to store the first node's value we encounter for every particular horizontal distance. The key represents the horizontal distance, and the value represents the node's data.
   - Because we do a level-order traversal, the first node we encounter at any given HD is guaranteed to be the topmost one.
   - We insert into the map only if the horizontal distance is not already present in it.
6. Since `std::map` keeps the keys sorted automatically, traversing the map from begin() to end() will yield the nodes from leftmost HD to rightmost HD, which is exactly the order required in the output.

## Complexity Analysis
- **Time Complexity:** O(N log N) where N is the number of nodes. Each node is processed once. Map operations (insertions/lookups) take O(log N) time. This can be optimized to O(N) by using an unordered_map to track the values and a min/max variable to track the range of HDs.
- **Space Complexity:** O(N). The queue can hold up to N/2 nodes at the leaf level, and the map will store at most N elements (in the case of a skewed tree).
