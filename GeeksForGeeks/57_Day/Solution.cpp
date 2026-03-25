#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if (V == 1) return {0};
        
        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        while (V > 2) {
            int size = q.size();
            V -= size;
            
            while (size--) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges(E, vector<int>(2));
        for (int i = 0; i < E; ++i) {
            cin >> edges[i][0] >> edges[i][1];
        }
        Solution obj;
        vector<int> res = obj.minHeightRoot(V, edges);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
