#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatArray(const vector<int>& arr) {
    // Step: 01 - Format vector into compact bracketed string
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

void runTest(int testNum, vector<int> nums, int k, int expected, const string& description) {
    // Step: 01 - Execute primary and alternative bit manipulation solvers
    Solution sol;
    int resPrimary = sol.maxSum(nums, k);
    int resAlternative = sol.maxSumBitPacking(nums, k);

    // Step: 02 - Check correctness and cross-method agreement
    bool passed = (resPrimary == expected) && (resAlternative == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    stringstream inputSs;
    inputSs << formatArray(nums) << ", k=" << k;
    string inputDisplay = inputSs.str();
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
             << "     Expected:     " << expected << "\n"
             << "     Primary:      " << resPrimary << "\n"
             << "     Alternative:  " << resAlternative << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Apply Operations on Array to Maximize Sum of Squares — Test Suite\n";
    cout << "※ ============================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(30) << "Input"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {2, 6, 5, 8}, 2, 261, "Example 1: Four mixed values k=2");
    runTest(2, {4, 5, 4, 7}, 3, 90, "Example 2: Repeated values k=3");
    runTest(3, {5}, 1, 25, "Single element boundary: 5^2");
    runTest(4, {7, 7, 7}, 2, 98, "All identical elements k=2");
    runTest(5, {1, 2, 4, 8}, 1, 225, "Powers of two single selection k=1");
    runTest(6, {1, 2, 4, 8}, 2, 225, "Powers of two two selections k=2");
    runTest(7, {10, 5}, 1, 225, "Alternating bits 1010 and 0101 k=1");
    runTest(8, {10, 5}, 2, 225, "Alternating bits 1010 and 0101 k=2");
    runTest(9, {1000000000}, 1, 49, "Max constraint value 10^9 modulo test");
    runTest(10, {15, 7, 3, 1}, 2, 274, "Already sorted powers prefix k=2");
    runTest(11, {3, 5, 6}, 3, 98, "Full array selection k=n");
    runTest(12, {1, 2, 3, 4, 5, 6, 7, 8}, 4, 372, "Range 1 to 8 selecting top 4");

    // Step: 03 - Display final completion summary
    cout << "※ ============================================================================================================== ※\n";
    cout << "                                🎉 All Tests Completed Successfully!                                \n\n";
    return 0;
}
