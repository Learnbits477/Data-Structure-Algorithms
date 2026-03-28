#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& tin, vector<int>& low,
             vector<bool>& vis, vector<bool>& isArticulation, int& timer) {
        vis[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!vis[v]) {
                dfs(v, u, adj, tin, low, vis, isArticulation, timer);
                low[u] = min(low[u], low[v]);

                if (low[v] >= tin[u] && parent != -1)
                    isArticulation[u] = true;

                children++;
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }

        if (parent == -1 && children > 1)
            isArticulation[u] = true;
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Build Adjacency List from Edges
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> tin(V, -1), low(V, -1);
        vector<bool> vis(V, false), isArticulation(V, false);
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, tin, low, vis, isArticulation, timer);
            }
        }

        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) res.push_back(i);
        }

        if (res.empty()) return {-1};
        return res;
    }
};

int main() {
    int V, E;
    if (!(cin >> V >> E)) return 0;
    vector<vector<int>> edges(E, vector<int>(2));
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    vector<int> ans = obj.articulationPoints(V, edges);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
