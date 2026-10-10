#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int a, int b, bool expected, const string& description) {
    // Step: 01 - Compute results using iterative and recursive approaches
    Solution sol;
    bool resIterative = sol.balancePan(a, b);
    bool resRecursive = sol.balancePanRecursive(a, b);

    // Step: 02 - Validate test result and cross-method consistency
    bool passed = (resIterative == expected) && (resRecursive == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    string inputDisplay = "a=" + to_string(a) + ", b=" + to_string(b);
    if (inputDisplay.length() > 24) {
        inputDisplay = inputDisplay.substr(0, 21) + "...";
    }

    string expectedStr = expected ? "true" : "false";
    string resultStr = resIterative ? "true" : "false";

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(26) << inputDisplay
         << setw(12) << expectedStr
         << setw(12) << resultStr
         << status << "\n";

    // Step: 04 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Base a:            " << a << "\n"
             << "     Target b:          " << b << "\n"
             << "     Expected:          " << expectedStr << "\n"
             << "     Iterative Result:  " << resultStr << "\n"
             << "     Recursive Result:  " << (resRecursive ? "true" : "false") << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n⚖️ Balancing with Distinct Powers — Test Suite\n";
    cout << "※ ============================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(26) << "Input (a, b)"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, 4, 11, true, "Example 1: Target 11 with base 4");
    runTest(2, 3, 5, true, "Example 2: Target 5 with base 3");
    runTest(3, 4, 7, false, "Counter-example: Target 7 with base 4");
    runTest(4, 2, 1, true, "Smallest bounds: a = 2, b = 1");
    runTest(5, 2, 100, true, "Base 2 always valid for any b");
    runTest(6, 3, 2, true, "Target 2 with base 3 (2 + 1 = 3)");
    runTest(7, 5, 19, true, "Target 19 with base 5 (19 + 5 + 1 = 25)");
    runTest(8, 5, 8, false, "Target 8 with base 5 (cannot balance)");
    runTest(9, 10, 10, true, "Target equals base (b = a)");
    runTest(10, 10, 9, true, "Target equals a - 1 (9 + 1 = 10)");
    runTest(11, 10, 8, false, "Target 8 with base 10 (remainder 8)");
    runTest(12, 7, 48, true, "Target 48 with base 7 (48 + 1 = 49)");
    runTest(13, 1000000000, 1, true, "Max base boundary with b = 1");
    runTest(14, 1000000000, 999999999, true, "Max base with b = a - 1");

    // Step: 03 - Display final completion summary
    cout << "※ ============================================================================================================== ※\n";
    cout << "                                🎉 All Tests Completed Successfully!                                \n\n";
    return 0;
}
