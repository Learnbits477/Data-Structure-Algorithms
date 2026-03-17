#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 1;i<n; i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            sort(matrix[i].begin(), matrix[i].end());

            for(int j=0;j<m;j++){
                int h = matrix[i][j];
                int w = m-j;
                ans = max(ans, h*w);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> matrix1 = {{0,0,1},{1,1,1},{1,0,1}};
    cout << "Example 1 Output: " << sol.largestSubmatrix(matrix1) << endl;
    
    // Example 2
    vector<vector<int>> matrix2 = {{1,0,1,0,1}};
    cout << "Example 2 Output: " << sol.largestSubmatrix(matrix2) << endl;
    
    // Example 3
    vector<vector<int>> matrix3 = {{1,1,0},{1,0,1}};
    cout << "Example 3 Output: " << sol.largestSubmatrix(matrix3) << endl;

    return 0;
}
