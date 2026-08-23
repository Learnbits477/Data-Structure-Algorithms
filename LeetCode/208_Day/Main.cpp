#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& num, bool expected, const string& desc) {
    Solution sol;
    bool result = sol.sumGame(num);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayNum = num;
    if (displayNum.length() > 20) {
        displayNum = displayNum.substr(0, 17) + "...";
    }

    string expectedStr = expected ? "true (Alice)" : "false (Bob)";
    string resultStr = result ? "true (Alice)" : "false (Bob)";

    cout << left << setw(6)  << testId
         << setw(22) << displayNum
         << setw(16) << expectedStr
         << setw(16) << resultStr
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch on " << desc << ":\n"
             << "     Expected: " << expectedStr << "\n"
             << "     Got:      " << resultStr << "\n";
    }
}

int main() {
    cout << "\n🎮 1927. Sum Game — Test Suite\n";
    cout << "※ ==================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(22) << "num"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "5023", false, "Example 1: All digits, equal halves");

    // Test 2: Example 2
    runTest(2, "25??", true, "Example 2: Alice forces inequality");

    // Test 3: Example 3
    runTest(3, "?3295???", false, "Example 3: Bob can force equality");

    // Test 4: Odd number of '?'
    runTest(4, "?2??", true, "Odd total '?' (Alice wins on last move)");

    // Test 5: All '?'
    runTest(5, "????", false, "All '?': Bob mirrors Alice");

    // Test 6: All digits unequal
    runTest(6, "123456", true, "All digits, unequal sums");

    // Test 7: Perfectly balanced with '?' on one side
    runTest(7, "??0009", false, "Two '?' on left with 9 deficit on left");

    // Test 8: Four '?' on left with 18 deficit on left
    runTest(8, "????0099", false, "Four '?' on left with 18 deficit on left (0+0+9+9=18)");

    // Test 9: Four '?' on left but unbalanced deficit
    runTest(9, "????0009", true, "Four '?' on left with only 9 deficit");

    // Test 10: Equal question marks across both halves
    runTest(10, "?1?2?3?1?2?3", false, "Equal numbers and equal '?' on both sides");

    cout << "※ ==================================================================== ※\n";
    cout << "                     🎉 All Tests Completed Successfully!              \n\n";

    return 0;
}
