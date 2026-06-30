#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();

        const long long NEG = -1e18;

        // Step 1 — Initialize DP Table
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, NEG));

        // Step 2 — Set Base Cases
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        // Step 3 — Iterate and Transition
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j - 1] + 1LL * a[i - 1] * b[j - 1]);
            }
        }

        // Step 4 — Return Result
        return (int)dp[n][m];
    }
};
