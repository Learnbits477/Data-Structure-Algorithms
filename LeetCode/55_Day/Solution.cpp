#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;
        
        vector<vector<long long>> max_prod(m, vector<long long>(n));
        vector<vector<long long>> min_prod(m, vector<long long>(n));
        
        max_prod[0][0] = min_prod[0][0] = grid[0][0];
        
        for (int i = 1; i < m; ++i) {
            max_prod[i][0] = min_prod[i][0] = max_prod[i-1][0] * grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            max_prod[0][j] = min_prod[0][j] = max_prod[0][j-1] * grid[0][j];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] >= 0) {
                    max_prod[i][j] = max(max_prod[i-1][j], max_prod[i][j-1]) * grid[i][j];
                    min_prod[i][j] = min(min_prod[i-1][j], min_prod[i][j-1]) * grid[i][j];
                } else {
                    max_prod[i][j] = min(min_prod[i-1][j], min_prod[i][j-1]) * grid[i][j];
                    min_prod[i][j] = max(max_prod[i-1][j], max_prod[i][j-1]) * grid[i][j];
                }
            }
        }
        
        if (max_prod[m-1][n-1] < 0) {
            return -1;
        }
        return max_prod[m-1][n-1] % MOD;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid1 = {{-1, -2, -3}, {-2, -3, -3}, {-3, -3, -2}};
    cout << "Example 1 Output: " << solution.maxProductPath(grid1) << endl;

    vector<vector<int>> grid2 = {{1, -2, 1}, {1, -2, 1}, {3, -4, 1}};
    cout << "Example 2 Output: " << solution.maxProductPath(grid2) << endl;

    vector<vector<int>> grid3 = {{1, 3}, {0, -4}};
    cout << "Example 3 Output: " << solution.maxProductPath(grid3) << endl;

    return 0;
}
