#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, int V, vector<vector<int>> edges, int src, int dest, int expected) {
    Solution sol;
    int result = sol.shortestPath(V, src, dest, edges);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string pathStr = to_string(src) + " ➜ " + to_string(dest);
    
    cout << left << setw(6)  << testId 
         << setw(10) << V
         << setw(12) << edges.size()
         << setw(16) << pathStr
         << setw(12) << (result == -1 ? "-1" : to_string(result))
         << setw(12) << (expected == -1 ? "-1" : to_string(expected))
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Shortest Path in 1-2 Graph — Test Suite\n";
    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(10) << "Vertices" 
         << setw(12) << "Edges Count" 
         << setw(16) << "Path Query" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1
    runTest(1, 4, {{0, 1, 1}, {0, 2, 2}, {2, 3, 1}, {1, 2, 1}, {1, 3, 2}}, 0, 3, 3);
    
    // Example 2
    runTest(2, 5, {{0, 1, 1}, {0, 2, 2}, {1, 2, 1}, {3, 4, 2}}, 1, 3, -1);
    
    // Example 3
    runTest(3, 5, {{1, 0, 1}, {0, 3, 2}, {1, 3, 1}, {1, 2, 2}, {2, 3, 2}, {3, 4, 1}, {2, 4, 1}}, 1, 4, 2);
    
    // Edge Case: Source is same as Destination
    runTest(4, 3, {{0, 1, 1}, {1, 2, 2}}, 1, 1, 0);
    
    // Edge Case: Simple direct weight-2 path vs two weight-1 paths
    runTest(5, 3, {{0, 1, 2}, {0, 2, 1}, {2, 1, 1}}, 0, 1, 2);
    
    // Edge Case: Multi-step weight-2 paths
    runTest(6, 4, {{0, 1, 2}, {1, 2, 2}, {2, 3, 2}}, 0, 3, 6);

    // Edge Case: Disconnected component query
    runTest(7, 6, {{0, 1, 1}, {1, 2, 2}, {3, 4, 1}, {4, 5, 2}}, 0, 5, -1);

    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
