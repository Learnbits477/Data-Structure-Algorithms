#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, string s1, string s2, int expected) {
    Solution sol;
    int result = sol.waysToIncreaseLCSBy1(s1, s2);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(16) << s1
         << setw(16) << s2
         << setw(16) << expected
         << setw(16) << result
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 157 - Ways to Increase LCS by One Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(16) << "s1" 
         << setw(16) << "s2"
         << setw(16) << "Expected" 
         << setw(16) << "Actual" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Example 1
    runTest(1, "abab", "abc", 3);
    
    // Example 2
    runTest(2, "abcabc", "abcd", 4);
    
    // Additional Test 3: Standard single character strings (no increase possible)
    runTest(3, "a", "a", 0);
    
    // Additional Test 4: Single insertion that can increase LCS
    runTest(4, "a", "ab", 1);
    
    // Additional Test 5: Multiple duplicates (no increase possible due to string lengths)
    runTest(5, "aaa", "aa", 0);

    // Additional Test 6: Disjoint character sets
    runTest(6, "xyz", "abc", 12);

    // Additional Test 7: Failing test case from GFG (testing duplicate insertions)
    runTest(7, "aacb", "acaa", 7);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
