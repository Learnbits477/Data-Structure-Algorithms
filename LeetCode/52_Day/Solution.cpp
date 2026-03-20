#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> ans(rows - k + 1, vector<int>(cols - k + 1));
        vector<int> vals(k * k);

        for (int i = 0; i <= rows - k; i++) {
            for (int j = 0; j <= cols - k; j++) {
                int idx = 0;
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        vals[idx++] = grid[r][c];
                    }
                }
                
                sort(vals.begin(), vals.end());
                int minDiff = INT_MAX;
                
                for (int p = 1; p < k * k; p++) {
                    if (vals[p] != vals[p - 1]) {
                        minDiff = min(minDiff, vals[p] - vals[p - 1]);
                    }
                }
                
                ans[i][j] = (minDiff == INT_MAX) ? 0 : minDiff;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid1 = {{1, 8}, {3, -2}};
    int k1 = 2;
    vector<vector<int>> ans1 = sol.minAbsDiff(grid1, k1);
    cout << "Example 1 Output:" << endl;
    for (const auto& row : ans1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
