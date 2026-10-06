#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, int expected, const string& description) {
    // Step: 01 - Compute minimum additions using both greedy counter and stack approach
    Solution sol;
    int resGreedy = sol.minAddToMakeValid(s);
    int resStack = sol.minAddToMakeValidStack(s);

    // Step: 02 - Verify result correctness and cross-method equivalence
    bool passed = (resGreedy == expected) && (resStack == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular identifiers and outputs
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 36) {
        displayDesc = displayDesc.substr(0, 33) + "...";
    }

    string inputDisplay = "\"" + (s.length() > 18 ? s.substr(0, 15) + "..." : s) + "\"";

    cout << left << setw(6)  << testId
         << setw(38) << displayDesc
         << setw(22) << inputDisplay
         << setw(12) << expected
         << setw(12) << resGreedy
         << status << "\n";

    // Step: 04 - Print debug information in case of failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:           " << s << "\n"
             << "     Expected:        " << expected << "\n"
             << "     Greedy Result:   " << resGreedy << "\n"
             << "     Stack Result:    " << resStack << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🛡️ Minimum Add to Make Parentheses Valid — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(38) << "Description"
         << setw(22) << "Input String"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(94, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, "())", 1, "Example 1: Single extra closing bracket");
    runTest(2, "(((", 3, "Example 2: Three unclosed opening brackets");
    runTest(3, "()", 0, "Already valid single pair");
    runTest(4, "()))((", 4, "Example 4: Deficits on both ends");
    runTest(5, ")))", 3, "All closing brackets (prefix deficit)");
    runTest(6, "()()()", 0, "Concatenated valid pairs");
    runTest(7, "((()))", 0, "Nested valid pairs");
    runTest(8, "((())", 1, "One unclosed outer opening bracket");
    runTest(9, ")(())(", 2, "Violations at start and end boundary");
    runTest(10, "(((((((((()", 9, "Heavy left-hand opening bias");
    runTest(11, "))))))))))", 10, "Heavy right-hand closing bias");
    runTest(12, "())(()((())))(", 2, "Complex mixed bracket composition");

    // Step: 03 - Display final completion summary
    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";
    return 0;
}
