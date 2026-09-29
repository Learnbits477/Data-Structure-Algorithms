#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        int startX = knightPos[0];
        int startY = knightPos[1];
        int targetX = targetPos[0];
        int targetY = targetPos[1];

        // Base case: Already at the destination
        if (startX == targetX && startY == targetY) {
            return 0;
        }

        // 8 possible L-shaped moves for a knight
        static const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        static const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        // 2D visited array (1-based indexing: 1 to n)
        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

        // BFS queue to store {x, y} coordinates of reachable cells
        queue<pair<int, int>> q;
        q.push({startX, startY});
        visited[startX][startY] = true;

        int steps = 0;

        // Standard level-order BFS traversal
        while (!q.empty()) {
            int levelSize = q.size();
            steps++;

            for (int i = 0; i < levelSize; ++i) {
                int currX = q.front().first;
                int currY = q.front().second;
                q.pop();

                for (int d = 0; d < 8; ++d) {
                    int nextX = currX + dx[d];
                    int nextY = currY + dy[d];

                    // Check if target is reached
                    if (nextX == targetX && nextY == targetY) {
                        return steps;
                    }

                    // Check chessboard boundaries and visited state
                    if (nextX >= 1 && nextX <= n && nextY >= 1 && nextY <= n && !visited[nextX][nextY]) {
                        visited[nextX][nextY] = true;
                        q.push({nextX, nextY});
                    }
                }
            }
        }

        return -1; // Unreachable destination
    }

    /**
     * Overload supporting const reference inputs for testing flexibility.
     */
    int minStepToReachTarget(const vector<int>& knightPos, const vector<int>& targetPos, int n) {
        vector<int> k = knightPos;
        vector<int> t = targetPos;
        return minStepToReachTarget(k, t, n);
    }
};
