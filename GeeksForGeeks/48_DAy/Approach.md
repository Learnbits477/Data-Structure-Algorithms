# Approach for K Sum Paths

## Problem Overview
We need to find the number of downward-only paths in a binary tree where the sum of node values equals a given integer `k`. A path can start and end anywhere but must go downwards.

## Optimal Solution: Prefix Sum with Hash Map (DFS)

### Intuition
This problem is similar to finding a continuous subarray sum equals to `k` in an array. We can keep track of the prefix sum from the root to the current node. If the difference between the current prefix sum and `k` exists in our previously seen prefix sums, it means there is a subpath ending at the current node that sums to `k`.

### Step-by-Step Algorithm
1. Maintain a hash map `prefix_sums` to store the frequencies of prefix sums encountered on the path from the root to the current node.
2. We initialize `prefix_sums[0] = 1`, because a prefix sum equal to `curr_sum - k` where `curr_sum == k` means the path from the root to the current node itself down to this point sums exactly to `k`.
3. Perform a Depth-First Search (DFS) on the tree.
4. At each node:
   - Calculate `curr_sum = curr_sum + node->data`.
   - Check if `curr_sum - k` exists in our map. If it does, add its frequency to our `count`.
   - Add the current sum to our map: `prefix_sums[curr_sum]++`.
   - Recurse for the left and right subtrees.
   - **Backtrack**: After exploring both subtrees, remove the current node's cumulative sum from the map to avoid using it in parallel branches: `prefix_sums[curr_sum]--`.

### Complexity
- **Time Complexity:** $O(N)$ where $N$ is the number of nodes in the tree. We visit each node exactly once, and hash map operations take $O(1)$ on average.
- **Space Complexity:** $O(H)$ where $H$ is the height of the tree, for the recursion stack and the hash map. In the worst case (skewed tree), it can be $O(N)$.
