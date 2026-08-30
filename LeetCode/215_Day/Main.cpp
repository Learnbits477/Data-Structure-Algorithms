#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string formatVector(const vector<int>& v, int maxItems = 7) {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (static_cast<int>(i) >= maxItems) {
            oss << "...";
            break;
        }
        oss << v[i];
        if (i + 1 < v.size() && static_cast<int>(i + 1) < maxItems) {
            oss << ",";
        }
    }
    oss << "]";
    return oss.str();
}

void runTest(int testNum, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.minimumDeletions(nums);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(32) << formatVector(nums)
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input nums: " << formatVector(nums, 100) << "\n"
             << "     Expected:   " << expected << "\n"
             << "     Got:        " << result << "\n";
    }
}

int main() {
    cout << "\n🎮 2091. Removing Minimum and Maximum From Array — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Input Array (nums)"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, {2, 10, 7, 5, 4, 1, 8, 6}, 5);

    // Test 2: Example 2 from problem description
    runTest(2, {0, -4, 19, 1, 8, -2, -3, 5}, 3);

    // Test 3: Example 3 (Single element)
    runTest(3, {101}, 1);

    // Test 4: Two elements (ascending)
    runTest(4, {1, 2}, 2);

    // Test 5: Two elements (descending)
    runTest(5, {5, 1}, 2);

    // Test 6: Min and max at opposite ends of array
    runTest(6, {10, 2, 3, 4, 5, 1}, 2);

    // Test 7: Min and max both at the end
    runTest(7, {3, 4, 5, 1, 10}, 2);

    // Test 8: Min and max both at the beginning
    runTest(8, {1, 10, 3, 4, 5}, 2);

    // Test 9: Array with negative numbers
    runTest(9, {-10, -5, -20, -1, -15}, 3);

    // Test 10: Three elements
    runTest(10, {10, 20, 30}, 2);

    cout << "※ ============================================================================== ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
