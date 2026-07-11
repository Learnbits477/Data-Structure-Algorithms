#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build Adjacency List
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponentsCount = 0;

        // Step 2: Traverse Graph using BFS/DFS
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertexCount = 0;
                int degreeSum = 0;
                
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    vertexCount++;
                    degreeSum += adj[u].size();

                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }

                // Step 3: Check Completeness Condition
                if (degreeSum == vertexCount * (vertexCount - 1)) {
                    completeComponentsCount++;
                }
            }
        }

        // Step 4: Return Result
        return completeComponentsCount;
    }
};
