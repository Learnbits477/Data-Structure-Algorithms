#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string formatDigits(const vector<int>& digits) {
    if (digits.empty()) return "[]";
    string s = "[";
    for (size_t i = 0; i < digits.size(); i++) {
        s += to_string(digits[i]);
        if (i + 1 < digits.size()) s += ", ";
    }
    s += "]";
    return s;
}

void runTest(int testNum, vector<int> digits, int expected) {
    Solution sol;
    int result = sol.totalNumbers(digits);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(26) << formatDigits(digits)
         << setw(16) << result
         << setw(16) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Digits   = " << formatDigits(digits) << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Unique 3-Digit Even Numbers — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Input Digits"
         << setw(16) << "Result"
         << setw(16) << "Expected"
         << "Status\n";
    cout << string(74, '-') << "\n";

    // Test 1: Example 1 from problem description: [1, 2, 3, 4] -> 12
    runTest(1, {1, 2, 3, 4}, 12);

    // Test 2: Example 2 from problem description: [0, 2, 2] -> 2 (202, 220)
    runTest(2, {0, 2, 2}, 2);

    // Test 3: Example 3 from problem description: [6, 6, 6] -> 1 (666)
    runTest(3, {6, 6, 6}, 1);

    // Test 4: Example 4 from problem description: [1, 3, 5] -> 0 (no even numbers)
    runTest(4, {1, 3, 5}, 0);

    // Test 5: Only even digits: [2, 4, 6] -> 6 (246, 264, 426, 462, 624, 642)
    runTest(5, {2, 4, 6}, 6);

    // Test 6: Multiple zeros: [0, 0, 0, 2] -> 1 (200)
    runTest(6, {0, 0, 0, 2}, 1);

    // Test 7: Duplicates with mixed parity: [2, 2, 8, 8] -> 6 (228, 282, 288, 822, 828, 882)
    runTest(7, {2, 2, 8, 8}, 6);

    // Test 8: All digits from 0 to 9 (10 digits): 10 digits full range
    runTest(8, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 328);

    cout << "※ ========================================================================= ※\n";
    cout << "                         🎉 All Tests Executed!                             \n\n";

    return 0;
}
