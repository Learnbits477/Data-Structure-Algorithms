#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, string s, int k, string expected) {
    Solution sol;
    string result = sol.smallestPalindrome(s, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string previewStr = s;
    if (previewStr.length() > 15) {
        previewStr = previewStr.substr(0, 12) + "...";
    }

    cout << left << setw(6)  << testId 
         << setw(18) << ("\"" + previewStr + "\"")
         << setw(8)  << k
         << setw(16) << ("\"" + result + "\"")
         << setw(16) << ("\"" + expected + "\"")
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: \"" << expected << "\"\n"
             << "     Got:      \"" << result << "\"\n";
    }
}

int main() {
    cout << "\n🔢 Smallest Palindromic Rearrangement II — Test Suite\n";
    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(18) << "Input String" 
         << setw(8)  << "k" 
         << setw(16) << "Result" 
         << setw(16) << "Expected" 
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1: abba, k = 2
    runTest(1, "abba", 2, "baab");
    
    // Example 2: aa, k = 2
    runTest(2, "aa", 2, "");
    
    // Example 3: bacab, k = 1
    runTest(3, "bacab", 1, "abcba");
    
    // Test Case 4: bacab, k = 2 (second permutation)
    runTest(4, "bacab", 2, "bacab");

    // Test Case 5: bacab, k = 3 (out of range)
    runTest(5, "bacab", 3, "");

    // Test Case 6: Single character string, k = 1
    runTest(6, "a", 1, "a");

    // Test Case 7: Single character string, k = 2 (out of range)
    runTest(7, "a", 2, "");

    // Test Case 8: aabbcc, k = 1 (abc -> abccba)
    runTest(8, "aabbcc", 1, "abccba");

    // Test Case 9: aabbcc, k = 6 (cba -> cbaabc)
    runTest(9, "aabbcc", 6, "cbaabc");

    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
