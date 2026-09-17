#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // Step: 01 - Handle base case where source is already destination
        if (src == dst) return 0;

        // Step: 02 - Build augmented adjacency list
        // Original edge u -> v has weight 0 (no reversal needed)
        // Reverse edge v -> u has weight 1 (reversal needed)
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        // Step: 03 - Initialize 0-1 BFS data structures
        const int INF = 1e9;
        vector<int> dist(n + 1, INF);
        deque<int> dq;

        dist[src] = 0;
        dq.push_back(src);

        // Step: 04 - Perform 0-1 BFS using deque
        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            // Optimal distance reached
            if (u == dst) {
                return dist[dst];
            }

            for (const auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;

                    // 0-weight edges go to the front, 1-weight edges to the back
                    if (weight == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }

        // Step: 05 - Return result if destination is reachable, else -1
        return dist[dst] == INF ? -1 : dist[dst];
    }

    // Overload for platforms passing edge count m explicitly
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int m, int src, int dst) {
        return minimumEdgeReversal(edges, n, src, dst);
    }
};
