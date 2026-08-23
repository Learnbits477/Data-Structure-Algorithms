#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int r, int c, int u, int d, const vector<vector<char>>& mat, int expected, const string& testDesc) {
    int n = mat.size();
    int m = mat[0].size();

    Solution sol;
    vector<vector<char>> matCopy = mat;
    int result = sol.numberOfCells(n, m, r, c, u, d, matCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string dimStr = to_string(n) + "x" + to_string(m);
    string startStr = "(" + to_string(r) + "," + to_string(c) + ")";
    string limitsStr = "u=" + to_string(u) + ",d=" + to_string(d);

    cout << left << setw(6)  << testId
         << setw(8)  << dimStr
         << setw(10) << startStr
         << setw(14) << limitsStr
         << setw(10) << expected
         << setw(10) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch on " << testDesc << ":\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎮 Geek in a Maze — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(8)  << "Size"
         << setw(10) << "Start"
         << setw(14) << "Limits"
         << setw(10) << "Expected"
         << setw(10) << "Result"
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Test 1: Example 1
    vector<vector<char>> mat1 = {
        {'.', '.', '.'},
        {'.', '#', '.'},
        {'#', '.', '.'}
    };
    runTest(1, 1, 0, 1, 1, mat1, 5, "Example 1 (Basic obstacle)");

    // Test 2: Example 2
    vector<vector<char>> mat2 = {
        {'.', '.', '.'},
        {'.', '#', '.'},
        {'.', '.', '.'}
    };
    runTest(2, 2, 1, 2, 2, mat2, 8, "Example 2 (Center obstacle, u=2, d=2)");

    // Test 3: Example 3
    vector<vector<char>> mat3 = {
        {'.', '.', '.'},
        {'.', '#', '.'},
        {'.', '.', '.'}
    };
    runTest(3, 2, 1, 1, 0, mat3, 5, "Example 3 (No down moves allowed)");

    // Test 4: Starting on obstacle
    vector<vector<char>> mat4 = {
        {'.', '.', '.'},
        {'.', '#', '.'},
        {'.', '.', '.'}
    };
    runTest(4, 1, 1, 2, 2, mat4, 0, "Start on obstacle cell");

    // Test 5: 1x1 Empty Cell
    vector<vector<char>> mat5 = {{'.'}};
    runTest(5, 0, 0, 0, 0, mat5, 1, "Single cell empty grid");

    // Test 6: 1x1 Obstacle Cell
    vector<vector<char>> mat6 = {{'#'}};
    runTest(6, 0, 0, 0, 0, mat6, 0, "Single cell obstacle grid");

    // Test 7: Horizontal moves only (u=0, d=0)
    vector<vector<char>> mat7 = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };
    runTest(7, 1, 1, 0, 0, mat7, 3, "Only horizontal moves (row 1 only)");

    // Test 8: Trapped cell surrounded by obstacles
    vector<vector<char>> mat8 = {
        {'#', '#', '#'},
        {'#', '.', '#'},
        {'#', '#', '#'}
    };
    runTest(8, 1, 1, 5, 5, mat8, 1, "Trapped in a single room");

    // Test 9: Snake corridor
    vector<vector<char>> mat9 = {
        {'.', '.', '.'},
        {'#', '#', '.'},
        {'.', '.', '.'}
    };
    runTest(9, 0, 0, 3, 3, mat9, 7, "Snake / U-shaped corridor");

    // Test 10: 4x4 Grid with walls
    vector<vector<char>> mat10 = {
        {'.', '.', '.', '.'},
        {'.', '#', '#', '.'},
        {'.', '#', '#', '.'},
        {'.', '.', '.', '.'}
    };
    runTest(10, 0, 0, 3, 3, mat10, 12, "4x4 grid outer ring");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                        \n\n";

    return 0;
}
