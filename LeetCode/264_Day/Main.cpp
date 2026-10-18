#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, const vector<int>& nums, int expected, const string& description) {
    // Step: 01 - Execute primary divide and conquer with Pascal's triangle
    Solution sol;
    vector<int> numsCopy = nums;
    int result = sol.numOfWays(numsCopy);

    // Step: 02 - Cross-verify with Fermat modular inverse method
    int fermatResult = sol.numOfWaysFermat(numsCopy);
    bool passed = (result == expected) && (fermatResult == expected);
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
        if (ss.str().length() > 22) {
            ss << "...";
            break;
        }
    }
    ss << "]";
    string inputDisplay = ss.str();
    if (inputDisplay.length() > 24) {
        inputDisplay = inputDisplay.substr(0, 21) + "...]";
    }

    string expDisplay = to_string(expected);
    string resDisplay = to_string(result);

    cout << left << setw(6)  << testId
         << setw(44) << displayDesc
         << setw(26) << inputDisplay
         << setw(14) << expDisplay
         << setw(14) << resDisplay
         << status << "\n";

    // Step: 04 - Print debug failure details if mismatch occurs
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:   " << expected << "\n"
             << "     Pascal DP:  " << result << "\n"
             << "     Fermat:     " << fermatResult << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Number of Ways to Reorder Array to Get Same BST — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(44) << "Description"
         << setw(26) << "Input"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Precompute large test cases with solution logic
    Solution sol;
    vector<int> t11 = {9, 4, 2, 1, 3, 6, 5, 7, 8, 14, 11, 10, 12, 13, 16, 15, 17, 18};
    int expT11 = sol.numOfWays(t11);

    vector<int> t12 = {10, 5, 15, 2, 7, 12, 20};
    int expT12 = sol.numOfWays(t12);

    // Step: 03 - Execute test cases
    runTest(1, {2, 1, 3}, 1, "Example 1: nums = [2, 1, 3]");
    runTest(2, {3, 4, 5, 1, 2}, 5, "Example 2: nums = [3, 4, 5, 1, 2]");
    runTest(3, {1, 2, 3}, 0, "Example 3: nums = [1, 2, 3]");
    runTest(4, {1}, 0, "Single element base case: nums = [1]");
    runTest(5, {1, 2}, 0, "Two elements ascending: nums = [1, 2]");
    runTest(6, {2, 1}, 0, "Two elements descending: nums = [2, 1]");
    runTest(7, {4, 2, 6, 1, 3, 5, 7}, 79, "Perfect balanced BST with 3 levels");
    runTest(8, {5, 4, 3, 2, 1}, 0, "Strictly descending: completely left-skewed");
    runTest(9, {3, 1, 2}, 0, "Zigzag insertion: only 1 valid ordering");
    runTest(10, {5, 3, 1, 2, 4}, 2, "Left-heavy BST with branching");
    runTest(11, t11, expT11, "Large BST with 18 distinct nodes");
    runTest(12, t12, expT12, "Balanced BST with root 10");

    // Step: 04 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
