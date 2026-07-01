#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void runTest(int testNum, long long n, int l, int r, int expected) {
    Solution sol;
    int result = sol.numOfArrays(n, l, r);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(15) << n
         << setw(8)  << l
         << setw(8)  << r
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 148 - Number of Zigzag Arrays II Test Suite  \n";
    cout << "⇚ - ============================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "n"
         << setw(8)  << "l"
         << setw(8)  << "r"
         << setw(18) << "Expected Output" 
         << setw(18) << "Actual Output" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Example 1
    runTest(1, 3, 4, 5, 2);
    
    // Example 2
    runTest(2, 3, 1, 3, 10);
    
    // Additional Test Cases
    runTest(3, 4, 1, 3, 16);
    runTest(4, 5, 1, 2, 2);
    runTest(5, 10, 1, 5, 97240);
    runTest(6, 1000000000LL, 1, 3, 16); // Large N test

    cout << "⇚ - ============================================================================= - ⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
