#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int palindromicStrings(int n, int k) {
        const int MOD = 1e9 + 7;
        long long totalCount = 0;

        // Step 1: Precompute permutations P(k, r) for r = 0 to k
        // P[r] stores P(k, r) = k * (k - 1) * ... * (k - r + 1) % MOD
        // For r = 0, P(k, 0) = 1; for r > k, P(k, r) = 0
        vector<long long> P(k + 1, 0);
        P[0] = 1;
        for (int r = 1; r <= k; ++r) {
            P[r] = (P[r - 1] * (k - r + 1)) % MOD;
        }

        // Step 2: Iterate over all possible palindrome lengths L from 1 to n
        // Number of distinct characters required = ceil(L / 2) = (L + 1) / 2
        for (int L = 1; L <= n; ++L) {
            int distinctNeeded = (L + 1) / 2;
            if (distinctNeeded <= k) {
                // Step 3: Accumulate valid permutations modulo 10^9 + 7
                totalCount = (totalCount + P[distinctNeeded]) % MOD;
            }
        }

        // Step 4: Return total valid palindromic strings count
        return static_cast<int>(totalCount);
    }

    // Aliases for driver/platform function name compatibility
    int countPalindromicStrings(int n, int k) {
        return palindromicStrings(n, k);
    }

    int numberOfPalindromicStrings(int n, int k) {
        return palindromicStrings(n, k);
    }
};
