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

void runTest(int testNum, vector<int> arr, int m, int expected) {
    Solution sol;
    int result = sol.maxFruits(arr, m);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string arrStr = formatVector(arr);
    if (arrStr.length() > 22) {
        arrStr = arrStr.substr(0, 19) + "...]";
    }

    cout << left << setw(6)  << testId
         << setw(24) << arrStr
         << setw(6)  << m
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     arr = " << formatVector(arr) << "\n"
             << "     m   = " << m << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🐦 Bird and Maximum Fruit Gathering — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(24) << "Array arr"
         << setw(6)  << "m"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, {2, 1, 3, 5, 0, 1, 4}, 3, 9);

    // Test 2: Example 2 from problem description
    runTest(2, {1, 6, 2, 5, 3, 4}, 2, 8);

    // Test 3: Example 3 from problem description
    runTest(3, {7, 2, 1, 3, 4}, 2, 11);

    // Test 4: m >= n (bird can visit all trees)
    runTest(4, {3, 1, 2, 4}, 5, 10);

    // Test 5: m == 1 (single max tree)
    runTest(5, {1, 9, 3, 5, 2}, 1, 9);

    // Test 6: Single element array
    runTest(6, {10}, 1, 10);

    // Test 7: All elements equal
    runTest(7, {4, 4, 4, 4, 4}, 3, 12);

    // Test 8: Wrap-around boundary case
    runTest(8, {10, 1, 2, 1, 10}, 2, 20);

    // Test 9: Larger window
    runTest(9, {5, 1, 2, 3, 4, 8, 9}, 4, 26);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
