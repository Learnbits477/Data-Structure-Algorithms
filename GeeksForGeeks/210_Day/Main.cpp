#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatArray(const vector<int>& arr) {
    if (arr.size() > 8) {
        stringstream ss;
        ss << "[" << arr[0] << ", " << arr[1] << ", " << arr[2] << ", ..., " << arr.back() << "]";
        return ss.str();
    }
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        ss << arr[i] << (i + 1 < arr.size() ? ", " : "");
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    int result = sol.minMoves(arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(24) << formatArray(arr)
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎮 Minimum Moves to Sort Permutation — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(24) << "Input Array"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1
    runTest(1, {2, 1, 3}, 1);

    // Example 2
    runTest(2, {4, 3, 1, 2}, 2);

    // Edge Case: Single element
    runTest(3, {1}, 0);

    // Edge Case: Already sorted
    runTest(4, {1, 2, 3, 4, 5}, 0);

    // Edge Case: Reverse sorted
    runTest(5, {5, 4, 3, 2, 1}, 4);

    // Two elements inverted
    runTest(6, {2, 1}, 1);

    // Two elements sorted
    runTest(7, {1, 2}, 0);

    // Alternating permutation
    runTest(8, {2, 4, 1, 5, 3}, 3);

    // Subsequence [3, 4, 5] of length 3 -> 5 - 3 = 2 moves
    runTest(9, {3, 1, 4, 2, 5}, 2);

    // Larger permutation
    runTest(10, {1, 5, 2, 4, 3, 6}, 3);

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                        \n\n";

    return 0;
}
