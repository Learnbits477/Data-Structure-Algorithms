#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatList(const vector<string>& list) {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < list.size(); ++i) {
        oss << "\"" << list[i] << "\"";
        if (i + 1 < list.size()) oss << ",";
    }
    oss << "]";
    return oss.str();
}

void runTest(int testNum, const string& expression, const vector<string>& expected, const string& description) {
    Solution sol;
    vector<string> result = sol.braceExpansionII(expression);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 28) {
        displayDesc = displayDesc.substr(0, 25) + "...";
    }

    string expStr = formatList(expected);
    if (expStr.length() > 20) {
        expStr = expStr.substr(0, 17) + "...]";
    }

    string resStr = formatList(result);
    if (resStr.length() > 20) {
        resStr = resStr.substr(0, 17) + "...]";
    }

    cout << left << setw(6)  << testId
         << setw(30) << displayDesc
         << setw(22) << expStr
         << setw(22) << resStr
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expression: " << expression << "\n"
             << "     Expected:   " << formatList(expected) << "\n"
             << "     Got:        " << formatList(result) << "\n";
    }
}

int main() {
    cout << "\n🔤 1096. Brace Expansion II — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(30) << "Description"
         << setw(22) << "Expected"
         << setw(22) << "Result"
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test 1: Example 1 (Product with nested union)
    runTest(1, "{a,b}{c,{d,e}}", {"ac", "ad", "ae", "bc", "bd", "be"}, "Example 1 (nested union)");

    // Test 2: Example 2 (Complex unions with overlap)
    runTest(2, "{{a,z},a{b,c},{ab,z}}", {"a", "ab", "ac", "z"}, "Example 2 (overlap dedup)");

    // Test 3: Single letter literal
    runTest(3, "a", {"a"}, "Single letter literal");

    // Test 4: Multi-letter word literal
    runTest(4, "leetcode", {"leetcode"}, "Plain word literal");

    // Test 5: Simple comma-separated list
    runTest(5, "{a,b,c}", {"a", "b", "c"}, "Simple braced list");

    // Test 6: Double nested redundant braces
    runTest(6, "{{a,b}}", {"a", "b"}, "Double nested braces");

    // Test 7: Multi-group concatenation with prefix/suffix
    runTest(7, "a{b,c}{d,e}f", {"abdf", "abef", "acdf", "acef"}, "Multi-group chaining");

    // Test 8: Cartesian product with repetitive results
    runTest(8, "{a,b}{a,b}", {"aa", "ab", "ba", "bb"}, "Cartesian square");

    // Test 9: Union with identical duplicate values
    runTest(9, "{a,a,a}", {"a"}, "Duplicate elements union");

    // Test 10: Nested union wrapped in prefix and suffix
    runTest(10, "x{{a,b},c}y", {"xay", "xby", "xcy"}, "Prefixed nested union");

    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                                \n\n";

    return 0;
}
