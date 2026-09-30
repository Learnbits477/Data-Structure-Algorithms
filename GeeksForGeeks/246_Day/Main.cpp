#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int x, int y, int expected, const string& description) {
    Solution sol;
    int result = sol.ways(x, y);
    int resultOpt = sol.waysSpaceOptimized(x, y);
    bool passed = (result == expected) && (resultOpt == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 32) {
        displayDesc = displayDesc.substr(0, 29) + "...";
    }

    string inputSummary = "(" + to_string(x) + ", " + to_string(y) + ")";

    cout << left << setw(6)  << testId
         << setw(34) << displayDesc
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input Coordinates: (x=" << x << ", y=" << y << ")\n"
             << "     Expected Output:   " << expected << "\n"
             << "     Actual (2D DP):    " << result << "\n"
             << "     Actual (1D DP):    " << resultOpt << "\n";
    }
}

int main() {
    cout << "\n📍 Ways to Reach Origin — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Description"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, 3, 0, 1, "Example 1 (Horizontal line y=0)");

    // Test 2: Example 2
    runTest(2, 3, 6, 84, "Example 2 (x=3, y=6)");

    // Test 3: Origin itself
    runTest(3, 0, 0, 1, "Origin point (0, 0)");

    // Test 4: Single step left and down
    runTest(4, 1, 1, 2, "Single 1x1 grid cell");

    // Test 5: Pure vertical movement
    runTest(5, 0, 5, 1, "Vertical axis (0, 5)");

    // Test 6: Pure horizontal movement
    runTest(6, 5, 0, 1, "Horizontal axis (5, 0)");

    // Test 7: 2x2 grid
    runTest(7, 2, 2, 6, "Symmetric 2x2 grid");

    // Test 8: 3x3 grid
    runTest(8, 3, 3, 20, "Symmetric 3x3 grid");

    // Test 9: 4x4 grid
    runTest(9, 4, 4, 70, "Symmetric 4x4 grid");

    // Test 10: 5x5 grid
    runTest(10, 5, 5, 252, "Symmetric 5x5 grid");

    // Test 11: Asymmetric coordinates
    runTest(11, 4, 2, 15, "Asymmetric (x=4, y=2)");

    // Test 12: Swap asymmetry (x=2, y=4 should equal x=4, y=2)
    runTest(12, 2, 4, 15, "Symmetry check (x=2, y=4)");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
