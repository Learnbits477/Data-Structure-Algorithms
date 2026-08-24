#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int n, int expected) {
    Solution sol;
    int result = sol.prefixStrings(n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(8)  << n
         << setw(14) << expected
         << setw(14) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎮 Count Prefix-Balanced Binary Strings — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(8)  << "n"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    runTest(1, 1, 1);
    runTest(2, 2, 2);
    runTest(3, 3, 5);
    runTest(4, 4, 14);
    runTest(5, 5, 42);
    runTest(6, 6, 132);
    runTest(7, 7, 429);
    runTest(8, 8, 1430);
    runTest(9, 9, 4862);
    runTest(10, 10, 16796);
    runTest(11, 50, 265470434);
    runTest(12, 1000, 110961515);

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                        \n\n";

    return 0;
}
