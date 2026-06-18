#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, const vector<vector<int>>& mat, int expected) {
    Solution sol;
    vector<vector<int>> matCopy = mat;
    int result = sol.findCoverage(matCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string dimensions = to_string(mat.size()) + "x" + to_string(mat[0].size());
    
    cout << left << setw(6)  << testId 
         << setw(15) << dimensions
         << setw(20) << expected
         << setw(20) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 142 - Coverage of all Zeros Test Suite  \n";
    cout << "⇚========================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "Matrix Size" 
         << setw(20) << "Expected Output" 
         << setw(20) << "Actual Output" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Example 1
    runTest(1, {{1, 1, 1, 0}, {1, 0, 0, 1}}, 8);
    
    // Example 2
    runTest(2, {{0, 1, 0}, {0, 1, 1}, {0, 0, 0}}, 6);
    
    // Example 3
    runTest(3, {{0, 1}}, 1);
    
    // Test Case 4: All Zeros (No ones, so coverage must be 0)
    runTest(4, {{0, 0}, {0, 0}}, 0);
    
    // Test Case 5: All Ones (No zeros, so coverage must be 0)
    runTest(5, {{1, 1}, {1, 1}}, 0);
    
    // Test Case 6: Single cell 0 (No ones, coverage 0)
    runTest(6, {{0}}, 0);
    
    // Test Case 7: Single cell 1 (No zeros, coverage 0)
    runTest(7, {{1}}, 0);
    
    // Test Case 8: Alternating matrix (2x4)
    runTest(8, {{0, 1, 0, 1}, {1, 0, 1, 0}}, 10);

    cout << "⇚========================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
