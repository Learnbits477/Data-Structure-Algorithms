#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total = 0;
        vector<long long> rowSum(m, 0);
        vector<long long> colSum(n, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                total += grid[i][j];
            }
        }
        
        if (total % 2 != 0) return false;
        long long target = total / 2;
        
        long long current = 0;
        for (int i = 0; i < m - 1; ++i) {
            current += rowSum[i];
            if (current == target) return true;
        }
        
        current = 0;
        for (int j = 0; j < n - 1; ++j) {
            current += colSum[j];
            if (current == target) return true;
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {{1, 4}, {2, 3}};
    cout << "Example 1 Output: " << (sol.canPartitionGrid(grid1) ? "true" : "false") << endl;
    
    vector<vector<int>> grid2 = {{1, 3}, {2, 4}};
    cout << "Example 2 Output: " << (sol.canPartitionGrid(grid2) ? "true" : "false") << endl;
    
    return 0;
}
