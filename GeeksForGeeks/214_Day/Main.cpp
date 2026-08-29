#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string formatString(const string& s) {
    if (s.length() <= 15) {
        return "\"" + s + "\"";
    }
    return "\"" + s.substr(0, 12) + "...\"";
}

void runTest(int testNum, const string& s, int n, int expected) {
    Solution sol;
    int result = sol.countSubsequences(s, n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(20) << formatString(s)
         << setw(10) << n
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input s:  " << s << "\n"
             << "     Divisor n:" << n << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎮 Count Subsequences Divisible by n — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(20) << "Input String (s)"
         << setw(10) << "Divisor(n)"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, "1234", 4, 4);

    // Test 2: Example 2 from problem description
    runTest(2, "330", 6, 4);

    // Test 3: Single digit divisible by n
    runTest(3, "6", 3, 1);

    // Test 4: Single digit not divisible by n
    runTest(4, "5", 3, 0);

    // Test 5: Trivial divisor n = 1 (all 2^|s| - 1 subsequences valid)
    runTest(5, "123", 1, 7);

    // Test 6: All zeros
    runTest(6, "000", 5, 7);

    // Test 7: No subsequence divisible by n
    runTest(7, "111", 4, 0);

    // Test 8: Subsequence with leading zero
    runTest(8, "04", 4, 3);

    // Test 9: Prime divisor (n = 7)
    runTest(9, "147", 7, 3);

    // Test 10: Multi-digit with multiple divisibility
    runTest(10, "1020", 5, 10);

    // Test 11: All identical even digits (n = 2)
    runTest(11, "222", 2, 7);

    // Test 12: Powers of 10 ("0", "0", "00", "10", "10", "100" are divisible by 10; only "1" is not)
    runTest(12, "100", 10, 6);

    cout << "※ ============================================================================== ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
