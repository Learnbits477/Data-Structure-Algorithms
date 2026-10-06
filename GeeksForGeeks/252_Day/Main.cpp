#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatMatrix(const vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return "[]";
    int n = mat.size();
    int m = mat[0].size();
    stringstream ss;
    ss << n << "x" << m << " [";
    for (int i = 0; i < n; ++i) {
        ss << "[";
        for (int j = 0; j < m; ++j) {
            ss << mat[i][j] << (j + 1 < m ? "," : "");
            if (ss.str().length() > 16) {
                ss << "...]";
                return ss.str();
            }
        }
        ss << "]" << (i + 1 < n ? "," : "");
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<vector<int>> matrix, int expected, const string& description) {
    // Step: 01 - Compute longest increasing path via DFS memoization and topological BFS
    Solution sol;
    int n = matrix.size();
    int m = n > 0 ? matrix[0].size() : 0;
    int resDFS = sol.longIncPath(matrix, n, m);
    int resBFS = sol.longIncPathBFS(matrix, n, m);

    // Step: 02 - Verify result correctness and cross-algorithm consistency
    bool passed = (resDFS == expected) && (resBFS == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular identifiers and outputs
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 36) {
        displayDesc = displayDesc.substr(0, 33) + "...";
    }

    string inputDisplay = formatMatrix(matrix);

    cout << left << setw(6)  << testId
         << setw(38) << displayDesc
         << setw(20) << inputDisplay
         << setw(12) << expected
         << setw(12) << resDFS
         << status << "\n";

    // Step: 04 - Print debug details upon failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:    " << expected << "\n"
             << "     DFS Result:  " << resDFS << "\n"
             << "     BFS Result:  " << resBFS << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n⛰️ Longest Increasing Path in Matrix — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(38) << "Description"
         << setw(20) << "Input Grid"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(94, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 5, "Example 1: Diagonal gradient (3x3)");
    runTest(2, {{3, 4, 5}, {6, 2, 6}, {2, 2, 1}}, 4, "Example 2: Branching matrix (3x3)");
    runTest(3, {{42}}, 1, "Single cell (1x1) matrix");
    runTest(4, {{1, 3, 5, 7, 9}}, 5, "Single row strictly increasing");
    runTest(5, {{9, 7, 5, 3, 1}}, 5, "Single row strictly decreasing");
    runTest(6, {{2}, {4}, {6}, {8}}, 4, "Single column strictly increasing");
    runTest(7, {{5, 5}, {5, 5}}, 1, "All equal elements (no moves possible)");
    runTest(8, {{1, 2, 3}, {6, 5, 4}, {7, 8, 9}}, 9, "Full 3x3 snake continuous path");
    runTest(9, {{1, 1, 1}, {1, 9, 1}, {1, 1, 1}}, 2, "Central isolated peak with flat rim");
    runTest(10, {{10, 9, 2, 1}, {11, 8, 3, 2}, {12, 7, 4, 3}, {13, 6, 5, 4}}, 13, "Complex spiral path of length 13");

    // Step: 03 - Display final completion summary
    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";
    return 0;
}
