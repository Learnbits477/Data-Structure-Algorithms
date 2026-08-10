#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, int n, bool expected) {
    Solution sol;
    bool result = sol.winnerSquareGame(n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string resultStr = result ? "true" : "false";
    string expectedStr = expected ? "true" : "false";
    
    cout << left << setw(6)  << testId 
         << setw(15) << ("n = " + to_string(n))
         << setw(12) << resultStr
         << setw(12) << expectedStr
         << status << "\n";
         
     if (!passed) {
          cout << "   ⚠️ Mismatch details:\n"
               << "     Expected: " << expectedStr << "\n"
               << "     Got:      " << resultStr << "\n";
     }
}

int main() {
    cout << "\n💎 Stone Game IV — Test Suite\n";
    cout << "⇚ - ==================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "Input (n)" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(60, '-') << "\n";

    runTest(1, 1, true);
    runTest(2, 2, false);
    runTest(3, 4, true);
    runTest(4, 3, true);
    runTest(5, 10000, true);
    runTest(6, 17, false);

    cout << "⇚ - ==================================================== - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
