#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

void runTest(int testNum, string s, string expected) {
    Solution sol;
    string result = sol.smallestPalindrome(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputDisp = s;
    if (inputDisp.length() > 20) {
        inputDisp = inputDisp.substr(0, 17) + "...";
    }
    
    string resultDisp = result;
    if (resultDisp.length() > 20) {
        resultDisp = resultDisp.substr(0, 17) + "...";
    }

    string expectedDisp = expected;
    if (expectedDisp.length() > 20) {
        expectedDisp = expectedDisp.substr(0, 17) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(24) << inputDisp
         << setw(24) << resultDisp
         << setw(24) << expectedDisp
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Smallest Palindromic Rearrangement I — Test Suite\n";
    cout << "⇚ - ================================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "Input String (s)" 
         << setw(24) << "Result Palindrome" 
         << setw(24) << "Expected Palindrome" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Example 1
    runTest(1, "z", "z");
    
    // Example 2
    runTest(2, "babab", "abbba");
    
    // Example 3
    runTest(3, "daccad", "acddca");
    
    // Edge case: Already smallest palindrome
    runTest(4, "a", "a");
    
    // Edge case: Multi-char distinct letters
    runTest(5, "dcbaabcd", "abcddcba");
    
    // Edge case: String with high count of same letters
    runTest(6, "zzzaazzz", "azzzzzza");

    cout << "⇚ - ================================================================================ - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
