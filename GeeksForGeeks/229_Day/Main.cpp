#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string formatGraph(int n, const vector<vector<int>>& adj) {
    string s = "N=" + to_string(n) + ", adj=[";
    for (size_t i = 0; i < adj.size(); i++) {
        s += "{";
        for (size_t j = 0; j < adj[i].size(); j++) {
            s += to_string(adj[i][j]);
            if (j + 1 < adj[i].size()) s += ",";
        }
        s += "}";
        if (i + 1 < adj.size()) s += ", ";
        if (s.length() > 28 && i + 1 < adj.size()) {
            s += "...]";
            return s;
        }
    }
    s += "]";
    return s;
}

void runTest(int testNum, int n, vector<vector<int>> adj, int expected) {
    Solution sol;
    int result = sol.partyHouse(n, adj);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(36) << formatGraph(n, adj)
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n        = " << n << "\n"
             << "     Expected = " << expected << "\n"
             << "     Got      = " << result << "\n";
    }
}

int main() {
    cout << "\n🏘️ Party in Town — Test Suite\n";
    cout << "※ ========================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(36) << "Tree / Adjacency"
         << setw(12) << "Result"
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(74, '-') << "\n";

    // Test 1: Example 1 - Star graph centered at 2: adj = [[2], [1, 4, 3], [2], [2]] -> 1
    runTest(1, 4, {{2}, {1, 4, 3}, {2}, {2}}, 1);

    // Test 2: Example 2 - Line graph: 1 - 2 - 3 - 4 -> 2
    runTest(2, 4, {{2}, {1, 3}, {4, 2}, {3}}, 2);

    // Test 3: Single node tree: N = 1 -> 0
    runTest(3, 1, {{}}, 0);

    // Test 4: Two nodes: 1 - 2 -> 1
    runTest(4, 2, {{2}, {1}}, 1);

    // Test 5: Line graph with 5 nodes: 1 - 2 - 3 - 4 - 5 -> 2
    runTest(5, 5, {{2}, {1, 3}, {2, 4}, {3, 5}, {4}}, 2);

    // Test 6: Star graph with 5 leaves centered at node 3 -> 1
    runTest(6, 6, {{3}, {3}, {1, 2, 4, 5, 6}, {3}, {3}, {3}}, 1);

    // Test 7: Symmetrical binary tree of height 2 (7 nodes) -> 2
    // 1 connected to 2, 3; 2 connected to 4, 5; 3 connected to 6, 7
    runTest(7, 7, {{2, 3}, {1, 4, 5}, {1, 6, 7}, {2}, {2}, {3}, {3}}, 2);

    // Test 8: Path of 6 nodes: 1 - 2 - 3 - 4 - 5 - 6 -> 3
    runTest(8, 6, {{2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}, {5}}, 3);

    cout << "※ ========================================================================= ※\n";
    cout << "                         🎉 All Tests Executed!                             \n\n";

    return 0;
}
