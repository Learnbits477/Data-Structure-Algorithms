#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

// Helper to print test results
void runTest(int id, vector<vector<int>> grid, int x, int expected) {
    Solution sol;
    int result = sol.minOperations(grid, x);
    cout << "Test " << id << ": ";
    cout << (result == expected ? "[PASS]" : "[FAIL]");
    cout << "  Output = " << result << "  Expected = " << expected << "\n";
}

int main() {
    cout << "=== LeetCode 2033: Minimum Operations to Make a Uni-Value Grid ===\n\n";

    // Example 1 — Expected: 4
    runTest(1, {{2,4},{6,8}}, 2, 4);

    // Example 2 — Expected: 5
    runTest(2, {{1,5},{2,3}}, 1, 5);

    // Example 3 — Expected: -1 (impossible)
    runTest(3, {{1,2},{3,4}}, 2, -1);

    // Edge: single cell — Expected: 0
    runTest(4, {{7}}, 3, 0);

    // Edge: all same values — Expected: 0
    runTest(5, {{5,5},{5,5}}, 3, 0);

    cout << "\nDone.\n";
    return 0;
}
