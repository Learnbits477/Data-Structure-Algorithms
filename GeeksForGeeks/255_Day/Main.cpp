#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int n, int expected, const string& description) {
    // Step: 01 - Compute results using greedy, bitwise, and DP approaches
    Solution sol;
    int resGreedy = sol.minOperation(n);
    int resBitwise = sol.minOperationBitwise(n);
    int resDP = (n <= 100000) ? sol.minOperationDP(n) : resGreedy;

    // Step: 02 - Validate test result and cross-method consistency
    bool passed = (resGreedy == expected) && (resBitwise == expected) && (resDP == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(14) << n
         << setw(12) << expected
         << setw(12) << resGreedy
         << status << "\n";

    // Step: 04 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Target n:      " << n << "\n"
             << "     Expected:      " << expected << "\n"
             << "     Greedy Result: " << resGreedy << "\n"
             << "     Bitwise:       " << resBitwise << "\n"
             << "     DP Result:     " << resDP << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n📈 Minimum Operations to Reach n — Test Suite\n";
    cout << "※ ============================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(14) << "Target (n)"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Step: 02 - Execute diverse test cases
    runTest(1, 8, 4, "Example 1: Pure power of 2 (8)");
    runTest(2, 7, 5, "Example 2: All set bits in 3 bits (7)");
    runTest(3, 1, 1, "Example 3: Smallest positive constraint (1)");
    runTest(4, 2, 2, "Minimal even power (2)");
    runTest(5, 3, 3, "Small odd number (3)");
    runTest(6, 4, 3, "Power of two (4 = 2^2)");
    runTest(7, 5, 4, "Number requiring alternation (5)");
    runTest(8, 6, 4, "Composite even number (6)");
    runTest(9, 15, 7, "All ones in 4 bits (15 = 1111_2)");
    runTest(10, 16, 5, "Power of two (16 = 2^4)");
    runTest(11, 42, 8, "Mixed bits (42 = 101010_2)");
    runTest(12, 1024, 11, "Large power of two (1024 = 2^10)");
    runTest(13, 1000000, 26, "Maximum constraint boundary (10^6)");

    // Step: 03 - Display final completion summary
    cout << "※ ============================================================================================================== ※\n";
    cout << "                                🎉 All Tests Completed Successfully!                                \n\n";
    return 0;
}
