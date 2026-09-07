#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, int expected) {
    Solution sol;
    int result = sol.distinctSubseqII(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string sDisplay = s;
    if (sDisplay.length() > 24) {
        sDisplay = sDisplay.substr(0, 21) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(26) << sDisplay
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     s        = " << s << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🔴 940. Distinct Subsequences II — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "String s"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(62, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, "abc", 7);

    // Test 2: Example 2 from problem description
    runTest(2, "aba", 6);

    // Test 3: Example 3 from problem description
    runTest(3, "aaa", 3);

    // Test 4: Single character string
    runTest(4, "a", 1);

    // Test 5: Two distinct characters
    runTest(5, "ab", 3);

    // Test 6: Two duplicate characters
    runTest(6, "aa", 2);

    // Test 7: String with duplicated prefix
    // "bba" -> "b", "a", "bb", "ba", "bba" (5 subsequences)
    runTest(7, "bba", 5);

    // Test 8: String with duplicated suffix
    // "lee" -> "l", "e", "le", "ee", "lee" (5 subsequences)
    runTest(8, "lee", 5);

    // Test 9: Alternating characters
    // "abab" -> "a", "b", "aa", "ab", "ba", "bb", "aab", "aba", "abb", "bab", "abab" (11 subsequences)
    runTest(9, "abab", 11);

    // Test 10: All 26 alphabet characters in order
    // Subsequence count = 2^26 - 1 = 67108863
    runTest(10, "abcdefghijklmnopqrstuvwxyz", 67108863);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
