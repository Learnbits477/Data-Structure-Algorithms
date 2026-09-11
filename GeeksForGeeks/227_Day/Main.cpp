#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string formatArray(const vector<int>& arr) {
    if (arr.empty()) return "[]";
    string s = "[";
    for (size_t i = 0; i < arr.size(); i++) {
        s += to_string(arr[i]);
        if (i + 1 < arr.size()) s += ", ";
        if (s.length() > 20 && i + 1 < arr.size()) {
            s += "...]";
            return s;
        }
    }
    s += "]";
    return s;
}

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    int result = sol.sameMod(arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(26) << formatArray(arr)
         << setw(16) << result
         << setw(16) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Array    = " << formatArray(arr) << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Values with Equal Array Remainders — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Input Array"
         << setw(16) << "Result"
         << setw(16) << "Expected"
         << "Status\n";
    cout << string(74, '-') << "\n";

    // Test 1: Example 1 from problem description: arr = [38, 6, 34] -> 3 (k = 1, 2, 4)
    runTest(1, {38, 6, 34}, 3);

    // Test 2: Example 2 from problem description: arr = [3, 2] -> 1 (k = 1)
    runTest(2, {3, 2}, 1);

    // Test 3: Example 3 from problem description: arr = [5, 5, 5] -> -1 (infinite)
    runTest(3, {5, 5, 5}, -1);

    // Test 4: Single element array -> -1
    runTest(4, {42}, -1);

    // Test 5: Multiples of 12: arr = [12, 24, 36, 48] -> gcd of diffs = 12 -> divisors of 12: 1, 2, 3, 4, 6, 12 (6 divisors)
    runTest(5, {12, 24, 36, 48}, 6);

    // Test 6: Prime difference: arr = [10, 23] -> diff = 13 (prime) -> divisors of 13: 1, 13 (2 divisors)
    runTest(6, {10, 23}, 2);

    // Test 7: Duplicate elements mixed with distinct: arr = [4, 4, 10] -> diffs = 0, 6 -> gcd = 6 -> divisors: 1, 2, 3, 6 (4 divisors)
    runTest(7, {4, 4, 10}, 4);

    // Test 8: Square number gcd: arr = [100, 136] -> diff = 36 -> divisors: 1, 2, 3, 4, 6, 9, 12, 18, 36 (9 divisors)
    runTest(8, {100, 136}, 9);

    // Test 9: Coprime differences: arr = [10, 15, 16] -> diffs = 5, 6 -> gcd = 1 -> 1 divisor (k = 1)
    runTest(9, {10, 15, 16}, 1);

    // Test 10: All large equal values at upper constraints: [100000, 100000] -> -1
    runTest(10, {100000, 100000}, -1);

    cout << "※ ========================================================================= ※\n";
    cout << "                         🎉 All Tests Executed!                             \n\n";

    return 0;
}
