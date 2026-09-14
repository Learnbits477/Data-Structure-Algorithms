#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string formatMatrix(const vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) return "[]";
    int m = mat[0].size();
    string s = to_string(n) + "x" + to_string(m) + " [";
    for (int i = 0; i < n; i++) {
        s += "{";
        for (int j = 0; j < m; j++) {
            s += to_string(mat[i][j]);
            if (j + 1 < m) s += ",";
        }
        s += "}";
        if (i + 1 < n) s += ", ";
        if (s.length() > 28 && i + 1 < n) {
            s += "...]";
            return s;
        }
    }
    s += "]";
    return s;
}

void runTest(int testNum, vector<vector<int>> mat, int expected) {
    Solution sol;
    int result = sol.shortestPath(mat);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(36) << formatMatrix(mat)
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🛡️ Find Shortest Safe Route in a Matrix — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(36) << "Matrix Size / Data"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(74, '-') << "\n";

    // Test 1: Example 1 (5x5 matrix with landmines) -> 6
    runTest(1, {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}
    }, 6);

    // Test 2: Example 2 (3x5 matrix with blocked column 2) -> -1
    runTest(2, {
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1}
    }, -1);

    // Test 3: 1x1 safe cell -> 1
    runTest(3, {{1}}, 1);

    // Test 4: 1x1 landmine cell -> -1
    runTest(4, {{0}}, -1);

    // Test 5: 1x5 all safe straight path -> 5
    runTest(5, {{1, 1, 1, 1, 1}}, 5);

    // Test 6: 3x3 all landmines -> -1
    runTest(6, {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    }, -1);

    // Test 7: 4x4 matrix with mines blocking row 0 and 1, but clear path along row 3 -> 4
    runTest(7, {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    }, 4);

    // Test 8: 4x4 matrix with a single mine at (1,1) allowing clear path along row 3 -> 4
    runTest(8, {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    }, 4);

    // Test 9: 3x3 matrix where entire column 1 is blocked by landmine at (1, 1) -> -1
    runTest(9, {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    }, -1);

    cout << "※ ========================================================================= ※\n";
    cout << "                         🎉 All Tests Executed!                             \n\n";

    return 0;
}
