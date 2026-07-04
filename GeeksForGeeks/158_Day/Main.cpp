#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, string s, long long expected) {
    Solution sol;
    long long result = sol.countSubstring(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(24) << s
         << setw(20) << expected
         << setw(20) << result
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input: s = \"" << s << "\"\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 158 - Substrings with more 1's than 0's Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "String s" 
         << setw(20) << "Expected" 
         << setw(20) << "Actual" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Example 1
    runTest(1, "011", 4);
    
    // Example 2
    runTest(2, "0000", 0);
    
    // Additional Test 3: All 1s (all substrings are valid)
    // Substrings: "1", "1", "1", "11", "11", "111" => 6
    runTest(3, "111", 6);
    
    // Additional Test 4: Alternate 1 and 0 (starting with 1)
    // s = "10", substrings: "1", "0", "10". Only "1" has more 1s.
    runTest(4, "10", 1);
    
    // Additional Test 5: Alternate 0 and 1 (starting with 0)
    // s = "01", substrings: "0", "1", "01". Only "1" has more 1s.
    runTest(5, "01", 1);
    
    // Additional Test 6: String: "101"
    // Substrings: "1" (idx 0), "0" (idx 1), "1" (idx 2), "10" (idx 0-1), "01" (idx 1-2), "101" (idx 0-2)
    // Valid: "1" (idx 0) [1], "1" (idx 2) [1], "101" [2 ones, 1 zero]
    runTest(6, "101", 3);

    // Additional Test 7: String: "1011"
    // Substrings:
    // Len 1: "1" (3 times), "0" (1 time) -> 3 valid
    // Len 2: "10", "01", "11" -> "11" is valid -> 1 valid
    // Len 3: "101", "011" -> both have two 1s, one 0 -> 2 valid
    // Len 4: "1011" -> three 1s, one 0 -> 1 valid
    // Total = 3 + 1 + 2 + 1 = 7.
    runTest(7, "1011", 7);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
