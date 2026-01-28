#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // locations[v] stores list of {r, c} where grid[r][c] == v
        vector<vector<pair<int, int>>> locations(10001);
        for(int r=0; r<m; ++r) {
            for(int c=0; c<n; ++c) {
                locations[grid[r][c]].push_back({r, c});
            }
        }
        
        // Priority Queue: {cost, type, r_or_val, c, k}
        // Type 0: Physical (r, c, k) -> {cost, 0, r, c, k}
        // Type 1: Virtual (val, k)   -> {cost, 1, val, 0, k} (c is unused)
        priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<tuple<int, int, int, int, int>>> pq;
        
        // Distances
        // dist[r][c][k]
        // dist_virtual[val][k]
        static int dist[81][81][12];
        static int dist_virtual[10002][12];
        
        const int INF = 1e9;
        
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                for(int l=0; l<=k; ++l)
                    dist[i][j][l] = INF;
                    
        for(int i=0; i<=10000; ++i)
            for(int l=0; l<=k; ++l)
                dist_virtual[i][l] = INF;

        // Start
        dist[0][0][0] = 0;
        pq.push(make_tuple(0, 0, 0, 0, 0));
        
        while(!pq.empty()) {
            tuple<int, int, int, int, int> t = pq.top();
            pq.pop();
            
            int d = get<0>(t);
            int type = get<1>(t);
            int p1 = get<2>(t);
            int p2 = get<3>(t);
            int used_k = get<4>(t);
            
            if (type == 0) {
                // Physical Node: p1=r, p2=c
                int r = p1;
                int c = p2;
                
                if (d > dist[r][c][used_k]) continue;
                if (r == m-1 && c == n-1) return d;
                
                // 1. Regular Moves (Right, Down)
                int dr[] = {0, 1};
                int dc[] = {1, 0};
                for(int i=0; i<2; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        int new_cost = d + grid[nr][nc];
                        if(new_cost < dist[nr][nc][used_k]) {
                            dist[nr][nc][used_k] = new_cost;
                            pq.push(make_tuple(new_cost, 0, nr, nc, used_k));
                        }
                    }
                }
                
                // 2. Start Teleport -> Virtual(val, used_k)
                if (used_k < k) {
                    int val = grid[r][c];
                    // Cost 0 to enter virtual node
                    if (d < dist_virtual[val][used_k]) {
                        dist_virtual[val][used_k] = d;
                        pq.push(make_tuple(d, 1, val, 0, used_k));
                    }
                }
            } else {
                // Virtual Node: p1=val
                int val = p1;
                
                if (d > dist_virtual[val][used_k]) continue;
                
                // 1. Flow down to Virtual(val-1, used_k) with cost 0
                if (val > 0) {
                    if (d < dist_virtual[val-1][used_k]) {
                        dist_virtual[val-1][used_k] = d;
                        pq.push(make_tuple(d, 1, val-1, 0, used_k));
                    }
                }
                
                // 2. Land Teleport -> Cell(r, c, used_k + 1)
                int next_k = used_k + 1;
                if (next_k <= k) {
                    for(auto& pair : locations[val]) {
                        int nr = pair.first;
                        int nc = pair.second;
                        if (d < dist[nr][nc][next_k]) {
                            dist[nr][nc][next_k] = d;
                            pq.push(make_tuple(d, 0, nr, nc, next_k));
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};

// Test Runner
void runTest(vector<vector<int>> grid, int k, int expected) {
    Solution sol;
    int result = sol.minCost(grid, k);
    cout << "Test Case: k=" << k << " Result: " << result << " Expected: " << expected;
    if(result == expected) cout << " [PASSED]" << endl;
    else cout << " [FAILED]" << endl;
}

int main() {
    // Ex 1
    vector<vector<int>> grid1 = {{1,3,3},{2,5,4},{4,3,5}};
    runTest(grid1, 2, 7);
    
    // Ex 2
    vector<vector<int>> grid2 = {{1,2},{2,3},{3,4}};
    runTest(grid2, 1, 9);
    
    return 0;
}