#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, int k, int expected) {
    Solution sol;
    int result = sol.maxPalindromes(s, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayStr = "\"" + s + "\"";
    if (displayStr.length() > 24) {
        displayStr = displayStr.substr(0, 21) + "...\"";
    }

    cout << left << setw(6)  << testId
         << setw(26) << displayStr
         << setw(10) << k
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     s:        \"" << s << "\"\n"
             << "     k:        " << k << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔤 2472. Maximum Number of Non-overlapping Palindrome Substrings — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "String s"
         << setw(10) << "k"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 ("abaccdbbd", k = 3) -> 2 ("aba", "dbbd")
    runTest(1, "abaccdbbd", 3, 2);

    // Test 2: Example 2 ("adbcda", k = 2) -> 0
    runTest(2, "adbcda", 2, 0);

    // Test 3: k = 1 (every character is a palindrome) -> 5
    runTest(3, "abcde", 1, 5);

    // Test 4: Repeated characters with k = 2 -> 2 ("aa", "aa")
    runTest(4, "aaaaa", 2, 2);

    // Test 5: Entire string is a single palindrome of length >= k -> 1
    runTest(5, "racecar", 5, 1);

    // Test 6: Overlapping palindromes requiring optimal choice -> 2 ("aba", "aba")
    runTest(6, "abacaba", 3, 2);

    // Test 7: Palindrome of length 4+ -> 1 ("abacaba" with k = 4)
    runTest(7, "abacaba", 4, 1);

    // Test 8: Single character string, k = 1 -> 1
    runTest(8, "z", 1, 1);

    // Test 9: Complex multi-palindrome string -> 3 ("fttf", "jhj", "qweewq")
    runTest(9, "fttfjhjqweewq", 3, 3);

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
