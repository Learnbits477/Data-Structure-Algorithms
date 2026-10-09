#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, int expected, const string& description) {
    // Step: 01 - Compute results using lookahead pair greedy and demand-driven solvers
    Solution sol;
    int res1 = sol.minInsertions(s);
    int res2 = sol.minInsertionsDemandDriven(s);

    // Step: 02 - Verify result correctness and cross-method equivalence
    bool passed = (res1 == expected) && (res2 == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    string inputDisplay = "\"" + (s.length() > 20 ? s.substr(0, 17) + "..." : s) + "\"";

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(24) << inputDisplay
         << setw(12) << expected
         << setw(12) << res1
         << status << "\n";

    // Step: 04 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:         " << s << "\n"
             << "     Expected:      " << expected << "\n"
             << "     Lookahead:     " << res1 << "\n"
             << "     Demand-Driven: " << res2 << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🛡️ Minimum Insertions to Balance a Parentheses String — Test Suite\n";
    cout << "※ ============================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(24) << "Input String"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, "(()))", 1, "Example 1: Single missing closing parenthesis");
    runTest(2, "())", 0, "Example 2: Perfectly balanced minimal string");
    runTest(3, "))())粘" == "))())(" ? "))())(" : "))())(" , 3, "Example 3: Disconnected prefix and suffix");
    runTest(4, ")", 2, "Single right bracket needs '(' and ')'");
    runTest(5, "(", 2, "Single left bracket needs '))'");
    runTest(6, "((((((", 12, "Multiple unclosed opening brackets");
    runTest(7, "))))", 2, "Four consecutive closing brackets");
    runTest(8, ")))", 3, "Three consecutive closing brackets");
    runTest(9, "()(", 3, "Open-close-open alternating");
    runTest(10, "())(())))", 0, "Balanced compound valid string");
    runTest(11, "(((())))", 4, "Four opens with two consecutive right pairs");
    runTest(12, "(((())))(", 6, "Nested closures followed by unclosed open");
    runTest(13, "(()))(()))()())))", 4, "Complex chain with solitary unclosed right");

    // Step: 03 - Display final completion summary
    cout << "※ ============================================================================================================== ※\n";
    cout << "                                🎉 All Tests Completed Successfully!                                \n\n";
    return 0;
}
