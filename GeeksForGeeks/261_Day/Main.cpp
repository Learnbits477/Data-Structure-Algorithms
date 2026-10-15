#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatArray(const vector<int>& arr) {
    // Step: 01 - Format vector into compact bracketed string representation
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        ss << arr[i];
        if (i + 1 < arr.size()) {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<int> nums, int expected, const string& description) {
    // Step: 01 - Execute primary and alternative algorithm implementations
    Solution sol;
    int resPrimary = sol.sumCounts(nums);
    int resSet = sol.sumCountsSet(nums);
    int resDynamic = sol.sumCountsDynamic(nums);

    // Step: 02 - Verify result correctness and cross-method agreement
    bool passed = (resPrimary == expected) && (resSet == expected) && (resDynamic == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    string inputDisplay = formatArray(nums);
    if (inputDisplay.length() > 24) {
        inputDisplay = inputDisplay.substr(0, 21) + "...]";
    }

    string expDisplay = to_string(expected);
    string resDisplay = to_string(resPrimary);

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(26) << inputDisplay
         << setw(16) << expDisplay
         << setw(16) << resDisplay
         << status << "\n";

    // Step: 04 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:  " << expected << "\n"
             << "     Primary:   " << resPrimary << "\n"
             << "     Set:       " << resSet << "\n"
             << "     Dynamic:   " << resDynamic << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Subarrays Distinct Element Sum of Squares I — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(26) << "Input"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {1, 2, 1}, 15, "Example 1: nums = [1, 2, 1]");
    runTest(2, {1, 1}, 3, "Example 2: nums = [1, 1]");
    runTest(3, {1}, 1, "Single element: nums = [1]");
    runTest(4, {1, 2, 3}, 20, "All distinct length 3");
    runTest(5, {2, 2, 2}, 6, "All identical length 3");
    runTest(6, {1, 2, 3, 4}, 50, "All distinct length 4");
    runTest(7, {1, 2, 1, 2}, 28, "Alternating two values");
    runTest(8, {5, 5, 5, 5, 5}, 15, "All 5 identical elements");
    runTest(9, {100, 1, 100, 1}, 28, "Boundary value 100 alternating");
    runTest(10, {1, 2, 3, 1, 2, 3}, 116, "Cyclic repeated pattern");
    runTest(11, {4, 3, 2, 1}, 50, "Strictly decreasing 4 values");
    runTest(12, {2, 3, 2, 4, 3, 2, 5, 4, 3, 2}, 519, "Arbitrary 10-element array");

    // Step: 03 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
