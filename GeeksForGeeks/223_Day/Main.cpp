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
    int result = sol.minCount(arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string arrStr = formatVector(arr);
    if (arrStr.length() > 32) {
        arrStr = arrStr.substr(0, 29) + "...]";
    }

    cout << left << setw(6)  << testId
         << setw(34) << arrStr
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     arr      = " << formatVector(arr) << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🌟 Minimum Elements Outside Subsequences — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Array arr"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, {7, 8, 1, 2, 4, 6, 3, 5, 2, 1, 8, 7}, 2);

    // Test 2: Example 2 from problem description
    runTest(2, {1, 4, 2, 3, 3, 2, 4}, 0);

    // Test 3: Strictly increasing array (all can go into IS)
    runTest(3, {1, 2, 3, 4, 5}, 0);

    // Test 4: Strictly decreasing array (all can go into DS)
    runTest(4, {5, 4, 3, 2, 1}, 0);

    // Test 5: Single element
    runTest(5, {10}, 0);

    // Test 6: Two identical elements (one in IS, one in DS)
    runTest(6, {5, 5}, 0);

    // Test 7: Three identical elements (one in IS, one in DS, one unselected)
    runTest(7, {5, 5, 5}, 1);

    // Test 8: Five identical elements (two selected, 3 unselected)
    runTest(8, {4, 4, 4, 4, 4}, 3);

    // Test 9: Interleaved increasing and decreasing subsequences
    // IS: [1, 2, 3, 4], DS: [10, 9, 8, 7] -> all 8 selected
    runTest(9, {10, 1, 9, 2, 8, 3, 7, 4}, 0);

    // Test 10: Array requiring unselected elements due to duplicates
    // [10, 5, 5, 5, 5] -> IS: [5], DS: [10, 5], 2 elements unselected
    runTest(10, {10, 5, 5, 5, 5}, 2);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
