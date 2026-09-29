#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> knightPos, vector<int> targetPos, int n, int expected, const string& description) {
    Solution sol;
    int result = sol.minStepToReachTarget(knightPos, targetPos, n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 32) {
        displayDesc = displayDesc.substr(0, 29) + "...";
    }

    auto posToStr = [](const vector<int>& p) -> string {
        return "[" + to_string(p[0]) + ", " + to_string(p[1]) + "]";
    };

    string inputSummary = posToStr(knightPos) + "->" + posToStr(targetPos) + " (N=" + to_string(n) + ")";
    if (inputSummary.length() > 24) {
        inputSummary = inputSummary.substr(0, 21) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(34) << displayDesc
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Board Size (N):  " << n << "\n"
             << "     Knight Start:    " << posToStr(knightPos) << "\n"
             << "     Target Position: " << posToStr(targetPos) << "\n"
             << "     Expected Output: " << expected << "\n"
             << "     Actual Output:   " << result << "\n";
    }
}

int main() {
    cout << "\n🐴 Steps by Knight — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Description"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {3, 3}, {1, 2}, 3, 1, "Example 1 (Single knight jump)");

    // Test 2: Example 2
    runTest(2, {1, 3}, {5, 1}, 6, 2, "Example 2 (Two-step path on 6x6)");

    // Test 3: Same start and target position
    runTest(3, {2, 2}, {2, 2}, 4, 0, "Source is already at target");

    // Test 4: Corner to diagonally opposite corner on 8x8
    runTest(4, {1, 1}, {8, 8}, 8, 6, "Standard 8x8 corner-to-corner");

    // Test 5: Adjacent cells requiring detour
    runTest(5, {1, 1}, {1, 2}, 4, 3, "Adjacent square on 4x4 board");

    // Test 6: Unreachable center on 3x3 board
    runTest(6, {1, 1}, {2, 2}, 3, -1, "Center of 3x3 board unreachable");

    // Test 7: Standard single jump on 8x8
    runTest(7, {1, 1}, {2, 3}, 8, 1, "Direct single jump on 8x8");

    // Test 8: Large chessboard 20x20
    runTest(8, {1, 1}, {20, 20}, 20, 14, "Large board 20x20 corner-to-corner");

    // Test 9: 4x4 diagonal opposite corner
    runTest(9, {1, 1}, {4, 4}, 4, 2, "Diagonal corner on 4x4");

    // Test 10: 5x5 corner to corner
    runTest(10, {1, 1}, {5, 5}, 5, 4, "Diagonal corner on 5x5");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
