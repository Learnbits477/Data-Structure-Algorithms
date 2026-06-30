#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Utility function to serialize a 2D vector into a single-line string representation
string serializeMatrix(const vector<vector<int>>& mat) {
    if (mat.empty()) return "[]";
    if (mat.size() == 1 && mat[0].size() == 1 && mat[0][0] == -1) return "[[-1]]";
    string res = "[";
    for (size_t i = 0; i < mat.size(); ++i) {
        res += "[";
        for (size_t j = 0; j < mat[i].size(); ++j) {
            res += to_string(mat[i][j]);
            if (j + 1 < mat[i].size()) res += ",";
        }
        res += "]";
        if (i + 1 < mat.size()) res += ",";
    }
    res += "]";
    return res;
}

// Function to run a single test case
void runTest(int testNum, vector<vector<int>> mat, vector<vector<int>> expected) {
    Solution sol;
    vector<vector<int>> result = sol.shortestDist(mat);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(45) << (serializeMatrix(mat).length() > 42 ? serializeMatrix(mat).substr(0, 39) + "..." : serializeMatrix(mat))
         << setw(45) << (serializeMatrix(expected).length() > 42 ? serializeMatrix(expected).substr(0, 39) + "..." : serializeMatrix(expected))
         << setw(45) << (serializeMatrix(result).length() > 42 ? serializeMatrix(result).substr(0, 39) + "..." : serializeMatrix(result))
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input Matrix:\n";
        for (const auto& row : mat) {
            cout << "       ";
            for (int val : row) cout << val << " ";
            cout << "\n";
        }
        cout << "     Expected Path:\n";
        for (const auto& row : expected) {
            cout << "       ";
            for (int val : row) cout << val << " ";
            cout << "\n";
        }
        cout << "     Got Path:\n";
        for (const auto& row : result) {
            cout << "       ";
            for (int val : row) cout << val << " ";
            cout << "\n";
        }
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 148 - Rat Maze with Multiple Jumps Test Suite  \n";
    cout << "⇚======================================================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Matrix" 
         << setw(45) << "Expected Path" 
         << setw(45) << "Actual Path" 
         << "Status\n";
    cout << string(150, '-') << "\n";

    // Example 1
    vector<vector<int>> mat1 = {
        {2, 1, 0, 0},
        {3, 0, 0, 1},
        {0, 1, 0, 1},
        {0, 0, 0, 1}
    };
    vector<vector<int>> expected1 = {
        {1, 0, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 1}
    };
    runTest(1, mat1, expected1);
    
    // Example 2
    vector<vector<int>> mat2 = {
        {2, 1, 0, 0},
        {2, 0, 0, 1},
        {0, 1, 0, 1},
        {0, 0, 0, 1}
    };
    vector<vector<int>> expected2 = {
        {-1}
    };
    runTest(2, mat2, expected2);
    
    // Test Case 3: 1x1 Matrix
    vector<vector<int>> mat3 = {
        {1}
    };
    vector<vector<int>> expected3 = {
        {1}
    };
    runTest(3, mat3, expected3);
    
    // Test Case 4: Blocked Start
    vector<vector<int>> mat4 = {
        {0, 1},
        {1, 1}
    };
    vector<vector<int>> expected4 = {
        {-1}
    };
    runTest(4, mat4, expected4);
    
    // Test Case 5: 2x2 Matrix with Right first preference
    vector<vector<int>> mat5 = {
        {1, 1},
        {1, 1}
    };
    vector<vector<int>> expected5 = {
        {1, 1},
        {0, 1}
    };
    runTest(5, mat5, expected5);
    
    // Test Case 6: Blocked path through center
    vector<vector<int>> mat6 = {
        {2, 0, 0},
        {0, 1, 1},
        {0, 1, 1}
    };
    vector<vector<int>> expected6 = {
        {-1}
    };
    runTest(6, mat6, expected6);

    cout << "⇚======================================================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
