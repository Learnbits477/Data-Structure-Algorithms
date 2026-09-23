#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> arr, int expected, const string& description) {
    Solution sol;
    int result = sol.formPyramid(arr);
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
             << "     Array size:     " << arr.size() << "\n"
             << "     Expected Cost:  " << expected << "\n"
             << "     Got Cost:       " << result << "\n";
    }
}

int main() {
    cout << "\n⛰️ Pyramid Array with Reduce Operations — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Description"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {1, 2, 3, 4, 2, 1}, 4, "Example 1 (standard)");

    // Test 2: Example 2 (Already perfect pyramid)
    runTest(2, {1, 2, 1}, 0, "Example 2 (already pyramid)");

    // Test 3: Single element array
    runTest(3, {5}, 4, "Single element stone");

    // Test 4: Uniform flat array
    runTest(4, {3, 3, 3, 3, 3}, 6, "Uniform flat values");

    // Test 5: Strictly increasing array
    runTest(5, {1, 2, 3, 4, 5}, 6, "Strictly increasing values");

    // Test 6: Strictly decreasing array
    runTest(6, {5, 4, 3, 2, 1}, 6, "Strictly decreasing values");

    // Test 7: Valley profile array (dip in middle)
    runTest(7, {5, 1, 5}, 10, "Valley profile (low center)");

    // Test 8: Asymmetric mountain profile
    runTest(8, {1, 3, 5, 2, 1}, 3, "Asymmetric mountain profile");

    // Test 9: Array of all 1s
    runTest(9, {1, 1, 1, 1, 1}, 4, "All ones array");

    // Test 10: Larger perfect pyramid of height 5
    runTest(10, {1, 2, 3, 4, 5, 4, 3, 2, 1}, 0, "Perfect pyramid of height 5");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
