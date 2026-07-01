#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct Cell {
        int safeness;
        int r;
        int c;
        
        // Constructor for compatibility
        Cell(int s, int row, int col) : safeness(s), r(row), c(col) {}

        bool operator<(const Cell& other) const {
            return safeness < other.safeness;
        }
    };

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1 — Run Multi-Source BFS for Safeness Distances
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Initialize BFS with all thief coordinates
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        // Direction arrays for four cardinal moves
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2 — Find the Safest Path using a Max-Heap
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        priority_queue<Cell> pq;
        pq.push(Cell(dist[0][0], 0, 0));
        dist[0][0] = -1; // Mark as visited

        while (!pq.empty()) {
            Cell curr = pq.top();
            pq.pop();
            int d = curr.safeness;
            int r = curr.r;
            int c = curr.c;

            if (r == n - 1 && c == n - 1) {
                return d;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] != -1) {
                    pq.push(Cell(min(d, dist[nr][nc]), nr, nc));
                    dist[nr][nc] = -1; // Mark as visited
                }
            }
        }

        // Step 3 — Fallback Return
        return 0;
    }
};
