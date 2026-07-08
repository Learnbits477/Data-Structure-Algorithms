#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string matrixToString(const vector<vector<int>>& grid) {
    if (grid.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < grid.size(); ++i) {
        res += "[";
        for (size_t j = 0; j < grid[i].size(); ++j) {
            res += to_string(grid[i][j]);
            if (j < grid[i].size() - 1) res += ", ";
        }
        res += "]";
        if (i < grid.size() - 1) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, const vector<vector<int>>& mat, int expected) {
    int n = mat.size();
    int m = n > 0 ? mat[0].size() : 0;
    Solution sol;
    
    vector<vector<int>> matCopy = mat;
    int result = sol.geeksIsland(matCopy, n, m);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "Dim: " + to_string(n) + "x" + to_string(m) + ", Mat: " + matrixToString(mat);
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
             << "     Dimensions: " << n << "x" << m << "\n"
             << "     Matrix:     " << matrixToString(mat) << "\n"
             << "     Expected:   " << expected << "\n"
             << "     Got:        " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 162 - Geeks Island (Towers Reaching Both Stations) Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (Dimensions, Matrix)" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    runTest(1, {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    }, 7);
    
    runTest(2, {
        {2, 2},
        {2, 2}
    }, 4);
    
    runTest(3, {
        {1}
    }, 1);
    
    runTest(4, {
        {1, 2, 3, 2, 1}
    }, 5);
    
    runTest(5, {
        {10, 10, 10},
        {2, 1, 2},
        {10, 10, 10}
    }, 6);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
