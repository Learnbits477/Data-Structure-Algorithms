#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string queriesToString(const vector<vector<int>>& queries) {
    if (queries.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < queries.size(); ++i) {
        res += "[" + to_string(queries[i][0]) + ", " + to_string(queries[i][1]) + "]";
        if (i < queries.size() - 1) res += ", ";
    }
    res += "]";
    return res;
}

string expectedToString(const vector<int>& vec) {
    if (vec.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        res += to_string(vec[i]);
        if (i < vec.size() - 1) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, string s, vector<vector<int>> queries, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.sumAndMultiply(s, queries);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "S=\"" + s + "\", Q=" + queriesToString(queries);
    if (inputStr.length() > 45) {
        inputStr = inputStr.substr(0, 42) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(15) << expectedToString(expected)
         << setw(15) << expectedToString(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     String:   " << s << "\n"
             << "     Queries:  " << queriesToString(queries) << "\n"
             << "     Expected: " << expectedToString(expected) << "\n"
             << "     Got:      " << expectedToString(result) << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 162 - Concatenate Non-Zero Digits and Multiply by Sum II Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (String, Queries)" 
         << setw(15) << "Expected" 
         << setw(15) << "Actual" 
         << "Status\n";
    cout << string(95, '-') << "\n";

    runTest(1, "10203004", {{0, 7}, {1, 3}, {4, 6}}, {12340, 4, 9});
    runTest(2, "1000", {{0, 3}, {1, 1}}, {1, 0});
    runTest(3, "9876543210", {{0, 9}}, {444444137});
    runTest(4, "00000", {{0, 4}, {1, 3}}, {0, 0});
    runTest(5, "7", {{0, 0}}, {49});

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
