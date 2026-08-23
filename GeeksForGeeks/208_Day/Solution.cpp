#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Finds the number of distinct empty cells Geek can visit in the maze.
     * Uses 0-1 BFS to find the minimum upward moves needed to reach each cell.
     * 
     * Time Complexity:  O(n * m)
     * Space Complexity: O(n * m)
     */
    int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat) {
        // Base case: If start cell is out of bounds or an obstacle
        if (r < 0 || r >= n || c < 0 || c >= m || mat[r][c] == '#') {
            return 0;
        }

        // dist[i][j] stores the minimum number of UP moves needed to reach cell (i, j)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;

        // Start at (r, c) with 0 up moves
        dist[r][c] = 0;
        dq.push_back({r, c});

        // Direction vectors: Up (-1,0), Down (+1,0), Left (0,-1), Right (0,+1)
        const int dx[4] = {-1, 1, 0, 0};
        const int dy[4] = {0, 0, -1, 1};
        const int upCost[4] = {1, 0, 0, 0}; // Only UP move incurs a cost of 1 up move

        int reachableCount = 1; // Starting cell (r, c) is visited

        while (!dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();

            int x = curr.first;
            int y = curr.second;
            int cur_u = dist[x][y];

            // Explore all 4 adjacent neighbors
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // Check bounds and obstacle
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == '.') {
                    int next_u = cur_u + upCost[i];
                    // Using net vertical displacement: D = U + (nx - r)
                    int next_d = next_u + (nx - r);

                    // Check if moves are within allowed bounds and improves minimum up moves
                    if (next_u <= u && next_d <= d && next_u < dist[nx][ny]) {
                        if (dist[nx][ny] == INT_MAX) {
                            reachableCount++;
                        }
                        dist[nx][ny] = next_u;

                        // 0-1 BFS: 0-weight edges go to front, 1-weight edges go to back
                        if (upCost[i] == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        return reachableCount;
    }

    /**
     * Overload for signatures omitting n and m.
     */
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        return numberOfCells(mat.size(), mat[0].size(), r, c, u, d, mat);
    }
};
