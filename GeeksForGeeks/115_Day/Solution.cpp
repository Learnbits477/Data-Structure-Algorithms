#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // Step 3: DFS Helper Routine
    void dfs(int r, int c, vector<vector<int>>& grid, int n, int m) {
        // Boundary check and condition to only visit 1s
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0) {
            return;
        }

        // Mark current 1 as visited (by changing to 0)
        grid[r][c] = 0;

        // Visit 4 neighbors (Up, Down, Left, Right)
        dfs(r - 1, c, grid, n, m);
        dfs(r + 1, c, grid, n, m);
        dfs(r, c - 1, grid, n, m);
        dfs(r, c + 1, grid, n, m);
    }

public:
    int cntOnes(vector<vector<int>>& grid) {
        // Step 1: Initialize Grid Dimensions
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        // Step 2: Traverse and Flood Fill from Grid Boundaries
        // Traverse top and bottom boundaries
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                dfs(0, j, grid, n, m);
            }
            if (grid[n - 1][j] == 1) {
                dfs(n - 1, j, grid, n, m);
            }
        }
        // Traverse left and right boundaries
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, grid, n, m);
            }
            if (grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid, n, m);
            }
        }

        // Step 4: Count Remaining Enclaves
        int enclaveCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    enclaveCount++;
                }
            }
        }

        return enclaveCount;
    }
};
