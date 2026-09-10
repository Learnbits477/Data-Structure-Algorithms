#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int x, int y, int expected) {
    Solution sol;
    int result = sol.pairCount(x, y);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(12) << x
         << setw(12) << y
         << setw(16) << result
         << setw(16) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     x        = " << x << "\n"
             << "     y        = " << y << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Pairs with Given GCD and LCM — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(12) << "x (GCD)"
         << setw(12) << "y (LCM)"
         << setw(16) << "Result"
         << setw(16) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description: x = 2, y = 12 -> 4
    // Pairs: (2, 12), (4, 6), (6, 4), (12, 2)
    runTest(1, 2, 12, 4);

    // Test 2: Example 2 from problem description: x = 6, y = 4 -> 0
    // y % x != 0
    runTest(2, 6, 4, 0);

    // Test 3: Equal GCD and LCM: x = 5, y = 5 -> 1
    // Pair: (5, 5)
    runTest(3, 5, 5, 1);

    // Test 4: Single prime quotient: x = 3, y = 15 -> n = 5 (prime) -> 2
    // Pairs: (3, 15), (15, 3)
    runTest(4, 3, 15, 2);

    // Test 5: Square of prime: x = 2, y = 18 -> n = 9 (3^2). Divisors 1 (coprime to 9) -> 2 pairs; 3 (not coprime to 3) -> 0 -> Total = 2
    // Pairs: (2, 18), (18, 2)
    runTest(5, 2, 18, 2);

    // Test 6: Three distinct prime factors: n = 30 = 2*3*5 -> 2^3 = 8 pairs. x = 1, y = 30 -> 8
    runTest(6, 1, 30, 8);

    // Test 7: n has power of prime factors: n = 72 = 2^3 * 3^2 -> 2 distinct prime factors -> 2^2 = 4 pairs. x = 10, y = 720 -> 4
    runTest(7, 10, 720, 4);

    // Test 8: Upper constraint bound: x = 1, y = 10000 -> 10000 = 2^4 * 5^4 (2 distinct primes) -> 2^2 = 4 pairs
    runTest(8, 1, 10000, 4);

    cout << "※ ========================================================================= ※\n";
    cout << "                         🎉 All Tests Executed!                             \n\n";

    return 0;
}
