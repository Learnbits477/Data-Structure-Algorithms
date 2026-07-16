#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, int n, int sum, int expected) {
    Solution sol;
    
    int result = sol.countWays(n, sum);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "n = " + to_string(n) + ", sum = " + to_string(sum);
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 170 - Numbers with Given Digit Sum Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (n, sum)" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from GFG description (n = 2, sum = 2) -> Expected: 2 (11, 20)
    runTest(1, 2, 2, 2);

    // Test Case 2: Example 2 from GFG description (n = 1, sum = 10) -> Expected: -1
    runTest(2, 1, 10, -1);

    // Test Case 3: Example 3 from GFG description (n = 2, sum = 10) -> Expected: 9
    runTest(3, 2, 10, 9);

    // Test Case 4: Single digit valid case (n = 1, sum = 5) -> Expected: 1 (5)
    runTest(4, 1, 5, 1);

    // Test Case 5: Three digit small sum case (n = 3, sum = 2) -> Expected: 3 (101, 110, 200)
    runTest(5, 3, 2, 3);

    // Test Case 6: Three digit maximum sum case (n = 3, sum = 27) -> Expected: 1 (999)
    runTest(6, 3, 27, 1);

    // Test Case 7: Three digit sum out of range (n = 3, sum = 28) -> Expected: -1
    runTest(7, 3, 28, -1);

    // Test Case 8: Four digit sum 4 (n = 4, sum = 4) -> Expected: 20
    runTest(8, 4, 4, 20);

    // Test Case 9: Maximum constraints case (n = 9, sum = 81) -> Expected: 1 (999999999)
    runTest(9, 9, 81, 1);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
