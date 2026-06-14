#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

// print a 2D matrix visually
void printMatrix(const vector<vector<int>>& mat) {
    cout << "[\n";
    for (const auto& row : mat) {
        cout << "  [";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i] << (i + 1 == row.size() ? "" : ", ");
        }
        cout << "]\n";
    }
    cout << "]";
}

// Test runner function
void runTest(int testNum, vector<vector<int>> mat, vector<int> expected) {
    int n = mat.size();
    int m = n > 0 ? mat[0].size() : 0;
    
    Solution sol;
    vector<int> result = sol.exitPoint(mat); // mat passed by value, no copy needed
    
    cout << "🚧 Test Case " << testNum << ":\n";
    cout << "  Input Matrix: ";
    printMatrix(mat);
    cout << "\n";
    cout << "  Expected Exit Point: [" << expected[0] << ", " << expected[1] << "]\n";
    cout << "  Actual Exit Point:   [" << result[0] << ", " << result[1] << "]\n";
    
    if (result == expected) {
        cout << "  Status:              ✅ PASSED\n\n";
    } else {
        cout << "  Status:              ❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🏁 Exit Point in a Matrix — Test Suite\n";
    cout << "=======================================\n" << endl;
    
    // Example 1
    vector<vector<int>> mat1 = {
        {0, 1, 0},
        {0, 1, 1},
        {0, 0, 0}
    };
    vector<int> expected1 = {1, 0};
    runTest(1, mat1, expected1);
    
    // Example 2
    vector<vector<int>> mat2 = {
        {0, 0}
    };
    vector<int> expected2 = {0, 1};
    runTest(2, mat2, expected2);
    
    // Additional Test Case 3: 1x1 Matrix with 0
    vector<vector<int>> mat3 = {
        {0}
    };
    vector<int> expected3 = {0, 0};
    runTest(3, mat3, expected3);
    
    // Additional Test Case 4: 1x1 Matrix with 1
    vector<vector<int>> mat4 = {
        {1}
    };
    vector<int> expected4 = {0, 0};
    runTest(4, mat4, expected4);
    
    // Additional Test Case 5: Standard spiral/turning behaviour
    vector<vector<int>> mat5 = {
        {0, 1},
        {1, 0}
    };
    vector<int> expected5 = {1, 1};
    runTest(5, mat5, expected5);
    
    return 0;
}
