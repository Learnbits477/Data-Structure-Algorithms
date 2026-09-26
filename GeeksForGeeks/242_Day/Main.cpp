#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int x, int s, int m, int l, int cs, int cm, int cl, int expected, const string& description) {
    Solution sol;
    int result = sol.minCost(x, s, m, l, cs, cm, cl);
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
             << "     Target Area (x): " << x << "\n"
             << "     Sizes (s,m,l):   (" << s << ", " << m << ", " << l << ")\n"
             << "     Costs (cs,cm,cl):(" << cs << ", " << cm << ", " << cl << ")\n"
             << "     Expected Cost:   " << expected << "\n"
             << "     Got Cost:        " << result << "\n";
    }
}

int main() {
    cout << "\n🍕 Minimum Cost Pizza Selection — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Description"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 (Smallest unit area price is optimal)
    runTest(1, 16, 3, 6, 9, 50, 150, 300, 300, "Example 1 (Small is cheapest)");

    // Test 2: Example 2 (Large pizza exact fit)
    runTest(2, 10, 1, 3, 10, 10, 20, 50, 50, "Example 2 (Large exact fit)");

    // Test 3: Minimal constraints
    runTest(3, 1, 1, 1, 1, 5, 5, 5, 5, "Minimal bounds (x=1, s=m=l=1)");

    // Test 4: Single Large pizza cheaper than smaller ones
    runTest(4, 15, 2, 5, 20, 30, 60, 40, 40, "Single large pizza suffices");

    // Test 5: Medium pizza has best value
    runTest(5, 25, 2, 10, 15, 30, 50, 120, 150, "Medium best unit value");

    // Test 6: Exact fit with repeated Small pizzas
    runTest(6, 12, 4, 7, 11, 20, 50, 90, 60, "Exact fit with small repeated");

    // Test 7: Large pizza overkill but cheaper overall
    runTest(7, 5, 1, 2, 50, 10, 15, 12, 12, "Overkill large is cheaper");

    // Test 8: Mixed combination (1 Large + 1 Medium)
    runTest(8, 13, 2, 5, 8, 10, 22, 35, 57, "Mixed combination optimal");

    // Test 9: Maximum constraints (x=500)
    runTest(9, 500, 10, 50, 100, 15, 70, 100, 500, "Maximum constraints (x=500)");

    // Test 10: Equal sizes with different pricing
    runTest(10, 10, 5, 5, 5, 40, 25, 60, 50, "Equal size differing costs");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
