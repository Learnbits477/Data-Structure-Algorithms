#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1 — Handle Base Cases and Initialize Priority Queue
        // dist[r][c] stores the minimum number of unsafe cells (1s) encountered to reach (r, c)
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        
        // Min-heap storing pair<cost, cell_index> where cell_index = r * n + c
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 2 — Run Dijkstra's Algorithm
        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            
            int cost = curr.first;
            int u = curr.second;
            int r = u / n;
            int c = u % n;

            // If we found a path with a larger cost than the current shortest, skip it
            if (cost > dist[r][c]) continue;

            // Early exit if we reached the bottom-right corner
            if (r == m - 1 && c == n - 1) break;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_cost = cost + grid[nr][nc];
                    if (next_cost < dist[nr][nc]) {
                        dist[nr][nc] = next_cost;
                        pq.push({next_cost, nr * n + nc});
                    }
                }
            }
        }

        // Step 3 — Return Result Based on Remaining Health
        // Remaining health must be >= 1, meaning initial health - min_health_loss >= 1 => dist[m-1][n-1] < health
        return dist[m - 1][n - 1] < health;
    }
};
