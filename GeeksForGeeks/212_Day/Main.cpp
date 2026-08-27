#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatMatrix(const vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) return "[]";
    int m = mat[0].size();
    stringstream ss;
    ss << n << "x" << m << " [";
    for (int i = 0; i < min(n, 2); ++i) {
        ss << "[";
        for (int j = 0; j < min(m, 3); ++j) {
            ss << mat[i][j] << (j + 1 < min(m, 3) ? "," : "");
        }
        if (m > 3) ss << "..";
        ss << "]" << (i + 1 < min(n, 2) ? "," : "");
    }
    if (n > 2) ss << "..";
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<vector<int>> mat, int expected) {
    Solution sol;
    int result = sol.maxArea(mat);
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
    cout << "\n🎮 Largest Rectangle with Column Swaps — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Matrix (n x m)"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1
    runTest(1, {
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 1, 0}
    }, 6);

    // Example 2
    runTest(2, {
        {0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1}
    }, 12);

    // Test 3: All 1s (3x3)
    runTest(3, {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    }, 9);

    // Test 4: All 0s (3x3)
    runTest(4, {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    }, 0);

    // Test 5: Single cell 1
    runTest(5, {
        {1}
    }, 1);

    // Test 6: Single cell 0
    runTest(6, {
        {0}
    }, 0);

    // Test 7: Single row multiple 1s
    runTest(7, {
        {0, 1, 0, 1, 1, 1}
    }, 4);

    // Test 8: Single column
    runTest(8, {
        {1},
        {1},
        {0},
        {1}
    }, 2);

    // Test 9: Checkerboard pattern
    runTest(9, {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    }, 2);

    // Test 10: Tall matrix (5x2) where single tall column beats 2x2
    runTest(10, {
        {1, 1},
        {1, 1},
        {1, 0},
        {1, 0},
        {1, 0}
    }, 5);

    // Test 11: Separated columns that become adjacent after swap
    runTest(11, {
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0}
    }, 4);

    // Test 12: vector<vector<bool>> overload validation
    Solution sol;
    vector<vector<bool>> boolMat = {
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 1, 0}
    };
    int boolResult = sol.maxArea(boolMat);
    string testId = "#12";
    cout << left << setw(6)  << testId
         << setw(32) << "3x5 [vector<bool> overload]"
         << setw(12) << 6
         << setw(12) << boolResult
         << (boolResult == 6 ? "✅ PASSED" : "❌ FAILED") << "\n";

    cout << "※ ============================================================================== ※\n";
    cout << "                             🎉 All Tests Executed!                               \n\n";

    return 0;
}
