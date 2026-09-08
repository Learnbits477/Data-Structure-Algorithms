#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // 8 Direction vectors: Up-Left, Up, Up-Right, Left, Right, Down-Left, Down, Down-Right
    const int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    const int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

    // Helper to check if word exists in a specific direction (dr, dc) starting from (r, c)
    bool searchInDirection(const vector<vector<char>>& mat, int r, int c, const string& word, int dr, int dc) {
        int n = mat.size();
        int m = mat[0].size();
        int len = word.length();

        for (int k = 1; k < len; k++) {
            int nr = r + k * dr;
            int nc = c + k * dc;

            // Boundary and character match check
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || mat[nr][nc] != word[k]) {
                return false;
            }
        }
        return true;
    }

public:
    // Step 1 & 2: Search starting positions of word across all 8 straight-line directions
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string word) {
        vector<vector<int>> ans;
        int n = mat.size();
        if (n == 0) return ans;
        int m = mat[0].size();
        if (m == 0 || word.empty()) return ans;

        // Iterate through all cells in row-major order (ensures lexicographical order)
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                // If first letter matches, test all 8 directions
                if (mat[r][c] == word[0]) {
                    // Step 3: Check all 8 directions
                    for (int d = 0; d < 8; d++) {
                        if (searchInDirection(mat, r, c, word, dx[d], dy[d])) {
                            // Step 4: Record coordinate and avoid duplicate addition for this cell
                            ans.push_back({r, c});
                            break; 
                        }
                    }
                }
            }
        }

        return ans;
    }
};
