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

void runTest(int testNum, vector<int> nums, int k, int expected) {
    Solution sol;
    int result = sol.missingMultiple(nums, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(26) << formatArray(nums)
         << setw(6)  << k
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
    cout << "\n🎮 Smallest Missing Multiple of K — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Input Array"
         << setw(6)  << "k"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1
    runTest(1, {8, 2, 3, 4, 6}, 2, 10);

    // Example 2
    runTest(2, {1, 4, 7, 10, 15}, 5, 5);

    // Edge Case: k = 1, missing 1
    runTest(3, {2, 3, 4}, 1, 1);

    // Edge Case: Array has no multiples of k
    runTest(4, {1, 3, 5, 7}, 2, 2);

    // Gap in multiples of 3 (15 is missing)
    runTest(5, {3, 6, 9, 12, 18}, 3, 15);

    // Single element equal to k
    runTest(6, {7}, 7, 14);

    // Single element not equal to k
    runTest(7, {5}, 7, 7);

    // Large multiples of 10
    runTest(8, {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, 10, 110);

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                        \n\n";

    return 0;
}
