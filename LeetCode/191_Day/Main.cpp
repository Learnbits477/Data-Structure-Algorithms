#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, int n, int t, int expected) {
    Solution sol;
    int result = sol.smallestNumber(n, t);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(10) << to_string(n)
         << setw(10) << to_string(t)
         << setw(10) << to_string(result)
         << setw(10) << to_string(expected)
         << status << "\n";
         
     if (!passed) {
         cout << "   ⚠️ Mismatch details:\n"
              << "     Expected: " << expected << "\n"
              << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n🔢 Smallest Divisible Digit Product I — Test Suite\n";
    cout << "⇚ - ================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(10) << "n" 
         << setw(10) << "t" 
         << setw(10) << "Result" 
         << setw(10) << "Expected" 
         << "Status\n";
    cout << string(72, '-') << "\n";

    runTest(1, 10, 2, 10);
    runTest(2, 15, 3, 16);
    runTest(3, 1, 1, 1);
    runTest(4, 99, 10, 100);
    runTest(5, 4, 7, 7);
    runTest(6, 100, 5, 100);

    cout << "⇚ - ================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
