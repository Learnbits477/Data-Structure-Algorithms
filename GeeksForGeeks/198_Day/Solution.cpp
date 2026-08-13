#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void topoSortDFS(int u, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, stack<int>& topo) {
        visited[u] = true;
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            if (!visited[v]) {
                topoSortDFS(v, adj, visited, topo);
            }
        }
        topo.push(u);
    }

public:
    vector<int> maxDistance(int V, int src, vector<vector<int>>& edges) {
        // Step 1: Build Adjacency List
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        // Step 2: Compute Topological Sort
        stack<int> topo;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topoSortDFS(i, adj, visited, topo);
            }
        }
        
        // Step 3: Initialize Distance Array
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;
        
        // Step 4: Relax Edges in Topological Order
        while (!topo.empty()) {
            int u = topo.top();
            topo.pop();
            
            if (dist[u] != INT_MIN) {
                for (auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int w = neighbor.second;
                    if (dist[u] + w > dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
        
        // Step 5: Return Distances
        return dist;
    }
};
