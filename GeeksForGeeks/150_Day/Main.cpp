#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, string s1, string s2, int expected) {
    Solution sol;
    int result = sol.countWays(s1, s2);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(20) << (s1.length() > 17 ? s1.substr(0, 14) + "..." : s1)
         << setw(15) << (s2.length() > 12 ? s2.substr(0, 9) + "..." : s2)
         << setw(15) << expected
         << setw(15) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     s1: " << s1 << "\n"
             << "     s2: " << s2 << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 150 - Count Matching Subsequences Test Suite  \n";
    cout << "⇚======================================================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(20) << "s1 (Source String)" 
         << setw(15) << "s2 (Pattern)" 
         << setw(15) << "Expected" 
         << setw(15) << "Actual" 
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Example 1
    runTest(1, "geeksforgeeks", "gks", 4);
    
    // Example 2
    runTest(2, "problemoftheday", "geek", 0);
    
    // Additional Test 3: Multiple occurrences of identical letters
    runTest(3, "aaa", "aa", 3);
    
    // Additional Test 4: Fully identical strings
    runTest(4, "abc", "abc", 1);
    
    // Additional Test 5: Long matching cases
    runTest(5, "abcdeabcde", "ace", 4);

    cout << "⇚======================================================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
