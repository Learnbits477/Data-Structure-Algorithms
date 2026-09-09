#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int n, int expected) {
    Solution sol;
    int result = sol.findMax(n);
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
    cout << "\n🌟 Max Digit Sum Number in 1 to n — Test Suite\n";
    cout << "※ =============================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(16) << "n"
         << setw(16) << "Result"
         << setw(16) << "Expected"
         << "Status\n";
    cout << string(65, '-') << "\n";

    // Test 1: Example 1 from problem description (n = 48 -> 48)
    runTest(1, 48, 48);

    // Test 2: Example 2 from problem description (n = 90 -> 89)
    runTest(2, 90, 89);

    // Test 3: Single digit boundary (n = 7 -> 7)
    runTest(3, 7, 7);

    // Test 4: Power of 10 boundary (n = 100 -> 99)
    runTest(4, 100, 99);

    // Test 5: Number already all 9s (n = 999 -> 999)
    runTest(5, 999, 999);

    // Test 6: Number with trailing zeros (n = 5000 -> 4999)
    runTest(6, 5000, 4999);

    // Test 7: Tie with multiple maximum digit sum candidates (n = 398 -> 398)
    runTest(7, 398, 398);

    // Test 8: Tie with multiple maximum digit sum candidates (n = 388 -> 299)
    runTest(8, 388, 299);

    // Test 9: Large number (n = 1000000000 -> 999999999)
    runTest(9, 1000000000, 999999999);

    cout << "※ =============================================================== ※\n";
    cout << "                     🎉 All Tests Executed!                       \n\n";

    return 0;
}
