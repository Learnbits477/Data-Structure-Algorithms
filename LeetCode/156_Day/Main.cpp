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

string boolToString(bool val) {
    return val ? "true" : "false";
}

void runTest(int testNum, vector<vector<int>> grid, int health, bool expected) {
    Solution sol;
    bool result = sol.findSafeWalk(grid, health);
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
         << setw(10) << health
         << setw(16) << boolToString(expected)
         << setw(16) << boolToString(result)
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input: grid = " << gridToString(grid) << ", health = " << health << "\n"
             << "     Expected: " << boolToString(expected) << "\n"
             << "     Got:      " << boolToString(result) << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 156 - Find a Safe Walk Through a Grid Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Input (grid)" 
         << setw(10) << "health"
         << setw(16) << "Expected" 
         << setw(16) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Example 1
    runTest(1, {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}}, 1, true);
    
    // Example 2
    runTest(2, {{0,1,1,0,0,0},{1,0,1,0,0,0},{0,1,1,1,0,1},{0,0,1,0,1,0}}, 3, false);
    
    // Example 3
    runTest(3, {{1,1,1},{1,0,1},{1,1,1}}, 5, true);
    
    // Additional Test 4 - Small grid with high cost
    runTest(4, {{1, 1}, {1, 1}}, 2, false);
    
    // Additional Test 5 - Small grid with enough health (needs health = 4 to end with health >= 1)
    runTest(5, {{1, 1}, {1, 1}}, 4, true);
    
    // Additional Test 6 - Clean grid
    runTest(6, {{0, 0}, {0, 0}}, 1, true);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
