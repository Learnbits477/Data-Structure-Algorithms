#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end, int mod = 1000) {
        // Step 1: Handle Edge Case
        if (start == end) return 0;

        // Step 2: Initialize Distance Array & Queue
        vector<int> dist(mod, -1);
        queue<int> q;
        
        q.push(start);
        dist[start] = 0;

        // Step 3: BFS Traversal
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == end) {
                return dist[curr];
            }

            for (int x : arr) {
                // Step 4: State Transition
                int next_val = (1LL * curr * x) % mod;

                // Step 5: Visit & Enqueue
                if (dist[next_val] == -1) {
                    dist[next_val] = dist[curr] + 1;
                    q.push(next_val);
                }
            }
        }

        // Step 6: Return Unreachable
        return -1;
    }

    int minimumMultiplications(vector<int>& arr, int start, int end, int mod = 1000) {
        return minSteps(arr, start, end, mod);
    }
};
