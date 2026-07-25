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
         << setw(18) << n
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Maximum Product of Two Digits — Test Suite\n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(18) << "Input Number n" 
         << setw(18) << "Expected Max" 
         << setw(18) << "Actual Max" 
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test Case 1: Example 1 from description
    runTest(1, 31, 3);

    // Test Case 2: Example 2 from description
    runTest(2, 22, 4);

    // Test Case 3: Example 3 from description
    runTest(3, 124, 8);

    // Test Case 4: Minimum constraints boundary
    runTest(4, 10, 0);

    // Test Case 5: Maximum constraints boundary (10^9)
    runTest(5, 1000000000, 0);

    // Test Case 6: Same digits appearing multiple times
    runTest(6, 999, 81);

    // Test Case 7: Descending order digits
    runTest(7, 98765, 72);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
