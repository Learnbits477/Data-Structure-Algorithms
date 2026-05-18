#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Step 1: Value-to-Index Mapping
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++) {
            indicesOfValue[arr[i]].push_back(i);
        }

        // Step 2: BFS Queue & Visited Initialization
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(0);
        visited[0] = true;
        int steps = 0;

        // Step 3: Level-by-Level Traversal
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1) {
                    return steps;
                }

                // Step 4: Neighbor Exploration
                // 1. Backward jump: curr - 1
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                // 2. Forward jump: curr + 1
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                // 3. Equal-value jump: indices with same value
                int val = arr[curr];
                if (indicesOfValue.count(val)) {
                    for (int nextIdx : indicesOfValue[val]) {
                        if (nextIdx != curr && !visited[nextIdx]) {
                            visited[nextIdx] = true;
                            q.push(nextIdx);
                        }
                    }
                    // Step 5: Redundant Check Optimization
                    indicesOfValue.erase(val);
                }
            }
            steps++;
        }

        return -1;
    }
};
