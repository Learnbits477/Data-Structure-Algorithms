#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k %= n;
        
        if (k == 0) return true;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> mat1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k1 = 4;
    cout << "Example 1: " << (sol.areSimilar(mat1, k1) ? "true" : "false") << " (Expected: false)" << endl;

    // Example 2
    vector<vector<int>> mat2 = {{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}};
    int k2 = 2;
    cout << "Example 2: " << (sol.areSimilar(mat2, k2) ? "true" : "false") << " (Expected: true)" << endl;

    // Example 3
    vector<vector<int>> mat3 = {{2, 2}, {2, 2}};
    int k3 = 3;
    cout << "Example 3: " << (sol.areSimilar(mat3, k3) ? "true" : "false") << " (Expected: true)" << endl;

    return 0;
}
