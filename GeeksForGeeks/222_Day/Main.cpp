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

void runTest(int testNum, vector<int> arr, long long expected) {
    Solution sol;
    long long result = sol.pairAndSum(arr);
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
         << setw(16) << result
         << setw(16) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     arr = " << formatVector(arr) << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🌟 Sum of Pairwise ANDs — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(30) << "Array arr"
         << setw(16) << "Result"
         << setw(16) << "Expected"
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Test 1: Example 1 from problem description
    runTest(1, {5, 10, 15}, 15);

    // Test 2: Example 2 from problem description
    runTest(2, {10, 20, 30, 40}, 46);

    // Test 3: Two elements with no common bits
    runTest(3, {4, 8}, 0);

    // Test 4: Two elements with common bits
    runTest(4, {6, 7}, 6);

    // Test 5: Single element (no pairs)
    runTest(5, {42}, 0);

    // Test 6: All elements identical
    // Pair count = (4 * 3) / 2 = 6, AND of each pair = 7, total = 42
    runTest(6, {7, 7, 7, 7}, 42);

    // Test 7: Powers of 2 (pairwise AND is always 0 for distinct powers)
    runTest(7, {1, 2, 4, 8, 16}, 0);

    // Test 8: Consecutive numbers
    // [1, 2, 3] -> (1&2=0) + (1&3=1) + (2&3=2) = 3
    runTest(8, {1, 2, 3}, 3);

    // Test 9: Large values (up to 10^8)
    // 100000000 & 100000000 = 100000000
    runTest(9, {100000000, 100000000, 100000000}, 300000000LL);

    cout << "※ ========================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
