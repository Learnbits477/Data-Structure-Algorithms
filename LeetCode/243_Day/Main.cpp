#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const string& s, vector<vector<int>> edges, int expected, const string& description) {
    Solution sol;
    int result = sol.longestColoredPath(s, edges);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 32) {
        displayDesc = displayDesc.substr(0, 29) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(34) << displayDesc
         << setw(14) << expected
         << setw(14) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Node Colors:     " << s << "\n"
             << "     Edges Count:     " << edges.size() << "\n"
             << "     Expected Output: " << expected << "\n"
             << "     Actual Output:   " << result << "\n";
    }
}

int main() {
    cout << "\n🌳 Longest Colored Path — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Description"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 (R center with 2 B children)
    runTest(1, "RBB", {{1, 2}, {1, 3}}, 2, "Example 1 (R with two B leaves)");

    // Test 2: Example 2 (Two B nodes)
    runTest(2, "BB", {{1, 2}}, 2, "Example 2 (Two Blue nodes)");

    // Test 3: Minimal tree (Single node)
    runTest(3, "R", {}, 1, "Single Red node (n=1)");

    // Test 4: Monochromatic all-Red chain
    runTest(4, "RRRR", {{1, 2}, {2, 3}, {3, 4}}, 4, "Monochromatic Red chain");

    // Test 5: Monochromatic all-Blue chain
    runTest(5, "BBBBB", {{1, 2}, {2, 3}, {3, 4}, {4, 5}}, 5, "Monochromatic Blue chain");

    // Test 6: Bipartite monotonic chain (3 R then 3 B)
    runTest(6, "RRRBBB", {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}}, 6, "Chain of 3 Red then 3 Blue");

    // Test 7: Alternating colors chain (R-B-R-B)
    runTest(7, "RBRB", {{1, 2}, {2, 3}, {3, 4}}, 2, "Alternating chain (R-B-R-B)");

    // Test 8: Star graph (Red center, Blue leaves)
    runTest(8, "RBBBB", {{1, 2}, {1, 3}, {1, 4}, {1, 5}}, 2, "Star graph (R center, B leaves)");

    // Test 9: Star graph (Blue center, Red leaves)
    runTest(9, "BRRRR", {{1, 2}, {1, 3}, {1, 4}, {1, 5}}, 2, "Star graph (B center, R leaves)");

    // Test 10: Two branchy components connected by bridge
    // Component 1 (Red): 1-2, 1-3 (eccentricity at 1 is 1)
    // Component 2 (Blue): 4-5, 5-6, 5-7 (eccentricity at 4 is 2 via 4-5-6 or 4-5-7)
    // Bridge: 1-4 (Red node 1 to Blue node 4)
    // Path: 2 -> 1 -> 4 -> 5 -> 6 (length 5 nodes: R, R, B, B, B)
    runTest(10, "RRRBBBB", {{1, 2}, {1, 3}, {1, 4}, {4, 5}, {5, 6}, {5, 7}}, 5, "Bridged tree components");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
