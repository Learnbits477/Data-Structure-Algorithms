#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        // Step 1 — Build the Graph Adjacency List
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        // Step 2 — Initialize Search Variables
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int min_score = INT_MAX;

        // Step 3 — Run BFS / Reachability Traversal
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int dist = neighbor.second;

                min_score = min(min_score, dist);

                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        // Step 4 — Return the Minimum Score
        return min_score;
    }
};
