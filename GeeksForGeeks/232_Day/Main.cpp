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
        if (ss.str().length() > 20 && i + 1 < arr.size()) {
            ss << "...]";
            return ss.str();
        }
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    int n = static_cast<int>(arr.size());
    int result = sol.dominantPairs(n, arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayArr = formatArray(arr);

    cout << left << setw(6)  << testId
         << setw(26) << displayArr
         << setw(8)  << n
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n:        " << n << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Dominant Pairs — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Array arr"
         << setw(8)  << "n"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 -> 2 pairs
    runTest(1, {10, 2, 2, 1}, 2);

    // Test 2: Example 2 -> 5 pairs
    runTest(2, {10, 8, 2, 1, 1, 2}, 5);

    // Test 3: Minimal size (n = 2), condition holds (15 >= 5 * 3) -> 1
    runTest(3, {15, 3}, 1);

    // Test 4: Minimal size (n = 2), condition fails (14 < 5 * 3) -> 0
    runTest(4, {14, 3}, 0);

    // Test 5: All zeros -> 0 >= 5 * 0 holds for all pairs -> (n/2) * (n/2) = 4
    runTest(5, {0, 0, 0, 0}, 4);

    // Test 6: All pairs dominant -> 3 * 3 = 9
    runTest(6, {50, 60, 70, 1, 2, 3}, 9);

    // Test 7: No pairs dominant -> 0
    runTest(7, {1, 2, 10, 20}, 0);

    // Test 8: Negative numbers -> arr[i] >= 5 * arr[j]
    // First half: [-5, 10], Second half: [-2, 1]
    // -5 >= 5 * (-2) = -10 (valid), -5 >= 5 * 1 = 5 (invalid) -> 1 pair
    // 10 >= 5 * (-2) = -10 (valid), 10 >= 5 * 1 = 5 (valid) -> 2 pairs
    // Total = 3 pairs
    runTest(8, {-5, 10, -2, 1}, 3);

    // Test 9: Larger mixed array
    // First half: [25, 10, 5, 0], Second half: [1, 2, -1, 5]
    // First half sorted: [0, 5, 10, 25]
    // Second half sorted: [-1, 1, 2, 5] -> 5 * arr[j] = [-5, 5, 10, 25]
    // 0 >= -5 (1)
    // 5 >= -5, 5 (2)
    // 10 >= -5, 5, 10 (3)
    // 25 >= -5, 5, 10, 25 (4)
    // Total = 1 + 2 + 3 + 4 = 10
    runTest(9, {25, 10, 5, 0, 1, 2, -1, 5}, 10);

    // Test 10: All equal positive elements (e.g. 5's): 5 >= 5 * 5 = 25 is False -> 0
    runTest(10, {5, 5, 5, 5, 5, 5}, 0);

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
