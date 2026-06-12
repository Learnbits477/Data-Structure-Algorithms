#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int LOG;
    vector<int> depth;
    vector<vector<int>> up;

    // Helper DFS to precompute depth and immediate parents
    void dfs(int u, int p, const vector<vector<int>>& adj) {
        up[u][0] = p;
        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u, adj);
            }
        }
    }

    // Step 3: Find Lowest Common Ancestor (LCA) using Binary Lifting
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        
        // Lift u to the same depth as v
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; ++i) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        // Lift u and v in tandem until they are just below the LCA
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // Step 1: Precompute Tree Depths and Binary Lifting Table
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        LOG = 0;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG));

        // Start DFS from root 1, setting its parent to 1
        dfs(1, 1, adj);

        // Precompute powers of 2 ancestors (Binary Lifting Table)
        for (int i = 1; i < LOG; ++i) {
            for (int j = 1; j <= n; ++j) {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }

        // Step 2: Precompute Powers of 2
        int MOD = 1e9 + 7;
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        // Process each query
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                // If nodes are the same, path is empty, cost is 0 (even)
                ans.push_back(0);
            } else {
                // Step 3: Find Lowest Common Ancestor (LCA)
                int lca = getLCA(u, v);

                // Step 4: Calculate Path Distance and Result
                int dist = depth[u] + depth[v] - 2 * depth[lca];
                ans.push_back(pow2[dist - 1]);
            }
        }

        return ans;
    }
};
