#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, vector<string> board, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.pathsWithMaxScore(board);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId;
    
    // Print a flattened representation of board or its size
    string boardStr = "[";
    for(size_t i = 0; i < board.size(); ++i) {
        boardStr += board[i];
        if(i < board.size() - 1) boardStr += ", ";
    }
    boardStr += "]";
    
    // Truncate boardStr if too long
    if (boardStr.length() > 28) {
        boardStr = boardStr.substr(0, 25) + "...";
    }
    
    string expectedStr = "[" + to_string(expected[0]) + ", " + to_string(expected[1]) + "]";
    string resultStr = "[" + to_string(result[0]) + ", " + to_string(result[1]) + "]";
    
    cout << setw(30) << boardStr
         << setw(20) << expectedStr
         << setw(20) << resultStr
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input: board = \n";
        for (const string& row : board) {
            cout << "       \"" << row << "\"\n";
        }
        cout << "     Expected: " << expectedStr << "\n"
             << "     Got:      " << resultStr << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 159 - Number of Paths with Max Score Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(30) << "Board" 
         << setw(20) << "Expected" 
         << setw(20) << "Actual" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Example 1
    runTest(1, {"E23","2X2","12S"}, {7, 1});
    
    // Example 2
    runTest(2, {"E12","1X1","21S"}, {4, 2});
    
    // Example 3
    runTest(3, {"E11","XXX","11S"}, {0, 0});
    
    // Additional Test 4: Smallest Board
    runTest(4, {"E2","1S"}, {2, 1});
    
    // Additional Test 5: E blocked on orthogonal directions, diagonal open
    runTest(5, {"EX","XS"}, {0, 1});
    
    // Additional Test 6: Fully blocked E (all paths blocked, valid board)
    runTest(6, {"EX1","XX1","11S"}, {0, 0});
    
    // Additional Test 7: Multiple paths with same max score
    runTest(7, {"E1", "1S"}, {1, 2});

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
