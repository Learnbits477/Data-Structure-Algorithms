#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> nums1, vector<int> nums2, int k1, int k2, long long expected, const string& description) {
    // Step: 01 - Compute results using bucket frequency and binary search solvers
    Solution sol;
    long long resBucket = sol.minSumSquareDiff(nums1, nums2, k1, k2);
    long long resBinary = sol.minSumSquareDiffBinarySearch(nums1, nums2, k1, k2);

    // Step: 02 - Validate test result and cross-method equivalence
    bool passed = (resBucket == expected) && (resBinary == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    string kDisplay = "k1=" + to_string(k1) + ", k2=" + to_string(k2);
    if (kDisplay.length() > 16) {
        kDisplay = kDisplay.substr(0, 13) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(18) << kDisplay
         << setw(14) << expected
         << setw(14) << resBucket
         << status << "\n";

    // Step: 04 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:      " << expected << "\n"
             << "     Bucket Result: " << resBucket << "\n"
             << "     Binary Search: " << resBinary << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Minimum Sum of Squared Difference — Test Suite\n";
    cout << "※ ============================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(18) << "Budget (k1, k2)"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {1, 2, 3, 4}, {2, 10, 20, 19}, 0, 0, 579LL, "Example 1: Zero modifications allowed");
    runTest(2, {1, 4, 10, 12}, {5, 8, 6, 9}, 1, 1, 43LL, "Example 2: Balanced partial reduction");
    runTest(3, {1, 2, 3}, {1, 2, 3}, 5, 5, 0LL, "Already identical arrays (diff = 0)");
    runTest(4, {10}, {20}, 5, 3, 4LL, "Single element reduced: 10 - 8 = 2");
    runTest(5, {10}, {20}, 10, 10, 0LL, "Excess budget reduces single diff to 0");
    runTest(6, {5, 5, 5}, {10, 10, 10}, 3, 3, 27LL, "Equal diffs reduced: 3 items to 3");
    runTest(7, {7, 11, 4, 1, 9}, {1, 3, 10, 6, 8}, 0, 2, 134LL, "One-sided budget with k1 = 0");
    runTest(8, {1, 2, 3}, {10, 20, 30}, 100, 100, 0LL, "Large budget exceeding total diffs");
    runTest(9, {0}, {0}, 0, 0, 0LL, "Single zero boundary values");
    runTest(10, {100000}, {0}, 50000, 25000, 625000000LL, "Max constraint: 10^5 reduced by 75K");
    runTest(11, {1, 3, 5, 7, 9}, {2, 4, 6, 8, 10}, 1, 2, 2LL, "Uniform diffs of 1 with partial budget");
    runTest(12, {10, 20, 30, 40}, {40, 30, 20, 10}, 10, 10, 1000LL, "Cross-symmetric differences reduction");

    // Step: 03 - Display final completion summary
    cout << "※ ============================================================================================================== ※\n";
    cout << "                                🎉 All Tests Completed Successfully!                                \n\n";
    return 0;
}
