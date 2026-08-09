#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, const vector<vector<int>>& mat, int expected) {
    Solution sol;
    auto matCopy = mat;
    int n = mat.size();
    int result = sol.largestZigzag(n, matCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string dimensions = to_string(n) + "x" + to_string(n);
    
    cout << left << setw(6)  << testId 
         << setw(15) << dimensions
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
    cout << "\n🔢 Largest Zigzag Sequence — Test Suite\n";
    cout << "⇚ - ================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "Dimensions" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(65, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {{3, 1, 2}, {4, 8, 5}, {6, 9, 7}}, 18);

    // Test 2: Example 2
    runTest(2, {{1, 2, 4}, {3, 9, 6}, {11, 3, 15}}, 28);

    // Test 3: Trivial n = 1 case
    runTest(3, {{42}}, 42);

    // Test 4: Small n = 2 case
    runTest(4, {{5, 10}, {15, 20}}, 25);

    // Test 5: All same numbers
    runTest(5, {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}}, 15);

    // Test 6: Custom 4x4 matrix
    runTest(6, {
        {1, 5, 3, 2},
        {4, 2, 8, 1},
        {9, 6, 3, 7},
        {2, 5, 4, 8}
    }, 30);

    cout << "⇚ - ================================================================ - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
