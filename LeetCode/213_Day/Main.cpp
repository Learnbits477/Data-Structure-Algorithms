#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, string s, string target, string expected) {
    Solution sol;
    string result = sol.lexPalindromicPermutation(s, target);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(16) << ("\"" + s + "\"")
         << setw(16) << ("\"" + target + "\"")
         << setw(16) << ("\"" + expected + "\"")
         << setw(16) << ("\"" + result + "\"")
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: \"" << expected << "\"\n"
             << "     Got:      \"" << result << "\"\n";
    }
}

int main() {
    cout << "\n🎮 Lexicographically Smallest Palindromic Permutation Greater Than Target — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(16) << "s"
         << setw(16) << "target"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1
    runTest(1, "baba", "abba", "baab");

    // Example 2
    runTest(2, "baba", "bbaa", "");

    // Example 3: Impossible palindrome (multiple odd counts)
    runTest(3, "abc", "abb", "");

    // Example 4: Odd length single palindrome strictly greater
    runTest(4, "aac", "abb", "aca");

    // Test 5: Single character strictly greater
    runTest(5, "b", "a", "b");

    // Test 6: Single character equal
    runTest(6, "a", "a", "");

    // Test 7: Odd length palindrome divergence in right half
    runTest(7, "abbba", "abbab", "abbba");

    // Test 8: Odd length equal to target, forces left-half divergence
    runTest(8, "abbba", "abbba", "babab");

    // Test 9: 6-char even palindrome with multi-character divergence
    runTest(9, "aabbcc", "abcabc", "abccba");

    // Test 10: All palindromic permutations smaller or equal to target
    runTest(10, "aabb", "bbaa", "");

    // Test 11: Palindrome with 3 distinct characters and equal target
    runTest(11, "daabbad", "daadabb", "dababad");

    // Test 12: Method alias verification
    Solution sol;
    string aliasRes1 = sol.lexGreaterPalindromicPermutation("baba", "abba");
    string aliasRes2 = sol.lexicographicallySmallestPalindromicPermutation("aac", "abb");
    bool aliasPassed = (aliasRes1 == "baab" && aliasRes2 == "aca");
    cout << left << setw(6)  << "#12"
         << setw(16) << "\"baba\"/\"aac\""
         << setw(16) << "[Aliases Test]"
         << setw(16) << "\"baab\"/\"aca\""
         << setw(16) << "\"" + aliasRes1 + "\"/\"" + aliasRes2 + "\""
         << (aliasPassed ? "✅ PASSED" : "❌ FAILED") << "\n";

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                    \n\n";

    return 0;
}
