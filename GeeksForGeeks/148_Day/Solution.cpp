#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to solve the maze recursively using backtracking
    bool solve(int i, int j, vector<vector<int>>& mat,
               vector<vector<int>>& ans,
               vector<vector<int>>& vis, int n) {

        // Step 1 — Base Case Check: If destination is reached, mark it and return true
        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }

        // Step 2 — Validity Check: Return false if out of bounds, blocked, or already visited
        if (i >= n || j >= n || mat[i][j] == 0 || vis[i][j])
            return false;

        // Step 3 — Mark Visited & Active Path: Mark the cell in vis and ans
        vis[i][j] = 1;
        ans[i][j] = 1;

        // Step 4 — Explore Jumps: Shortest jumps first, Right before Down
        for (int jump = 1; jump <= mat[i][j]; jump++) {
            // Try moving Right first
            if (j + jump < n && solve(i, j + jump, mat, ans, vis, n))
                return true;

            // Try moving Down second
            if (i + jump < n && solve(i + jump, j, mat, ans, vis, n))
                return true;
        }

        // Step 5 — Backtrack: Reset the cell in ans if no path is found
        ans[i][j] = 0;
        return false;
    }

    // Main solver function to find the shortest-jump path
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();

        if (n == 1)
            return {{1}};

        // Step 6 — Entry Point: Initialize matrices and start recursion
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (solve(0, 0, mat, ans, vis, n))
            return ans;

        return {{-1}};
    }
};
