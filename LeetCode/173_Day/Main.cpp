#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, string s, string expected) {
    Solution sol;
    
    string result = sol.smallestSubsequence(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "\"" + s + "\"";
    if (inputStr.length() > 32) {
        inputStr = inputStr.substr(0, 29) + "...\"";
    }
    
    cout << left << setw(6)  << testId 
         << setw(35) << inputStr
         << setw(20) << ("\"" + expected + "\"")
         << setw(20) << ("\"" + result + "\"")
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: \"" << expected << "\"\n"
             << "     Got:      \"" << result << "\"\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 173 - Smallest Subsequence of Distinct Characters Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(35) << "Input String (s)" 
         << setw(20) << "Expected" 
         << setw(20) << "Actual" 
         << "Status\n";
    cout << string(95, '-') << "\n";

    // Test Case 1: Example 1 from description
    runTest(1, "bcabc", "abc");

    // Test Case 2: Example 2 from description
    runTest(2, "cbacdcbc", "acdb");

    // Test Case 3: Already distinct and sorted
    runTest(3, "abcdef", "abcdef");

    // Test Case 4: Reverse sorted distinct
    runTest(4, "fedcba", "fedcba");

    // Test Case 5: Duplicate characters with overlapping ranges
    runTest(5, "cdadabcc", "adbc");

    // Test Case 6: Single character string
    runTest(6, "z", "z");

    // Test Case 7: All characters same
    runTest(7, "eeeeee", "e");

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
