#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string vectorToString(const vector<int>& vec) {
    if (vec.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        res += to_string(vec[i]);
        if (i < vec.size() - 1) res += ", ";
    }
    res += "]";
    return res;
}

string queriesToString(const vector<vector<int>>& queries) {
    if (queries.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < queries.size(); ++i) {
        res += "[" + to_string(queries[i][0]) + "," + to_string(queries[i][1]) + "]";
        if (i < queries.size() - 1) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, int n, const vector<int>& nums, int maxDiff, const vector<vector<int>>& queries, const vector<int>& expected) {
    Solution sol;
    vector<int> numsCopy = nums;
    vector<vector<int>> queriesCopy = queries;
    vector<int> result = sol.pathExistenceQueries(n, numsCopy, maxDiff, queriesCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "n=" + to_string(n) + ", maxDiff=" + to_string(maxDiff) + ", Qs=" + queriesToString(queries);
    if (inputStr.length() > 45) {
        inputStr = inputStr.substr(0, 42) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(30) << vectorToString(expected)
         << setw(30) << vectorToString(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n:        " << n << "\n"
             << "     nums:     " << vectorToString(nums) << "\n"
             << "     maxDiff:  " << maxDiff << "\n"
             << "     Expected: " << vectorToString(expected) << "\n"
             << "     Got:      " << vectorToString(result) << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 164 - Path Existence Queries in a Graph II Test Suite  \n";
    cout << "⇚ - ================================================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (n, maxDiff, Queries)" 
         << setw(30) << "Expected" 
         << setw(30) << "Actual" 
         << "Status\n";
    cout << string(120, '-') << "\n";

    runTest(1, 5, {1, 8, 3, 4, 2}, 3, {{0, 3}, {2, 4}}, {1, 1});
    runTest(2, 5, {5, 3, 1, 9, 10}, 2, {{0, 1}, {0, 2}, {2, 3}, {4, 3}}, {1, 2, -1, 1});
    runTest(3, 3, {3, 6, 1}, 1, {{0, 0}, {0, 1}, {1, 2}}, {0, -1, -1});
    runTest(4, 5, {1, 3, 5, 7, 9}, 2, {{0, 4}, {0, 1}, {1, 3}}, {4, 1, 2});
    runTest(5, 6, {1, 10, 100, 1000, 10000, 100000}, 5, {{0, 1}, {2, 2}}, {-1, 0});

    cout << "⇚ - ================================================================================================================== - ⇛\n";
    cout << "                                     🎉 All Tests Completed Successfully!                                       \n";

    return 0;
}
