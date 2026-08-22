#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int n, bool expected) {
    Solution sol;
    bool result = sol.checkDivisibility(n);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string expectedStr = expected ? "true" : "false";
    string resultStr = result ? "true" : "false";

    cout << left << setw(6)  << testId
         << setw(16) << n
         << setw(16) << expectedStr
         << setw(16) << resultStr
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expectedStr << "\n"
             << "     Got:      " << resultStr << "\n";
    }
}

int main() {
    cout << "\n🔢 3622. Check Divisibility by Digit Sum and Product — Test Suite\n";
    cout << "※ ==================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(16) << "n"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(68, '-') << "\n";

    runTest(1, 99, true);
    runTest(2, 23, false);
    runTest(3, 1, false);
    runTest(4, 10, true);
    runTest(5, 100, true);
    runTest(6, 1000000, true);
    runTest(7, 12, false);
    runTest(8, 70, true);
    runTest(9, 24, false);
    runTest(10, 36, false);

    cout << "※ ==================================================================== ※\n";
    cout << "                     🎉 All Tests Completed Successfully!              \n\n";

    return 0;
}
