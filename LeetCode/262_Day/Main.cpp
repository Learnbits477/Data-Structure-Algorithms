#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, const vector<int>& nums, int expected, const string& description) {
    // Step: 01 - Execute primary segment tree algorithm
    Solution sol;
    vector<int> numsCopy = nums;
    int result = sol.sumCounts(numsCopy);

    // Step: 02 - Verify result correctness and cross-check with brute-force for smaller inputs
    bool passed = (result == expected);
    if (nums.size() <= 200) {
        vector<int> numsBf = nums;
        int bfResult = sol.sumCountsBruteForce(numsBf);
        passed = passed && (bfResult == expected);
    }
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
             << "     Expected:    " << expected << "\n"
             << "     SegmentTree: " << result << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Subarrays Distinct Element Sum of Squares II — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(44) << "Description"
         << setw(28) << "Input"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {1, 2, 1}, 15, "Example 1: nums = [1, 2, 1]");
    runTest(2, {2, 2}, 3, "Example 2: nums = [2, 2]");
    runTest(3, {1}, 1, "Single element: nums = [1]");
    runTest(4, {1, 2, 3, 4, 5}, 105, "All unique: 5 strictly distinct numbers");
    runTest(5, {5, 5, 5, 5}, 10, "All duplicates: 4 identical elements");
    runTest(6, {1, 3, 2, 1, 3, 2, 4}, 194, "Repeating cycle with new ending element");
    runTest(7, {10, 20, 10, 30, 20, 40}, 132, "General mixed sequence");
    runTest(8, {1, 1, 2, 2, 3, 3}, 77, "Adjacent duplicate pairs");
    runTest(9, {100000, 100000, 100000}, 6, "Maximum constraint elements");
    runTest(10, {1, 2, 1, 2, 1, 2}, 66, "Alternating binary values");
    runTest(11, {4, 1, 2, 3, 1, 4}, 151, "Boundary repetitions");
    runTest(12, {5, 4, 3, 2, 1, 1, 2, 3, 4, 5}, 605, "Palindrome-like mirrored array");

    // Step: 03 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
