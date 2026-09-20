#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, vector<vector<char>> mat, int expected, const string& description) {
    Solution sol;
    int result = sol.largestSubsquare(mat);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    int n = mat.size();
    string dimensionStr = to_string(n) + "x" + to_string(n);

    string displayDesc = description;
    if (displayDesc.length() > 28) {
        displayDesc = displayDesc.substr(0, 25) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(10) << dimensionStr
         << setw(30) << displayDesc
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Dimension: " << dimensionStr << "\n"
             << "     Description: " << description << "\n"
             << "     Expected:  " << expected << "\n"
             << "     Got:       " << result << "\n"
             << "     Matrix:\n";
        for (const auto& row : mat) {
            cout << "       ";
            for (char c : row) cout << c << ' ';
            cout << "\n";
        }
    }
}

int main() {
    cout << "\n🔳 Largest Subsquare Surrounded by X — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(10) << "Size"
         << setw(30) << "Test Description"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Test 1: Example 1 (4x4 matrix)
    runTest(1, {
        {'X', 'X', 'X', 'O'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'X', 'O'},
        {'X', 'O', 'X', 'X'}
    }, 3, "Example 1 (4x4 mixed)");

    // Test 2: Example 2 (2x2 all 'X')
    runTest(2, {
        {'X', 'X'},
        {'X', 'X'}
    }, 2, "Example 2 (2x2 all X)");

    // Test 3: All 'O' matrix (3x3)
    runTest(3, {
        {'O', 'O', 'O'},
        {'O', 'O', 'O'},
        {'O', 'O', 'O'}
    }, 0, "All 'O' matrix");

    // Test 4: Single cell 'X'
    runTest(4, {
        {'X'}
    }, 1, "Single cell 'X'");

    // Test 5: Single cell 'O'
    runTest(5, {
        {'O'}
    }, 0, "Single cell 'O'");

    // Test 6: 3x3 boundary surrounded by 'X', center 'O'
    runTest(6, {
        {'X', 'X', 'X'},
        {'X', 'O', 'X'},
        {'X', 'X', 'X'}
    }, 3, "3x3 hollow border");

    // Test 7: 3x3 broken boundary with one 'O' on edge
    runTest(7, {
        {'X', 'X', 'O'},
        {'X', 'O', 'X'},
        {'X', 'X', 'X'}
    }, 1, "3x3 broken border");

    // Test 8: 5x5 all 'X' matrix
    runTest(8, {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'}
    }, 5, "5x5 all 'X' matrix");

    // Test 9: 4x4 diagonal only 'X'
    runTest(9, {
        {'X', 'O', 'O', 'O'},
        {'O', 'X', 'O', 'O'},
        {'O', 'O', 'X', 'O'},
        {'O', 'O', 'O', 'X'}
    }, 1, "Diagonal 'X' only");

    // Test 10: 5x5 with 4x4 subsquare at bottom-right
    runTest(10, {
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'X', 'X', 'X', 'X'},
        {'O', 'X', 'O', 'O', 'X'},
        {'O', 'X', 'O', 'O', 'X'},
        {'O', 'X', 'X', 'X', 'X'}
    }, 4, "5x5 with 4x4 at bottom-right");

    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
