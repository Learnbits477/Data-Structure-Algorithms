# Approach

## Dijkstra's Algorithm

This problem can be effectively solved using Dijkstra's Algorithm. We need to find the shortest path in a graph with non-negative edge weights, and simultaneously count the number of such shortest paths.

### Steps:

1. **Adjacency List Representation**: 
   - Convert the given `edges` list into an adjacency list where each node points to its neighbors with the corresponding edge weight `(neighbor, time)`.
   ```cpp
   vector<vector<pair<int, int>>> adj(n);
   for (auto& edge : edges) {
       adj[edge[0]].push_back({edge[1], edge[2]});
       adj[edge[1]].push_back({edge[0], edge[2]});
   }
   ```

2. **Min-Heap (Priority Queue)**: 
   - Use a priority queue (min-heap) to always process the node with the shortest time from the source node `0`. 
   ```cpp
   priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
   ```

3. **Distance and Ways Arrays**:
   - Initialize the arrays to track distance and number of ways.
   ```cpp
   vector<long long> dist(n, 1e18); // Use large value for initial distance
   vector<long long> ways(n, 0);
   
   dist[0] = 0;
   ways[0] = 1;
   pq.push({0, 0});
   ```

4. **Iterative Processing**:
   - Process nodes, ignoring the ones we've found shorter paths for before. Traverse neighbors to update shortest distances and the ways to reach them.
   ```cpp
   int mod = 1e9 + 7;
   while (!pq.empty()) {
       long long current_time = pq.top().first;
       int u = pq.top().second;
       pq.pop();
       
       if (current_time > dist[u]) continue;
       
       for (auto& neighbor : adj[u]) {
           int v = neighbor.first;
           long long edge_time = neighbor.second;
           
           if (current_time + edge_time < dist[v]) {
               dist[v] = current_time + edge_time;
               ways[v] = ways[u]; 
               pq.push({dist[v], v});
           } 
           else if (current_time + edge_time == dist[v]) {
               ways[v] = (ways[v] + ways[u]) % mod;
           }
       }
   }
   ```

5. **Return Result**: 
   - The result will simply be the number of ways to the target node modulo `10^9 + 7`.
   ```cpp
   return ways[n - 1] % mod;
   ```

### Complexity:
- **Time Complexity:** `O(E * logV)` where `V` is the number of vertices and `E` is the number of edges, as each edge is processed and priority queue operations take logarithmic time.
- **Space Complexity:** `O(V + E)` for storing the graph in an adjacency list and maintaining the `dist` and `ways` arrays.
