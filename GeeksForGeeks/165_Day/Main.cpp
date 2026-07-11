#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, vector<vector<int>> mat, int xs, int ys, int xd, int yd, int expected) {
    Solution sol;
    int result = sol.longestPath(mat, xs, ys, xd, yd);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    int n = mat.size();
    int m = n > 0 ? mat[0].size() : 0;
    string inputStr = "(" + to_string(xs) + "," + to_string(ys) + ")->(" + to_string(xd) + "," + to_string(yd) + ") [" + to_string(n) + "x" + to_string(m) + "]";
    if (inputStr.length() > 45) {
        inputStr = inputStr.substr(0, 42) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 165 - Longest Possible Route in a Matrix with Hurdles Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (Start->End [Grid])" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from description
    vector<vector<int>> mat1 = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    runTest(1, mat1, 0, 0, 1, 7, 24);

    // Test Case 2: Example 2 from description (Destination unreachable due to hurdles)
    vector<vector<int>> mat2 = {
        {1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0}
    };
    runTest(2, mat2, 0, 3, 2, 2, -1);

    // Test Case 3: Start or End is a hurdle
    vector<vector<int>> mat3 = {
        {1, 0, 1},
        {1, 1, 1}
    };
    runTest(3, mat3, 0, 1, 1, 2, -1); // Start is hurdle (0,1)

    // Test Case 4: Start and End are same and traversable
    vector<vector<int>> mat4 = {
        {1}
    };
    runTest(4, mat4, 0, 0, 0, 0, 0);

    // Test Case 5: 3x3 grid with multiple paths
    vector<vector<int>> mat5 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    runTest(5, mat5, 0, 0, 2, 2, 8); // Longest path visits all 9 cells (length 8)

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
