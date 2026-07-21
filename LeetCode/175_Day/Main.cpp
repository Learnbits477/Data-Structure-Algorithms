#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, string s, int expected) {
    Solution sol;
    int result = sol.maxActiveSectionsAfterTrade(s);
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
    cout << "  🚀 LeetCode Day 175 - Maximize Active Section with Trade I Test Suite  \n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Input String (s)" 
         << setw(18) << "Expected Active" 
         << setw(18) << "Actual Active" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Test Case 1: Example 1 from LeetCode
    runTest(1, "01", 1);

    // Test Case 2: Example 2 from LeetCode
    runTest(2, "0100", 4);

    // Test Case 3: Example 3 from LeetCode
    runTest(3, "1000100", 7);

    // Test Case 4: Example 4 from LeetCode
    runTest(4, "01010", 4);

    // Test Case 5: All zeros
    runTest(5, "0000", 0);

    // Test Case 6: All ones
    runTest(6, "1111", 4);

    // Test Case 7: Single character '0'
    runTest(7, "0", 0);

    // Test Case 8: Single character '1'
    runTest(8, "1", 1);

    // Test Case 9: Multiple internal blocks with varying zero block sizes
    runTest(9, "001000100", 7);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
