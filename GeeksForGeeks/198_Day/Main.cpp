#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <climits>

using namespace std;

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == INT_MIN) {
            cout << "INF";
        } else {
            cout << vec[i];
        }
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

// Test runner function
void runTest(int testNum, int V, int src, vector<vector<int>> edges, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.maxDistance(V, src, edges);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(8)  << to_string(V)
         << setw(8)  << to_string(src)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: ";
        printVector(expected);
        cout << "\n     Got:      ";
        printVector(result);
        cout << "\n";
    }
}

int main() {
    cout << "\n🔢 Longest Path in a Directed Acyclic Graph — Test Suite\n";
    cout << "========================================================\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(8)  << "V" 
         << setw(8)  << "Source" 
         << "Status\n";
    cout << string(40, '-') << "\n";

    // Test 1: Example 1
    runTest(1, 4, 0, 
        {{0, 1, 1}, {0, 2, 1}, {1, 2, 5}, {3, 1, 2}, {3, 2, -1}}, 
        {0, 1, 6, INT_MIN}
    );

    // Test 2: Example 2
    runTest(2, 5, 1, 
        {{0, 1, 1}, {0, 2, 2}, {1, 4, 4}, {3, 2, -1}, {4, 2, 3}, {4, 3, 6}}, 
        {INT_MIN, 0, 9, 10, 4}
    );

    // Test 3: Edge Case (Single Vertex)
    runTest(3, 1, 0, 
        {}, 
        {0}
    );

    // Test 4: Edge Case (Disconnected Graph)
    runTest(4, 3, 1, 
        {}, 
        {INT_MIN, 0, INT_MIN}
    );

    // Test 5: Complex DAG with Negative/Positive weights
    runTest(5, 6, 0, 
        {{0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 2, 2}, {2, 4, 4}, {2, 5, 2}, {3, 4, -1}, {3, 5, 1}, {4, 5, -2}}, 
        {0, 5, 7, 11, 11, 12}
    );

    cout << "========================================================\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
