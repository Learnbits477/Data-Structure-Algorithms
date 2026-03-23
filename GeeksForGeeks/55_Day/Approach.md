# Approach: Depth First Search (DFS) for Functional Graph

This problem asks us to find the longest cycle in a directed graph where each vertex has at most one outgoing edge. This type of graph is also known as a functional graph.

## Strategy
We can simulate walking along the edges until we hit a cycle or a dead-end. 
To calculate cycle lengths efficiently, we need to track:
1. `visited` array: To ensure we don't process the same node in a completely different connected component again.
2. `dist` array: To track the sequence/distance of the nodes we're currently visiting.
3. `pathStart` array: To differentiate between hitting a cycle in the *current path* versus hitting a dead-end processed in a *previous path*.

---

## Step-by-Step Code Explanation

### 1. Graph Representation
Start by converting the 2D `edges` array into a single target array `next_node` where `next_node[u] = v`. Initialize `next_node` with `-1` to represent no outgoing edge. 

```cpp
vector<int> next_node(V, -1);
for (const auto& edge : edges) {
    next_node[edge[0]] = edge[1];
}
```

### 2. State Mapping
Initialize the necessary arrays to keep track of the node states during traversals. We need a `visited` boolean array, a `pathStart` array to identify paths, and a `dist` array to store distances relative to the start of the path.

```cpp
vector<bool> visited(V, false);
vector<int> pathStart(V, -1);
vector<int> dist(V, 0);

int ans = -1; // To track the maximum cycle length
```

### 3. Start DFS Traversal
Iterate through all nodes from `0` to `V-1`. For each unvisited node, start a new traversal (DFS-like simulation).

```cpp
for (int i = 0; i < V; ++i) {
    if (!visited[i]) {
        int curr = i;
        int current_dist = 0;
```

### 4. Traverse the Current Path
Follow the edges as long as we don't hit a dead end (`curr == -1`) or a node we have already visited in ANY traversal (`!visited[curr]`). At each step, update the node's state: mark it visited, record its distance from the start, and assign it the identifier of the current path (`i`).

```cpp
        while (curr != -1 && !visited[curr]) {
            visited[curr] = true;
            dist[curr] = current_dist++;
            pathStart[curr] = i; 
            
            curr = next_node[curr]; // Move to the next node
        }
```

### 5. Check for Cycles
When the `while` loop terminates, we evaluate why it stopped. If `curr != -1` AND `pathStart[curr] == i`, it means we stopped because we encountered a node we just visited in *this exact same traversal*. This means we found a cycle!
Calculate the length of the cycle by subtracting the recorded `dist` of `curr` from our `current_dist`.

```cpp
        if (curr != -1 && pathStart[curr] == i) {
            ans = max(ans, current_dist - dist[curr]);
        }
    }
}

return ans;
```

### Complexity:
- **Time Complexity:** `O(V)`. Each vertex is processed at most twice. Since the number of edges `E` is at most `V`, this takes linear time relative to vertices.
- **Space Complexity:** `O(V)`. We maintain arrays of size `V` for `next_node`, `visited`, `dist`, and `pathStart`.
