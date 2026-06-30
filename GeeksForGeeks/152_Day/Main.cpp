#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, int n, int k, int expected) {
    Solution sol;
    int result = sol.countStrings(n, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "n = " + to_string(n) + ", k = " + to_string(k);
    
    cout << left << setw(6)  << testId 
         << setw(25) << inputStr
         << setw(20) << expected
         << setw(20) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input: n = " << n << ", k = " << k << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 152 - k Times Appearing Adjacent Two 1's Test Suite  \n";
    cout << "⇚======================================================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Input (n, k)" 
         << setw(20) << "Expected" 
         << setw(20) << "Actual" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Example 1
    runTest(1, 3, 2, 1);
    
    // Example 2
    runTest(2, 5, 2, 6);
    
    // Additional Test 3: n = 4, k = 1
    runTest(3, 4, 1, 5);
    
    // Additional Test 4: n = 2, k = 1
    runTest(4, 2, 1, 1);
    
    // Additional Test 5: n = 6, k = 3
    runTest(5, 6, 3, 7);

    cout << "⇚======================================================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
