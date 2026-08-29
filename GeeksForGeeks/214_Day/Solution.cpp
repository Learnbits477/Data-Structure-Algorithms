#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubsequences(string s, int n) {
        const int MOD = 1e9 + 7;
        
        // dp[r] represents the count of non-empty subsequences formed so far with remainder r modulo n
        vector<int> dp(n, 0);

        for (char ch : s) {
            int digit = ch - '0';
            vector<int> next_dp = dp; // Choice 1: Exclude the current digit

            // Choice 2: Start a new single-digit subsequence with this digit
            int single_rem = digit % n;
            next_dp[single_rem] = (next_dp[single_rem] + 1) % MOD;

            // Choice 3: Append this digit to all existing non-empty subsequences
            for (int r = 0; r < n; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (static_cast<long long>(r) * 10 + digit) % n;
                    next_dp[new_rem] = (next_dp[new_rem] + dp[r]) % MOD;
                }
            }

            dp = move(next_dp);
        }

        // Return the count of non-empty subsequences with remainder 0 modulo n
        return dp[0];
    }

    // Alias to match potential GFG driver function naming variations
    int countDivisibleSubseq(string s, int n) {
        return countSubsequences(s, n);
    }
};
