#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 0) return -1;
        int m = mat[0].size();
        if (m == 0) return -1;

        // Step 1: Pre-process hazard cells (landmines and their 4-directional neighbors)
        vector<vector<bool>> isSafe(n, vector<bool>(m, true));
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    isSafe[i][j] = false;
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dr[d];
                        int nj = j + dc[d];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            isSafe[ni][nj] = false;
                        }
                    }
                }
            }
        }

        // Step 2: Multi-source queue initialization from all safe cells in column 0
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (isSafe[i][0]) {
                dist[i][0] = 1;
                q.push({i, 0});
            }
        }

        // Step 3: Breadth-First Search (BFS) Traversal
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            // Destination reached: any cell in the rightmost column
            if (c == m - 1) {
                return dist[r][c];
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && isSafe[nr][nc] && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 4: Return default failure if no path exists
        return -1;
    }

    int shortestPath(vector<vector<int>> &mat) {
        return findShortestPath(mat);
    }
};
