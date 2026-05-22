#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

// Utility function to print a 2D matrix
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        cout << "     [";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i] << (i + 1 < row.size() ? ", " : "");
        }
        cout << "]\n";
    }
}

void runTest(int testId, vector<vector<int>> grid, int expected) {
    Solution solver;
    
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input Grid:\n";
    printGrid(grid);
    
    int actual = solver.cntOnes(grid);
    cout << "   Expected: " << expected << "\n";
    cout << "   Actual:   " << actual << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 115] 1s Surrounded by 0s — Test Suite 🚀\n";
    
    // Example 1
    vector<vector<int>> grid1 = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    runTest(1, grid1, 3);
    
    // Example 2
    vector<vector<int>> grid2 = {
        {1, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0, 1}
    };
    runTest(2, grid2, 6);
    
    // Example 3: Completely surrounded 1 in a 3x3 grid
    vector<vector<int>> grid3 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    runTest(3, grid3, 1);
    
    // Example 4: All 1s grid (all reach the boundary, so no enclaves)
    vector<vector<int>> grid4 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    runTest(4, grid4, 0);

    // Example 5: Single element 1 (is on boundary, so 0 enclaves)
    vector<vector<int>> grid5 = {
        {1}
    };
    runTest(5, grid5, 0);

    // Example 6: Single element 0 (no enclaves)
    vector<vector<int>> grid6 = {
        {0}
    };
    runTest(6, grid6, 0);
    
    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
