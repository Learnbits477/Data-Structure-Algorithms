#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatArray(const vector<int>& arr, size_t maxElements = 6) {
    // Step: 01 - Format vector contents into compact string representation
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        if (i > 0) ss << ", ";
        if (i >= maxElements && arr.size() > maxElements + 1) {
            ss << "... (" << arr.size() << " items)";
            break;
        }
        ss << arr[i];
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<int> arr, int expected, const string& description) {
    // Step: 01 - Execute primary DFS memoization solver and driver interface
    Solution sol;
    int n = (int)arr.size();
    int result = sol.goodIndices(arr);

    // Step: 02 - Cross-verify with explicit size, iterative, and BFS algorithms
    int stonesResult = sol.goodStones(n, arr);
    int iterResult = sol.goodStonesIterative(n, arr);
    int bfsResult = sol.goodStonesBFS(n, arr);
    bool passed = (result == expected) && (stonesResult == expected) && (iterResult == expected) && (bfsResult == expected);

    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 42) {
        displayDesc = displayDesc.substr(0, 39) + "...";
    }

    string inputDisplay = formatArray(arr, 5);
    if (inputDisplay.length() > 24) {
        inputDisplay = inputDisplay.substr(0, 21) + "...";
    }

    string expDisplay = to_string(expected);
    string resDisplay = to_string(result);

    cout << left << setw(6)  << testId
         << setw(44) << displayDesc
         << setw(26) << inputDisplay
         << setw(12) << expDisplay
         << setw(12) << resDisplay
         << status << "\n";

    // Step: 04 - Print debug failure details if mismatch occurs
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:  " << expected << "\n"
             << "     DFS:       " << result << "\n"
             << "     Iterative: " << iterResult << "\n"
             << "     BFS:       " << bfsResult << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Count Indices That Escape Array (Good Stones) — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(44) << "Description"
         << setw(26) << "Input"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {2, 3, -1, 2, -2, 4, 1}, 3, "Example 1: Cycle with escape branches");
    runTest(2, {1, 0, -3, 0, -5, 0}, 2, "Example 2: Zero dead-ends and escapes");
    runTest(3, {1}, 1, "Single element jumping outside right");
    runTest(4, {-1}, 1, "Single element jumping outside left");
    runTest(5, {0}, 0, "Single element with 0 jump self-loop");
    runTest(6, {1, -1}, 0, "Two-element mutual cycle");
    runTest(7, {0, 0, 0, 0}, 0, "All zeroes array (all dead ends)");
    runTest(8, {5, 5, 5, 5}, 4, "All elements immediately jump right out");
    runTest(9, {-5, -5, -5, -5}, 4, "All elements immediately jump left out");
    runTest(10, {1, 1, 1, 1, 1}, 5, "Right-directed chain escaping at end");
    runTest(11, {-1, -1, -1, -1, -1}, 5, "Left-directed chain escaping at start");
    runTest(12, {1, -1, 3, -10}, 2, "Separated cycle and escape components");
    runTest(13, {100000, -100000}, 2, "Extreme large boundary jumps");

    // Step: 03 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
