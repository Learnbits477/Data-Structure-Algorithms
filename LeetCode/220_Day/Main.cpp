#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string formatVector(const vector<int>& v) {
    if (v.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < v.size(); i++) {
        res += to_string(v[i]);
        if (i + 1 < v.size()) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<int> nums, int k, int expected) {
    Solution sol;
    int result = sol.firstStableIndex(nums, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string arrStr = formatVector(nums);
    if (arrStr.length() > 22) {
        arrStr = arrStr.substr(0, 19) + "...]";
    }

    cout << left << setw(6)  << testId
         << setw(24) << arrStr
         << setw(6)  << k
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     nums = " << formatVector(nums) << "\n"
             << "     k    = " << k << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🟡 3903. Smallest Stable Index I — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(24) << "Array nums"
         << setw(6)  << "k"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, {5, 0, 1, 4}, 3, 3);

    // Test 2: Example 2 from problem description
    runTest(2, {3, 2, 1}, 1, -1);

    // Test 3: Example 3 from problem description
    runTest(3, {0}, 0, 0);

    // Test 4: Single element with k > 0
    runTest(4, {42}, 10, 0);

    // Test 5: All elements identical (diff is 0 for all indices)
    runTest(5, {7, 7, 7, 7}, 0, 0);

    // Test 6: Strictly increasing array
    runTest(6, {1, 2, 3, 4, 5}, 0, 0);

    // Test 7: Large k where first element is immediately valid
    runTest(7, {10, 20, 30}, 100, 0);

    // Test 8: Stable index occurs in middle
    runTest(8, {10, 2, 8, 9}, 7, 2); // At index 2: max([10,2,8])=10, min([8,9])=8 => 10-8=2 <= 7

    // Test 9: Large values
    runTest(9, {1000000000, 500000000, 1000000000}, 500000000, 0);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
