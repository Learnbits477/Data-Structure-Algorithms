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

void runTest(int testNum, vector<int> nums1, bool expected) {
    Solution sol;
    bool result = sol.constructUniformParityArray(nums1);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string arrStr = formatVector(nums1);
    if (arrStr.length() > 28) {
        arrStr = arrStr.substr(0, 25) + "...]";
    }

    string resStr = result ? "true" : "false";
    string expStr = expected ? "true" : "false";

    cout << left << setw(6)  << testId
         << setw(30) << arrStr
         << setw(12) << resStr
         << setw(12) << expStr
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     nums1 = " << formatVector(nums1) << "\n"
             << "     Expected: " << expStr << "\n"
             << "     Got:      " << resStr << "\n";
    }
}

int main() {
    cout << "\n🟡 3876. Construct Uniform Parity Array II — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(30) << "Array nums1"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, {1, 4, 7}, true);

    // Test 2: Example 2 from problem description
    runTest(2, {2, 3}, false);

    // Test 3: Example 3 from problem description
    runTest(3, {4, 6}, true);

    // Test 4: Single element (odd)
    runTest(4, {7}, true);

    // Test 5: Single element (even)
    runTest(5, {8}, true);

    // Test 6: All elements are odd
    runTest(6, {1, 3, 5, 7, 9}, true);

    // Test 7: All elements are even
    runTest(7, {2, 4, 6, 8, 10}, true);

    // Test 8: Min element is even, but odd elements exist
    runTest(8, {2, 10, 5}, false);

    // Test 9: Min element is odd, even elements exist
    runTest(9, {3, 4, 6, 8}, true);

    // Test 10: Large values
    runTest(10, {1000000000, 1}, true);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
