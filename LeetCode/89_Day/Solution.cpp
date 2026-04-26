#include <vector>

using namespace std;

class Solution {
private:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int pr, int pc, char val) {
        visited[r][c] = true;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == val) {
                if (nr == pr && nc == pc) continue; 
                if (visited[nr][nc]) return true; 
                if (dfs(grid, visited, nr, nc, r, c, val)) return true;
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return false;
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
