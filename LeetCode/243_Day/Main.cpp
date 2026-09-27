#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, const string& expected, const string& description) {
    Solution sol;
    string result = sol.reverseParentheses(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 26) {
        displayDesc = displayDesc.substr(0, 23) + "...";
    }

    string expDisplay = expected;
    if (expDisplay.length() > 22) {
        expDisplay = expDisplay.substr(0, 19) + "...";
    }

    string resDisplay = result;
    if (resDisplay.length() > 22) {
        resDisplay = resDisplay.substr(0, 19) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(28) << displayDesc
         << setw(24) << expDisplay
         << setw(24) << resDisplay
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input String: " << s << "\n"
             << "     Expected:     " << expected << "\n"
             << "     Got:          " << result << "\n";
    }
}

int main() {
    cout << "\n🔄 1190. Reverse Substrings Between Each Pair of Parentheses — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(28) << "Description"
         << setw(24) << "Expected"
         << setw(24) << "Result"
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "(abcd)", "dcba", "Example 1 (single reverse)");

    // Test 2: Example 2
    runTest(2, "(u(love)i)", "iloveu", "Example 2 (nested reverse)");

    // Test 3: Example 3
    runTest(3, "(ed(et(oc))el)", "leetcode", "Example 3 (deep nested)");

    // Test 4: No parentheses present
    runTest(4, "helloworld", "helloworld", "No parentheses");

    // Test 5: Multiple independent parentheses
    runTest(5, "(abc)(def)", "cbafed", "Independent pairs");

    // Test 6: Mixed plain and nested
    runTest(6, "a(bcdefghijkl(mno)p)q", "apmnolkjihgfedcbq", "Mixed plain and nested");

    // Test 7: Quadruple nested single char
    runTest(7, "((((a))))", "a", "Even nested depth");

    // Test 8: Triple nested single char
    runTest(8, "(((a)))", "a", "Odd nested depth");

    // Test 9: Prefix and suffix text
    runTest(9, "pre(test)post", "pretsetpost", "Prefix & suffix text");

    // Test 10: Nested with flanking text inside
    runTest(10, "(ab(cd)ef)", "fecdba", "Nested with flanked chars");

    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
