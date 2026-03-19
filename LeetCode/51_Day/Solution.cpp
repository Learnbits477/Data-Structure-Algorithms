#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // To optimize memory, we only need to keep track of prefix counts dynamically for columns.
        // We use pairs to store {countX, countY} for every column j up to the current row.
        vector<pair<int, int>> prevRowTotals(n, {0, 0});
        
        int ans = 0;
        
        for (int i = 0; i < m; ++i) {
            int rowRunningCountX = 0;
            int rowRunningCountY = 0;
            
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'X') {
                    rowRunningCountX++;
                } else if (grid[i][j] == 'Y') {
                    rowRunningCountY++;
                }
                
                // Cumulative counts from grid[0][0] to grid[i][j]
                prevRowTotals[j].first += rowRunningCountX;
                prevRowTotals[j].second += rowRunningCountY;
                
                if (prevRowTotals[j].first > 0 && prevRowTotals[j].first == prevRowTotals[j].second) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid1 = {{'X','Y','.'},{'Y','.','.'}};
    cout << "Example 1 Output: " << sol.numberOfSubmatrices(grid1) << endl; // Expected: 3
    
    vector<vector<char>> grid2 = {{'X','X'},{'X','Y'}};
    cout << "Example 2 Output: " << sol.numberOfSubmatrices(grid2) << endl; // Expected: 0
    
    vector<vector<char>> grid3 = {{'.','.'},{'.','.'}};
    cout << "Example 3 Output: " << sol.numberOfSubmatrices(grid3) << endl; // Expected: 0
    
    return 0;
}
