#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> mat1 = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
    cout << "Example 1 Output: " << sol.numSpecial(mat1) << endl;
    
    vector<vector<int>> mat2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << "Example 2 Output: " << sol.numSpecial(mat2) << endl;
    
    return 0;
}
