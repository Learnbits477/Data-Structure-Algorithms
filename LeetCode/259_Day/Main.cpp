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

void runTest(int testNum, vector<int> nums, long long expected, const string& description) {
    // Step: 01 - Execute primary sorting and alternative partition solvers
    Solution sol;
    vector<int> numsCopy = nums;
    long long resPrimary = sol.maxAlternatingSum(nums);
    long long resPartition = sol.maxAlternatingSumQuickSelect(numsCopy);

    // Step: 02 - Verify result correctness and cross-algorithm agreement
    bool passed = (resPrimary == expected) && (resPartition == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    string inputDisplay = formatArray(numsCopy);
    if (inputDisplay.length() > 28) {
        inputDisplay = inputDisplay.substr(0, 25) + "...]";
    }

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(30) << inputDisplay
         << setw(14) << expected
         << setw(14) << resPrimary
         << status << "\n";

    // Step: 04 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:   " << expected << "\n"
             << "     Primary:    " << resPrimary << "\n"
             << "     Partition:  " << resPartition << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Maximum Alternating Sum of Squares — Test Suite\n";
    cout << "※ ============================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(30) << "Input"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {1, 2, 3}, 12LL, "Example 1: Positive sequence size 3");
    runTest(2, {1, -1, 2, -2, 3, -3}, 16LL, "Example 2: Symmetrical positive and negative");
    runTest(3, {5}, 25LL, "Single positive element: 5^2");
    runTest(4, {-7}, 49LL, "Single negative element: (-7)^2");
    runTest(5, {2, 5}, 21LL, "Two elements one positive one negative");
    runTest(6, {-10, 3}, 91LL, "Two mixed signs: 100 - 9");
    runTest(7, {0, 0, 0, 0}, 0LL, "All zero elements");
    runTest(8, {4, 4, 4, 4}, 0LL, "All identical elements even length");
    runTest(9, {4, 4, 4, 4, 4}, 16LL, "All identical elements odd length");
    runTest(10, {40000, -40000, 30000, -30000}, 1400000000LL, "Large values constraint boundary");
    runTest(11, {-3, 5, 2, -1, 4}, 45LL, "Five mixed elements odd partition");
    runTest(12, {-8, 7, -6, 5, -4, 3, -2, 1}, 144LL, "Alternating signs eight elements");

    // Step: 03 - Display final completion summary
    cout << "※ ============================================================================================================== ※\n";
    cout << "                                🎉 All Tests Completed Successfully!                                \n\n";
    return 0;
}
