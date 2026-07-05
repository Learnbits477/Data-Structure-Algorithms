#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, string s, int expected) {
    Solution sol;
    int result = sol.maxCharGap(s);
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
    cout << "  🚀 GeeksforGeeks Day 159 - Max Gap Between Two Same Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "String s" 
         << setw(20) << "Expected" 
         << setw(20) << "Actual" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Example 1
    runTest(1, "socks", 3);
    
    // Example 2
    runTest(2, "for", -1);
    
    // Additional Test 3: String: "abca"
    runTest(3, "abca", 2);
    
    // Additional Test 4: String: "abcdef" (no duplicates)
    runTest(4, "abcdef", -1);
    
    // Additional Test 5: String: "aa" (adjacent duplicates)
    runTest(5, "aa", 0);
    
    // Additional Test 6: String: "aba" (one char between)
    runTest(6, "aba", 1);
    
    // Additional Test 7: String: "abacaba"
    runTest(7, "abacaba", 5);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
