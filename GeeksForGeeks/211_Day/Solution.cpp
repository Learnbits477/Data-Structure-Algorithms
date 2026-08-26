#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        // Step 1: Initialize distance array with 0 for all vertices
        vector<int> dist(n, 0);

        // Step 2: Relax all edges (n - 1) times
        for (int i = 1; i <= n - 1; ++i) {
            bool updated = false;
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
            if (!updated) {
                return 0;
            }
        }

        // Step 3: Check for negative weight cycle on the n-th pass
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] + w < dist[v]) {
                return 1;
            }
        }

        return 0;
    }
};
