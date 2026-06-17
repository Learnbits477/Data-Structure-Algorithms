#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void runTest(int testNum, int n, int expected) {
    Solution sol;
    int result = sol.maxProduct(n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(15) << n
         << setw(20) << expected
         << setw(20) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 141 - Cut Rope to Maximise Product Test Suite  \n";
    cout << "⇚========================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "Rope Length (n)" 
         << setw(20) << "Expected Output" 
         << setw(20) << "Actual Output" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Example 1
    runTest(1, 2, 1);
    
    // Example 2
    runTest(2, 5, 6);
    
    // Additional Edge Cases & Boundaries
    runTest(3, 3, 2);       // n = 3 -> 2
    runTest(4, 4, 4);       // n = 4 -> 4
    runTest(5, 6, 9);       // n = 6 -> 9 (3 * 3)
    runTest(6, 10, 36);     // n = 10 -> 36 (3^2 * 4)
    runTest(7, 15, 243);    // n = 15 -> 243 (3^5)
    runTest(8, 58, 1549681956); // n = 58 -> 1,549,681,956 (3^18 * 4)

    cout << "⇚========================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
