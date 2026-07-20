#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Solution.cpp"

using namespace std;

string format2DVector(const vector<vector<int>>& grid) {
    string res = "[";
    for (size_t i = 0; i < grid.size(); ++i) {
        res += "[";
        for (size_t j = 0; j < grid[i].size(); ++j) {
            res += to_string(grid[i][j]);
            if (j + 1 < grid[i].size()) res += ",";
        }
        res += "]";
        if (i + 1 < grid.size()) res += ",";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<vector<int>> grid, int k, vector<vector<int>> expected) {
    Solution solver;
    vector<vector<int>> result = solver.shiftGrid(grid, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string gridStr = format2DVector(grid);
    if (gridStr.length() > 40) {
        gridStr = gridStr.substr(0, 37) + "...";
    }
    
    string expectedStr = format2DVector(expected);
    if (expectedStr.length() > 25) {
        expectedStr = expectedStr.substr(0, 22) + "...";
    }
    
    string actualStr = format2DVector(result);
    if (actualStr.length() > 25) {
        actualStr = actualStr.substr(0, 22) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(42) << gridStr
         << setw(5)  << to_string(k)
         << setw(27) << expectedStr
         << setw(27) << actualStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << format2DVector(expected) << "\n"
             << "     Got:      " << format2DVector(result) << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 174 - Shift 2D Grid Test Suite  \n";
    cout << "⇚ - ========================================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(42) << "Input Grid" 
         << setw(5)  << "k"
         << setw(27) << "Expected Grid" 
         << setw(27) << "Actual Grid" 
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Example 1
    runTest(1, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 1, {{9, 1, 2}, {3, 4, 5}, {6, 7, 8}});
    
    // Example 2
    runTest(2, {{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}}, 4, {{12, 0, 21, 13}, {3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}});

    // Example 3
    runTest(3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 9, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

    // Edge Case 4: Single element grid
    runTest(4, {{5}}, 100, {{5}});

    // Edge Case 5: 1D grid (Single row, multiple columns)
    runTest(5, {{1, 2, 3, 4}}, 2, {{3, 4, 1, 2}});

    // Edge Case 6: 1D grid (Multiple rows, single column)
    runTest(6, {{1}, {2}, {3}, {4}}, 2, {{3}, {4}, {1}, {2}});

    cout << "⇚ - ========================================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
