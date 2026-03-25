# Approach: Topological Sort (BFS) from Leaves Iteratively

This problem can be mapped to finding the centers of a given tree. A tree can have at most two centers. Those centers (nodes) will act as the roots that give the minimum height of the tree.

Our main strategy is to repeatedly peel off the leaf nodes layer by layer until we reach the core (1 or 2 center nodes).

### Step-by-Step Implementation:

1.  **Handle Edge Cases and Initialization:**
    If `V == 1` (a tree with only 1 node), the only valid root is `0`. We also initialize an adjacency list `adj` and a `degree` array to keep track of the number of edges connected to each node.
    ```cpp
    if (V == 1) return {0};
    
    vector<vector<int>> adj(V);
    vector<int> degree(V, 0);
    ```

2.  **Build Graph and Calculate Degrees:**
    Iterate through the `edges` array to populate the adjacency list and degree array for both nodes of an edge.
    ```cpp
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }
    ```

3.  **Initialize the Queue with Leaves (Outer Layer):**
    Iterate through all nodes. If a node has a degree of `1` (which means it's a leaf node), enqueue it into a queue `q` for performing Breadth-First Search (BFS).
    ```cpp
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }
    ```

4.  **Trim the Leaves iteratively (BFS):**
    We remove leaves level by level until we are restricted to `1` or `2` nodes (the tree centers). For each level, we decrement the degree of the neighbors of the current leaves. If a neighbor becomes a leaf (`degree == 1`), we enqueue it.
    ```cpp
    while (V > 2) {
        int size = q.size();
        V -= size; // Remove current leaves from total count
        
        while (size--) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                degree[neighbor]--;
                // If the neighbor becomes a leaf node, enqueue it
                if (degree[neighbor] == 1) {
                    q.push(neighbor);
                }
            }
        }
    }
    ```

5.  **Return the Minimum Height Roots:**
    The remaining `1` or `2` nodes in the queue are the centers of the tree. We extract them and return them as our result.
    ```cpp
    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
    ```
