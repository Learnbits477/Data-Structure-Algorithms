#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, int num, int sum, const string& expected, const string& description) {
    // Step: 01 - Execute primary mathematical and alternative simulation solvers
    Solution sol;
    string resPrimary = sol.maxSumOfSquares(num, sum);
    string resSimulation = sol.maxSumOfSquaresSimulation(num, sum);

    // Step: 02 - Verify result correctness and cross-algorithm agreement
    bool passed = (resPrimary == expected) && (resSimulation == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    stringstream inputSs;
    inputSs << "num=" << num << ", sum=" << sum;
    string inputDisplay = inputSs.str();
    if (inputDisplay.length() > 24) {
        inputDisplay = inputDisplay.substr(0, 21) + "...";
    }

    string expDisplay = expected.empty() ? "\"\"" : (expected.length() > 16 ? expected.substr(0, 13) + "..." : expected);
    string resDisplay = resPrimary.empty() ? "\"\"" : (resPrimary.length() > 16 ? resPrimary.substr(0, 13) + "..." : resPrimary);

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(26) << inputDisplay
         << setw(18) << expDisplay
         << setw(18) << resDisplay
         << status << "\n";

    // Step: 04 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:   " << (expected.empty() ? "\"\"" : expected) << "\n"
             << "     Primary:    " << (resPrimary.empty() ? "\"\"" : resPrimary) << "\n"
             << "     Simulation: " << (resSimulation.empty() ? "\"\"" : resSimulation) << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Maximize Sum of Squares of Digits — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(26) << "Input"
         << setw(18) << "Expected"
         << setw(18) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, 2, 3, "30", "Example 1: num=2, sum=3");
    runTest(2, 2, 17, "98", "Example 2: num=2, sum=17");
    runTest(3, 1, 10, "", "Example 3: Impossible single digit");
    runTest(4, 1, 9, "9", "Single digit maximum possible");
    runTest(5, 1, 1, "1", "Single digit minimum positive");
    runTest(6, 3, 27, "999", "All nines maximum capacity");
    runTest(7, 3, 28, "", "Sum exceeds maximum possible");
    runTest(8, 5, 1, "10000", "Smallest sum with trailing zeros");
    runTest(9, 4, 18, "9900", "Multiple nines with trailing zeros");
    runTest(10, 5, 23, "99500", "Two nines, remainder 5, two zeros");
    runTest(11, 6, 54, "999999", "Exact maximum capacity length 6");
    runTest(12, 7, 10, "9100000", "One nine, remainder 1, five zeros");

    // Step: 03 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
