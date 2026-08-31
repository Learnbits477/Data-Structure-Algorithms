#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int n, int i, int d, int c, int expected) {
    Solution sol;
    int result = sol.minCost(n, i, d, c);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(8)  << n
         << setw(8)  << i
         << setw(8)  << d
         << setw(8)  << c
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n=" << n << ", i=" << i << ", d=" << d << ", c=" << c << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎯 Minimum Cost for n Characters — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(8)  << "n"
         << setw(8)  << "i"
         << setw(8)  << "d"
         << setw(8)  << "c"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(75, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, 9, 1, 2, 1, 5);

    // Test 2: Example 2 from problem description
    runTest(2, 9, 10, 1, 1, 17);

    // Test 3: Base case n = 1
    runTest(3, 1, 5, 2, 3, 5);

    // Test 4: Small even n = 2
    runTest(4, 2, 4, 3, 2, 6);

    // Test 5: Power of 2 (n = 8) with cheap copy
    runTest(5, 8, 2, 2, 1, 5);

    // Test 6: Expensive copy, cheap insert
    runTest(6, 6, 2, 5, 20, 12);

    // Test 7: n = 10, balanced costs
    runTest(7, 10, 2, 1, 3, 12);

    // Test 8: Odd n where copy + delete is superior
    runTest(8, 7, 15, 2, 3, 26);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
