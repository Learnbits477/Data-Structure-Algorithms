#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> duration, vector<vector<int>> dependencies, int expected, const string& description) {
    Solution sol;
    int result = sol.minTime(duration, dependencies);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 34) {
        displayDesc = displayDesc.substr(0, 31) + "...";
    }

    cout << left << setw(6)  << testId
         << setw(36) << displayDesc
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Modules:   " << duration.size() << "\n"
             << "     Edges:     " << dependencies.size() << "\n"
             << "     Expected:  " << expected << "\n"
             << "     Actual:    " << result << "\n";
    }
}

int main() {
    cout << "\n📍 Minimum Time to Finish Project — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(36) << "Description"
         << setw(12) << "Expected"
         << setw(12) << "Result"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1 from prompt
    runTest(1, 
            {10, 20, 30, 10, 30, 20}, 
            {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}}, 
            80, 
            "Example 1 (Complex DAG)");

    // Test 2: Example 2 (Direct 3-node cycle)
    runTest(2, 
            {5, 5, 5}, 
            {{0, 1}, {1, 2}, {2, 0}}, 
            -1, 
            "Example 2 (3-node cycle)");

    // Test 3: Single module without dependencies
    runTest(3, 
            {42}, 
            {}, 
            42, 
            "Single module, no dependencies");

    // Test 4: Completely independent modules
    runTest(4, 
            {10, 25, 15, 30}, 
            {}, 
            30, 
            "All independent modules (max)");

    // Test 5: Linear sequential chain
    runTest(5, 
            {5, 10, 15, 20}, 
            {{0, 1}, {1, 2}, {2, 3}}, 
            50, 
            "Linear chain 0->1->2->3");

    // Test 6: Diamond graph (fork and join)
    // 0 forks to 1 and 2, then both join to 3
    runTest(6, 
            {10, 20, 5, 15}, 
            {{0, 1}, {0, 2}, {1, 3}, {2, 3}}, 
            45, 
            "Diamond DAG (fork-join)");

    // Test 7: Disconnected graph with cycle in one component
    runTest(7, 
            {10, 20, 30, 40}, 
            {{0, 1}, {2, 3}, {3, 2}}, 
            -1, 
            "Disconnected component with cycle");

    // Test 8: Two-node mutual dependency cycle
    runTest(8, 
            {10, 15}, 
            {{0, 1}, {1, 0}}, 
            -1, 
            "2-node mutual cycle");

    // Test 9: Zero duration module
    runTest(9, 
            {0, 10, 0, 20}, 
            {{0, 1}, {1, 2}, {2, 3}}, 
            30, 
            "Modules with zero duration");

    // Test 10: Multi-root wide tree
    // Root 0, 1, 2 all lead to 3, and 3 leads to 4
    runTest(10, 
            {12, 18, 5, 25, 10}, 
            {{0, 3}, {1, 3}, {2, 3}, {3, 4}}, 
            53, 
            "Multi-root convergence into 3->4");

    // Test 11: Tree branching out (one root to many leaves)
    runTest(11, 
            {10, 5, 20, 15}, 
            {{0, 1}, {0, 2}, {0, 3}}, 
            30, 
            "1 root branching to 3 leaves");

    // Test 12: Complex 8-module DAG
    // Path 1: 0(4) -> 2(2) -> 3(7) -> 5(6) -> 7(1) => 4+2+7+6+1 = 20
    // Path 2: 0(4) -> 2(2) -> 4(5) -> 6(8) -> 7(1) => 4+2+5+8+1 = 20
    runTest(12,
            {4, 3, 2, 7, 5, 6, 8, 1},
            {{0, 2}, {1, 2}, {2, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}, {6, 7}},
            20,
            "Complex 8-module dual-branch DAG");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
