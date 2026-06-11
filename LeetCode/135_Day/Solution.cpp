#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        // Step 1: Determine the number of nodes n.
        int n = edges.size() + 1;
        
        // Step 2: Build the adjacency list representation of the tree.
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Step 3: Run a BFS to find the maximum depth (distance from root node 1).
        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        q.push(1);
        dist[1] = 0;
        int max_depth = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            max_depth = max(max_depth, dist[u]);
            
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        
        // Step 4: Calculate 2^(max_depth - 1) modulo 10^9 + 7.
        long long ans = 1;
        long long base = 2;
        long long exp = max_depth - 1;
        long long MOD = 1e9 + 7;
        
        while (exp > 0) {
            if (exp & 1) {
                ans = (ans * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        
        return ans;
    }
};
