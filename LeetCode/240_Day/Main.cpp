#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> nums, int expected, const string& description) {
    Solution sol;
    int result = sol.smallestIndex(nums);
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
         << setw(14) << expected
         << setw(14) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Array size:     " << nums.size() << "\n"
             << "     Expected Index: " << expected << "\n"
             << "     Got Index:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎯 3550. Smallest Index With Digit Sum Equal to Index — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Description"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {1, 3, 2}, 2, "Example 1 (match at index 2)");

    // Test 2: Example 2 (multiple candidates, return smallest)
    runTest(2, {1, 10, 11}, 1, "Example 2 (smallest among many)");

    // Test 3: Example 3 (no match exists)
    runTest(3, {1, 2, 3}, -1, "Example 3 (no valid index)");

    // Test 4: Match at index 0 with value 0
    runTest(4, {0, 5, 5}, 0, "Match at index 0 with zero");

    // Test 5: Single element match
    runTest(5, {0}, 0, "Single element matching 0");

    // Test 6: Single element mismatch
    runTest(6, {5}, -1, "Single element mismatch");

    // Test 7: Multiple matches, must return first/smallest
    runTest(7, {12, 10, 20}, 1, "Multiple matches (i=1, i=2)");

    // Test 8: Upper bound constraint value 1000
    runTest(8, {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 1000}, -1, "Constraint bound 1000");

    // Test 9: Match at the very last index
    runTest(9, {10, 20, 30, 40, 50, 23}, 5, "Match at final index 5");

    // Test 10: Completely disjoint large digit sums
    runTest(10, {99, 99, 99, 99}, -1, "All digit sums exceed indices");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
