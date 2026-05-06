#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Apply gravity for each row
        for (int i = 0; i < m; i++) {
            int empty_pos = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '#') {
                    boxGrid[i][j] = '.';
                    boxGrid[i][empty_pos] = '#';
                    empty_pos--;
                } else if (boxGrid[i][j] == '*') {
                    empty_pos = j - 1;
                }
            }
        }

        // Step 2: Rotate the matrix 90 degrees clockwise
        vector<vector<char>> result(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return result;
    }
};
