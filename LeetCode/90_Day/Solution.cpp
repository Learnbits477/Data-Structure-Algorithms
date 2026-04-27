#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Direction vectors: 0: Up, 1: Right, 2: Down, 3: Left
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        
        // Connections for each street type (1-indexed)
        // Array of boolean for [Up, Right, Down, Left]
        vector<vector<bool>> dirs = {
            {false, false, false, false}, // 0 (dummy)
            {false, true, false, true},   // 1: Left, Right
            {true, false, true, false},   // 2: Up, Down
            {false, false, true, true},   // 3: Left, Down
            {false, true, true, false},   // 4: Right, Down
            {true, false, false, true},   // 5: Left, Up
            {true, true, false, false}    // 6: Right, Up
        };
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == m - 1 && c == n - 1) return true;
            
            int type = grid[r][c];
            for (int d = 0; d < 4; ++d) {
                if (dirs[type][d]) { // If current street can go in direction d
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        int next_type = grid[nr][nc];
                        // Check if the adjacent cell can connect back
                        // Opposite direction is (d + 2) % 4
                        if (dirs[next_type][(d + 2) % 4]) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        
        return false;
    }
};

// Problem Link: ./Problem.md
// Approach Link: ./Approach.md
// Main Link: ./main.cpp
