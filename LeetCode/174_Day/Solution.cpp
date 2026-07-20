#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k % total;
        
        if (k == 0) return grid;
        
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int flat_idx = i * n + j;
                int new_flat_idx = (flat_idx + k) % total;
                result[new_flat_idx / n][new_flat_idx % n] = grid[i][j];
            }
        }
        return result;
    }
};
