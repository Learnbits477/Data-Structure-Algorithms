#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));
        
        long long pref = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                p[i][j] = pref;
                pref = (pref * (grid[i][j] % 12345)) % 12345;
            }
        }
        
        long long suff = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                p[i][j] = (p[i][j] * suff) % 12345;
                suff = (suff * (grid[i][j] % 12345)) % 12345;
            }
        }
        
        return p;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<vector<int>> grid1 = {{1, 2}, {3, 4}};
    vector<vector<int>> result1 = solution.constructProductMatrix(grid1);
    
    cout << "Example 1 Output:" << endl;
    for (const auto& row : result1) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    // Test Case 2
    vector<vector<int>> grid2 = {{12345}, {2}, {1}};
    vector<vector<int>> result2 = solution.constructProductMatrix(grid2);
    
    cout << "Example 2 Output:" << endl;
    for (const auto& row : result2) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
