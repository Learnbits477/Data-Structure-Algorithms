#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    template <typename Matrix>
    int computeMaxArea(const Matrix& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        if (m == 0) return 0;

        // Step 1: Precompute consecutive 1s ending at each cell (histogram heights)
        // hist[i][j] represents the height of continuous 1s ending at (i, j)
        vector<vector<int>> hist(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            hist[0][j] = mat[0][j] ? 1 : 0;
            for (int i = 1; i < n; ++i) {
                hist[i][j] = (!mat[i][j]) ? 0 : hist[i - 1][j] + 1;
            }
        }

        int max_area = 0;

        // Step 2: For each row, count frequencies of heights using Counting Sort
        // Since heights are bounded by [0, n], counting sort runs in O(n + m) per row.
        // Overall Time Complexity: O(n * (n + m))
        vector<int> count(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            fill(count.begin(), count.end(), 0);

            // Frequency of each height in the current row
            for (int j = 0; j < m; ++j) {
                count[hist[i][j]]++;
            }

            // width accumulates the number of columns with height >= h
            int width = 0;
            for (int h = n; h >= 1; --h) {
                width += count[h];
                max_area = max(max_area, h * width);
            }
        }

        return max_area;
    }

public:
    int maxArea(vector<vector<int>> &mat) {
        return computeMaxArea(mat);
    }

    int maxArea(vector<vector<bool>> &mat) {
        return computeMaxArea(mat);
    }
};
