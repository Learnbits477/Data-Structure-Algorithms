#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, int n, int d, int expected) {
    Solution sol;
    int result = sol.countWithout(n, d);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(14) << to_string(n)
         << setw(8)  << to_string(d)
         << setw(10) << to_string(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Numbers Without d as Digit — Test Suite\n";
    cout << "※ ================================================ ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(14) << "n" 
         << setw(8)  << "d" 
         << setw(10) << "Result" 
         << "Status\n";
    cout << string(52, '-') << "\n";

    // Test 1: Example 1
    runTest(1, 25, 3, 22);

    // Test 2: Example 2
    runTest(2, 5, 3, 4);

    // Test 3: d = 0 case
    runTest(3, 10, 0, 9);

    // Test 4: n = 100, d = 0
    runTest(4, 100, 0, 90);

    // Test 5: n = 100, d = 3
    runTest(5, 100, 3, 81);

    // Test 6: Small n (n = 0)
    runTest(6, 0, 5, 0);

    // Test 7: n containing d at MSD
    runTest(7, 35, 3, 26);

    // Test 8: Large n (10^9) with d = 3
    runTest(8, 1000000000, 3, 387420489);

    cout << "※================================================ ※\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
