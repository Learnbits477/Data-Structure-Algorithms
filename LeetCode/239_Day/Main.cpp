#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> nums, int x, int expected, const string& description) {
    Solution sol;
    int result = sol.minOperations(nums, x);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 30) {
        displayDesc = displayDesc.substr(0, 27) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(32) << displayDesc
         << setw(10) << x
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Array size:     " << nums.size() << "\n"
             << "     Target x:       " << x << "\n"
             << "     Expected ops:   " << expected << "\n"
             << "     Got ops:        " << result << "\n";
    }
}

int main() {
    cout << "\n🎯 1658. Minimum Operations to Reduce X to Zero — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Description"
         << setw(10) << "x"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {1, 1, 4, 2, 3}, 5, 2, "Example 1 (suffix removal)");

    // Test 2: Example 2 (impossible, all elements > x)
    runTest(2, {5, 6, 7, 8, 9}, 4, -1, "Example 2 (impossible)");

    // Test 3: Example 3 (both ends removed)
    runTest(3, {3, 2, 20, 1, 1, 3}, 10, 5, "Example 3 (split removal)");

    // Test 4: Exactly entire array removed
    runTest(4, {2, 3, 5}, 10, 3, "Entire array removed");

    // Test 5: Single element exact match
    runTest(5, {7}, 7, 1, "Single element match");

    // Test 6: Single element mismatch
    runTest(6, {7}, 4, -1, "Single element mismatch");

    // Test 7: Pure prefix removal
    runTest(7, {3, 4, 1, 10, 20}, 7, 2, "Prefix only removal");

    // Test 8: Pure suffix removal
    runTest(8, {10, 20, 1, 4, 3}, 7, 2, "Suffix only removal");

    // Test 9: Total sum strictly less than x
    runTest(9, {1, 2}, 10, -1, "Total sum < x");

    // Test 10: Target split around single preserved element
    runTest(10, {1, 2, 3, 4, 5}, 11, 4, "Split removal around middle");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
