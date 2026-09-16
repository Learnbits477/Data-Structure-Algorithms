#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int n, int k, int expected) {
    Solution sol;
    int result = sol.numberOfSets(n, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(10) << n
         << setw(10) << k
         << setw(16) << expected
         << setw(16) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n:        " << n << "\n"
             << "     k:        " << k << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n📏 1621. Number of Sets of K Non-Overlapping Line Segments — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(10) << "n"
         << setw(10) << "k"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 (n = 4, k = 2) -> 5
    runTest(1, 4, 2, 5);

    // Test 2: Example 2 (n = 3, k = 1) -> 3
    runTest(2, 3, 1, 3);

    // Test 3: Example 3 (n = 30, k = 7) -> 796297179
    runTest(3, 30, 7, 796297179);

    // Test 4: Minimal boundary (n = 2, k = 1) -> C(2, 2) = 1
    runTest(4, 2, 1, 1);

    // Test 5: Maximum segments for minimal n (n = 5, k = 4) -> C(8, 8) = 1
    runTest(5, 5, 4, 1);

    // Test 6: Single segment for general n (n = 5, k = 1) -> C(5, 2) = 10
    runTest(6, 5, 1, 10);

    // Test 7: n = 10, k = 3 -> C(12, 6) = 924
    runTest(7, 10, 3, 924);

    // Test 8: n = 50, k = 10 -> C(59, 20) % (10^9 + 7) = 984308396
    runTest(8, 50, 10, 984308396);

    // Test 9: n = 1000, k = 1 -> C(1000, 2) = 499500
    runTest(9, 1000, 1, 499500);

    // Test 10: n = 1000, k = 999 (k = n - 1) -> C(1998, 1998) = 1
    runTest(10, 1000, 999, 1);

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
