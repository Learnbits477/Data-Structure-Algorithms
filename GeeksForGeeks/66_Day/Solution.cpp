#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> downwardDiagonal(int N, vector<vector<int>> A) {
        return diagView(A);
    }

    vector<int> diagView(vector<vector<int>>& A) {
        int N = A.size();
        vector<int> result;
        
        // Traverse the first row anti-diagonals
        for (int col = 0; col < N; ++col) {
            int i = 0;
            int j = col;
            while (i < N && j >= 0) {
                result.push_back(A[i][j]);
                i++;
                j--;
            }
        }
        
        // Traverse the last column anti-diagonals (skip the first element/row since it has been traversed)
        for (int row = 1; row < N; ++row) {
            int i = row;
            int j = N - 1;
            while (i < N && j >= 0) {
                result.push_back(A[i][j]);
                i++;
                j--;
            }
        }
        
        return result;
    }
};

// Driver code to allow local execution
int main() {
    Solution obj;
    
    // Example 1
    vector<vector<int>> mat1 = {
        {1, 2},
        {3, 4}
    };
    cout << "Example 1 Output: ";
    vector<int> ans1 = obj.diagView(mat1);
    for (int num : ans1) cout << num << " ";
    cout << endl;
    
    // Example 2
    vector<vector<int>> mat2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Example 2 Output: ";
    vector<int> ans2 = obj.diagView(mat2);
    for (int num : ans2) cout << num << " ";
    cout << endl;
    
    return 0;
}
