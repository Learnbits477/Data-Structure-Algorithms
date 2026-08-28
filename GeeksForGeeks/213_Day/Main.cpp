#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string formatMatrix(const vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) return "[]";
    int m = mat[0].size();
    stringstream ss;
    ss << n << "x" << m << " [";
    for (int i = 0; i < min(n, 2); ++i) {
        ss << "[";
        for (int j = 0; j < m; ++j) {
            ss << mat[i][j] << (j + 1 < m ? "," : "");
        }
        ss << "]" << (i + 1 < min(n, 2) ? "," : "");
    }
    if (n > 2) ss << "..";
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<vector<int>> mat, int expected) {
    Solution sol;
    int result = sol.minCost(mat);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(32) << formatMatrix(mat)
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎮 Minimum Cost Selection — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Matrix (n x 3)"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {
        {1, 50, 50},
        {50, 50, 50},
        {1, 50, 50}
    }, 52);

    // Test 2: Example 2
    runTest(2, {
        {1, 4, 1},
        {3, 2, 2},
        {3, 2, 3}
    }, 5);

    // Test 3: Single row
    runTest(3, {
        {5, 10, 2}
    }, 2);

    // Test 4: Two rows
    runTest(4, {
        {1, 2, 3},
        {3, 2, 1}
    }, 2);

    // Test 5: All equal values across rows
    runTest(5, {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    }, 6);

    // Test 6: Greedy trap (Row 0 min is choice 0, but choosing choice 1 allows smaller row 1 choice)
    runTest(6, {
        {1, 2, 10},
        {1, 100, 100}
    }, 3);

    // Test 7: Alternating optimal choices
    runTest(7, {
        {1, 10, 10},
        {10, 1, 10},
        {1, 10, 10},
        {10, 1, 10}
    }, 4);

    // Test 8: Monotonically increasing choices
    runTest(8, {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    }, 130);

    // Test 9: Empty matrix edge case
    runTest(9, {}, 0);

    // Test 10: Larger 5-row matrix
    runTest(10, {
        {7, 3, 8},
        {6, 5, 2},
        {9, 4, 1},
        {8, 6, 7},
        {1, 4, 5}
    }, 17);

    cout << "※ ============================================================================== ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
