#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Total path length is (m - 1) + (n - 1) + 1 = m + n - 1
        // A valid parentheses string must have an even length
        if ((m + n - 1) % 2 != 0) {
            return false;
        }

        // Start must be '(' and end must be ')'
        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')') {
            return false;
        }

        // dp[r][c] represents the set of all achievable open parenthesis counts at cell (r, c).
        // Since m, n <= 100, the maximum open count cannot exceed (100 + 100 - 1) / 2 = 99 < 105.
        vector<vector<bitset<105>>> dp(m, vector<bitset<105>>(n));

        // Base case at (0, 0): open count is 1
        dp[0][0][1] = 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r == 0 && c == 0) continue;

                bitset<105> mask;
                if (r > 0) mask |= dp[r - 1][c];
                if (c > 0) mask |= dp[r][c - 1];

                if (grid[r][c] == '(') {
                    // '(' increments open bracket count
                    dp[r][c] = mask << 1;
                } else {
                    // ')' decrements open bracket count
                    // A balance of 0 shifted right is discarded, naturally pruning invalid negative counts
                    dp[r][c] = mask >> 1;
                }
            }
        }

        // Return true if a path ends with balance 0 (bit 0 is set)
        return dp[m - 1][n - 1][0];
    }
};
