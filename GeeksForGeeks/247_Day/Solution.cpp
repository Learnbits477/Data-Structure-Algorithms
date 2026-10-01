#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(vector<int>& duration, vector<vector<int>>& dependencies) {
        int n = duration.size();
        if (n == 0) return 0;

        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        // Build directed graph: u -> v (module v depends on module u)
        for (const auto& dep : dependencies) {
            int u = dep[0];
            int v = dep[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        // finishTime[i] stores earliest completion time for module i
        vector<int> finishTime(n);
        for (int i = 0; i < n; ++i) {
            finishTime[i] = duration[i];
        }

        // Enqueue all modules with no prerequisite dependencies
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int processedCount = 0;

        // BFS Topological traversal
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processedCount++;

            for (int v : adj[u]) {
                // Earliest start time of v is bounded by the finish time of predecessor u
                finishTime[v] = max(finishTime[v], finishTime[u] + duration[v]);

                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If not all modules could be processed, a cycle exists
        if (processedCount < n) {
            return -1;
        }

        // Project finishes when the last module finishes
        int totalTime = 0;
        for (int i = 0; i < n; ++i) {
            totalTime = max(totalTime, finishTime[i]);
        }

        return totalTime;
    }

    /**
     * @brief Overload for alternate legacy signature compatibility on GeeksforGeeks.
     */
    int minTime(vector<pair<int, int>>& dependency, int duration[], int n, int m) {
        vector<int> dur(duration, duration + n);
        vector<vector<int>> dep;
        dep.reserve(m);
        for (int i = 0; i < m; ++i) {
            dep.push_back({dependency[i].first, dependency[i].second});
        }
        return minTime(dur, dep);
    }
};
