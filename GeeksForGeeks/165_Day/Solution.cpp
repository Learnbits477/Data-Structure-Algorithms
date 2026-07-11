#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<vector<int>>& mat, int r, int c, int xd, int yd, int dist, int& maxDist, int n, int m) {
        // Base case: destination reached
        if (r == xd && c == yd) {
            maxDist = max(maxDist, dist);
            return;
        }

        // Step 3: Depth First Search with Backtracking
        // Mark current cell as visited
        mat[r][c] = 0;

        // Directions: Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1) {
                solve(mat, nr, nc, xd, yd, dist + 1, maxDist, n, m);
            }
        }

        // Restore the cell (Backtrack)
        mat[r][c] = 1;
    }

public:
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // Step 1: Check Feasibility
        if (mat.empty() || mat[0].empty()) return -1;
        int n = mat.size();
        int m = mat[0].size();
        
        if (xs < 0 || xs >= n || ys < 0 || ys >= m || xd < 0 || xd >= n || yd < 0 || yd >= m) {
            return -1;
        }
        if (mat[xs][ys] == 0 || mat[xd][yd] == 0) return -1;

        // Step 2: Initialize Maximum Distance
        int maxDist = -1;

        // Start DFS
        solve(mat, xs, ys, xd, yd, 0, maxDist, n, m);

        // Step 4: Return Result
        return maxDist;
    }
};
