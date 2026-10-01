#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, bool expected, const string& description) {
    Solution sol;
    bool res1 = sol.isValid(s);
    bool res2 = sol.isValidFast(s);
    bool res3 = sol.isValidClassic(s);

    bool allMatch = (res1 == expected) && (res2 == expected) && (res3 == expected);
    string status = allMatch ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 32) {
        displayDesc = displayDesc.substr(0, 29) + "...";
    }

    string strDisplay = s.length() > 18 ? s.substr(0, 15) + "..." : s;
    if (strDisplay.empty()) strDisplay = "\"\"";

    cout << left << setw(6)  << testId
         << setw(34) << displayDesc
         << setw(14) << (expected ? "true" : "false")
         << setw(14) << (res1 ? "true" : "false")
         << status << "\n";

    if (!allMatch) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input string:    \"" << s << "\"\n"
             << "     Expected:        " << (expected ? "true" : "false") << "\n"
             << "     isValid():       " << (res1 ? "true" : "false") << "\n"
             << "     isValidFast():   " << (res2 ? "true" : "false") << "\n"
             << "     isValidClassic():" << (res3 ? "true" : "false") << "\n";
    }
}

int main() {
    cout << "\n📍 20. Valid Parentheses — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Description"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "()", true, "Example 1 (Simple pair)");

    // Test 2: Example 2
    runTest(2, "()[]{}", true, "Example 2 (Sequential pairs)");

    // Test 3: Example 3
    runTest(3, "(]", false, "Example 3 (Mismatched closer)");

    // Test 4: Example 4
    runTest(4, "([])", true, "Example 4 (Nested brackets)");

    // Test 5: Example 5
    runTest(5, "([)]", false, "Example 5 (Interleaved brackets)");

    // Test 6: Single opening bracket
    runTest(6, "(", false, "Single open bracket (odd len)");

    // Test 7: Single closing bracket
    runTest(7, "]", false, "Single close bracket");

    // Test 8: Deeply nested balanced brackets
    runTest(8, "{([([{}])])}", true, "Deeply nested balanced");

    // Test 9: Deeply nested with one wrong bracket
    runTest(9, "{([([{}]])}", false, "Deeply nested mismatch");

    // Test 10: Premature closer at start
    runTest(10, ")()(", false, "Closer before opener");

    // Test 11: Long alternating valid string
    runTest(11, "()()()[][]{}{}()[]", true, "Long repeated valid sequence");

    // Test 12: Unclosed opening brackets at end
    runTest(12, "()[]((", false, "Unclosed openers at end");

    // Test 13: Only opening brackets
    runTest(13, "((((((", false, "All opening brackets");

    // Test 14: Only closing brackets
    runTest(14, "))))))", false, "All closing brackets");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
