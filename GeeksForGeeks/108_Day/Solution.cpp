#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int optimalKeys(int n) {
        // Step 1: Handle Base Cases
        if (n <= 6) {
            return n;
        }

        // Step 2: Initialize DP Array
        vector<long long int> dp(n + 1, 0);
        
        for (int i = 1; i <= 6; i++) {
            dp[i] = i;
        }

        // Step 3: Iterate for Larger n
        for (int i = 7; i <= n; i++) {
            // Step 4: Find Optimal Break Point
            for (int j = i - 3; j >= 1; j--) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }

        // Step 5: Return Result
        return dp[n];
    }
};
