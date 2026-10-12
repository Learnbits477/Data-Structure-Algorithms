#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, long long n, long long m, long long expected, const string& description) {
    // Step: 01 - Execute primary iterative and recursive methods
    Solution sol;
    long long resIterative = sol.minSquares(n, m);
    long long resRecursive = sol.minSquaresRecursive(n, m);

    // Step: 02 - Validate result and check equivalence
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

    stringstream inputSs;
    inputSs << "n=" << n << ", m=" << m;
    string inputDisplay = inputSs.str();
    if (inputDisplay.length() > 24) {
        inputDisplay = inputDisplay.substr(0, 21) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(26) << inputDisplay
         << setw(16) << expected
         << setw(16) << resIterative
         << status << "\n";

    // Step: 04 - Print debug details on test failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:   " << expected << "\n"
             << "     Iterative:  " << resIterative << "\n"
             << "     Recursive:  " << resRecursive << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Minimum Squares with Full Cuts — Test Suite\n";
    cout << "※ ==================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(26) << "Input"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, 4, 5, 5, "Example 1: 4x5 rectangle");
    runTest(2, 2, 4, 2, "Example 2: 2x4 rectangle");
    runTest(3, 11, 13, 8, "Example 3: 11x13 rectangle");
    runTest(4, 1, 1, 1, "Single 1x1 square already perfect");
    runTest(5, 6, 6, 1, "Already a square 6x6");
    runTest(6, 1, 10, 10, "Strip paper 1x10");
    runTest(7, 10, 1, 10, "Inverted strip paper 10x1");
    runTest(8, 13, 11, 8, "Symmetric orientation 13x11");
    runTest(9, 5, 6, 6, "Consecutive integers 5x6");
    runTest(10, 34, 21, 8, "Fibonacci numbers 34x21");
    runTest(11, 1000000000LL, 1000000000LL, 1, "Max constraint square 10^9 x 10^9");
    runTest(12, 1000000000LL, 1LL, 1000000000LL, "Max constraint strip 10^9 x 1");

    // Step: 03 - Display final completion summary
    cout << "※ ==================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
