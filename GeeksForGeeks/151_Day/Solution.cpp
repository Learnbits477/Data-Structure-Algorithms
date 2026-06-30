#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(int n, int m) {
        const int MOD = 1000000007;

        // Step 1: Initialize the DP array to store the number of ways for each floor height
        vector<long long> dp(n + 1, 0);

        // Step 2: Iterate through all floor heights from 0 to n
        for (int i = 0; i <= n; i++) {
            // Step 3: Base case - height is less than tile width m, only horizontal placement is possible
            if (i < m) {
                dp[i] = 1;
            }
            // Step 4: Base case - height is equal to m, can place all horizontal or all vertical tiles (2 ways)
            else if (i == m) {
                dp[i] = 2;
            }
            // Step 5: Transition - place one horizontal tile (dp[i-1]) or m vertical tiles (dp[i-m])
            else {
                dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
            }
        }

        // Step 6: Return the number of ways to tile a floor of height n
        return dp[n];
    }
};
