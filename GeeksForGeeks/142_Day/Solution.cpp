#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        int totalCoverage = 0;

        // Step 1 — Left-to-Right Pass
        for (int i = 0; i < n; ++i) {
            bool has_one = false;
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    has_one = true;
                } else if (mat[i][j] == 0 && has_one) {
                    totalCoverage++;
                }
            }
        }

        // Step 2 — Right-to-Left Pass
        for (int i = 0; i < n; ++i) {
            bool has_one = false;
            for (int j = m - 1; j >= 0; --j) {
                if (mat[i][j] == 1) {
                    has_one = true;
                } else if (mat[i][j] == 0 && has_one) {
                    totalCoverage++;
                }
            }
        }

        // Step 3 — Top-to-Bottom Pass
        for (int j = 0; j < m; ++j) {
            bool has_one = false;
            for (int i = 0; i < n; ++i) {
                if (mat[i][j] == 1) {
                    has_one = true;
                } else if (mat[i][j] == 0 && has_one) {
                    totalCoverage++;
                }
            }
        }

        // Step 4 — Bottom-to-Top Pass
        for (int j = 0; j < m; ++j) {
            bool has_one = false;
            for (int i = n - 1; i >= 0; --i) {
                if (mat[i][j] == 1) {
                    has_one = true;
                } else if (mat[i][j] == 0 && has_one) {
                    totalCoverage++;
                }
            }
        }

        return totalCoverage;
    }
};
