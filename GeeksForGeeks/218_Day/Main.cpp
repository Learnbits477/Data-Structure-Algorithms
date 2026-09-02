#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int n, const string& s, int expected) {
    Solution sol;
    int result = sol.solve(n, s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(6)  << n
         << setw(24) << s
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n=" << n << ", s=\"" << s << "\"\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n💻 Unoccupied Computers — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(6)  << "n"
         << setw(24) << "Event Stream (s)"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, 3, "GACCBDDBAGEE", 1);

    // Test 2: Example 2 from problem description
    runTest(2, 1, "ABCBAC", 2);

    // Test 3: Large capacity, no rejections
    runTest(3, 3, "ABCABC", 0);

    // Test 4: Capacity 1, sequential arrivals
    runTest(4, 1, "AABBCC", 0);

    // Test 5: Capacity 2, alternating usage
    runTest(5, 2, "ABBA", 0);

    // Test 6: Capacity 2, 3 customers overlapping
    runTest(6, 2, "ABCCBA", 1);

    // Test 7: All rejected except first
    runTest(7, 1, "ABCDEEDCBA", 4);

    // Test 8: Large capacity with 26 letters
    runTest(8, 26, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
