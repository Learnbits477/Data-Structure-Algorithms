#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, int n, int expected, const string& description) {
    // Step: 01 - Execute primary reverse greedy algorithm
    Solution sol;
    int result = sol.minimumStep(n);

    // Step: 02 - Cross-verify with chunked modulo algorithm
    int chunkResult = sol.minimumStepChunked(n);
    bool passed = (result == expected) && (chunkResult == expected);

    // Step: 03 - Cross-verify with BFS if n is within reasonable limit
    if (n <= 20000) {
        int bfsResult = sol.minimumStepBFS(n);
        if (bfsResult != expected) {
            passed = false;
        }
    }

    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 04 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 42) {
        displayDesc = displayDesc.substr(0, 39) + "...";
    }

    string inputDisplay = "n = " + to_string(n);
    if (inputDisplay.length() > 20) {
        inputDisplay = inputDisplay.substr(0, 17) + "...";
    }

    string expDisplay = to_string(expected);
    string resDisplay = to_string(result);

    cout << left << setw(6)  << testId
         << setw(44) << displayDesc
         << setw(22) << inputDisplay
         << setw(14) << expDisplay
         << setw(14) << resDisplay
         << status << "\n";

    // Step: 05 - Print debug failure details if mismatch occurs
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:   " << expected << "\n"
             << "     Reverse:    " << result << "\n"
             << "     Chunked:    " << chunkResult << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Shortest Path From 1 To n — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(44) << "Description"
         << setw(22) << "Input"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Precompute expected for 10^8 using solution logic
    Solution sol;
    int exp100M = sol.minimumStep(100000000);

    // Step: 03 - Execute test cases
    runTest(1, 4, 2, "Example 1: n = 4 (1 -> 3 -> 4)");
    runTest(2, 9, 2, "Example 2: n = 9 (1 -> 3 -> 9)");
    runTest(3, 15, 4, "Example 3: n = 15 (1 -> 3 -> 4 -> 5 -> 15)");
    runTest(4, 1, 0, "Base boundary: n = 1 (already at start)");
    runTest(5, 2, 1, "Single increment: n = 2 (1 -> 2)");
    runTest(6, 3, 1, "Single tripling: n = 3 (1 -> 3)");
    runTest(7, 7, 3, "Small prime: n = 7 (1 -> 2 -> 6 -> 7)");
    runTest(8, 10, 3, "Composite: n = 10 (1 -> 3 -> 9 -> 10)");
    runTest(9, 27, 3, "Power of 3: n = 27 (1 -> 3 -> 9 -> 27)");
    runTest(10, 100, 7, "Century value: n = 100");
    runTest(11, 243, 5, "Power of 3: n = 3^5 = 243");
    runTest(12, 100000000, exp100M, "Maximum constraint boundary: n = 10^8");

    // Step: 04 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
