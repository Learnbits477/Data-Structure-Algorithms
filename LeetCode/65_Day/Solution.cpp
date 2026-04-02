#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Maximum Amount of Money Robot Can Earn
 * Link: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        const int INF = 1e9;
        
        // dp[i][j][k] represents the max profit at (i, j) using exactly k neutralizations.
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -INF)));
        
        // Base case initialization for the starting cell
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip the starting cell as it's already properly initialized
                if (i == 0 && j == 0) continue;
                
                for (int k = 0; k < 3; ++k) {
                    // Find the maximum from reachable neighbor cells (top and left) 
                    // that also use exactly k neutralizations so far
                    int prev = -INF;
                    if (i > 0) prev = max(prev, dp[i - 1][j][k]);
                    if (j > 0) prev = max(prev, dp[i][j - 1][k]);
                    
                    // Case 1: Do not use a neutralization at the current cell.
                    // This is applicable regardless of whether the cell is negative
                    if (prev != -INF) {
                        dp[i][j][k] = max(dp[i][j][k], prev + coins[i][j]);
                    }
                    
                    // Case 2: Use a neutralization at the current cell (if possible).
                    // This option is viable only if the current cell contains a robber (coins[i][j] < 0) 
                    // and we have executed at least 1 neutralization previously.
                    if (coins[i][j] < 0 && k > 0) {
                        int prev_k = -INF;
                        if (i > 0) prev_k = max(prev_k, dp[i - 1][j][k - 1]);
                        if (j > 0) prev_k = max(prev_k, dp[i][j - 1][k - 1]);
                        
                        // Because neutralization provides a zero drop over negative value,
                        // we effectively add 0 to the accrued value `prev_k`
                        if (prev_k != -INF) {
                            dp[i][j][k] = max(dp[i][j][k], prev_k);
                        }
                    }
                }
            }
        }
        
        // Final aggregate answer will be the highest value across any combination configurations
        int ans = -INF;
        for (int k = 0; k < 3; ++k) {
            ans = max(ans, dp[m - 1][n - 1][k]);
        }
        
        return ans;
    }
};

int main() {
    // Example test harness for local validation
    int t;
    if (cin >> t) {
        while (t--) {
            int m, n;
            cin >> m >> n;
            vector<vector<int>> coins(m, vector<int>(n));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    cin >> coins[i][j];
                }
            }
            Solution obj;
            cout << obj.maximumAmount(coins) << endl;
        }
    }
    return 0;
}
