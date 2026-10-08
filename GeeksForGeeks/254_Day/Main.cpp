#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatArray(const vector<int>& arr) {
    if (arr.empty()) return "[]";
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        ss << arr[i] << (i + 1 < arr.size() ? "," : "");
    }
    ss << "]";
    string res = ss.str();
    if (res.length() > 20) {
        return res.substr(0, 17) + "...]";
    }
    return res;
}

void runTest(int testNum, vector<int> arr, int k, int expected, const string& description) {
    // Step: 01 - Execute primary sliding window and secondary binary search solvers
    Solution sol;
    vector<int> arrCopy1 = arr;
    vector<int> arrCopy2 = arr;
    int res1 = sol.maxFrequency(arrCopy1, k);
    int res2 = sol.maxFrequencyBinarySearch(arrCopy2, k);

    // Step: 02 - Validate test result and cross-method consistency
    bool passed = (res1 == expected) && (res2 == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 36) {
        displayDesc = displayDesc.substr(0, 33) + "...";
    }

    string arrayDisplay = formatArray(arr);

    cout << left << setw(6)  << testId
         << setw(38) << displayDesc
         << setw(20) << arrayDisplay
         << setw(8)  << k
         << setw(12) << expected
         << setw(12) << res1
         << status << "\n";

    // Step: 04 - Print debug information in case of failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input Array:   " << formatArray(arr) << "\n"
             << "     k Operations:  " << k << "\n"
             << "     Expected:      " << expected << "\n"
             << "     Sliding Window:" << res1 << "\n"
             << "     Binary Search: " << res2 << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n📈 Maximum Frequency with K Increments — Test Suite\n";
    cout << "※ ============================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(38) << "Description"
         << setw(20) << "Input Array"
         << setw(8)  << "k"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {2, 2, 4}, 4, 3, "Example 1: Equalize to largest element");
    runTest(2, {7, 7, 7, 7}, 5, 4, "Example 2: All elements already identical");
    runTest(3, {1, 4, 8, 13}, 5, 2, "Example 3: Dispersed ascending sequence");
    runTest(4, {10}, 0, 1, "Single element array with zero k");
    runTest(5, {3, 9, 3, 3, 5}, 0, 3, "Zero operations with existing duplicate");
    runTest(6, {1, 2, 3, 4}, 100, 4, "Generous k budget leveling all values");
    runTest(7, {1, 2, 4}, 5, 3, "All elements reach maximum value");
    runTest(8, {100, 200, 300}, 50, 1, "Insufficient budget for gap bridging");
    runTest(9, {1, 1, 2, 2, 3, 3}, 2, 4, "Multiple paired groups shifted up");
    runTest(10, {1000000, 1000000, 1000000}, 100000, 3, "Max constraint values");
    runTest(11, {9, 8, 7, 6, 5}, 4, 3, "Descending input requires sorting");

    // Step: 03 - Display final completion summary
    cout << "※ ============================================================================================================== ※\n";
    cout << "                                🎉 All Tests Completed Successfully!                                \n\n";
    return 0;
}
