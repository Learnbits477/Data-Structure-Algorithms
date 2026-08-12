#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, vector<vector<int>> grid, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.findWays(grid);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(12) << to_string(grid.size())
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: [" << expected[0] << ", " << expected[1] << "]\n"
             << "     Got:      [" << result[0] << ", " << result[1] << "]\n";
    }
}

int main() {
    cout << "\n🔢 Adventure in a Maze — Test Suite\n";
    cout << "⇐ - ================================ - ⇒\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(12) << "Size (N)" 
         << "Status\n";
    cout << string(40, '-') << "\n";

    // Test 1: Example 1
    runTest(1, 
        {{3, 2}, 
         {1, 3}}, 
        {2, 8}
    );

    // Test 2: Example 2
    runTest(2, 
        {{1, 1, 3, 2, 1}, 
         {3, 2, 2, 1, 2}, 
         {1, 3, 3, 1, 3}, 
         {1, 2, 3, 1, 2}, 
         {1, 1, 1, 3, 1}}, 
        {4, 18}
    );

    // Test 3: Edge Case (1x1 Grid)
    runTest(3, 
        {{3}}, 
        {1, 3}
    );

    // Test 4: Edge Case (Unreachable Exit)
    runTest(4, 
        {{2, 2}, 
         {2, 2}}, 
        {0, 0}
    );

    // Test 5: Simple path grid
    runTest(5,
        {{1, 2},
         {2, 1}},
        {1, 4}
    );

    cout << "⇐ - ==================================- ⇒\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
