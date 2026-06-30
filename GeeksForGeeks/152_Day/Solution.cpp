#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStrings(int n, int k) {
        const int MOD = 1000000007;

        // Step 1 — Initialize DP Table
        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(k + 2, vector<long long>(2, 0))
        );

        // Step 2 — Set Base Cases
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;

        // Step 3 — Iterate and Transition
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[i][j][0]) {
                    dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][0]) % MOD;
                    dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][0]) % MOD;
                }

                if (dp[i][j][1]) {
                    dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][1]) % MOD;

                    if (j + 1 <= k) {
                        dp[i + 1][j + 1][1] =
                            (dp[i + 1][j + 1][1] + dp[i][j][1]) % MOD;
                    }
                }
            }
        }

        // Step 4 — Sum and Return Result
        return (dp[n][k][0] + dp[n][k][1]) % MOD;
    }
};
