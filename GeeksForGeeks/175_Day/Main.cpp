#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, string s, int expected) {
    Solution sol;
    int result = sol.maxIndexDifference(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string sStr = "\"" + s + "\"";
    if (sStr.length() > 30) {
        sStr = sStr.substr(0, 27) + "...\"";
    }
    
    cout << left << setw(6)  << testId 
         << setw(32) << sStr
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 175 - Maximum Reachable Index Difference Test Suite  \n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Input String (s)" 
         << setw(18) << "Expected Diff" 
         << setw(18) << "Actual Diff" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Test Case 1: Example 1 from GFG
    runTest(1, "aaabcb", 5);

    // Test Case 2: Example 2 from GFG (no 'a')
    runTest(2, "xynjir", -1);

    // Test Case 3: Example 3 from GFG
    runTest(3, "abcbzzd", 6);

    // Test Case 4: Single character 'a'
    runTest(4, "a", 0);

    // Test Case 5: Simple two characters 'a' to 'b'
    runTest(5, "ab", 1);

    // Test Case 6: Palindromic letter pattern
    runTest(6, "abcba", 3);

    // Test Case 7: Repeated pattern
    runTest(7, "abacaba", 5);

    // Test Case 8: No 'a' single char
    runTest(8, "z", -1);

    // Test Case 9: Sequential full range
    runTest(9, "aaaaabbbbbccccc", 14);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
