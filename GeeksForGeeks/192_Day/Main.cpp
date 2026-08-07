#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, int n, int expected) {
    Solution sol;
    int result = sol.countFriendsPairings(n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(15) << to_string(n)
         << setw(15) << to_string(result)
         << setw(15) << to_string(expected)
         << status << "\n";
         
     if (!passed) {
          cout << "   ⚠️ Mismatch details:\n"
               << "     Expected: " << expected << "\n"
               << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n👥 Friends Pairing Problem — Test Suite\n";
    cout << "⇚ - ================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "n" 
         << setw(15) << "Result" 
         << setw(15) << "Expected" 
         << "Status\n";
    cout << string(60, '-') << "\n";

    runTest(1, 3, 4);
    runTest(2, 2, 2);
    runTest(3, 1, 1);
    runTest(4, 4, 10);
    runTest(5, 5, 26);
    runTest(6, 6, 76);
    runTest(7, 18, 997313824);

    cout << "⇚ - ================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
