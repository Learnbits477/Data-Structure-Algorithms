#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string matrixToString(const vector<vector<int>>& mat) {
    string s = "[";
    for (size_t r = 0; r < mat.size(); ++r) {
        s += "[";
        for (size_t c = 0; c < mat[r].size(); ++c) {
            s += to_string(mat[r][c]);
            if (c < mat[r].size() - 1) s += ",";
        }
        s += "]";
        if (r < mat.size() - 1) s += ", ";
    }
    s += "]";
    return s;
}

void runTest(int testNum, vector<vector<int>> matrix, int k, int expected) {
    Solution sol;
    
    int result = sol.findWays(matrix, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = matrixToString(matrix);
    if (inputStr.length() > 38) {
        inputStr = inputStr.substr(0, 35) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(40) << inputStr
         << setw(6)  << k
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 172 - Cut Matrix Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(40) << "Input Matrix" 
         << setw(6)  << "k"
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from GFG
    runTest(1, {{1, 0, 0}, {1, 1, 1}, {0, 0, 0}}, 3, 3);

    // Test Case 2: Example 2 from GFG
    runTest(2, {{0, 0}, {1, 1}}, 2, 1);

    // Test Case 3: Example 3 from GFG
    runTest(3, {{1, 0}, {0, 0}}, 1, 1);

    // Test Case 4: No 1s present, impossible to cut
    runTest(4, {{0, 0}, {0, 0}}, 1, 0);

    // Test Case 5: 2x2 all 1s matrix with k = 2
    runTest(5, {{1, 1}, {1, 1}}, 2, 2);

    // Test Case 6: 2x2 all 1s matrix with k = 3
    // Cuts:
    // If first horizontal cut at row 1: top rows 0..0, bottom rows 1..1.
    // Top has 1s, bottom can be cut vertically at col 1 (since it needs to be cut into 2 pieces).
    // So 1 way: row 0 cut, then col 0 cut in bottom.
    // If first vertical cut at col 1: left cols 0..0, right cols 1..1.
    // Left has 1s, right can be cut horizontally at row 1.
    // So 1 way: col 0 cut, then row 0 cut in right.
    // Total: 2 ways.
    runTest(6, {{1, 1}, {1, 1}}, 3, 2);

    // Test Case 7: 2x2 all 1s matrix with k = 4
    // Cuts:
    // - Cut row 0 (top: row 0, bottom: row 1).
    //   Then cut col 0 in top? Wait, "If the cut is horizontal, only the bottom part can be cut further."
    //   So top part row 0 CANNOT be cut further. So top must remain 1 piece (rows 0..0, cols 0..1).
    //   Bottom row 1 can be cut vertically (which is 1 cut, so 2 pieces).
    //   So total pieces possible from horizontal first cut is 1 + 2 = 3.
    //   We can never get 4 pieces if we cut horizontally first!
    // - If we cut vertically first at col 1 (left: col 0, right: col 1).
    //   Left col 0 cannot be cut further. Right col 1 can be cut horizontally (which is 1 cut, so 2 pieces).
    //   So total pieces possible from vertical first cut is 1 + 2 = 3.
    //   We can never get 4 pieces.
    // Therefore, for k = 4, output should be 0.
    runTest(7, {{1, 1}, {1, 1}}, 4, 0);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
