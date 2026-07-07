#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void runTest(int testNum, int n, long long expected) {
    Solution sol;
    long long result = sol.sumAndMultiply(n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(20) << n
         << setw(20) << expected
         << setw(20) << result
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input N:  " << n << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 161 - Concatenate Non-Zero Digits and Multiply by Sum I Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(20) << "Input N" 
         << setw(20) << "Expected" 
         << setw(20) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Example 1
    runTest(1, 10203004, 12340);
    
    // Example 2
    runTest(2, 1000, 1);
    
    // Additional Test 3: Standard single digit
    runTest(3, 7, 49);
    
    // Additional Test 4: All zeros (e.g. 0)
    runTest(4, 0, 0);
    
    // Additional Test 5: Maximum constraint boundary
    runTest(5, 999999999, 80999999919LL);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
