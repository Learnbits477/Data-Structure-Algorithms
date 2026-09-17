#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatArray(const vector<int>& arr) {
    if (arr.empty()) return "[]";
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        ss << arr[i];
        if (i + 1 < arr.size()) ss << ",";
        if (ss.str().length() > 22 && i + 1 < arr.size()) {
            ss << "...]";
            return ss.str();
        }
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<int> arr, int target, int expected) {
    Solution sol;
    int result = sol.minSumOfLengths(arr, target);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayArr = formatArray(arr);

    cout << left << setw(6)  << testId
         << setw(26) << displayArr
         << setw(10) << target
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Target:   " << target << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n📏 Find Two Non-overlapping Sub-arrays Each With Target Sum — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Array arr"
         << setw(10) << "Target"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 -> [3] and [3] (len 1 + 1 = 2)
    runTest(1, {3, 2, 2, 4, 3}, 3, 2);

    // Test 2: Example 2 -> [7] and [7] (len 1 + 1 = 2)
    runTest(2, {7, 3, 4, 7}, 7, 2);

    // Test 3: Example 3 -> Only one subarray equals target (-1)
    runTest(3, {4, 3, 2, 6, 2, 3, 4}, 6, -1);

    // Test 4: Minimal size with two separate matches (len 1 + 1 = 2)
    runTest(4, {5, 5}, 5, 2);

    // Test 5: Subarrays of different lengths [1, 2] and [3] -> len 2 + 1 = 3
    runTest(5, {1, 2, 3}, 3, 3);

    // Test 6: Overlapping subarrays only (cannot pick 2 non-overlapping) -> -1
    runTest(6, {2, 2, 2}, 4, -1);

    // Test 7: Adjacent non-overlapping subarrays [1, 1] and [1, 1] -> 2 + 2 = 4
    runTest(7, {1, 1, 1, 1}, 2, 4);

    // Test 8: Multiple candidate subarrays, choose shortest pair -> [3] (len 1) + [1, 2] (len 2) = 3
    runTest(8, {3, 1, 1, 1, 5, 1, 2, 1}, 3, 3);

    // Test 9: No subarrays sum to target (-1)
    runTest(9, {10, 20, 30}, 15, -1);

    // Test 10: Multi-element choice: [1, 2, 1] (len 3) and [4] (len 1) = 4
    runTest(10, {1, 2, 1, 4, 1, 1, 1, 1}, 4, 4);

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
