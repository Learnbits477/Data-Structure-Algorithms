#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(int n, int sum) {
        // Step 1: Check Feasibility
        if (sum < 1 || sum > 9 * n) {
            return -1;
        }

        // Step 2: Initialize DP Table
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;

        // Step 3: Compute DP Transitions
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                for (int d = 0; d <= 9; ++d) {
                    if (j - d >= 0) {
                        dp[i][j] += dp[i - 1][j - d];
                    }
                }
            }
        }

        // Step 4: Calculate the Final Answer
        int ans = 0;
        for (int d = 1; d <= 9; ++d) {
            if (sum - d >= 0) {
                ans += dp[n - 1][sum - d];
            }
        }

        return ans;
    }
};
