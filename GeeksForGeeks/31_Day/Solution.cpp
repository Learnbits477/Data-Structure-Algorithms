#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();

        // Prefix Sum
        vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                pre[i][j] = mat[i-1][j-1] 
                          + pre[i-1][j] 
                          + pre[i][j-1] 
                          - pre[i-1][j-1];
            }
        }

        // Function to get sum
        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return pre[r2+1][c2+1] 
                 - pre[r1][c2+1] 
                 - pre[r2+1][c1] 
                 + pre[r1][c1];
        };

        int count = 0;

        for(int k = 1; k <= min(n, m); k++) {
            for(int i = 0; i + k <= n; i++) {
                for(int j = 0; j + k <= m; j++) {
                    if(getSum(i, j, i+k-1, j+k-1) == x)
                        count++;
                }
            }
        }

        return count;
    }
};

int main() {
    int n = 3, m = 3;

    // Hardcoded matrix (so no input confusion)
    vector<vector<int>> mat = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    int x = 4;

    Solution obj;
    int result = obj.countSquare(mat, x);

    cout << "Number of square submatrices with sum = " << x << " is: " << result << endl;

    return 0;
}