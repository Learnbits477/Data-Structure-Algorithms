#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Utility to print edges
void printEdges(const vector<vector<int>>& edges) {
    cout << "[";
    for (size_t i = 0; i < edges.size(); ++i) {
        cout << "[" << edges[i][0] << "," << edges[i][1] << "]";
        if (i < edges.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Function to run a test case and print results
void runTest(int testId, vector<vector<int>> edges, int expected) {
    Solution solver;
    int actual = solver.assignEdgeWeights(edges);
    
    bool passed = (actual == expected);
    
    cout << "Test Case " << testId << ":\n";
    cout << "  Input edges: ";
    printEdges(edges);
    cout << "\n";
    cout << "  Expected: " << expected << "\n";
    if (passed) {
        cout << "  Status:   ✅ PASSED\n";
    } else {
        cout << "  Actual:   " << actual << "\n";
        cout << "  Status:   ❌ FAILED\n";
    }
    cout << "-------------------------------------------\n";
}

int main() {
    cout << "\n🔢 Number of Ways to Assign Edge Weights I — Test Suite\n";
    cout << "===========================================\n" << endl;
    
    // Example 1
    runTest(1, {{1, 2}}, 1);
    
    // Example 2
    runTest(2, {{1, 2}, {1, 3}, {3, 4}, {3, 5}}, 2);
    
    // Additional Test Case 3: Star Graph (depth 1)
    runTest(3, {{1, 2}, {1, 3}, {1, 4}}, 1);
    
    // Additional Test Case 4: Path Graph (depth 3)
    runTest(4, {{1, 2}, {2, 3}, {3, 4}}, 4);

    return 0;
}
