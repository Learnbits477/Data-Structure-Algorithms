#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPerimeter(vector<vector<int>> &mat) {
        // Step: 01 - Validate matrix dimensions and initialize perimeter counter
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        int perimeter = 0;

        // Step: 02 - Define directional offsets for orthogonal neighbors
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step: 03 - Iterate across all grid cells
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (mat[r][c] == 1) {
                    // Step: 04 - Count exposed sides bordering grid boundaries or zeros
                    for (int d = 0; d < 4; ++d) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= m || mat[nr][nc] == 0) {
                            perimeter++;
                        }
                    }
                }
            }
        }

        // Step: 05 - Return total computed perimeter
        return perimeter;
    }

    int findPerimeterSharedEdges(vector<vector<int>> &mat) {
        // Step: 01 - Validate grid bounds and initialize counter
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        int perimeter = 0;

        // Step: 02 - Traverse cells adding 4 for active cell and subtracting for shared edges
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (mat[r][c] == 1) {
                    perimeter += 4;
                    if (r > 0 && mat[r - 1][c] == 1) perimeter -= 2;
                    if (c > 0 && mat[r][c - 1] == 1) perimeter -= 2;
                }
            }
        }

        // Step: 03 - Return perimeter result
        return perimeter;
    }
};
