#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(int n) {
        // Step 1: Handle Base Cases
        if (n == 0) return 0;

        // Step 2: Initialize DP Table
        vector<int> dp(n + 1, 0);

        // Step 3: Bottom-Up DP Computation
        for (int i = 1; i <= n; ++i) {
            dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
        }

        // Step 4: Return Results
        return dp[n];
    }
};
