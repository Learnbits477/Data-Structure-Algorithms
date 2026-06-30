#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(string &s1, string &s2) {
        const int MOD = 1000000007;
        int n = s1.size(), m = s2.size();

        // Step 1: Initialize the DP array where dp[j] holds counts of subsequences of length j
        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        // Step 2: Traverse s1 and update the DP state backwards to avoid using same character twice
        for (int i = 0; i < n; i++) {
            for (int j = m; j >= 1; j--) {
                // Step 3: If characters match, add ways from subsequence of length j-1
                if (s1[i] == s2[j - 1]) {
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
                }
            }
        }

        // Step 4: Return the total count of subsequences matching s2
        return dp[m];
    }
};
