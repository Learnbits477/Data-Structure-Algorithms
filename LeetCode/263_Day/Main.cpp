#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, const vector<int>& nums, int expected, const string& description) {
    // Step: 01 - Execute cycle decomposition algorithm
    Solution sol;
    vector<int> numsCopy = nums;
    int result = sol.minSwaps(numsCopy);

    // Step: 02 - Cross-verify with simulation algorithm
    vector<int> numsSim = nums;
    int simResult = sol.minSwapsSimulation(numsSim);
    bool passed = (result == expected) && (simResult == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 42) {
        displayDesc = displayDesc.substr(0, 39) + "...";
    }

    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        ss << nums[i];
        if (i + 1 < nums.size()) ss << ",";
        if (ss.str().length() > 24) {
            ss << "...";
            break;
        }
    }
    ss << "]";
    string inputDisplay = ss.str();
    if (inputDisplay.length() > 26) {
        inputDisplay = inputDisplay.substr(0, 23) + "...]";
    }

    string expDisplay = to_string(expected);
    string resDisplay = to_string(result);

    cout << left << setw(6)  << testId
         << setw(44) << displayDesc
         << setw(28) << inputDisplay
         << setw(14) << expDisplay
         << setw(14) << resDisplay
         << status << "\n";

    // Step: 04 - Print debug failure details if mismatch occurs
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:   " << expected << "\n"
             << "     CycleDecomp:" << result << "\n"
             << "     Simulation: " << simResult << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Minimum Swaps to Sort by Digit Sum — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(44) << "Description"
         << setw(28) << "Input"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {37, 100}, 1, "Example 1: nums = [37, 100]");
    runTest(2, {22, 14, 33, 7}, 0, "Example 2: nums = [22, 14, 33, 7]");
    runTest(3, {18, 43, 34, 16}, 2, "Example 3: nums = [18, 43, 34, 16]");
    runTest(4, {42}, 0, "Single element: already sorted");
    runTest(5, {10, 20}, 0, "Two sorted elements: sums 1 and 2");
    runTest(6, {20, 10}, 1, "Two elements reversed: sums 2 and 1");
    runTest(7, {34, 43, 25, 52}, 2, "Identical digit sums: sorted by value");
    runTest(8, {1000000000, 999999999, 100000000}, 2, "Large boundary numbers up to 10^9");
    runTest(9, {8, 1, 9, 2}, 3, "Single long permutation cycle");
    runTest(10, {40, 30, 20, 10}, 2, "Strictly descending digit sums");
    runTest(11, {11, 20, 101, 110}, 0, "Identical digit sums already sorted");
    runTest(12, {105, 30, 12, 401, 23}, 2, "Mixed digit sums with fixed points");

    // Step: 03 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
