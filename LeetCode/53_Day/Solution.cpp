#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; i++) {
            for (int j = 0; j < k; j++) {
                swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
            }
        }
        return grid;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int x1 = 1, y1 = 0, k1 = 3;
    vector<vector<int>> result1 = sol.reverseSubmatrix(grid1, x1, y1, k1);
    
    cout << "Example 1 Output:" << endl;
    for (const auto& row : result1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;

    vector<vector<int>> grid2 = {{3, 4, 2, 3}, {2, 3, 4, 2}};
    int x2 = 0, y2 = 2, k2 = 2;
    vector<vector<int>> result2 = sol.reverseSubmatrix(grid2, x2, y2, k2);

    cout << "Example 2 Output:" << endl;
    for (const auto& row : result2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
