#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(102, vector<double>(102, 0.0));
        tower[0][0] = (double)poured;

        for (int i = 0; i <= query_row; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (tower[i][j] > 1.0) {
                    double excess = tower[i][j] - 1.0;
                    tower[i][j] = 1.0; // The glass is full
                    tower[i + 1][j] += excess / 2.0;
                    tower[i + 1][j + 1] += excess / 2.0;
                }
            }
        }

        return tower[query_row][query_glass];
    }
};

int main() {
    Solution sol;

    // Example 1
    cout << "Example 1: " << sol.champagneTower(1, 1, 1) << endl; 
    // Expected: 0.0

    // Example 2
    cout << "Example 2: " << sol.champagneTower(2, 1, 1) << endl; 
    // Expected: 0.5

    // Example 3
    cout << "Example 3: " << sol.champagneTower(100000009, 33, 17) << endl; 
    // Expected: 1.0

    return 0;
}
