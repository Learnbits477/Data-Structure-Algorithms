#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatEdges(const vector<vector<int>>& edges) {
    if (edges.empty()) return "[]";
    if (edges.size() > 4) {
        stringstream ss;
        ss << "[[" << edges[0][0] << "," << edges[0][1] << "," << edges[0][2] << "], ..., ["
           << edges.back()[0] << "," << edges.back()[1] << "," << edges.back()[2] << "]]";
        return ss.str();
    }
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < edges.size(); ++i) {
        ss << "[" << edges[i][0] << "," << edges[i][1] << "," << edges[i][2] << "]"
           << (i + 1 < edges.size() ? ", " : "");
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, int n, vector<vector<int>> edges, int expected) {
    Solution sol;
    int result = sol.isNegativeWeightCycle(n, edges);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(6)  << n
         << setw(36) << formatEdges(edges)
         << setw(12) << (expected ? "1 (true)" : "0 (false)")
         << setw(12) << (result ? "1 (true)" : "0 (false)")
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎮 Negative Weight Cycle Detection — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(6)  << "V"
         << setw(36) << "Edges [u, v, w]"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(89, '-') << "\n";

    runTest(1, 4, {{0, 3, 6}, {1, 0, 4}, {1, 2, 6}, {3, 1, 2}}, 0);
    runTest(2, 4, {{1, 0, 4}, {3, 1, -2}, {1, 2, -6}, {2, 3, 5}}, 1);
    runTest(3, 2, {{0, 0, -5}}, 1);
    runTest(4, 2, {{0, 0, 10}}, 0);
    runTest(5, 5, {{0, 1, 4}, {1, 2, 3}, {3, 4, -7}, {4, 3, 2}}, 1);
    runTest(6, 5, {{0, 1, 4}, {1, 2, 3}, {3, 4, 7}, {4, 3, 2}}, 0);
    runTest(7, 4, {{0, 1, -2}, {1, 2, -3}, {2, 3, -4}, {0, 3, -10}}, 0);
    runTest(8, 3, {{0, 1, 3}, {1, 2, -1}, {2, 0, -2}}, 0);
    runTest(9, 3, {}, 0);
    runTest(10, 1, {}, 0);
    runTest(11, 6, {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {3, 4, 4}, {4, 5, -20}, {5, 0, 5}}, 1);

    cout << "※ ========================================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                                       \n\n";

    return 0;
}
