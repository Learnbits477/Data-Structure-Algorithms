#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ways(int x, int y) {
        const int MOD = 1000000007;

        // dp[i][j] stores the number of paths from (i, j) to (0, 0)
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        // Base cases:
        // When on the axes, there is only 1 path to reach the origin
        for (int i = 0; i <= x; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j <= y; ++j) {
            dp[0][j] = 1;
        }

        // Fill the DP table using bottom-up transition
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }

        return dp[x][y];
    }

    int waysToReachOrigin(int x, int y) {
        return ways(x, y);
    }

    int waysSpaceOptimized(int x, int y) {
        const int MOD = 1000000007;
        vector<int> dp(y + 1, 1);

        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }

        return dp[y];
    }
};
