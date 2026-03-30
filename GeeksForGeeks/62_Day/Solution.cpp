#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        if (n == 0) return 0;
        
        // distance[i] stores the minimum cost to connect house i to the MST
        vector<int> min_dist(n, INT_MAX);
        // visited[i] tracks if house i is already included in the MST
        vector<bool> in_mst(n, false);
        
        int total_cost = 0;
        
        // Start from house 0
        min_dist[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            int u = -1;
            
            // Find the house with the minimum distance to the MST
            for (int v = 0; v < n; ++v) {
                if (!in_mst[v] && (u == -1 || min_dist[v] < min_dist[u])) {
                    u = v;
                }
            }
            
            // If u is still -1, the graph is not connected (though not possible in this problem)
            if (u == -1) break;
            
            // Add house u to MST
            in_mst[u] = true;
            total_cost += min_dist[u];
            
            // Update distances of adjacent houses (all other houses)
            for (int v = 0; v < n; ++v) {
                if (!in_mst[v]) {
                    int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    if (dist < min_dist[v]) {
                        min_dist[v] = dist;
                    }
                }
            }
        }
        
        return total_cost;
    }
};

#ifndef ONLINE_JUDGE
int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> houses1 = {{0, 7}, {0, 9}, {20, 7}, {30, 7}, {40, 70}};
    cout << "Example 1 Output: " << sol.minCost(houses1) << " (Expected: 105)" << endl;
    
    // Example 2
    vector<vector<int>> houses2 = {{0, 0}, {1, 1}, {1, 3}, {3, 0}};
    cout << "Example 2 Output: " << sol.minCost(houses2) << " (Expected: 7)" << endl;
    
    return 0;
}
#endif
