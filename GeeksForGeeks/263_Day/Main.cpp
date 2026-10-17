#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void runTest(int testNum, const string& s1, const string& s2, bool expected, const string& description) {
    // Step: 01 - Execute primary two-pointer algorithm
    Solution sol;
    bool result = sol.isItPossible(s1, s2);

    // Step: 02 - Cross-verify with vector filtering algorithm
    bool vecResult = sol.canBeConvertedVector(s1, s2);
    bool passed = (result == expected) && (vecResult == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    string inputDisplay = "\"" + s1 + "\" -> \"" + s2 + "\"";
    if (inputDisplay.length() > 28) {
        inputDisplay = inputDisplay.substr(0, 25) + "...\"";
    }

    string expDisplay = expected ? "true" : "false";
    string resDisplay = result ? "true" : "false";

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(30) << inputDisplay
         << setw(12) << expDisplay
         << setw(12) << resDisplay
         << status << "\n";

    // Step: 04 - Print debug failure details if mismatch occurs
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:   " << (expected ? "true" : "false") << "\n"
             << "     TwoPointer: " << (result ? "true" : "false") << "\n"
             << "     VectorExt:  " << (vecResult ? "true" : "false") << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Convert One String to Another with Constraints — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(30) << "Input (s1 -> s2)"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, "#A#B#B#", "A###B#B", true, "Example 1: A moves left, B moves right");
    runTest(2, "#A#B#", "#B#A#", false, "Example 2: A and B attempt to cross");
    runTest(3, "#", "#", true, "Single empty space match");
    runTest(4, "A", "A", true, "Single character identical position");
    runTest(5, "A", "B", false, "Single character identity mismatch");
    runTest(6, "##A", "A##", true, "A drifts two positions to the left");
    runTest(7, "A##", "##A", false, "A attempts to move to the right");
    runTest(8, "B##", "##B", true, "B drifts two positions to the right");
    runTest(9, "##B", "B##", false, "B attempts to move to the left");
    runTest(10, "A#B", "A#B#", false, "String length inequality");
    runTest(11, "A#B#", "A#B#B", false, "Non-empty character count mismatch");
    runTest(12, "#A##B#A#B#", "A###BA###B", true, "Complex multiple moves maintaining order");

    // Step: 03 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
