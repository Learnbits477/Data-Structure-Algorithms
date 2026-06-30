#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, int n, int m, int expected) {
    Solution sol;
    int result = sol.countWays(n, m);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "n = " + to_string(n) + ", m = " + to_string(m);
    
    cout << left << setw(6)  << testId 
         << setw(25) << inputStr
         << setw(20) << expected
         << setw(20) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input: n = " << n << ", m = " << m << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 151 - Ways to Tile the Floor Test Suite  \n";
    cout << "⇚======================================================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Input (n, m)" 
         << setw(20) << "Expected" 
         << setw(20) << "Actual" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Example 1
    runTest(1, 4, 4, 2);
    
    // Example 2
    runTest(2, 2, 3, 1);
    
    // Additional Test 3: n = 5, m = 3
    runTest(3, 5, 3, 4);
    
    // Additional Test 4: n = 1, m = 2
    runTest(4, 1, 2, 1);
    
    // Additional Test 5: n = 7, m = 4
    runTest(5, 7, 4, 5);

    cout << "⇚======================================================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
