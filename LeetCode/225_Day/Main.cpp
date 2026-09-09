#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, long long n, long long expected) {
    Solution sol;
    long long result = sol.countCommas(n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(20) << n
         << setw(20) << result
         << setw(20) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n        = " << n << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🌟 Count Commas in Range II — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(20) << "n"
         << setw(20) << "Result"
         << setw(20) << "Expected"
         << "Status\n";
    cout << string(75, '-') << "\n";

    // Test 1: Example 1 from problem description (n = 1002 -> 3)
    runTest(1, 1002LL, 3LL);

    // Test 2: Example 2 from problem description (n = 998 -> 0)
    runTest(2, 998LL, 0LL);

    // Test 3: Lower boundary n = 1 -> 0
    runTest(3, 1LL, 0LL);

    // Test 4: Exactly before 1st comma threshold n = 999 -> 0
    runTest(4, 999LL, 0LL);

    // Test 5: Exact 1st comma threshold n = 1000 -> 1
    runTest(5, 1000LL, 1LL);

    // Test 6: Exactly before 2nd comma threshold n = 999999 -> 999000
    runTest(6, 999999LL, 999000LL);

    // Test 7: Exact 2nd comma threshold n = 1000000 -> 999002
    runTest(7, 1000000LL, 999002LL);

    // Test 8: Crossing multiple thresholds n = 1000005 -> 999012
    runTest(8, 1000005LL, 999012LL);

    // Test 9: Billions range n = 1000000002 -> 1998999009
    runTest(9, 1000000002LL, 1998999009LL);

    // Test 10: Maximum constraint boundary n = 10^15
    // Thresholds: 10^3, 10^6, 10^9, 10^12, 10^15
    // 10^15 - 1000 + 1 = 999999999999001
    // 10^15 - 10^6 + 1 = 999999999000001
    // 10^15 - 10^9 + 1 = 999999000000001
    // 10^15 - 10^12 + 1 = 999000000000001
    // 10^15 - 10^15 + 1 = 1
    // Total = 3998998998999005
    runTest(10, 1000000000000000LL, 3998998998999005LL);

    cout << "※ ========================================================================= ※\n";
    cout << "                         🎉 All Tests Executed!                             \n\n";

    return 0;
}
