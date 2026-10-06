#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dfs(int i, int j, const vector<vector<int>>& matrix, vector<vector<int>>& memo, int n, int m) {
        // Step: 01 - Return cached path length if already computed
        if (memo[i][j] != 0) return memo[i][j];

        int maxLen = 1;
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        // Step: 02 - Explore all four cardinal directions for strictly greater elements
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(ni, nj, matrix, memo, n, m));
            }
        }

        // Step: 03 - Cache and return longest increasing path starting at cell (i, j)
        return memo[i][j] = maxLen;
    }

public:
    int longIncPath(vector<vector<int>>& matrix, int n, int m) {
        // Step: 01 - Handle edge cases for empty or degenerated matrices
        if (n == 0 || m == 0) return 0;

        // Step: 02 - Initialize memoization table with zeros
        vector<vector<int>> memo(n, vector<int>(m, 0));
        int maxPath = 0;

        // Step: 03 - Trigger DFS from each cell to find global maximum path
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxPath = max(maxPath, dfs(i, j, matrix, memo, n, m));
            }
        }

        // Step: 04 - Return maximum path length across all cells
        return maxPath;
    }

    int longIncPath(vector<vector<int>>& matrix) {
        // Step: 01 - Compute matrix dimensions and delegate to primary solver
        int n = matrix.size();
        int m = n > 0 ? matrix[0].size() : 0;
        return longIncPath(matrix, n, m);
    }

    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
        // Step: 01 - Alias to official GFG longIncPath method
        return longIncPath(matrix, n, m);
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Step: 01 - Alias to official GFG longIncPath method
        return longIncPath(matrix);
    }

    int longIncPathBFS(vector<vector<int>>& matrix, int n, int m) {
        // Step: 01 - Validate non-empty matrix boundaries
        if (n == 0 || m == 0) return 0;

        // Step: 02 - Compute out-degree for each cell based on strictly greater neighbors
        vector<vector<int>> outDegree(n, vector<int>(m, 0));
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                        outDegree[i][j]++;
                    }
                }
            }
        }

        // Step: 03 - Collect all sink cells with out-degree zero into queue
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (outDegree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Step: 04 - Peeling layers via reverse topological sort BFS
        int pathLen = 0;
        while (!q.empty()) {
            int sz = q.size();
            pathLen++;
            for (int s = 0; s < sz; ++s) {
                pair<int, int> curr = q.front();
                q.pop();
                int ci = curr.first;
                int cj = curr.second;

                for (int k = 0; k < 4; ++k) {
                    int pi = ci + dx[k];
                    int pj = cj + dy[k];
                    if (pi >= 0 && pi < n && pj >= 0 && pj < m && matrix[ci][cj] > matrix[pi][pj]) {
                        if (--outDegree[pi][pj] == 0) {
                            q.push({pi, pj});
                        }
                    }
                }
            }
        }

        // Step: 05 - Return total peeled topological layers
        return pathLen;
    }

    int longIncPathBFS(vector<vector<int>>& matrix) {
        // Step: 01 - Compute matrix dimensions and delegate to BFS solver
        int n = matrix.size();
        int m = n > 0 ? matrix[0].size() : 0;
        return longIncPathBFS(matrix, n, m);
    }

    int longestIncreasingPathBFS(vector<vector<int>>& matrix, int n, int m) {
        // Step: 01 - Alias to official GFG longIncPathBFS method
        return longIncPathBFS(matrix, n, m);
    }

    int longestIncreasingPathBFS(vector<vector<int>>& matrix) {
        // Step: 01 - Alias to official GFG longIncPathBFS method
        return longIncPathBFS(matrix);
    }
};
