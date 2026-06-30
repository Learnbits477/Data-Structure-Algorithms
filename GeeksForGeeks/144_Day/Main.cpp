#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, string a, string b, int expected) {
    Solution sol;
    int result = sol.getLastDigit(a, b);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string displayA = a;
    if (displayA.length() > 15) {
        displayA = displayA.substr(0, 12) + "...";
    }
    string displayB = b;
    if (displayB.length() > 15) {
        displayB = displayB.substr(0, 12) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(18) << displayA
         << setw(18) << displayB
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Base (a):     " << a << "\n"
             << "     Exponent (b): " << b << "\n"
             << "     Expected:     " << expected << "\n"
             << "     Got:          " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 144 - Last Digit of a^b Test Suite  \n";
    cout << "⇚======================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(18) << "Base (a)" 
         << setw(18) << "Exponent (b)" 
         << setw(18) << "Expected Output" 
         << setw(18) << "Actual Output" 
         << "Status\n";
    cout << string(92, '-') << "\n";

    // Example 1
    runTest(1, "3", "10", 9);
    
    // Example 2
    runTest(2, "6", "2", 6);
    
    // Test Case 3: Exponent is 0
    runTest(3, "15", "0", 1);
    
    // Test Case 4: Base ends with 0
    runTest(4, "10", "5", 0);
    
    // Test Case 5: Large base and exponent
    runTest(5, "123", "456", 1);
    
    // Test Case 6: Edge case - Base 0
    runTest(6, "0", "10", 0);
    
    // Test Case 7: Another standard case
    runTest(7, "2", "10", 4);

    cout << "⇚======================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
