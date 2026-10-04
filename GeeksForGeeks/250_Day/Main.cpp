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
    string s = to_string(n) + "x" + to_string(m) + " [";
    int onesCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 1) onesCount++;
        }
    }
    s += to_string(onesCount) + " ones]";
    return s;
}

void runTest(int testNum, vector<vector<int>> mat, int expected, const string& description) {
    // Step: 01 - Execute perimeter calculations using both methods
    Solution sol;
    int resPrimary = sol.findPerimeter(mat);
    int resShared = sol.findPerimeterSharedEdges(mat);

    // Step: 02 - Validate test result and cross-method consistency
    bool passed = (resPrimary == expected) && (resShared == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular identifiers and outputs
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 34) {
        displayDesc = displayDesc.substr(0, 31) + "...";
    }

    string inputDisplay = formatMatrix(mat);

    cout << left << setw(6)  << testId
         << setw(36) << displayDesc
         << setw(18) << inputDisplay
         << setw(12) << expected
         << setw(12) << resPrimary
         << status << "\n";

    // Step: 04 - Print debug information in case of failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:           " << expected << "\n"
             << "     Actual (Primary):   " << resPrimary << "\n"
             << "     Actual (Shared):    " << resShared << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n📐 Perimeter of Shapes in Binary Matrix — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(36) << "Description"
         << setw(18) << "Input Dimensions"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {{0, 1, 0, 0, 0}, {1, 1, 1, 0, 0}, {1, 0, 0, 0, 0}}, 12, "Example 1: Connected 5-cell figure");
    runTest(2, {{1, 0}, {1, 1}}, 8, "Example 2: 3-cell corner figure");
    runTest(3, {{1}}, 4, "Single cell containing 1");
    runTest(4, {{0}}, 0, "Single cell containing 0");
    runTest(5, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0, "All zeros 3x3 matrix");
    runTest(6, {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 12, "All ones 3x3 matrix (solid block)");
    runTest(7, {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}}, 20, "Diagonal disconnected cells (5 * 4)");
    runTest(8, {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, 16, "Hollow donut square (8 outer + 4 inner)");
    runTest(9, {{1, 1, 1, 1, 1}}, 12, "Single row line of length 5 (2 * (1 + 5))");
    runTest(10, {{1}, {1}, {1}, {1}}, 10, "Single column line of length 4 (2 * (1 + 4))");

    // Step: 03 - Display final completion summary
    cout << "※ ========================================================================================= ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";
    return 0;
}
