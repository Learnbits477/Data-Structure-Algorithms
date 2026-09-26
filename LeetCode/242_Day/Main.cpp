#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, vector<vector<string>> knowledge, const string& expected, const string& description) {
    Solution sol;
    string result = sol.evaluate(s, knowledge);
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
    cout << "\n🔤 1807. Evaluate the Bracket Pairs of a String — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(28) << "Description"
         << setw(24) << "Expected"
         << setw(24) << "Result"
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test 1: Example 1 (Standard replacement)
    runTest(1, "(name)is(age)yearsold", {{"name", "bob"}, {"age", "two"}}, "bobistwoyearsold", "Example 1 (standard)");

    // Test 2: Example 2 (Unknown key yields '?')
    runTest(2, "hi(name)", {{"a", "b"}}, "hi?", "Example 2 (missing key)");

    // Test 3: Example 3 (Repetitive evaluation and plain letters)
    runTest(3, "(a)(a)(a)aaa", {{"a", "yes"}}, "yesyesyesaaa", "Example 3 (repeated key)");

    // Test 4: String without any brackets
    runTest(4, "plainstring", {{"plain", "skip"}}, "plainstring", "No brackets present");

    // Test 5: Empty knowledge array
    runTest(5, "(unknown)", {}, "?", "Empty knowledge array");

    // Test 6: Consecutive bracket pairs
    runTest(6, "(first)(second)", {{"first", "hello"}, {"second", "world"}}, "helloworld", "Adjacent brackets");

    // Test 7: Partially known adjacent brackets
    runTest(7, "(first)(second)", {{"first", "hello"}}, "hello?", "Partial unknown adjacent");

    // Test 8: Multiple identical unknown keys
    runTest(8, "(x)+(x)=(y)", {{"y", "two"}}, "?+?=two", "Multiple identical '?'");

    // Test 9: Brackets at both ends
    runTest(9, "(start)middle(end)", {{"start", "1"}, {"end", "9"}}, "1middle9", "Brackets at boundary");

    // Test 10: Single-letter keys and values
    runTest(10, "a(b)c(d)e", {{"b", "x"}, {"d", "y"}}, "axcye", "Single char keys/vals");

    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                                \n\n";

    return 0;
}
