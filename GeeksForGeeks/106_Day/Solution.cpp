#include <bits/stdc++.h>
using namespace std;

class Solution {
    // ── DFS helpers ──────────────────────────────────────────

    void dfs(int src, const vector<vector<int>>& adj,
             vector<bool>& visited, int& lastFinished) {
        stack<pair<int, int>> st; // {node, iterator index}
        st.push({src, 0});
        visited[src] = true;

        while (!st.empty()) {
            auto& [node, idx] = st.top();
            if (idx < (int)adj[node].size()) {
                int nb = adj[node][idx++];
                if (!visited[nb]) {
                    visited[nb] = true;
                    st.push({nb, 0});
                }
            } else {
                // All neighbors processed → node is finished
                lastFinished = node;
                st.pop();
            }
        }
    }

    int countReachable(int src, int V,
                       const vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        stack<int> st;
        st.push(src);
        vis[src] = true;
        int cnt = 1;

        while (!st.empty()) {
            int node = st.top(); st.pop();
            for (int nb : adj[node]) {
                if (!vis[nb]) {
                    vis[nb] = true;
                    ++cnt;
                    st.push(nb);
                }
            }
        }
        return cnt;
    }

public:
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // ── Build adjacency list ──────────────────────────
        vector<vector<int>> adj(V);
        for (auto& e : edges)
            adj[e[0]].push_back(e[1]);

        // ── Step 1: DFS sweep — find last-finishing vertex ─
        vector<bool> visited(V, false);
        int candidate = -1;

        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                dfs(i, adj, visited, candidate);
        }

        // ── Step 2: Verify candidate reaches all vertices ──
        if (candidate == -1 || countReachable(candidate, V, adj) != V)
            return -1;

        // ── Step 3: Find the smallest mother vertex ────────
        for (int v = 0; v < V; ++v) {
            if (countReachable(v, V, adj) == V)
                return v;
        }

        return -1; // unreachable, but needed for compilation
    }
};
