#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Step 1: Parse grid to locate student start 'S' and index all litter cells 'L'
        int startR = -1, startC = -1;
        vector<pair<int, int>> litters;
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    litterId[r][c] = litters.size();
                    litters.push_back({r, c});
                }
            }
        }

        // Step 2: Handle base case (no litter to collect)
        int K = litters.size();
        if (K == 0) return 0;
        int targetMask = (1 << K) - 1;

        // Step 3: Initialize BFS state space and dominance pruning table
        // maxEnergy[r][c][mask] stores the maximum remaining energy when reaching (r, c) with a given collected mask.
        // In BFS, states are processed in non-decreasing order of moves.
        // Reaching (r, c, mask) with <= energy in >= moves is strictly dominated, hence pruned.
        vector<vector<vector<int>>> maxEnergy(m, vector<vector<int>>(n, vector<int>(1 << K, -1)));

        struct State {
            int r, c, mask, e, moves;
        };

        queue<State> q;
        maxEnergy[startR][startC][0] = energy;
        q.push({startR, startC, 0, energy, 0});

        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        // Step 4: Perform Breadth-First Search (BFS) exploration
        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            if (cur.mask == targetMask) {
                return cur.moves;
            }

            for (int d = 0; d < 4; ++d) {
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                // 4.1. Grid boundary check
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                // 4.2. Obstacle check
                if (classroom[nr][nc] == 'X') continue;

                // 4.3. Energy cost
                int remEnergy = cur.e - 1;
                if (remEnergy < 0) continue;

                // 4.4. Update litter collection mask
                int nextMask = cur.mask;
                if (classroom[nr][nc] == 'L') {
                    int id = litterId[nr][nc];
                    nextMask |= (1 << id);
                }

                // 4.5. Energy reset on 'R'
                int nextEnergy = remEnergy;
                if (classroom[nr][nc] == 'R') {
                    nextEnergy = energy;
                }

                // 4.6. Early exit on collecting all litter
                if (nextMask == targetMask) {
                    return cur.moves + 1;
                }

                // 4.7. If energy depleted and not on 'R', cannot make any subsequent moves
                if (nextEnergy == 0 && classroom[nr][nc] != 'R') {
                    continue;
                }

                // 4.8. Dominance pruning and enqueue
                if (nextEnergy > maxEnergy[nr][nc][nextMask]) {
                    maxEnergy[nr][nc][nextMask] = nextEnergy;
                    q.push({nr, nc, nextMask, nextEnergy, cur.moves + 1});
                }
            }
        }

        // Step 5: If all valid paths are exhausted without collecting all litter, return -1
        return -1;
    }

    // Platform aliases for compatibility
    int minimumMoves(vector<string>& classroom, int energy) {
        return minMoves(classroom, energy);
    }
};
