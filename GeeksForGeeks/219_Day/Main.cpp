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
    int result = sol.maxDiffSum(arr);
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
    cout << "\n📊 Max Adjacent Diffs Sum with 1 Replacements — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(30) << "Array arr"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, {3, 2, 1, 4, 5}, 8);

    // Test 2: Example 2 from problem description
    runTest(2, {1, 5}, 4);

    // Test 3: Array of size 1 (edge case)
    runTest(3, {10}, 0);

    // Test 4: All elements already 1
    runTest(4, {1, 1, 1, 1}, 0);

    // Test 5: Decreasing large values
    runTest(5, {10, 1, 10, 1, 10}, 36);

    // Test 6: Uniform large values
    runTest(6, {5, 5, 5, 5}, 12); // e.g. [5, 1, 5, 1] -> 4+4+4 = 12

    // Test 7: Strictly increasing elements
    runTest(7, {1, 2, 3, 4, 5}, 8); // [1, 2, 1, 4, 1] or [1, 1, 1, 4, 1] -> 8

    // Test 8: Two identical elements
    runTest(8, {10, 10}, 9); // [10, 1] -> |1-10| = 9

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
