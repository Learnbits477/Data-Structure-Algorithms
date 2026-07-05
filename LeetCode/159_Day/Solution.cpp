#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        // dp[i][j] stores pair of {max_score, number_of_paths}
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        
        // Step 1 — Initialize Arrays and Offset Variables
        // Start from bottom-right 'S' with score 0 and 1 valid path
        dp[n - 1][n - 1] = {0, 1};
        
        // Step 2 — Iterate Through the String/Matrix
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Skip the start cell or obstacles
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                    continue;
                }
                
                // Step 3 — Apply Constant Time State Transitions
                int max_s = -1;
                int count = 0;
                
                // Three possible predecessors: down, right, and diagonal-down-right
                int dirs[3][2] = {{0, 1}, {1, 0}, {1, 1}};
                for (auto& d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    
                    if (ni < n && nj < n && dp[ni][nj].first != -1) {
                        if (dp[ni][nj].first > max_s) {
                            max_s = dp[ni][nj].first;
                            count = dp[ni][nj].second;
                        } else if (dp[ni][nj].first == max_s) {
                            count = (count + dp[ni][nj].second) % MOD;
                        }
                    }
                }
                
                // If at least one predecessor is reachable, update current cell
                if (max_s != -1) {
                    int val = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                    dp[i][j] = {max_s + val, count};
                }
            }
        }
        
        // Step 4 — Return the Result
        if (dp[0][0].first == -1) {
            return {0, 0};
        }
        return {dp[0][0].first, dp[0][0].second};
    }
};
