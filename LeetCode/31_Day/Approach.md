# Approach - Minimum Operations to Equalize Binary String

The problem asks for the minimum number of operations to turn a binary string into all `'1'`s. In each operation, we are allowed to select exactly `k` distinct indices and flip the bits at those indices.

Notice that the actual positions of the bits do not matter. The state of the string can be entirely represented by the number of `'0'`s it contains.

## Logic

1.  **State Representation:** If there are currently `d` zeros, in one operation we can select $x$ zeros (to turn them into `'1'`s) and $y$ ones (to turn them into `'0'`s), such that $x + y = k$.
2.  **State Transitions:** The new number of zeros will be $d + k - 2x$. We must respect the bounds on $x$: $x \in [\max(0, k - n + d), \min(d, k)]$.
    From a single step with initial $d$ zeros, the possible next numbers of zeros form an arithmetic sequence of step `2` ranging from a minimum to a maximum value. This suggests the problem can be modeled as a shortest path problem (BFS).
3.  **Breadth-First Search (BFS) with DSU Optimization:** A standard BFS would examine up to $O(n)$ neighbors per state, leading to $O(n^2)$ time. To optimize this, we maintain two Disjoint Set Union (DSU) structures (for even and odd state transitions) to quickly find valid unvisited neighbors to add to our queue and skip over visited states.
4.  **Process:** Find the possible range `[min_next, max_next]` of next zeros, iterate through the unvisited states in that range using DSU path compression, enqueue them, update their distances, and mark them as visited.

## Complexity

- **Time Complexity:** $O(n \cdot \alpha(n))$, where $n$ is the length of the string `s` and $\alpha$ is the inverse Ackermann function. This effectively operates in $O(n)$ time.
- **Space Complexity:** $O(n)$ for storing the BFS distance array, queue, and alternating parity DSU arrays.
