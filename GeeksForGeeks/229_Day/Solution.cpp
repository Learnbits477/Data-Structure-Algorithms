#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Runs BFS from startNode and returns {farthest_node, max_distance}
    pair<int, int> bfs(int startNode, int n, const vector<vector<int>> &g) {
        vector<int> dist(n + 1, -1);
        queue<int> q;

        dist[startNode] = 0;
        q.push(startNode);

        int farthestNode = startNode;
        int maxDist = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] > maxDist) {
                maxDist = dist[u];
                farthestNode = u;
            }

            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return {farthestNode, maxDist};
    }

public:
    // Step 1: Build 1-based tree adjacency list
    int partyHouse(int n, vector<vector<int>> &adj) {
        if (n <= 1) return 0;

        vector<vector<int>> g(n + 1);

        // Map input adjacency to 1-based indexed tree
        if (static_cast<int>(adj.size()) == n) {
            for (int i = 0; i < n; i++) {
                int u = i + 1;
                for (int v : adj[i]) {
                    g[u].push_back(v);
                }
            }
        } else {
            for (int i = 1; i <= n && i < static_cast<int>(adj.size()); i++) {
                for (int v : adj[i]) {
                    g[i].push_back(v);
                }
            }
        }

        // Step 2 & 3: First BFS from node 1 to find diameter endpoint A
        pair<int, int> firstBfs = bfs(1, n, g);
        int nodeA = firstBfs.first;

        // Step 4: Second BFS from node A to find diameter D
        pair<int, int> secondBfs = bfs(nodeA, n, g);
        int diameter = secondBfs.second;

        // Step 5: The tree radius is ceil(diameter / 2) = (diameter + 1) / 2
        return (diameter + 1) / 2;
    }

    // Overload for case when N is inferred from adj
    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();
        return partyHouse(n, adj);
    }
};
