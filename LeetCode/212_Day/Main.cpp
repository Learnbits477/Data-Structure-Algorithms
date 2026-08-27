#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, string s, string target, string expected) {
    Solution sol;
    string result = sol.lexGreaterPermutation(s, target);
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
    cout << "\n🎮 Lexicographically Smallest Permutation Greater Than Target — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(16) << "s"
         << setw(16) << "target"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1
    runTest(1, "abc", "bba", "bca");

    // Example 2
    runTest(2, "leet", "code", "eelt");

    // Example 3
    runTest(3, "baba", "bbaa", "");

    // Test 4: Exact match with anagram
    runTest(4, "ab", "ab", "ba");

    // Test 5: Reverse sorted string vs sorted target
    runTest(5, "dcba", "abcd", "abdc");

    // Test 6: Single identical character
    runTest(6, "a", "a", "");

    // Test 7: Single strictly greater character
    runTest(7, "b", "a", "b");

    // Test 8: Duplicate characters with divergence near the end
    runTest(8, "aabcc", "aacbb", "aacbc");

    // Test 9: No match at index 0, forced to pick higher character
    runTest(9, "azzz", "bzzz", "zazz");

    // Test 10: Already the largest permutation and equal to target
    runTest(10, "cba", "cba", "");

    // Test 11: s has duplicate characters and equals target
    runTest(11, "aba", "aab", "aba");

    // Test 12: Target is the lexicographically maximum possible string
    runTest(12, "abcdef", "fedcba", "");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                    \n\n";

    return 0;
}
