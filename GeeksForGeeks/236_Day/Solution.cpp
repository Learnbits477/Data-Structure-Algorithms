#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubsquare(vector<vector<char>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;

        // horiz[r][c]: continuous 'X' count ending at (r, c) horizontally (leftwards)
        // vert[r][c]: continuous 'X' count ending at (r, c) vertically (upwards)
        vector<vector<int>> horiz(n, vector<int>(n, 0));
        vector<vector<int>> vert(n, vector<int>(n, 0));

        // Step 1: Precompute consecutive runs of 'X'
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 'X') {
                    horiz[r][c] = (c > 0 ? horiz[r][c - 1] : 0) + 1;
                    vert[r][c] = (r > 0 ? vert[r - 1][c] : 0) + 1;
                }
            }
        }

        int maxSide = 0;

        // Step 2: Iterate every possible bottom-right corner (r, c) in reverse order
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                // Maximum possible side length bounded by bottom and right edges ending at (r, c)
                int limit = min(horiz[r][c], vert[r][c]);

                // Step 3: Check candidate side lengths k in descending order down to maxSide + 1
                for (int k = limit; k > maxSide; --k) {
                    // Check top edge and left edge
                    if (horiz[r - k + 1][c] >= k && vert[r][c - k + 1] >= k) {
                        maxSide = k;
                        break; // Since k descends, first match is optimal for this cell
                    }
                }
            }
        }

        return maxSide;
    }

    // Overload for platform compatibility with signature (int n, vector<vector<char>> mat)
    int largestSubsquare(int n, vector<vector<char>> mat) {
        return largestSubsquare(mat);
    }
};
