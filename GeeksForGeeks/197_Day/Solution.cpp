#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        // Step 1: State Definition
        int n = grid.size();
        int mod = 1e9 + 7;
        
        vector<vector<int>> paths(n, vector<int>(n, 0));
        vector<vector<int>> maxAdv(n, vector<int>(n, 0));
        vector<vector<bool>> reachable(n, vector<bool>(n, false));
        
        // Step 2: Base Case Initialization
        paths[0][0] = 1;
        maxAdv[0][0] = grid[0][0];
        reachable[0][0] = true;
        
        // Step 3: DP Transitions
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!reachable[i][j]) continue;
                
                int val = grid[i][j];
                
                // Move Right (val == 1 or val == 3)
                if (val == 1 || val == 3) {
                    if (j + 1 < n) {
                        reachable[i][j + 1] = true;
                        paths[i][j + 1] = (paths[i][j + 1] + paths[i][j]) % mod;
                        maxAdv[i][j + 1] = max(maxAdv[i][j + 1], maxAdv[i][j] + grid[i][j + 1]);
                    }
                }
                
                // Move Down (val == 2 or val == 3)
                if (val == 2 || val == 3) {
                    if (i + 1 < n) {
                        reachable[i + 1][j] = true;
                        paths[i + 1][j] = (paths[i + 1][j] + paths[i][j]) % mod;
                        maxAdv[i + 1][j] = max(maxAdv[i + 1][j], maxAdv[i][j] + grid[i + 1][j]);
                    }
                }
            }
        }
        
        // Step 4: Answer Extraction
        if (!reachable[n - 1][n - 1]) {
            return {0, 0};
        }
        
        return {paths[n - 1][n - 1], maxAdv[n - 1][n - 1]};
    }
};
