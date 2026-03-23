#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> next_node(V, -1);
        for (const auto& edge : edges) {
            next_node[edge[0]] = edge[1];
        }

        vector<bool> visited(V, false);
        vector<int> pathStart(V, -1);
        vector<int> dist(V, 0);
        
        int ans = -1;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                int curr = i;
                int current_dist = 0;
                
                while (curr != -1 && !visited[curr]) {
                    visited[curr] = true;
                    dist[curr] = current_dist++;
                    pathStart[curr] = i; 
                    
                    curr = next_node[curr];
                }
                
                if (curr != -1 && pathStart[curr] == i) {
                    ans = max(ans, current_dist - dist[curr]);
                }
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> edges;
        for (int i = 0; i < e; ++i) {
            int u, dest;
            cin >> u >> dest;
            edges.push_back({u, dest});
        }
        Solution obj;
        cout << obj.longestCycle(v, edges) << "\n";
    }
    return 0;
}
