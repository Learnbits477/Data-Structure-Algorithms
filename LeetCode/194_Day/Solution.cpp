#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // Step 1: Precompute Suffix Sums
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Step 2: Initialize DP Table
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Step 3: Iterate Backward
        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                // Case A: Take all remaining piles
                if (i + 2 * M >= n) {
                    dp[i][M] = suffixSum[i];
                    continue;
                }
                
                // Case B: Try all valid pile splits
                int maxStones = 0;
                for (int X = 1; X <= 2 * M; ++X) {
                    int nextM = min(n, max(M, X));
                    maxStones = max(maxStones, suffixSum[i] - dp[i + X][nextM]);
                }
                dp[i][M] = maxStones;
            }
        }

        // Step 4: Extract Answer
        return dp[0][1];
    }
};
