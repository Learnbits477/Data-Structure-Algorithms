#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        const int UNREACH = -1;
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, UNREACH)));

        dp[0][0][0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    for (int c = 0; c <= k; c++) {
                        if (dp[i-1][j][c] == UNREACH) continue;
                        int val   = grid[i][j];
                        int score = (val == 2) ? 2 : val;
                        int cost  = (val >= 1) ? 1 : 0;
                        int nc    = c + cost;
                        if (nc > k) continue;
                        dp[i][j][nc] = max(dp[i][j][nc],
                                           dp[i-1][j][c] + score);
                    }
                }
                
                if (j > 0) {
                    for (int c = 0; c <= k; c++) {
                        if (dp[i][j-1][c] == UNREACH) continue;
                        int val   = grid[i][j];
                        int score = (val == 2) ? 2 : val;
                        int cost  = (val >= 1) ? 1 : 0;
                        int nc    = c + cost;
                        if (nc > k) continue;
                        dp[i][j][nc] = max(dp[i][j][nc],
                                           dp[i][j-1][c] + score);
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            if (dp[m-1][n-1][c] != UNREACH)
                ans = max(ans, dp[m-1][n-1][c]);
        }
        return ans;
    }
};
