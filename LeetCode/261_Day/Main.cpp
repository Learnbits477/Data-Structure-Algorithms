#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, int n, int expected, const string& description) {
    // Step: 01 - Execute primary and alternative algorithms
    Solution sol;
    int resPrimary = sol.noConseBits(n);
    int resCounter = sol.noConseBitsCounter(n);
    int resArray = sol.noConseBitsArray(n);

    // Step: 02 - Verify result correctness and cross-method agreement
    bool passed = (resPrimary == expected) && (resCounter == expected) && (resArray == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    string inputDisplay = "n = " + to_string(n);
    if (inputDisplay.length() > 24) {
        inputDisplay = inputDisplay.substr(0, 21) + "...";
    }

    string expDisplay = to_string(expected);
    string resDisplay = to_string(resPrimary);

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(26) << inputDisplay
         << setw(16) << expDisplay
         << setw(16) << resDisplay
         << status << "\n";

    // Step: 04 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:  " << expected << "\n"
             << "     Primary:   " << resPrimary << "\n"
             << "     Counter:   " << resCounter << "\n"
             << "     Array:     " << resArray << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Geek hates too many 1s — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(26) << "Input"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, 2, 2, "Example 1: n = 2 (Binary 10)");
    runTest(2, 7, 6, "Example 2: n = 7 (Binary 111 -> 110)");
    runTest(3, 0, 0, "Zero boundary: n = 0");
    runTest(4, 1, 1, "Single bit: n = 1");
    runTest(5, 3, 3, "Two set bits: n = 3 (Binary 11)");
    runTest(6, 15, 13, "Four set bits: n = 15 (1111 -> 1101)");
    runTest(7, 31, 27, "Five set bits: n = 31 (11111 -> 11011)");
    runTest(8, 63, 54, "Six set bits: n = 63 (111111 -> 110110)");
    runTest(9, 127, 109, "Seven set bits: n = 127");
    runTest(10, 255, 219, "Eight set bits: n = 255");
    runTest(11, 1000000000, 857393664, "Upper constraint: n = 10^9");
    runTest(12, 1073741823, 920350134, "30 set bits: 2^30 - 1");

    // Step: 03 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
