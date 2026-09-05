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

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    int result = sol.longestSubsequence(arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string arrStr = formatVector(arr);
    if (arrStr.length() > 28) {
        arrStr = arrStr.substr(0, 25) + "...]";
    }

    cout << left << setw(6)  << testId
         << setw(30) << arrStr
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     arr = " << formatVector(arr) << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🌟 Longest Subsequence with Adjacent Diff as 1 — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(30) << "Array arr"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, {10, 9, 4, 5, 4, 8, 6}, 3);

    // Test 2: Example 2 from problem description
    runTest(2, {1, 2, 3, 2, 3, 7, 2, 1}, 7);

    // Test 3: Single element array
    runTest(3, {42}, 1);

    // Test 4: All equal elements
    runTest(4, {5, 5, 5, 5}, 1);

    // Test 5: Strictly increasing by 1
    runTest(5, {1, 2, 3, 4, 5, 6}, 6);

    // Test 6: Strictly decreasing by 1
    runTest(6, {10, 9, 8, 7, 6}, 5);

    // Test 7: Alternating values
    runTest(7, {2, 3, 2, 3, 2, 3}, 6);

    // Test 8: Disjoint elements (no adjacent diff 1 possible)
    runTest(8, {1, 10, 20, 30, 40}, 1);

    // Test 9: Complex sequence
    runTest(9, {4, 6, 5, 7, 8, 9, 8, 7}, 6); // e.g., 4, 5, 7, 8, 9, 8, 7 -> [6, 7, 8, 9, 8, 7] = 6

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
