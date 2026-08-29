#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string formatVector(const vector<int>& v) {
    if (v.empty()) return "[]";
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i < 4 || i + 2 >= v.size()) {
            ss << v[i] << (i + 1 < v.size() ? "," : "");
        } else if (i == 4) {
            ss << "..,";
        }
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<int> nums, int limit, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.lexicographicallySmallestArray(nums, limit);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(24) << formatVector(nums)
         << setw(8)  << limit
         << setw(24) << formatVector(expected)
         << setw(24) << formatVector(result)
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << formatVector(expected) << "\n"
             << "     Got:      " << formatVector(result) << "\n";
    }
}

int main() {
    cout << "\n🎮 Make Lexicographically Smallest Array by Swapping Elements — Test Suite\n";
    cout << "※ ==================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(24) << "nums"
         << setw(8)  << "limit"
         << setw(24) << "Expected"
         << setw(24) << "Result"
         << "Status\n";
    cout << string(98, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {1, 5, 3, 9, 8}, 2, {1, 3, 5, 8, 9});

    // Test 2: Example 2
    runTest(2, {1, 7, 6, 18, 2, 1}, 3, {1, 6, 7, 18, 1, 2});

    // Test 3: Example 3 (no swaps possible)
    runTest(3, {1, 7, 28, 19, 10}, 3, {1, 7, 28, 19, 10});

    // Test 4: Single element array
    runTest(4, {42}, 5, {42});

    // Test 5: Already sorted array
    runTest(5, {1, 2, 3, 4}, 1, {1, 2, 3, 4});

    // Test 6: Reverse sorted (all connected)
    runTest(6, {5, 4, 3, 2, 1}, 1, {1, 2, 3, 4, 5});

    // Test 7: Identical duplicate values with limit 0
    runTest(7, {2, 2, 2, 2}, 0, {2, 2, 2, 2});

    // Test 8: Disjoint pairs
    runTest(8, {10, 1, 12, 3}, 2, {10, 1, 12, 3});

    // Test 9: Interleaved components
    runTest(9, {1, 50, 3, 49, 2}, 1, {1, 49, 2, 50, 3});

    // Test 10: Zero operations possible (gaps > limit)
    runTest(10, {10, 20, 30}, 5, {10, 20, 30});

    // Test 11: Large values up to 10^9
    runTest(11, {1000000000, 1, 999999999}, 2, {999999999, 1, 1000000000});

    cout << "※ ==================================================================================================== ※\n";
    cout << "                                  🎉 All Tests Executed!                                  \n\n";

    return 0;
}
