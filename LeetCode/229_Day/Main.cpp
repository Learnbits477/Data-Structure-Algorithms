#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string formatMatrixSummary(const vector<vector<int>>& mat) {
    int n = mat.size();
    int countOnes = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (mat[r][c] == 1) countOnes++;
        }
    }
    return to_string(n) + "x" + to_string(n) + " (" + to_string(countOnes) + " 1s)";
}

void runTest(int testNum, vector<vector<int>> img1, vector<vector<int>> img2, int expected) {
    Solution sol;
    int result = sol.largestOverlap(img1, img2);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(16) << formatMatrixSummary(img1)
         << setw(16) << formatMatrixSummary(img2)
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
    cout << "\n🖼️ 835. Image Overlap — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(16) << "img1 (Size/1s)"
         << setw(16) << "img2 (Size/1s)"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(70, '-') << "\n";

    // Test 1: Example 1 from problem description -> 3
    runTest(1, 
        {{1, 1, 0}, 
         {0, 1, 0}, 
         {0, 1, 0}},
        {{0, 0, 0}, 
         {0, 1, 1}, 
         {0, 0, 1}}, 
        3);

    // Test 2: Example 2: 1x1 both 1s -> 1
    runTest(2, 
        {{1}}, 
        {{1}}, 
        1);

    // Test 3: Example 3: 1x1 both 0s -> 0
    runTest(3, 
        {{0}}, 
        {{0}}, 
        0);

    // Test 4: One has 1s, other has only 0s -> 0
    runTest(4,
        {{1, 1}, 
         {1, 1}},
        {{0, 0}, 
         {0, 0}},
        0);

    // Test 5: Exact identical 3x3 matrices -> 5
    runTest(5,
        {{1, 0, 1}, 
         {0, 1, 0}, 
         {1, 0, 1}},
        {{1, 0, 1}, 
         {0, 1, 0}, 
         {1, 0, 1}},
        5);

    // Test 6: Diagonal line shift in 4x4
    runTest(6,
        {{1, 0, 0, 0}, 
         {0, 1, 0, 0}, 
         {0, 0, 1, 0}, 
         {0, 0, 0, 1}},
        {{0, 1, 0, 0}, 
         {0, 0, 1, 0}, 
         {0, 0, 0, 1}, 
         {0, 0, 0, 0}},
        3);

    // Test 7: Full 2x2 matrices of all 1s -> 4
    runTest(7,
        {{1, 1}, 
         {1, 1}},
        {{1, 1}, 
         {1, 1}},
        4);

    cout << "※ ========================================================================= ※\n";
    cout << "                         🎉 All Tests Executed!                             \n\n";

    return 0;
}
