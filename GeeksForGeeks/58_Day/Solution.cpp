#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        // Priority queue to store {duration, node} and sort them by duration
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 1e18); // Use large value for initial distance
        vector<long long> ways(n, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        int mod = 1e9 + 7;
        
        while (!pq.empty()) {
            long long current_time = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // If we find a longer path than already recorded shortest path, skip it
            if (current_time > dist[u]) continue;
            
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                long long edge_time = neighbor.second;
                
                // If a strictly shorter path is found
                if (current_time + edge_time < dist[v]) {
                    dist[v] = current_time + edge_time;
                    ways[v] = ways[u]; // Inherit ways from parent
                    pq.push({dist[v], v});
                } 
                // If another path with the exact same shortest time is found
                else if (current_time + edge_time == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        
        return ways[n - 1] % mod;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int V1 = 4;
    vector<vector<int>> edges1 = {{0, 1, 2}, {1, 2, 3}, {0, 3, 5}, {1, 3, 3}, {2, 3, 4}};
    cout << "Example 1 Output: " << sol.countPaths(V1, edges1) << endl;
    
    // Example 2
    int V2 = 6;
    vector<vector<int>> edges2 = {{0, 2, 3}, {0, 4, 2}, {0, 5, 7}, {2, 3, 1}, {2, 5, 5}, {5, 3, 3}, {5, 1, 4}, {1, 4, 1}, {4, 5, 5}};
    cout << "Example 2 Output: " << sol.countPaths(V2, edges2) << endl;
    
    return 0;
}
