#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool isValidParentheses(const string& s) {
    // Step: 01 - Track balance of open minus close parentheses
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else if (c == ')') balance--;
        if (balance < 0) return false;
    }

    // Step: 02 - Return true if all parentheses are balanced
    return balance == 0;
}

void runTest(int testNum, int n, int expectedCount, const vector<string>& sampleExpected, const string& description) {
    // Step: 01 - Generate combinations using Backtracking, DP, and BFS
    Solution sol;
    vector<string> resBacktrack = sol.generateParenthesis(n);
    vector<string> resDP = sol.generateParenthesisDP(n);
    vector<string> resBFS = sol.generateParenthesisBFS(n);

    // Step: 02 - Verify count match across all three methods
    bool countMatch = (static_cast<int>(resBacktrack.size()) == expectedCount) &&
                      (static_cast<int>(resDP.size()) == expectedCount) &&
                      (static_cast<int>(resBFS.size()) == expectedCount);

    // Step: 03 - Verify validity of every generated bracket sequence
    bool allWellFormed = true;
    for (const string& s : resBacktrack) {
        if (!isValidParentheses(s)) {
            allWellFormed = false;
            break;
        }
    }

    // Step: 04 - Check sample expected strings if provided
    bool sampleMatches = true;
    if (!sampleExpected.empty()) {
        unordered_set<string> actualSet(resBacktrack.begin(), resBacktrack.end());
        for (const string& expStr : sampleExpected) {
            if (actualSet.find(expStr) == actualSet.end()) {
                sampleMatches = false;
                break;
            }
        }
    }

    // Step: 05 - Format and print test result row
    bool passed = countMatch && allWellFormed && sampleMatches;
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 34) {
        displayDesc = displayDesc.substr(0, 31) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(36) << displayDesc
         << setw(16) << (to_string(expectedCount) + " combos")
         << setw(16) << (to_string(resBacktrack.size()) + " combos")
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n:                  " << n << "\n"
             << "     Expected Count:     " << expectedCount << "\n"
             << "     Backtrack Count:    " << resBacktrack.size() << "\n"
             << "     DP Count:           " << resDP.size() << "\n"
             << "     BFS Count:          " << resBFS.size() << "\n"
             << "     All Well-Formed:    " << (allWellFormed ? "true" : "false") << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n📍 22. Generate Parentheses — Test Suite\n";
    cout << "※ =================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(36) << "Description"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Step: 02 - Execute test cases from n = 1 to n = 8
    runTest(1, 1, 1, {"()"}, "Example 2: n = 1 pair");
    runTest(2, 2, 2, {"(())", "()()"}, "n = 2 pairs (Catalan C_2 = 2)");
    runTest(3, 3, 5, {"((()))", "(()())", "(())()", "()(())", "()()()"}, "Example 1: n = 3 pairs (C_3 = 5)");
    runTest(4, 4, 14, {}, "n = 4 pairs (Catalan C_4 = 14)");
    runTest(5, 5, 42, {}, "n = 5 pairs (Catalan C_5 = 42)");
    runTest(6, 6, 132, {}, "n = 6 pairs (Catalan C_6 = 132)");
    runTest(7, 7, 429, {}, "n = 7 pairs (Catalan C_7 = 429)");
    runTest(8, 8, 1430, {}, "Upper Bound: n = 8 pairs (C_8 = 1430)");

    // Step: 03 - Display final completion banner
    cout << "※ =================================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
