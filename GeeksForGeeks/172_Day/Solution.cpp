#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        const int MOD = 1e9 + 7;

        // Step 1: Compute 1-Density and Indices
        vector<vector<int>> count1(n + 1, vector<int>(m + 1, 0));
        for (int r = n - 1; r >= 0; --r) {
            for (int c = m - 1; c >= 0; --c) {
                count1[r][c] = (matrix[r][c] == 1) + count1[r + 1][c] + count1[r][c + 1] - count1[r + 1][c + 1];
            }
        }

        vector<vector<bool>> row_has_1(n, vector<bool>(m, false));
        for (int r = 0; r < n; ++r) {
            for (int c = m - 1; c >= 0; --c) {
                row_has_1[r][c] = (matrix[r][c] == 1) || (c + 1 < m && row_has_1[r][c + 1]);
            }
        }

        vector<vector<bool>> col_has_1(n, vector<bool>(m, false));
        for (int c = 0; c < m; ++c) {
            for (int r = n - 1; r >= 0; --r) {
                col_has_1[r][c] = (matrix[r][c] == 1) || (r + 1 < n && col_has_1[r + 1][c]);
            }
        }

        vector<vector<int>> next_row_with_1(n, vector<int>(m, n));
        for (int c = 0; c < m; ++c) {
            for (int r = n - 1; r >= 0; --r) {
                next_row_with_1[r][c] = row_has_1[r][c] ? r : (r + 1 < n ? next_row_with_1[r + 1][c] : n);
            }
        }

        vector<vector<int>> next_col_with_1(n, vector<int>(m, m));
        for (int r = 0; r < n; ++r) {
            for (int c = m - 1; c >= 0; --c) {
                next_col_with_1[r][c] = col_has_1[r][c] ? c : (c + 1 < m ? next_col_with_1[r][c + 1] : m);
            }
        }

        // Step 2: Base Case (k = 1)
        vector<vector<int>> prev_dp(n, vector<int>(m, 0));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                prev_dp[r][c] = (count1[r][c] > 0) ? 1 : 0;
            }
        }

        // Step 3: DP Transitions (p = 2 to k)
        for (int p = 2; p <= k; ++p) {
            vector<vector<int>> dp(n, vector<int>(m, 0));

            // Compute suffix sums of prev_dp along rows and columns
            vector<vector<int>> sum_row(n + 1, vector<int>(m + 1, 0));
            for (int c = 0; c < m; ++c) {
                for (int r = n - 1; r >= 0; --r) {
                    sum_row[r][c] = (prev_dp[r][c] + sum_row[r + 1][c]) % MOD;
                }
            }

            vector<vector<int>> sum_col(n + 1, vector<int>(m + 1, 0));
            for (int r = 0; r < n; ++r) {
                for (int c = m - 1; c >= 0; --c) {
                    sum_col[r][c] = (prev_dp[r][c] + sum_col[r][c + 1]) % MOD;
                }
            }

            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < m; ++c) {
                    if (count1[r][c] == 0) {
                        dp[r][c] = 0;
                        continue;
                    }

                    long long ways = 0;

                    // Horizontal cuts
                    int i_first = next_row_with_1[r][c] + 1;
                    if (i_first < n) {
                        ways = (ways + sum_row[i_first][c]) % MOD;
                    }

                    // Vertical cuts
                    int j_first = next_col_with_1[r][c] + 1;
                    if (j_first < m) {
                        ways = (ways + sum_col[r][j_first]) % MOD;
                    }

                    dp[r][c] = ways;
                }
            }
            prev_dp = move(dp);
        }

        return prev_dp[0][0];
    }
};
