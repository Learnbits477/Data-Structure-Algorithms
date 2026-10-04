#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, bool expected, const string& description) {
    // Step: 01 - Execute validity check across all algorithmic approaches
    Solution sol;
    bool resGreedy = sol.checkValidString(s);
    bool resStacks = sol.checkValidStringTwoStacks(s);
    bool resDP = sol.checkValidStringDP(s);

    // Step: 02 - Validate test result and consistency across algorithms
    bool passed = (resGreedy == expected) && (resStacks == expected) && (resDP == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular identifiers and outputs
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 34) {
        displayDesc = displayDesc.substr(0, 31) + "...";
    }

    string inputDisplay = "\"" + (s.length() > 18 ? s.substr(0, 15) + "..." : s) + "\"";
    string expDisplay = expected ? "true" : "false";
    string actDisplay = resGreedy ? "true" : "false";

    cout << left << setw(6)  << testId
         << setw(36) << displayDesc
         << setw(22) << inputDisplay
         << setw(12) << expDisplay
         << setw(12) << actDisplay
         << status << "\n";

    // Step: 04 - Print debug information in case of failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:           " << s << "\n"
             << "     Expected:        " << (expected ? "true" : "false") << "\n"
             << "     Greedy Result:   " << (resGreedy ? "true" : "false") << "\n"
             << "     Stacks Result:   " << (resStacks ? "true" : "false") << "\n"
             << "     DP Result:       " << (resDP ? "true" : "false") << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n✨ Valid Parenthesis String — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(36) << "Description"
         << setw(22) << "Input String"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, "()", true, "Example 1: Standard balanced pair");
    runTest(2, "(*)", true, "Example 2: Asterisk as empty string");
    runTest(3, "(*))", true, "Example 3: Asterisk as open parenthesis");
    runTest(4, "(", false, "Example 4: Unmatched opening bracket");
    runTest(5, ")", false, "Unmatched closing bracket");
    runTest(6, "*", true, "Single asterisk as empty string");
    runTest(7, "***", true, "All asterisks sequence");
    runTest(8, "(((***", true, "Asterisks closing trailing opens");
    runTest(9, "*)(", false, "Closing before opening with star");
    runTest(10, "(*()", true, "Star matching preceding open bracket");
    runTest(11, "(((((*(()((((*((**(((()()())()()()*((((**)())())())))))))()))))())(((())())(((**((**((((***", false, "Long complex unbalanced string");

    // Step: 03 - Display final completion summary
    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";
    return 0;
}
