#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Computes the number of distinct subsequences of s that equal t
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m < n) return 0;

        // dp[j] represents the number of distinct subsequences of current prefix of s that equal t[0..j-1]
        // Using unsigned long long to avoid intermediate integer overflow before casting to int
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // Empty string t is formed by 1 empty subsequence

        for (int i = 0; i < m; i++) {
            for (int j = n; j >= 1; j--) {
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return (int)dp[n];
    }

    // Aliases for compatibility
    int distinctSubsequences(string s, string t) {
        return numDistinct(s, t);
    }
};
