#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, int p, int expected) {
    Solution sol;
    int result = sol.maxPeopleDefeated(p);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(24) << p
         << setw(24) << expected
         << setw(24) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Strength (p): " << p << "\n"
             << "     Expected:     " << expected << "\n"
             << "     Got:          " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 147 - Killing Spree Test Suite  \n";
    cout << "⇚======================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "Strength (p)" 
         << setw(24) << "Expected Defeated" 
         << setw(24) << "Actual Defeated" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Example 1
    runTest(1, 14, 3);
    
    // Example 2
    runTest(2, 10, 2);
    
    // Test Case 3: Zero strength (nobody defeated)
    runTest(3, 0, 0);
    
    // Test Case 4: Strength for exactly 1 person (1^2 = 1)
    runTest(4, 1, 1);
    
    // Test Case 5: Strength just under next person
    runTest(5, 5, 2); // 1 + 4 = 5 (needs 9 more for 3rd person)
    
    // Test Case 6: Exact strength for 4 people (1+4+9+16 = 30)
    runTest(6, 30, 4);
    
    // Test Case 7: One point short of 4 people
    runTest(7, 29, 3);
    
    // Test Case 8: Maximum constraint limit (p = 3*10^8)
    runTest(8, 300000000, 964);

    cout << "⇚======================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
