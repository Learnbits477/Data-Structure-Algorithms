# Minimum Cost to Connect All Houses in a City - Approach

## Problem Overview
The problem asks for the minimum cost to connect all houses in a 2D plane. The cost between two houses is the Manhattan distance: `|xi - xj| + |yi - yj|`. We need to ensure all houses are connected with the minimum total cost.

## Algorithmic Strategy
Since we need to connect all nodes (houses) with the minimum total edge weight, this is a classic **Minimum Spanning Tree (MST)** problem.

### Algorithm Selection
- **Prim's Algorithm**: Efficient for dense graphs ($V^2$ edges). With $n \le 1000$, $O(n^2)$ is optimal.
- **Kruskal's Algorithm**: Efficient for sparse graphs ($E \log V$). With $E \approx 5 \times 10^5$ and $V = 1000$, both are feasible, but Prim's $O(n^2)$ is simpler and avoids explicit edge construction.

### Prim's Algorithm Implementation Details
1.  **Initialize**:
    - `min_dist[n]` to `infinity` (except `min_dist[0] = 0`).
    - `in_mst[n]` to `false`.
    - `total_cost = 0`.
2.  **Iterate `n` times**:
    - Find the node `u` not yet in MST with the minimum `min_dist[u]`.
    - Mark `u` as `in_mst[u] = true`.
    - Add `min_dist[u]` to `total_cost`.
    - For each node `v` not in MST:
        - Calculate the Manhattan distance `dist(u, v) = |u.x - v.x| + |u.y - v.y|`.
        - Update `min_dist[v] = min(min_dist[v], dist(u, v))`.
3.  **Return**: `total_cost`.

## Complexity Analysis
- **Time Complexity**: $O(n^2)$, where $n$ is the number of houses. We iterate $n$ times to find the minimum distance node and another $n$ times to update distances.
- **Space Complexity**: $O(n)$ to store the `min_dist` and `in_mst` arrays.

## Source Code Reference
Refer to [Solution.cpp](file:///c:/Users/Pankaj%20Kumar/OneDrive/Desktop/DSA/GeeksForGeeks/62_Day/Solution.cpp) for the full implementation.
