#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int n, int k, int expected) {
    Solution sol;
    int result = sol.palindromicStrings(n, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(8)  << n
         << setw(8)  << k
         << setw(14) << result
         << setw(14) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n=" << n << ", k=" << k << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎯 Count Palindromic Strings with Constraints — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(8)  << "n"
         << setw(8)  << "k"
         << setw(14) << "Result"
         << setw(14) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, 3, 2, 6);

    // Test 2: Example 2 from problem description
    runTest(2, 4, 3, 18);

    // Test 3: Single character alphabet, length 1
    runTest(3, 1, 1, 1);

    // Test 4: Single character alphabet, length 2 (only "a", "aa")
    runTest(4, 2, 1, 2);

    // Test 5: Single character alphabet, length 3 ("a", "aa", length 3 impossible since 'a' appears 3 times)
    runTest(5, 3, 1, 2);

    // Test 6: k = 2, n = 4 ("a", "b", "aa", "bb", "aba", "bab", "abba", "baab") -> 2 + 2 + 2 + 2 = 8
    runTest(6, 4, 2, 8);

    // Test 7: k = 5, n = 5
    // L=1: P(5,1)=5
    // L=2: P(5,1)=5
    // L=3: P(5,2)=20
    // L=4: P(5,2)=20
    // L=5: P(5,3)=60
    // Total = 5 + 5 + 20 + 20 + 60 = 110
    runTest(7, 5, 5, 110);

    // Test 8: Large k and n: k = 26, n = 10
    // L=1..2: 2 * 26 = 52
    // L=3..4: 2 * 650 = 1300
    // L=5..6: 2 * 15600 = 31200
    // L=7..8: 2 * 358800 = 717600
    // L=9..10: 2 * 7893600 = 15787200
    // Total = 52 + 1300 + 31200 + 717600 + 15787200 = 16537352
    runTest(8, 10, 26, 16537352);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
