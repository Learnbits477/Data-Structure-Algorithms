#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, string num, long long t, string expected) {
    Solution sol;
    string result = sol.smallestNumber(num, t);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(15) << num
         << setw(15) << to_string(t)
         << setw(15) << result
         << setw(15) << expected
         << status << "\n";
         
     if (!passed) {
          cout << "   ⚠️ Mismatch details:\n"
               << "     Expected: " << expected << "\n"
               << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n🔢 Smallest Divisible Digit Product II — Test Suite\n";
    cout << "⇚ - ==================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "num" 
         << setw(15) << "t" 
         << setw(15) << "Result" 
         << setw(15) << "Expected" 
         << "Status\n";
    cout << string(72, '-') << "\n";

    runTest(1, "1234", 256, "1488");
    runTest(2, "12355", 50, "12355");
    runTest(3, "11111", 26, "-1");
    runTest(4, "10", 2, "12");
    runTest(5, "99", 10, "125");
    runTest(6, "1000", 5, "1115");

    cout << "⇚ - ===================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
