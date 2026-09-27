#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Core function to find the maximum number of nodes in a valid colored path
    int longestColoredPath(string s, vector<vector<int>>& edges) {
        int n = s.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        // Partition the tree into monochromatic components and bi-colored edges
        vector<vector<int>> monoAdj(n + 1);
        vector<pair<int, int>> bicoloredEdges;

        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            if (s[u - 1] == s[v - 1]) {
                monoAdj[u].push_back(v);
                monoAdj[v].push_back(u);
            } else {
                bicoloredEdges.push_back({u, v});
            }
        }

        vector<int> eccentricity(n + 1, 0);
        vector<bool> visited(n + 1, false);
        vector<int> distA(n + 1, -1);
        vector<int> distB(n + 1, -1);
        int maxPath = 1;

        // BFS helper that explores only within a monochromatic component
        auto bfs = [&](int startNode, vector<int>& dist) -> int {
            queue<int> q;
            q.push(startNode);
            dist[startNode] = 0;
            int furthestNode = startNode;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                if (dist[curr] > dist[furthestNode]) {
                    furthestNode = curr;
                }

                for (int nxt : monoAdj[curr]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = dist[curr] + 1;
                        q.push(nxt);
                    }
                }
            }
            return furthestNode;
        };

        // Process each monochromatic component in the forest
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                vector<int> compNodes;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    compNodes.push_back(u);

                    for (int v : monoAdj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }

                // Single node component
                if (compNodes.size() == 1) {
                    eccentricity[compNodes[0]] = 0;
                    maxPath = max(maxPath, 1);
                    continue;
                }

                // 1. Find diameter endpoint A
                for (int u : compNodes) distA[u] = -1;
                int A = bfs(compNodes[0], distA);

                // 2. Find diameter endpoint B from A
                for (int u : compNodes) distA[u] = -1;
                int B = bfs(A, distA);

                // Diameter of this component in number of vertices
                int componentDiameter = distA[B] + 1;
                maxPath = max(maxPath, componentDiameter);

                // 3. Compute distances from B to all nodes in the component
                for (int u : compNodes) distB[u] = -1;
                bfs(B, distB);

                // In any tree, eccentricity(u) = max(dist(u, A), dist(u, B))
                for (int u : compNodes) {
                    eccentricity[u] = max(distA[u], distB[u]);
                }
            }
        }

        // Evaluate all bi-colored edges (u, v) bridging Red and Blue components
        for (const auto& edge : bicoloredEdges) {
            int u = edge.first;
            int v = edge.second;
            // Valid path: (Longest path in u's component ending at u) + (Longest path in v's component starting at v)
            int pathLength = (1 + eccentricity[u]) + (1 + eccentricity[v]);
            maxPath = max(maxPath, pathLength);
        }

        return maxPath;
    }

    // Platform alias methods
    int longestPath(string s, vector<vector<int>>& edges) {
        return longestColoredPath(s, edges);
    }

    int longestColoredPath(int n, string s, vector<vector<int>>& edges) {
        return longestColoredPath(s, edges);
    }

    int longestPath(int n, string s, vector<vector<int>>& edges) {
        return longestColoredPath(s, edges);
    }
};
