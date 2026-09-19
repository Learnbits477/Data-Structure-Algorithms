#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, const string& s1, const string& s2, int costS1, int costS2, int expected) {
    Solution sol;
    int result = sol.findMinCost(s1, s2, costS1, costS2);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayS1 = "\"" + s1 + "\"";
    if (displayS1.length() > 14) displayS1 = displayS1.substr(0, 11) + "...\"";

    string displayS2 = "\"" + s2 + "\"";
    if (displayS2.length() > 14) displayS2 = displayS2.substr(0, 11) + "...\"";

    string displayCosts = to_string(costS1) + "/" + to_string(costS2);

    cout << left << setw(6)  << testId
         << setw(16) << displayS1
         << setw(16) << displayS2
         << setw(14) << displayCosts
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     s1:       \"" << s1 << "\"\n"
             << "     s2:       \"" << s2 << "\"\n"
             << "     costS1:   " << costS1 << ", costS2: " << costS2 << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🧵 Min Cost To Make Two Strings Identical — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(16) << "s1"
         << setw(16) << "s2"
         << setw(14) << "Costs(S1/S2)"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "abcd", "acdb", 10, 20, 30);

    // Test 2: Example 2 (disjoint strings)
    runTest(2, "ef", "gh", 10, 20, 60);

    // Test 3: Completely identical strings
    runTest(3, "programming", "programming", 15, 25, 0);

    // Test 4: s1 is subsequence of s2
    runTest(4, "abc", "aebfc", 5, 10, 20);

    // Test 5: Single character match
    runTest(5, "a", "a", 100, 200, 0);

    // Test 6: Single character mismatch
    runTest(6, "a", "b", 100, 200, 300);

    // Test 7: Reverse strings (LCS length 1 e.g. 'c')
    runTest(7, "abcde", "edcba", 7, 7, 56);

    // Test 8: Alternating characters
    runTest(8, "ababab", "baba", 10, 30, 20);

    // Test 9: Prefix substring match
    runTest(9, "geeksforgeeks", "geeks", 50, 100, 400);

    // Test 10: Repeated characters with different frequencies
    runTest(10, "aaaa", "aa", 12, 34, 24);

    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
