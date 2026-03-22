#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true;
        
        int n = mat.size();
        int rotations = 3;
        
        while (rotations--) {
            // Transpose the matrix
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            
            // Reverse each row
            for (int i = 0; i < n; ++i) {
                reverse(mat[i].begin(), mat[i].end());
            }
            
            // Check if matches target
            if (mat == target) return true;
        }
        
        return false;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> mat1 = {{0, 1}, {1, 0}};
    vector<vector<int>> target1 = {{1, 0}, {0, 1}};
    cout << "Example 1 Output: " << (sol.findRotation(mat1, target1) ? "true" : "false") << endl;

    // Example: 2
    vector<vector<int>> mat2 = {{0, 1}, {1, 1}};
    vector<vector<int>> target2 = {{1, 0}, {0, 1}};
    cout << "Example 2 Output: " << (sol.findRotation(mat2, target2) ? "true" : "false") << endl;

    // Example: 3
    vector<vector<int>> mat3 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> target3 = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    cout << "Example 3 Output: " << (sol.findRotation(mat3, target3) ? "true" : "false") << endl;

    return 0;
}
