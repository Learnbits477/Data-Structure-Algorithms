#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string vectorToString(const vector<int>& vec) {
    string s = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        s += to_string(vec[i]);
        if (i < vec.size() - 1) s += ",";
    }
    s += "]";
    return s;
}

string boolVectorToString(const vector<bool>& vec) {
    string s = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        s += vec[i] ? "true" : "false";
        if (i < vec.size() - 1) s += ",";
    }
    s += "]";
    return s;
}

string queriesToString(const vector<vector<int>>& queries) {
    string s = "[";
    for (size_t i = 0; i < queries.size(); ++i) {
        s += "[" + to_string(queries[i][0]) + "," + to_string(queries[i][1]) + "]";
        if (i < queries.size() - 1) s += ",";
    }
    s += "]";
    return s;
}

void runTest(int testNum, vector<int> arr, vector<vector<int>> queries, vector<bool> expected) {
    Solution sol;
    
    vector<bool> result = sol.processQueries(arr, queries);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string arrStr = vectorToString(arr);
    if (arrStr.length() > 28) {
        arrStr = arrStr.substr(0, 25) + "...";
    }
    
    string queriesStr = queriesToString(queries);
    if (queriesStr.length() > 18) {
        queriesStr = queriesStr.substr(0, 15) + "...";
    }
    
    string expectedStr = boolVectorToString(expected);
    string actualStr = boolVectorToString(result);
    
    cout << left << setw(6)  << testId 
         << setw(30) << arrStr
         << setw(20) << queriesStr
         << setw(20) << expectedStr
         << setw(20) << actualStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << boolVectorToString(expected) << "\n"
             << "     Got:      " << boolVectorToString(result) << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 173 - Mountain Subarray Queries Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(30) << "Input Array" 
         << setw(20) << "Queries"
         << setw(20) << "Expected" 
         << setw(20) << "Actual" 
         << "Status\n";
    cout << string(105, '-') << "\n";

    // Test Case 1: Example 1 from GFG
    runTest(1, {2, 3, 2, 4, 4, 6, 3, 2}, {{0, 2}, {1, 3}}, {true, false});

    // Test Case 2: Example 2 from GFG
    runTest(2, {2, 2, 2, 2}, {{0, 2}, {1, 3}}, {true, true});

    // Test Case 3: Entirely non-decreasing array
    runTest(3, {1, 2, 3, 4, 5}, {{0, 4}, {1, 3}}, {true, true});

    // Test Case 4: Entirely non-increasing array
    runTest(4, {5, 4, 3, 2, 1}, {{0, 4}, {0, 2}}, {true, true});

    // Test Case 5: Single element subarray query
    runTest(5, {4, 5, 2}, {{1, 1}, {0, 0}}, {true, true});

    // Test Case 6: Valley shape array (decreasing then increasing)
    // subarray [0, 2] is [5, 2, 6], which is decreasing then increasing (not a mountain).
    // subarray [0, 1] is [5, 2] (non-increasing, is a mountain).
    // subarray [1, 2] is [2, 6] (non-decreasing, is a mountain).
    runTest(6, {5, 2, 6}, {{0, 2}, {0, 1}, {1, 2}}, {false, true, true});

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
