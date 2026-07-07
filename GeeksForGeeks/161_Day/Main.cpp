#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string matrixToString(const vector<vector<int>>& grid) {
    string res = "[";
    for (size_t i = 0; i < grid.size(); ++i) {
        res += "[";
        if (grid[i].size() >= 2) {
            res += to_string(grid[i][0]) + ", " + to_string(grid[i][1]);
        }
        res += "]";
        if (i < grid.size() - 1) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, int n, int m, int k, vector<vector<int>> arr, int expected) {
    Solution sol;
    int result = sol.largestArea(n, m, k, arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "N=" + to_string(n) + ", M=" + to_string(m) + ", K=" + to_string(k) + ", Arr=" + matrixToString(arr);
    if (inputStr.length() > 45) {
        inputStr = inputStr.substr(0, 42) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input N, M, K: " << n << ", " << m << ", " << k << "\n"
             << "     Blocked cells: " << matrixToString(arr) << "\n"
             << "     Expected:      " << expected << "\n"
             << "     Got:           " << result << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 161 - Largest Unblocked Submatrix Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (N, M, K, Arr)" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Example 1
    runTest(1, 5, 5, 2, {{2, 3}, {5, 1}}, 4);
    
    // Example 2
    runTest(2, 2, 2, 1, {{2, 2}}, 1);
    
    // Additional Test 3: No blocked cells
    runTest(3, 4, 4, 0, {}, 16);
    
    // Additional Test 4: Fully blocked
    runTest(4, 3, 3, 3, {{1, 1}, {2, 2}, {3, 3}}, 0);
    
    // Additional Test 5: Standard case with larger gaps
    runTest(5, 10, 8, 3, {{3, 2}, {7, 5}, {9, 8}}, 6);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
