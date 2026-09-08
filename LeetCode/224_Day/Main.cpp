#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int n, int expected) {
    Solution sol;
    int result = sol.countCommas(n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(16) << n
         << setw(16) << result
         << setw(16) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n        = " << n << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🌟 Count Commas in Range — Test Suite\n";
    cout << "※ =============================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(16) << "n"
         << setw(16) << "Result"
         << setw(16) << "Expected"
         << "Status\n";
    cout << string(65, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, 1002, 3);

    // Test 2: Example 2 from problem description
    runTest(2, 998, 0);

    // Test 3: Lower boundary n = 1
    runTest(3, 1, 0);

    // Test 4: Just before first comma n = 999
    runTest(4, 999, 0);

    // Test 5: Exact threshold for 1 comma n = 1000
    runTest(5, 1000, 1);

    // Test 6: Small number with comma n = 1001
    runTest(6, 1001, 2);

    // Test 7: Intermediate 4-digit number n = 2500
    runTest(7, 2500, 1501);

    // Test 8: 5-digit number n = 10000
    runTest(8, 10000, 9001);

    // Test 9: Upper constraint boundary n = 100000 (10^5)
    runTest(9, 100000, 99001);

    cout << "※ =============================================================== ※\n";
    cout << "                     🎉 All Tests Executed!                       \n\n";

    return 0;
}
