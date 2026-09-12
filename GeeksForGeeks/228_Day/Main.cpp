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

void runTest(int testNum, vector<int> arr, int k, int expected) {
    Solution sol;
    vector<int> arrCopy = arr;
    int result = sol.maxProduct(arrCopy, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(26) << formatArray(arr)
         << setw(8)  << k
         << setw(14) << result
         << setw(14) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Array    = " << formatArray(arr) << "\n"
             << "     k        = " << k << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Max Product Subsequence of Size K — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Input Array"
         << setw(8)  << "k"
         << setw(14) << "Result"
         << setw(14) << "Expected"
         << "Status\n";
    cout << string(74, '-') << "\n";

    // Test 1: Example 1 from problem description: arr = [1, 2, 0, 3], k = 2 -> 6 (2 * 3)
    runTest(1, {1, 2, 0, 3}, 2, 6);

    // Test 2: Example 2 from problem description: arr = [1, 2, -1, -3, -6, 4], k = 4 -> 144
    runTest(2, {1, 2, -1, -3, -6, 4}, 4, 144);

    // Test 3: All negative elements and odd k: [-5, -4, -3, -2, -1], k = 3 -> -6
    runTest(3, {-5, -4, -3, -2, -1}, 3, -6);

    // Test 4: All negative elements and even k: [-5, -4, -3, -2], k = 2 -> 20 (-5 * -4)
    runTest(4, {-5, -4, -3, -2}, 2, 20);

    // Test 5: Full array chosen: k == n
    runTest(5, {2, 3, -4}, 3, -24);

    // Test 6: Single element array: k = 1
    runTest(6, {-7}, 1, -7);

    // Test 7: Array with zeros and negative numbers, odd k
    runTest(7, {-5, -4, -3, -2, 0}, 3, 0);

    // Test 8: Mixed positive and negative with odd k
    runTest(8, {-5, -2, -1, 0, 0, 3}, 3, 30);

    // Test 9: Two positive and two negative: [-10, -10, 10, 10], k = 2 -> 100
    runTest(9, {-10, -10, 10, 10}, 2, 100);

    // Test 10: All identical positive elements: [2, 2, 2, 2, 2], k = 3 -> 8
    runTest(10, {2, 2, 2, 2, 2}, 3, 8);

    cout << "※ ========================================================================= ※\n";
    cout << "                         🎉 All Tests Executed!                             \n\n";

    return 0;
}
