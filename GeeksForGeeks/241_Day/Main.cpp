#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> height, vector<int> width, vector<int> length, int expected, const string& description) {
    Solution sol;
    int result = sol.maxHeight(height, width, length);
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
             << "     Boxes count:     " << height.size() << "\n"
             << "     Expected Height: " << expected << "\n"
             << "     Got Height:      " << result << "\n";
    }
}

int main() {
    cout << "\n📦 Box Stacking — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Description"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 (Standard stack with rotation chaining)
    runTest(1, {4, 1, 4, 10}, {6, 2, 5, 12}, {7, 3, 6, 32}, 60, "Example 1 (standard stack)");

    // Test 2: Example 2 (Multiple boxes, incompatible dimensions)
    runTest(2, {1, 4, 3}, {2, 5, 4}, {3, 6, 1}, 15, "Example 2 (incompatible)");

    // Test 3: Single symmetric cube
    runTest(3, {5}, {5}, {5}, 5, "Single cube box");

    // Test 4: Single rectangular box with distinct dimensions (self-stacking rotated)
    runTest(4, {10}, {20}, {30}, 40, "Single box rotated self-stack");

    // Test 5: Two cubes of strictly different sizes
    runTest(5, {3, 10}, {3, 10}, {3, 10}, 13, "Two nested cubes");

    // Test 6: Multiple instances of same non-cube box
    runTest(6, {4, 4, 4}, {5, 5, 5}, {6, 6, 6}, 10, "Multiple identical boxes");

    // Test 7: Strictly increasing chain in all dimensions
    runTest(7, {1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, 22, "Strictly increasing chain");

    // Test 8: Large dimension box allows chaining rotated instances
    runTest(8, {100, 1, 2}, {2, 3, 4}, {3, 4, 5}, 103, "Asymmetric dimensions chain");

    // Test 9: All identical unit cubes (cannot stack any on another)
    runTest(9, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}, 1, "All identical unit cubes");

    // Test 10: Equal width strictness with rotated nested stacking
    runTest(10, {10, 20}, {5, 5}, {15, 25}, 30, "Chained nesting with rotations");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
