#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string edgesToString(const vector<vector<int>>& edges) {
    if (edges.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < edges.size(); ++i) {
        res += "[" + to_string(edges[i][0]) + "," + to_string(edges[i][1]) + "]";
        if (i < edges.size() - 1) res += ",";
    }
    res += "]";
    return res;
}

void runTest(int testNum, int n, const vector<vector<int>>& edges, int expected) {
    Solution sol;
    vector<vector<int>> edgesCopy = edges;
    int result = sol.countCompleteComponents(n, edgesCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "n=" + to_string(n) + ", edges=" + edgesToString(edges);
    if (inputStr.length() > 45) {
        inputStr = inputStr.substr(0, 42) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n:        " << n << "\n"
             << "     edges:    " << edgesToString(edges) << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 165 - Count the Number of Complete Components Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (n, edges)" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from description (all complete)
    runTest(1, 6, {{0,1},{0,2},{1,2},{3,4}}, 3);

    // Test Case 2: Example 2 from description (one complete, one incomplete)
    runTest(2, 6, {{0,1},{0,2},{1,2},{3,4},{3,5}}, 1);

    // Test Case 3: Empty edges (each node is a separate complete component of size 1)
    runTest(3, 4, {}, 4);

    // Test Case 4: Complete graph (1 component, complete)
    runTest(4, 4, {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}}, 1);

    // Test Case 5: Path graph (not complete for size > 2)
    runTest(5, 4, {{0,1},{1,2},{2,3}}, 0);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
