#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        // Step 1 — Preprocess and Filter Offline Nodes
        // Adjacency list storing outgoing edges: {neighbor, cost}
        vector<vector<pair<int, int>>> adj(n);
        vector<int> in_degree(n, 0);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            // Ignore edges connected to offline intermediate nodes
            if (u != 0 && u != n - 1 && !online[u]) continue;
            if (v != 0 && v != n - 1 && !online[v]) continue;

            adj[u].push_back({v, cost});
            in_degree[v]++;
        }

        // Step 2 — Compute Topological Sort
        // Run Kahn's Algorithm on valid online nodes
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (i != 0 && i != n - 1 && !online[i]) continue;
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo_order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo_order.push_back(u);

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Step 3 — Establish Search Range
        // Extract all unique edge costs in sorted order
        vector<int> costs;
        for (const auto& edge : edges) {
            costs.push_back(edge[2]);
        }
        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());

        // Verification function to check if score X is achievable
        auto check = [&](int X) -> bool {
            vector<long long> dist(n, 1e18);
            dist[0] = 0;

            for (int u : topo_order) {
                if (dist[u] == 1e18) continue;
                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int cost = edge.second;
                    if (cost >= X) {
                        if (dist[u] + cost < dist[v]) {
                            dist[v] = dist[u] + cost;
                        }
                    }
                }
            }
            return dist[n - 1] <= k;
        };

        // If no valid path exists even when keeping all edges (threshold = 0)
        if (!check(0)) {
            return -1;
        }

        // Step 4 — Binary Search on Edge Cost Threshold
        int low = 0;
        int high = costs.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(costs[mid])) {
                ans = costs[mid];
                low = mid + 1; // Try to maximize the minimum edge cost
            } else {
                high = mid - 1; // High threshold cannot be met
            }
        }

        return ans;
    }
};
