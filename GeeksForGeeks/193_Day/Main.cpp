#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, int n, const vector<vector<int>>& edges, int expected) {
    Solution sol;
    auto edgesCopy = edges;
    int result = sol.solve(n, edgesCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string edgesStr = "[" + to_string(edges.size()) + " edges]";
    
    cout << left << setw(6)  << testId 
         << setw(10) << to_string(n)
         << setw(15) << edgesStr
         << setw(12) << to_string(result)
         << setw(12) << to_string(expected)
         << status << "\n";
         
     if (!passed) {
          cout << "   ⚠️ Mismatch details:\n"
               << "     Expected: " << expected << "\n"
               << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n🌐 Connecting the Graph — Test Suite\n";
    cout << "⇚ - ================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(10) << "n" 
         << setw(15) << "Edges" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(65, '-') << "\n";

    // Test 1: Example 1
    runTest(1, 4, {{0, 1}, {0, 2}, {1, 2}}, 1);

    // Test 2: Example 2
    runTest(2, 6, {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}}, 2);

    // Test 3: Insufficient edges (m < n - 1)
    runTest(3, 4, {{0, 1}, {0, 2}}, -1);

    // Test 4: Already connected (spanning tree)
    runTest(4, 4, {{0, 1}, {0, 2}, {0, 3}}, 0);

    // Test 5: Multiple cycles with one isolated node
    runTest(5, 5, {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}}, 1);

    // Test 6: Highly disconnected, insufficient edges
    runTest(6, 5, {{0, 1}, {2, 3}}, -1);

    // Test 7: Single node graph (trivial case)
    runTest(7, 1, {}, 0);

    cout << "⇚ - ================================================================ - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
