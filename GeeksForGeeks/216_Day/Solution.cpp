#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, int i, int d, int c) {
        if (n <= 0) return 0;
        if (n == 1) return i;

        // dp[x] stores the minimum cost to obtain exactly x characters
        vector<long long> dp(n + 1, 0);

        // Step 1: Base Case
        dp[1] = i;

        // Step 2: Tabulation DP from 2 up to n
        for (int x = 2; x <= n; ++x) {
            if (x % 2 == 0) {
                // If even, we can either insert from (x - 1) or double from (x / 2)
                dp[x] = min(dp[x - 1] + i, dp[x / 2] + c);
            } else {
                // If odd, we can either insert from (x - 1) or double from (x + 1)/2 and delete 1
                dp[x] = min(dp[x - 1] + i, dp[(x + 1) / 2] + c + d);
            }
        }

        // Step 3: Return minimum cost for n characters
        return static_cast<int>(dp[n]);
    }

    // Aliases for driver/platform function name compatibility
    int minTime(int n, int i, int d, int c) {
        return minCost(n, i, d, c);
    }

    int minimumCost(int n, int i, int d, int c) {
        return minCost(n, i, d, c);
    }
};
