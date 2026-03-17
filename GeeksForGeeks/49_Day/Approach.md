# Approach: Burning Tree

## Intuition
To find the minimum time required to burn the entire tree, we can think of the tree as an undirected graph. The fire spreads from the target node to its adjacent nodes (left child, right child, and parent) in one second. This is equivalent to finding the maximum distance from the target node to any other node in the tree. We can solve this intuitively using Breadth-First Search (BFS) to simulate the fire spreading level by level (second by second).

Since a standard binary tree only has `left` and `right` child pointers, we can't naturally traverse upwards towards the root. We can fix this by doing a preliminary traversal of the tree to create parent pointers for every node using a map. 

## Steps
1. **Map Parents & Find Target:** 
   - Perform a level-order traversal (BFS) using a queue to map each node to its parent in an `unordered_map<Node*, Node*> parentMap`. 
   - Keep track of the node whose data matches the `target`, let's call it `targetNode`.
   
2. **Burn the Tree (BFS):** 
   - Initialize a new queue for BFS to simulate the burning process and an `unordered_map<Node*, bool> visited` map to keep track of burnt nodes and prevent visiting a node multiple times.
   - Push `targetNode` into the queue and mark it as visited.
   
3. **Simulate Time Passing:**
   - Keep a `time` counter initially at 0.
   - Run a while loop as long as the queue is not empty.
   - At each step, process all nodes currently in the queue (nodes that are currently on fire).
   - Track if any unburnt adjacent nodes catch fire in this step (`anyNodeAdded`).
   - For every node, if its `left` child, `right` child, or `parent` is not visited, push it into the queue and mark it as visited.
   - If at least one new adjacent node was added to the queue during this level expansion, we increment the `time` counter.
   
4. Output the `time`.

## Complexity
- **Time Complexity:** $O(N)$, where $N$ is the total number of nodes in the tree. We visit each node to assign parents, and then at most once again during the BFS burn traversal. Map lookups and queue operations take $O(1)$ on average.
- **Space Complexity:** $O(N)$ auxiliary space for the `parentMap`, the `visited` map, and the queue during BFS traversals. In the worst case, the queue can hold roughly $O(N)$ level elements (or up to $N/2$ leaf nodes).
