#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, const string& t, int expected) {
    Solution sol;
    int result = sol.numDistinct(s, t);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string sDisplay = s;
    if (sDisplay.length() > 18) {
        sDisplay = sDisplay.substr(0, 15) + "...";
    }

    string tDisplay = t;
    if (tDisplay.length() > 12) {
        tDisplay = tDisplay.substr(0, 9) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(20) << sDisplay
         << setw(14) << tDisplay
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     s        = " << s << "\n"
             << "     t        = " << t << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🔴 115. Distinct Subsequences — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(20) << "String s"
         << setw(14) << "String t"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, "rabbbit", "rabbit", 3);

    // Test 2: Example 2 from problem description
    runTest(2, "babgbag", "bag", 5);

    // Test 3: Identical strings
    runTest(3, "leetcode", "leetcode", 1);

    // Test 4: s shorter than t
    runTest(4, "cat", "caterpillar", 0);

    // Test 5: Target character not in source
    runTest(5, "abcdef", "z", 0);

    // Test 6: Single character repeated
    // "aaaaa", "aa" -> C(5, 2) = 10
    runTest(6, "aaaaa", "aa", 10);

    // Test 7: Single character repeated exact
    // "aaaa", "aaaa" -> C(4, 4) = 1
    runTest(7, "aaaa", "aaaa", 1);

    // Test 8: Multiple identical options
    // "abcdeabcde", "ace"
    // 'a' at {0, 5}, 'c' at {2, 7}, 'e' at {4, 9} -> valid tuples (i < j < k):
    // (0,2,4), (0,2,9), (0,7,9), (5,7,9) = 4 ways
    runTest(8, "abcdeabcde", "ace", 4);

    // Test 9: Alternating characters
    // "ababab", "ab" -> a at {0,2,4}, b at {1,3,5} -> 3+2+1 = 6 ways
    runTest(9, "ababab", "ab", 6);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
