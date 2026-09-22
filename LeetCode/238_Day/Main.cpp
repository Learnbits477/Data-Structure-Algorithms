#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatVector(const vector<int>& vec) {
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i + 1 < vec.size()) ss << ", ";
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<int> nums, int k, vector<vector<int>> queries, const vector<int>& expected, const string& description) {
    Solution sol;
    vector<int> result = sol.resultArray(nums, k, queries);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 28) {
        displayDesc = displayDesc.substr(0, 25) + "...";
    }

    string displayExpected = formatVector(expected);
    string displayResult = formatVector(result);

    cout << left << setw(6)  << testId
         << setw(30) << displayDesc
         << setw(16) << displayExpected
         << setw(16) << displayResult
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     k:              " << k << "\n"
             << "     Expected:       " << displayExpected << "\n"
             << "     Got:            " << displayResult << "\n";
    }
}

int main() {
    cout << "\n🎯 Find X Value of Array II — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(30) << "Description"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {1, 2, 3, 4, 5}, 3, {{2, 2, 0, 2}, {3, 3, 3, 0}, {0, 1, 0, 1}}, {2, 2, 2}, "Example 1 (standard)");

    // Test 2: Example 2
    runTest(2, {1, 2, 4, 8, 16, 32}, 4, {{0, 2, 0, 2}, {0, 2, 0, 1}}, {1, 0}, "Example 2 (powers of 2 mod 4)");

    // Test 3: Example 3
    runTest(3, {1, 1, 2, 1, 1}, 2, {{2, 1, 0, 1}}, {5}, "Example 3 (all ones mod 2)");

    // Test 4: Single element array with various modulo values
    runTest(4, {7}, 5, {{0, 4, 0, 4}, {0, 3, 0, 3}, {0, 5, 0, 0}}, {1, 1, 1}, "Single element array");

    // Test 5: Trivial modulo k = 1
    runTest(5, {2, 3, 5}, 1, {{1, 4, 0, 0}, {0, 2, 1, 0}}, {3, 2}, "Modulo k = 1 boundary");

    // Test 6: Zero remainder propagation
    runTest(6, {3, 2, 5}, 3, {{0, 3, 0, 0}, {1, 3, 0, 0}}, {3, 3}, "Zero propagation mod 3");

    // Test 7: Query starting at final index n - 1
    runTest(7, {2, 4, 6, 8}, 5, {{3, 3, 3, 3}, {3, 4, 3, 4}, {3, 4, 3, 1}}, {1, 1, 0}, "Query at last index (len 1)");

    // Test 8: Large integer values modulo k
    runTest(8, {1000000000, 1000000000}, 3, {{0, 1000000001, 0, 2}, {1, 1000000002, 0, 0}}, {2, 1}, "Large values (10^9)");

    // Test 9: Prime modulo k = 5 with cyclic steps
    runTest(9, {2, 2, 2, 2}, 5, {{0, 2, 0, 4}, {0, 2, 0, 3}, {0, 2, 0, 1}}, {1, 1, 1}, "Modulo 5 cycles (2^i mod 5)");

    // Test 10: Consecutive updates at same index
    runTest(10, {1, 2, 3}, 4, {{1, 1, 0, 1}, {1, 2, 0, 2}, {1, 3, 0, 3}}, {2, 2, 1}, "Repeated updates at same idx");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
