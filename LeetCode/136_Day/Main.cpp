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

// Utility to print queries
void printQueries(const vector<vector<int>>& queries) {
    cout << "[";
    for (size_t i = 0; i < queries.size(); ++i) {
        cout << "[" << queries[i][0] << "," << queries[i][1] << "]";
        if (i < queries.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Utility to print vector output
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]";
}

// Function to run a test case and print results
void runTest(int testId, vector<vector<int>> edges, vector<vector<int>> queries, vector<int> expected) {
    Solution solver;
    vector<int> actual = solver.assignEdgeWeights(edges, queries);
    
    bool passed = (actual == expected);
    
    cout << "Test Case " << testId << ":\n";
    cout << "  Input edges:   ";
    printEdges(edges);
    cout << "\n";
    cout << "  Queries:       ";
    printQueries(queries);
    cout << "\n";
    cout << "  Expected:      ";
    printVector(expected);
    cout << "\n";
    if (passed) {
        cout << "  Status:        ✅ PASSED\n";
    } else {
        cout << "  Actual:        ";
        printVector(actual);
        cout << "\n";
        cout << "  Status:        ❌ FAILED\n";
    }
    cout << "---------------------------------------------------------\n";
}

int main() {
    cout << "\n🔢 Number of Ways to Assign Edge Weights II — Test Suite\n";
    cout << "=========================================================\n" << endl;
    
    // Example 1
    runTest(1, {{1, 2}}, {{1, 1}, {1, 2}}, {0, 1});
    
    // Example 2
    runTest(2, {{1, 2}, {1, 3}, {3, 4}, {3, 5}}, {{1, 4}, {3, 4}, {2, 5}}, {2, 1, 4});
    
    // Additional Test Case 3: Line tree with self loop queries
    runTest(3, {{1, 2}, {2, 3}, {3, 4}}, {{1, 4}, {2, 2}, {3, 1}}, {4, 0, 2});
    
    // Additional Test Case 4: Complete binary tree lookalike
    runTest(4, {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}}, {{4, 5}, {5, 6}, {7, 7}}, {2, 8, 0});

    return 0;
}
