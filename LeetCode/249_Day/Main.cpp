#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, int expected, const string& description) {
    // Step: 01 - Calculate result using Two-Pass, Stack, and DP algorithms
    Solution sol;
    int resTwoPass = sol.longestValidParentheses(s);
    int resStack = sol.longestValidParenthesesStack(s);
    int resDP = sol.longestValidParenthesesDP(s);

    // Step: 02 - Verify agreement across all algorithms and match with expected
    bool allMatch = (resTwoPass == expected) &&
                    (resStack == expected) &&
                    (resDP == expected);
    string status = allMatch ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format test ID and tabular column displays
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 32) {
        displayDesc = displayDesc.substr(0, 29) + "...";
    }

    string sDisplay = s.empty() ? "\"\"" : ("\"" + (s.length() > 16 ? s.substr(0, 13) + "..." : s) + "\"");

    // Step: 04 - Print formatted test result row
    cout << left << setw(6)  << testId
         << setw(34) << displayDesc
         << setw(20) << sDisplay
         << setw(12) << expected
         << setw(12) << resTwoPass
         << status << "\n";

    if (!allMatch) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:              \"" << s << "\"\n"
             << "     Expected:           " << expected << "\n"
             << "     Two-Pass Result:    " << resTwoPass << "\n"
             << "     Stack Result:       " << resStack << "\n"
             << "     DP Result:          " << resDP << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n📍 32. Longest Valid Parentheses — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Description"
         << setw(20) << "Input String"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, "(()", 2, "Example 1: Left surplus");
    runTest(2, ")()())", 4, "Example 2: Two pairs adjacent");
    runTest(3, "", 0, "Example 3: Empty string");
    runTest(4, "(", 0, "Single open parenthesis");
    runTest(5, ")", 0, "Single close parenthesis");
    runTest(6, "(((((", 0, "All open parentheses");
    runTest(7, ")))))", 0, "All close parentheses");
    runTest(8, "()()()()", 8, "Repeating simple pairs");
    runTest(9, "(((())))", 8, "Deeply nested valid pairs");
    runTest(10, "()(()", 2, "First pair valid, broken end");
    runTest(11, ")))((()))", 6, "Leading invalid then nested");
    runTest(12, ")(()())", 6, "Leading invalid then balanced");
    runTest(13, ")(()())(", 6, "Surrounded by invalid brackets");

    // Step: 03 - Display final completion summary
    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
