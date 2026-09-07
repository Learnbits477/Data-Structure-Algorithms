#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Computes the number of distinct non-empty subsequences of s modulo 10^9 + 7
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        // last[c] stores the number of distinct subsequences ending with character ('a' + c)
        vector<long long> last(26, 0);

        for (char c : s) {
            long long current_sum = 0;
            for (int j = 0; j < 26; j++) {
                current_sum = (current_sum + last[j]) % MOD;
            }
            // Add 1 for the single-character subsequence consisting only of char c
            last[c - 'a'] = (current_sum + 1) % MOD;
        }

        long long total = 0;
        for (int j = 0; j < 26; j++) {
            total = (total + last[j]) % MOD;
        }

        return (int)total;
    }

    // Platform and driver compatibility aliases
    int distinctSubsequencesII(string s) {
        return distinctSubseqII(s);
    }

    int numDistinctSubseq(string s) {
        return distinctSubseqII(s);
    }
};
