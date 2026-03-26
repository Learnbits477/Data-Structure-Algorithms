#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total_sum = 0;
        vector<long long> row_sum(m, 0);
        vector<long long> col_sum(n, 0);
        
        int MAX_VAL = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                MAX_VAL = max(MAX_VAL, grid[i][j]);
                row_sum[i] += grid[i][j];
                col_sum[j] += grid[i][j];
                total_sum += grid[i][j];
            }
        }
        
        vector<int> min_r(MAX_VAL + 1, 1e9);
        vector<int> max_r(MAX_VAL + 1, -1);
        vector<int> min_c(MAX_VAL + 1, 1e9);
        vector<int> max_c(MAX_VAL + 1, -1);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                min_r[v] = min(min_r[v], i);
                max_r[v] = max(max_r[v], i);
                min_c[v] = min(min_c[v], j);
                max_c[v] = max(max_c[v], j);
            }
        }
        
        // Horizontal cuts
        long long S_top = 0;
        for (int r = 0; r < m - 1; r++) {
            S_top += row_sum[r];
            long long S_bottom = total_sum - S_top;
            
            if (S_top == S_bottom) return true;
            
            if (S_top > S_bottom) {
                long long diff = S_top - S_bottom;
                if (diff <= MAX_VAL) {
                    if (n == 1) {
                        if (diff == grid[0][0] || diff == grid[r][0]) return true;
                    } else if (r == 0) {
                        if (diff == grid[0][0] || diff == grid[0][n-1]) return true;
                    } else {
                        if (min_r[diff] <= r) return true;
                    }
                }
            } else {
                long long diff = S_bottom - S_top;
                if (diff <= MAX_VAL) {
                    if (n == 1) {
                        if (diff == grid[r+1][0] || diff == grid[m-1][0]) return true;
                    } else if (r == m - 2) {
                        if (diff == grid[m-1][0] || diff == grid[m-1][n-1]) return true;
                    } else {
                        if (max_r[diff] >= r + 1) return true;
                    }
                }
            }
        }
        
        // Vertical cuts
        long long S_left = 0;
        for (int c = 0; c < n - 1; c++) {
            S_left += col_sum[c];
            long long S_right = total_sum - S_left;
            
            if (S_left == S_right) return true;
            
            if (S_left > S_right) {
                long long diff = S_left - S_right;
                if (diff <= MAX_VAL) {
                    if (m == 1) {
                        if (diff == grid[0][0] || diff == grid[0][c]) return true;
                    } else if (c == 0) {
                        if (diff == grid[0][0] || diff == grid[m-1][0]) return true;
                    } else {
                        if (min_c[diff] <= c) return true;
                    }
                }
            } else {
                long long diff = S_right - S_left;
                if (diff <= MAX_VAL) {
                    if (m == 1) {
                        if (diff == grid[0][c+1] || diff == grid[0][n-1]) return true;
                    } else if (c == n - 2) {
                        if (diff == grid[0][n-1] || diff == grid[m-1][n-1]) return true;
                    } else {
                        if (max_c[diff] >= c + 1) return true;
                    }
                }
            }
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> grid1 = {{1, 4}, {2, 3}};
    cout << "Example 1: " << (sol.canPartitionGrid(grid1) ? "true" : "false") << " (Expected: true)\n";
    
    // Example 2
    vector<vector<int>> grid2 = {{1, 2}, {3, 4}};
    cout << "Example 2: " << (sol.canPartitionGrid(grid2) ? "true" : "false") << " (Expected: true)\n";
    
    // Example 3
    vector<vector<int>> grid3 = {{1, 2, 4}, {2, 3, 5}};
    cout << "Example 3: " << (sol.canPartitionGrid(grid3) ? "true" : "false") << " (Expected: false)\n";
    
    // Example 4
    vector<vector<int>> grid4 = {{4, 1, 8}, {3, 2, 6}};
    cout << "Example 4: " << (sol.canPartitionGrid(grid4) ? "true" : "false") << " (Expected: false)\n";
    
    return 0;
}
