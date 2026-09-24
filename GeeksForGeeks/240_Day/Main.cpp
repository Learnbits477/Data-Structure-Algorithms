#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> r, vector<int> h, int expected, const string& description) {
    Solution sol;
    int result = sol.maxStackHeight(r, h);
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
             << "     Discs count:     " << r.size() << "\n"
             << "     Expected Height: " << expected << "\n"
             << "     Got Height:      " << result << "\n";
    }
}

int main() {
    cout << "\n🥞 Maximum Height Disc Stack — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Description"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 (standard stack of 2 discs)
    runTest(1, {5, 7, 3}, {6, 5, 4}, 10, "Example 1 (standard)");

    // Test 2: Example 2 (no two discs can stack)
    runTest(2, {3, 7}, {7, 4}, 7, "Example 2 (incompatible)");

    // Test 3: Single disc
    runTest(3, {10}, {25}, 25, "Single disc");

    // Test 4: Equal radii, different heights (no stacking possible)
    runTest(4, {5, 5, 5}, {2, 8, 4}, 8, "Same radius different heights");

    // Test 5: Equal heights, different radii (no stacking possible)
    runTest(5, {2, 4, 6}, {5, 5, 5}, 5, "Same height different radii");

    // Test 6: Strictly increasing sequence in both dimensions
    runTest(6, {1, 2, 3, 4}, {2, 3, 4, 5}, 14, "Strictly increasing chain");

    // Test 7: Reverse order input of fully stackable discs
    runTest(7, {4, 3, 2, 1}, {5, 4, 3, 2}, 14, "Reversed stackable input");

    // Test 8: Single tall disc beats smaller multi-disc chain
    runTest(8, {1, 2, 3}, {10, 2, 3}, 10, "Tall disc vs small chain");

    // Test 9: All identical discs (only one can be picked)
    runTest(9, {4, 4, 4, 4}, {6, 6, 6, 6}, 6, "All identical duplicate discs");

    // Test 10: Multi-branch chain optimization
    runTest(10, {2, 5, 3, 6, 8}, {3, 2, 4, 5, 7}, 19, "Multi-branch chain");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
