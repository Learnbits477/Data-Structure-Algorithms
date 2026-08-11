#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, vector<vector<int>> mat, vector<vector<int>> queries, int k, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.largestSquare(mat, queries, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(10) << to_string(queries.size())
         << setw(12) << to_string(k)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: [";
        for (size_t i = 0; i < expected.size(); ++i) {
            cout << expected[i] << (i + 1 < expected.size() ? ", " : "");
        }
        cout << "]\n     Got:      [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << (i + 1 < result.size() ? ", " : "");
        }
        cout << "]\n";
    }
}

int main() {
    cout << "\n🔢 Largest Odd Squares with Limited 1s — Test Suite\n";
    cout << "⇚ - ============================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(10) << "Queries" 
         << setw(12) << "K" 
         << "Status\n";
    cout << string(40, '-') << "\n";

    // Test 1: Example 1
    runTest(1, 
        {{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}}, 
        {{1, 2}}, 
        9, 
        {3}
    );

    // Test 2: Example 2
    runTest(2, 
        {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 
        {{1, 1}, {2, 2}}, 
        9, 
        {3, 1}
    );

    // Test 3: Edge Case (Center cell = 1, k = 0) -> Should return -1
    runTest(3, 
        {{1, 0}, {0, 0}}, 
        {{0, 0}}, 
        0, 
        {-1}
    );

    // Test 4: Edge Case (Center cell = 0, k = 0) -> Should return 1
    runTest(4, 
        {{1, 0}, {0, 0}}, 
        {{1, 1}}, 
        0, 
        {1}
    );

    // Test 5: Multiple Queries on a uniform matrix with boundary limits
    runTest(5, 
        {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}, 
        {{1, 1}, {1, 2}, {2, 1}, {2, 2}}, 
        9, 
        {3, 3, 3, 3}
    );

    // Test 6: Queries with k smaller than full expansion
    runTest(6, 
        {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}, 
        {{1, 1}, {1, 2}, {2, 1}, {2, 2}}, 
        4, 
        {1, 1, 1, 1}
    );

    cout << "⇚ - ============================================== - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
