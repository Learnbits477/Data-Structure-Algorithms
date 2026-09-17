#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatEdges(const vector<vector<int>>& edges) {
    if (edges.empty()) return "[]";
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < edges.size(); ++i) {
        ss << "[" << edges[i][0] << "," << edges[i][1] << "]";
        if (i + 1 < edges.size()) ss << ",";
        if (ss.str().length() > 22 && i + 1 < edges.size()) {
            ss << "...]";
            return ss.str();
        }
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, int n, vector<vector<int>> edges, int src, int dst, int expected) {
    Solution sol;
    int result = sol.minimumEdgeReversal(edges, n, src, dst);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayEdges = formatEdges(edges);
    string endpoints = to_string(src) + "->" + to_string(dst);

    cout << left << setw(6)  << testId
         << setw(26) << displayEdges
         << setw(6)  << n
         << setw(10) << endpoints
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n:        " << n << "\n"
             << "     src->dst: " << endpoints << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔀 Min Edge Reversals for Path — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(26) << "Edges"
         << setw(6)  << "n"
         << setw(10) << "src->dst"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 -> Reverse edge 3->2 (1 reversal)
    runTest(1, 3, {{1, 2}, {3, 2}}, 1, 3, 1);

    // Test 2: Example 2 -> Direct path exists (0 reversals)
    runTest(2, 4, {{1, 2}, {2, 3}, {3, 4}}, 1, 4, 0);

    // Test 3: Source is Destination (0 reversals)
    runTest(3, 3, {{1, 2}, {2, 3}}, 2, 2, 0);

    // Test 4: Completely disconnected component (-1)
    runTest(4, 4, {{1, 2}}, 1, 4, -1);

    // Test 5: All edges in opposite direction (3 reversals)
    // 2->1, 3->2, 4->3. Path from 1 to 4 requires reversing all 3 edges
    runTest(5, 4, {{2, 1}, {3, 2}, {4, 3}}, 1, 4, 3);

    // Test 6: Cycle where 0-reversal path exists despite backwards shortcut
    // Path 1->2->3->4 costs 0; edge 4->1 if reversed costs 1. Min is 0.
    runTest(6, 4, {{1, 2}, {2, 3}, {3, 4}, {4, 1}}, 1, 4, 0);

    // Test 7: Star graph where edges point to center 1
    // Edges: 2->1, 3->1, 4->1. Path 2 to 4: 2->1 (cost 0) + 1->4 (cost 1 reversal) = 1
    runTest(7, 4, {{2, 1}, {3, 1}, {4, 1}}, 2, 4, 1);

    // Test 8: Two parallel paths: one with 2 reversals, one with 1 reversal
    // Path A: 1->2 (0), 3->2 (rev 1), 3->4 (0) => 1 reversal
    // Path B: 2->1 (rev 1), 4->2 (rev 1) => 2 reversals
    runTest(8, 4, {{1, 2}, {3, 2}, {3, 4}}, 1, 4, 1);

    // Test 9: Diamond graph with multiple paths
    // 1->2 (0), 1->3 (0), 4->2 (1), 4->3 (1) => path 1->2->4 costs 1 reversal
    runTest(9, 4, {{1, 2}, {1, 3}, {4, 2}, {4, 3}}, 1, 4, 1);

    // Test 10: Linear chain requiring 2 reversals
    // 1->2 (0), 3->2 (rev 1), 4->3 (rev 1) => 1->2->3->4 costs 2 reversals
    runTest(10, 4, {{1, 2}, {3, 2}, {4, 3}}, 1, 4, 2);

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
