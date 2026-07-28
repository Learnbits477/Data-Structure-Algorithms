#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>>& edges) {
        // Step 1: Graph Representation
        vector<vector<pair<int, int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Step 2: Initialize Distance and Buckets
        const int INF = 1e9;
        vector<int> dist(V, INF);
        queue<int> Q[3];

        dist[src] = 0;
        Q[0].push(src);

        int curr_dist = 0;

        // Step 3: Sequential Distance Iteration
        while (true) {
            int idx = curr_dist % 3;

            if (Q[0].empty() && Q[1].empty() && Q[2].empty()) {
                break;
            }

            while (!Q[idx].empty()) {
                int u = Q[idx].front();
                Q[idx].pop();

                if (dist[u] < curr_dist) {
                    continue;
                }

                if (u == dest) {
                    return dist[u];
                }

                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int w = neighbor.second;

                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        Q[dist[v] % 3].push(v);
                    }
                }
            }
            curr_dist++;
        }

        // Step 4: Unreachable Check
        return dist[dest] == INF ? -1 : dist[dest];
    }
};

