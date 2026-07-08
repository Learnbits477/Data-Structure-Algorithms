#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int r, int c, int prevVal, const vector<vector<int>>& mat, vector<vector<bool>>& visited, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || mat[r][c] < prevVal) {
            return;
        }
        
        visited[r][c] = true;
        
        dfs(r + 1, c, mat[r][c], mat, visited, n, m);
        dfs(r - 1, c, mat[r][c], mat, visited, n, m);
        dfs(r, c + 1, mat[r][c], mat, visited, n, m);
        dfs(r, c - 1, mat[r][c], mat, visited, n, m);
    }

public:
    int countCoordinates(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        if (m == 0) return 0;
        
        // Step 1 — Reachability Matrices Initialization
        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));
        
        // Step 2 — Traversal from Station P Boundaries (Top & Left)
        for (int c = 0; c < m; ++c) {
            dfs(0, c, mat[0][c], mat, reachP, n, m);
        }
        for (int r = 0; r < n; ++r) {
            dfs(r, 0, mat[r][0], mat, reachP, n, m);
        }
        
        // Step 3 — Traversal from Station Q Boundaries (Bottom & Right)
        for (int c = 0; c < m; ++c) {
            dfs(n - 1, c, mat[n - 1][c], mat, reachQ, n, m);
        }
        for (int r = 0; r < n; ++r) {
            dfs(r, m - 1, mat[r][m - 1], mat, reachQ, n, m);
        }
        
        // Step 4 — Counting the Intersection
        int commonCount = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (reachP[r][c] && reachQ[r][c]) {
                    commonCount++;
                }
            }
        }
        
        return commonCount;
    }

    int geeksIsland(vector<vector<int>> &mat, int n, int m) {
        return countCoordinates(mat);
    }
};
