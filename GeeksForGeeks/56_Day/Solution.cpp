#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Create adjacency list and in-degree array
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        
        // Build the graph and update in-degrees
        for (const auto& pre : prerequisites) {
            int u = pre[1]; // prerequisite course
            int v = pre[0]; // course to take
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        // Queue to process courses with 0 in-degree
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0; // To keep track of completed courses
        
        // Process courses using BFS (Kahn's Algorithm)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;
            
            // Decrease in-degree of all dependent courses
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                
                // If in-degree becomes 0, all prerequisites are met
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If count equals the total number of courses, we can finish all

        
        return count == n;
    }
};

int main() {
    Solution sol;
    
    int n1 = 4;
    vector<vector<int>> prerequisites1 = {{2, 0}, {2, 1}, {3, 2}};
    cout << "Example 1 Output: " << (sol.canFinish(n1, prerequisites1) ? "true" : "false") << endl; // Expected: true
    
    int n2 = 3;
    vector<vector<int>> prerequisites2 = {{0, 1}, {1, 2}, {2, 0}};
    cout << "Example 2 Output: " << (sol.canFinish(n2, prerequisites2) ? "true" : "false") << endl; // Expected: false
    
    return 0;
}
