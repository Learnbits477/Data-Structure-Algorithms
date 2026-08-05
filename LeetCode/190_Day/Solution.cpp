#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build adjacency list for directed graph
        vector<vector<int>> adj(n);
        for (const auto& invocation : invocations) {
            adj[invocation[0]].push_back(invocation[1]);
        }
        
        // Step 2: Use BFS to find all methods reachable from method k (suspicious group)
        vector<bool> suspicious(n, false);
        queue<int> q;
        
        q.push(k);
        suspicious[k] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : adj[curr]) {
                if (!suspicious[neighbor]) {
                    suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        // Step 3: Check if there is any invocation from a non-suspicious method to a suspicious method
        bool can_remove = true;
        for (const auto& invocation : invocations) {
            int u = invocation[0];
            int v = invocation[1];
            if (!suspicious[u] && suspicious[v]) {
                can_remove = false;
                break;
            }
        }
        
        // Step 4: Construct result array
        vector<int> result;
        if (can_remove) {
            for (int i = 0; i < n; ++i) {
                if (!suspicious[i]) {
                    result.push_back(i);
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
