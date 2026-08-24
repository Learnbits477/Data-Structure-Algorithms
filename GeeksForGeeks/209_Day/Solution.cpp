#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixStrings(int n) {
        // Step 1: Initialize DP table with base case
        const int MOD = 1000000007;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        // Step 2: Compute Catalan numbers iteratively
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = (dp[i] + (dp[j] * dp[i - 1 - j]) % MOD) % MOD;
            }
        }

        // Step 3: Return result
        return (int)dp[n];
    }
};
