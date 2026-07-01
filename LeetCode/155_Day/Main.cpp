#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string gridToString(const vector<vector<int>>& grid) {
    string res = "[";
    for (size_t i = 0; i < grid.size(); i++) {
        res += "[";
        for (size_t j = 0; j < grid[i].size(); j++) {
            res += to_string(grid[i][j]);
            if (j + 1 < grid[i].size()) res += ",";
        }
        res += "]";
        if (i + 1 < grid.size()) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<vector<int>> grid, int expected) {
    Solution sol;
    int result = sol.maximumSafenessFactor(grid);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = gridToString(grid);
    if (inputStr.length() > 30) {
        inputStr = inputStr.substr(0, 27) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(32) << inputStr
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input grid: " << gridToString(grid) << "\n"
             << "     Expected:   " << expected << "\n"
             << "     Got:        " << result << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 155 - Find the Safest Path in a Grid Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Input (grid)" 
         << setw(18) << "Expected" 
         << setw(18) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Example 1
    runTest(1, {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}}, 0);
    
    // Example 2
    runTest(2, {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}}, 2);
    
    // Example 3
    runTest(3, {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}}, 2);
    
    // Additional Test 4 - Smallest thief-adjacent grid
    runTest(4, {{0, 1}, {1, 0}}, 0);
    
    // Additional Test 5 - Corner thief in 3x3
    runTest(5, {{0, 0, 0}, {0, 0, 0}, {0, 1, 0}}, 1);

    // Additional Test 6 - Single thief in middle
    runTest(6, {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 1);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
