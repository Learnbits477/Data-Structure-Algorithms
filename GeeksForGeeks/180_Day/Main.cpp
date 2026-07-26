#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string vecToString(const vector<int>& vec) {
    string res = "[";
    for (size_t i = 0; i < vec.size(); i++) {
        res += to_string(vec[i]);
        if (i + 1 < vec.size()) res += ", ";
    }
    res += "]";
    return res;
}

string vec2DToString(const vector<vector<int>>& grid) {
    string res = "[";
    for (size_t i = 0; i < grid.size(); i++) {
        res += "[";
        for (size_t j = 0; j < grid[i].size(); j++) {
            res += to_string(grid[i][j]);
            if (j + 1 < grid[i].size()) res += ", ";
        }
        res += "]";
        if (i + 1 < grid.size()) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<int> arr, vector<vector<int>> expected) {
    Solution sol;
    vector<vector<int>> result = sol.levelSort(arr);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string arrStr = vecToString(arr);
    if (arrStr.length() > 25) {
        arrStr = arrStr.substr(0, 22) + "...";
    }
    
    string expStr = vec2DToString(expected);
    if (expStr.length() > 25) {
        expStr = expStr.substr(0, 22) + "...";
    }
    
    string resStr = vec2DToString(result);
    if (resStr.length() > 25) {
        resStr = resStr.substr(0, 22) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(28) << arrStr
         << setw(28) << expStr
         << setw(28) << resStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << vec2DToString(expected) << "\n"
             << "     Got:      " << vec2DToString(result) << "\n";
    }
}

int main() {
    cout << "\n🔢 Complete Binary Tree Traversal with Array Input — Test Suite\n";
    cout << "⇚ - ============================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(28) << "Input Array" 
         << setw(28) << "Expected Levels" 
         << setw(28) << "Actual Levels" 
         << "Status\n";
    cout << string(96, '-') << "\n";

    // Test Case 1: Example 1
    runTest(1, {7, 6, 5, 4, 3, 2, 1}, {{7}, {5, 6}, {1, 2, 3, 4}});

    // Test Case 2: Example 2
    runTest(2, {7, 16, 1, 4, 13}, {{7}, {1, 16}, {4, 13}});

    // Test Case 3: Single element tree
    runTest(3, {99}, {{99}});

    // Test Case 4: Perfect sorted level order traversal tree
    runTest(4, {1, 2, 3, 4, 5, 6, 7}, {{1}, {2, 3}, {4, 5, 6, 7}});

    // Test Case 5: Incomplete last level
    runTest(5, {10, 9, 8, 7, 6, 5}, {{10}, {8, 9}, {5, 6, 7}});

    // Test Case 6: Tree with duplicates
    runTest(6, {5, 5, 5, 1, 2, 3}, {{5}, {5, 5}, {1, 2, 3}});

    cout << "⇚ - ============================================================================================== - ⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
