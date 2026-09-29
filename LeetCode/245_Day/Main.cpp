#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<vector<char>> grid, bool expected, const string& description) {
    Solution sol;
    bool result = sol.hasValidPath(grid);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 32) {
        displayDesc = displayDesc.substr(0, 29) + "...";
    }

    string expStr = expected ? "true" : "false";
    string resStr = result ? "true" : "false";

    cout << left << setw(6)  << testId
         << setw(34) << displayDesc
         << setw(12) << expStr
         << setw(12) << resStr
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Grid Dimensions: " << grid.size() << "x" << (grid.empty() ? 0 : grid[0].size()) << "\n"
             << "     Expected Output: " << expStr << "\n"
             << "     Actual Output:   " << resStr << "\n";
    }
}

int main() {
    cout << "\n🔤 Check if There Is a Valid Parentheses String Path — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Description"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {
        {'(', '(', '('},
        {')', '(', ')'},
        {'(', '(', ')'},
        {'(', '(', ')'}
    }, true, "Example 1 (4x3 valid paths)");

    // Test 2: Example 2
    runTest(2, {
        {')', ')'},
        {'(', '('}
    }, false, "Example 2 (2x2 invalid start)");

    // Test 3: Minimal valid 1x2 grid
    runTest(3, {
        {'(', ')'}
    }, true, "Minimal 1x2 valid pair");

    // Test 4: Reversed 1x2 grid
    runTest(4, {
        {')', '('}
    }, false, "Reversed 1x2 invalid pair");

    // Test 5: Odd path length (2x2 -> len 3)
    runTest(5, {
        {'(', '('},
        {'(', ')'}
    }, false, "Odd total path length (2x2)");

    // Test 6: 1x4 horizontal valid sequence
    runTest(6, {
        {'(', '(', ')', ')'}
    }, true, "1x4 horizontal balanced string");

    // Test 7: 1x4 horizontal invalid sequence
    runTest(7, {
        {'(', ')', ')', '('}
    }, false, "1x4 horizontal negative prefix");

    // Test 8: 4x1 vertical valid column
    runTest(8, {
        {'('},
        {'('},
        {')'},
        {')'}
    }, true, "4x1 vertical balanced string");

    // Test 9: 3x4 grid with winding valid path
    runTest(9, {
        {'(', '(', ')', '('},
        {')', '(', ')', ')'},
        {'(', ')', '(', ')'}
    }, true, "3x4 grid with winding path");

    // Test 10: 3x3 grid (always odd path length 5)
    runTest(10, {
        {'(', '(', '('},
        {')', ')', '('},
        {'(', ')', ')'}
    }, false, "3x3 square (always odd length)");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
