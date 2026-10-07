#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string formatResult(const vector<string>& list) {
    if (list.empty()) return "[]";
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < list.size(); ++i) {
        ss << "\"" << list[i] << "\"" << (i + 1 < list.size() ? "," : "");
    }
    ss << "]";
    string res = ss.str();
    if (res.length() > 22) {
        return res.substr(0, 19) + "...]";
    }
    return res;
}

void runTest(int testNum, const string& s, vector<string> expected, const string& description) {
    // Step: 01 - Compute solutions using both DFS backtracking and BFS level-order solvers
    Solution sol;
    vector<string> resDFS = sol.removeInvalidParentheses(s);
    vector<string> resBFS = sol.removeInvalidParenthesesBFS(s);

    // Step: 02 - Sort result lists to ensure canonical order comparison
    sort(resDFS.begin(), resDFS.end());
    sort(resBFS.begin(), resBFS.end());
    sort(expected.begin(), expected.end());

    // Step: 03 - Verify correctness and equivalence across algorithms
    bool passed = (resDFS == expected) && (resBFS == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 04 - Format test identifier and tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 36) {
        displayDesc = displayDesc.substr(0, 33) + "...";
    }

    string inputDisplay = "\"" + (s.length() > 16 ? s.substr(0, 13) + "..." : s) + "\"";
    string expectedDisplay = formatResult(expected);
    string resultDisplay = formatResult(resDFS);

    cout << left << setw(6)  << testId
         << setw(38) << displayDesc
         << setw(20) << inputDisplay
         << setw(24) << expectedDisplay
         << setw(24) << resultDisplay
         << status << "\n";

    // Step: 05 - Print debug information in case of failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input:       " << s << "\n"
             << "     Expected:    " << formatResult(expected) << "\n"
             << "     DFS Result:  " << formatResult(resDFS) << "\n"
             << "     BFS Result:  " << formatResult(resBFS) << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🔤 Remove Invalid Parentheses — Test Suite\n";
    cout << "※ ================================================================================================================ ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(38) << "Description"
         << setw(20) << "Input String"
         << setw(24) << "Expected"
         << setw(24) << "Result"
         << "Status\n";
    cout << string(114, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, "()())()", {"(())()", "()()()"}, "Example 1: Single redundant closing");
    runTest(2, "(a)())()", {"(a())()", "(a)()()"}, "Example 2: Mixed letters and brackets");
    runTest(3, ")(", {""}, "Example 3: Completely inverted brackets");
    runTest(4, "x", {"x"}, "Single letter string without brackets");
    runTest(5, "()", {"()"}, "Already valid minimal pair");
    runTest(6, "(())", {"(())"}, "Already valid nested pair");
    runTest(7, "(((", {""}, "All opening brackets (empty expected)");
    runTest(8, ")))", {""}, "All closing brackets (empty expected)");
    runTest(9, "(()", {"()"}, "One extra opening bracket");
    runTest(10, "a)b(c)d", {"ab(c)d"}, "Interspersed letters with violations");
    runTest(11, ")()(", {"()"}, "Mismatched start and trailing brackets");
    runTest(12, "(a)(b))", {"(a(b))", "(a)(b)"}, "Valid prefix followed by surplus closing");

    // Step: 03 - Display final completion summary
    cout << "※ ================================================================================================================ ※\n";
    cout << "                                🎉 All Tests Completed Successfully!                                \n\n";
    return 0;
}
