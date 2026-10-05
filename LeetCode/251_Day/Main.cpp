#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, int expected, const string& description) {
    // Step: 01 - Compute parenthesis score using both primary and stack approaches
    Solution sol;
    int resPrimary = sol.scoreOfParentheses(s);
    int resStack = sol.scoreOfParenthesesStack(s);

    // Step: 02 - Validate test result and consistency across algorithms
    bool passed = (resPrimary == expected) && (resStack == expected);
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
         << setw(12) << resPrimary
         << status << "\n";

    // Step: 04 - Print debug information in case of failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:           " << s << "\n"
             << "     Expected:        " << expected << "\n"
             << "     Primary Result:  " << resPrimary << "\n"
             << "     Stack Result:    " << resStack << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Score of Parentheses — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(38) << "Description"
         << setw(22) << "Input String"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(94, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, "()", 1, "Example 1: Single balanced pair");
    runTest(2, "(())", 2, "Example 2: Doubly nested pair");
    runTest(3, "()()", 2, "Example 3: Adjacent balanced pairs");
    runTest(4, "(()(()))", 6, "Example 4: Nested mixed composition");
    runTest(5, "((()))", 4, "Triply nested parentheses (2^2)");
    runTest(6, "(()()())", 6, "Three nested pairs doubled");
    runTest(7, "((())())", 6, "Asymmetric nested branch doubled");
    runTest(8, "()(())()", 4, "Concatenated single and nested pairs");
    runTest(9, "((((()))))", 16, "5-level deep nested parentheses (2^4)");
    runTest(10, "(()((())()))", 14, "Complex multi-level nesting hierarchy");

    // Step: 03 - Display final completion summary
    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";
    return 0;
}
