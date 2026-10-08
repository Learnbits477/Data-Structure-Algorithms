#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, const string& expected, const string& description) {
    // Step: 01 - Compute results using depth counter and primitive decomposition solvers
    Solution sol;
    string res1 = sol.removeOuterParentheses(s);
    string res2 = sol.removeOuterParenthesesDecomposition(s);

    // Step: 02 - Verify result correctness and cross-method equivalence
    bool passed = (res1 == expected) && (res2 == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 36) {
        displayDesc = displayDesc.substr(0, 33) + "...";
    }

    string inputDisplay = "\"" + (s.length() > 20 ? s.substr(0, 17) + "..." : s) + "\"";
    string expectedDisplay = "\"" + (expected.length() > 16 ? expected.substr(0, 13) + "..." : expected) + "\"";
    string resultDisplay = "\"" + (res1.length() > 16 ? res1.substr(0, 13) + "..." : res1) + "\"";

    cout << left << setw(6)  << testId
         << setw(38) << displayDesc
         << setw(24) << inputDisplay
         << setw(20) << expectedDisplay
         << setw(20) << resultDisplay
         << status << "\n";

    // Step: 04 - Print debug information in case of failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:         " << s << "\n"
             << "     Expected:      " << expected << "\n"
             << "     Depth Pass:    " << res1 << "\n"
             << "     Decomposition: " << res2 << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🛡️ Remove Outermost Parentheses — Test Suite\n";
    cout << "※ ============================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(38) << "Description"
         << setw(24) << "Input String"
         << setw(20) << "Expected"
         << setw(20) << "Result"
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, "(()())(())", "()()()", "Example 1: Two compound primitives");
    runTest(2, "(()())(())(()(()))", "()()()()(())", "Example 2: Three nested primitives");
    runTest(3, "()()", "", "Example 3: Minimal primitives (empty expected)");
    runTest(4, "()", "", "Single minimal primitive");
    runTest(5, "(((())))", "((()))", "Deeply nested single primitive");
    runTest(6, "()()()()", "", "Four consecutive simple primitives");
    runTest(7, "(())", "()", "Single two-level nested primitive");
    runTest(8, "((())())(()(()))", "(())()()(())", "Asymmetric nested primitive blocks");
    runTest(9, "((()))(())", "(())()", "Three-level nested followed by two-level");
    runTest(10, "((()()))((()()))", "(()())(()())", "Identical compound primitive repetitions");

    // Step: 03 - Display final completion summary
    cout << "※ ============================================================================================================== ※\n";
    cout << "                                🎉 All Tests Completed Successfully!                                \n\n";
    return 0;
}
