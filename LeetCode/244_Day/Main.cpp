#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, int expected, const string& description) {
    Solution sol;
    int result = sol.maxDepth(s);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 32) {
        displayDesc = displayDesc.substr(0, 29) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(34) << displayDesc
         << setw(14) << expected
         << setw(14) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input String:    " << s << "\n"
             << "     Expected Output: " << expected << "\n"
             << "     Actual Output:   " << result << "\n";
    }
}

int main() {
    cout << "\n🔤 Maximum Nesting Depth of the Parentheses — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Description"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "(1+(2*3)+((8)/4))+1", 3, "Example 1 (Nested arithmetic)");

    // Test 2: Example 2
    runTest(2, "(1)+((2))+(((3)))", 3, "Example 2 (Ascending nested)");

    // Test 3: Example 3
    runTest(3, "()(())((()()))", 3, "Example 3 (Mixed parenthesis)");

    // Test 4: No parentheses
    runTest(4, "1", 0, "Single digit no parentheses");

    // Test 5: Simple single pair
    runTest(5, "(1)", 1, "Single depth parenthesis");

    // Test 6: Deeply nested single digit
    runTest(6, "((((5))))", 4, "4-levels nested parenthesis");

    // Test 7: Arithmetic operations without parens
    runTest(7, "1+2*3/4-5", 0, "Arithmetic without brackets");

    // Test 8: Sequential shallow parentheses
    runTest(8, "()+()+()", 1, "Multiple flat parentheses");

    // Test 9: Consecutive nested
    runTest(9, "((()))", 3, "Pure 3-nested brackets");

    // Test 10: Deep linear chain
    runTest(10, "(1+(2+(3+(4+(5)))))", 5, "5-levels nested expression");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
