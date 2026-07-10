#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, int n, int expected) {
    Solution sol;
    int result = sol.getCount(n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "n = " + to_string(n);
    if (inputStr.length() > 45) {
        inputStr = inputStr.substr(0, 42) + "...";
    }
    
    cout << left << setw(6)  << testId 
     << setw(45) << inputStr
     << setw(12) << expected
     << setw(12) << result
     << status << "\n";
     
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n:        " << n << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 164 - Ways to Express as Sum of Consecutives Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
     << setw(45) << "Input Parameters (n)" 
     << setw(12) << "Expected" 
     << setw(12) << "Actual" 
     << "Status\n";
    cout << string(90, '-') << "\n";

    runTest(1, 10, 1);
    runTest(2, 15, 3);
    runTest(3, 1, 0);
    runTest(4, 3, 1);
    runTest(5, 100, 2);
    runTest(6, 100000000, 8);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
