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
    int result = sol.smallestStableIndex(nums, k);
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
    cout << "\n🟡 3904. Smallest Stable Index II — Test Suite\n";
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

    // Test 4: Single element with large k
    runTest(4, {100}, 50, 0);

    // Test 5: All identical elements
    runTest(5, {8, 8, 8, 8}, 0, 0);

    // Test 6: Strictly increasing array
    runTest(6, {1, 2, 3, 4, 5}, 0, 0);

    // Test 7: Middle stable index
    runTest(7, {10, 2, 8, 9}, 7, 2);

    // Test 8: Large array (simulation of 10^5 elements)
    vector<int> largeNums(100000, 5);
    runTest(8, largeNums, 0, 0);

    // Test 9: Large values up to 10^9
    runTest(9, {1000000000, 500000000, 1000000000}, 500000000, 0);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
