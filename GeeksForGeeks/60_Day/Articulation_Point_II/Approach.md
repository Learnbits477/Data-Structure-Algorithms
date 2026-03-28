# [Articulation Point - II](https://www.geeksforgeeks.org/problems/articulation-point2616/1) - Approach

The goal is to find all **Articulation Points** (Cut Vertices) in an undirected graph. For this problem, the input is provided as a list of edges, which we first convert into an adjacency list.

## Algorithm: Tarjan's Algorithm (DFS Based)

We use DFS with two auxiliary arrays to identify vertices whose removal increases the number of connected components:
1.  **Discovery Time (`tin[]`)**: Time at which a node was first visited.
2.  **Lowest Reachable Discovery Time (`low[]`)**: Lowest `tin` reachable from the node (including itself) in the DFS tree, through back-edges.

### Step-by-Step Code Explanation

#### 1. Graph Preprocessing
The input is given as a list of edges. We convert this into an adjacency list for efficient traversal.
```cpp
vector<int> adj[V];
for (auto& edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
}
```

#### 2. Initialization
-   `tin` and `low` arrays are initialized to `-1`.
-   `vis` and `isArticulation` boolean arrays are used for tracking visited status and identifying cut vertices.
-   A `timer` variable tracks the discovery order.

#### 3. DFS Traversal (Handling Multiple Components)
We iterate through all vertices and call DFS if the vertex hasn't been visited yet. This ensures all connected components are covered.

#### 4. Inside the DFS Function
For each vertex `u` and its neighbor `v`:
-   **Parent Check**: If `v` is the parent of `u`, we skip it.
-   **If `v` is not visited (Tree Edge)**:
    -   Increment the child count of `u`.
    -   Recursive call: `dfs(v, u, ...)`.
    -   Update `low[u] = min(low[u], low[v])`.
    -   **Articulation Condition**: If `low[v] >= tin[u]` and `u` is not the root, then `u` is an articulation point.
-   **If `v` is already visited (Back Edge)**:
    -   Update `low[u] = min(low[u], tin[v])`.

#### 5. Root Node Special Case
After exploring all neighbors, if `u` is the root (`parent == -1`) and it has more than one child in the DFS tree, it is an articulation point.
```cpp
if (parent == -1 && children > 1) isArticulation[u] = true;
```

#### 6. Collecting Results
Iterate from `0` to `V-1`. If `isArticulation[i]` is true, add `i` to the result vector. If the vector is empty, return `{-1}`.

## Complexity
-   **Time Complexity**: $O(V + E)$ due to DFS and graph construction.
-   **Space Complexity**: $O(V + E)$ for the adjacency list and auxiliary arrays.
