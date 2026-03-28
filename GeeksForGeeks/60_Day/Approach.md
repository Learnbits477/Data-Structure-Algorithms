# Articulation Point - II (Tarjan's Approach)

This approach identifies **Articulation Points** (Cut Vertices) in an undirected graph using a single DFS traversal.

## Core Logic: Tarjan's Algorithm

Each node is assigned two values during DFS:
1.  `tin[u]` (Time In): The timestamp when node `u` was first visited.
2.  `low[u]` (Lowest): The lowest `tin` reachable from `u` using a back-edge in the DFS tree.

## Step-by-Step Code Walkthrough

### 1. Build Adjacency List
Given an edge list `edges[][]`, we first convert it into an adjacency list `adj[]` for efficient graph traversal.
```cpp
vector<int> adj[V];
for (auto& edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
}
```

### 2. DFS Traversal (Handling Multiple Components)
Since the graph might be disconnected, we iterate through all vertices from 0 to V-1. If a node is not visited, we trigger a new DFS.
```cpp
for (int i = 0; i < V; i++) {
    if (!vis[i]) dfs(i, -1, adj, ...);
}
```

### 3. Identify Articulation Point Conditions

For an edge `u -> v` in the DFS tree:

#### A. Internal Node Condition
If `u` is NOT the root of the DFS tree and `low[v] >= tin[u]`, then `u` is an articulation point. This means there is no path from `v` or its subtree to any ancestor of `u`.
```cpp
if (low[v] >= tin[u] && parent != -1)
    isArticulation[u] = true;
```

#### B. Root Node Condition
If `u` IS the root of the DFS tree and it has more than one child, then it is an articulation point.
```cpp
if (parent == -1 && children > 1)
    isArticulation[u] = true;
```

#### C. Back-Edge Case
If `v` was already visited and it's not the parent of `u`, it's a back-edge. We update `low[u]` using `tin[v]`.
```cpp
low[u] = min(low[u], tin[v]);
```

### 4. Result Formatting
Collect all vertices marked as `isArticulation` and sort them. If the list is empty, return `{-1}`.

## Complexity
-   **Time**: $O(V + E)$ - Each node and edge is visited once.
-   **Space**: $O(V + E)$ - Adjacency list storage and auxiliary arrays.
