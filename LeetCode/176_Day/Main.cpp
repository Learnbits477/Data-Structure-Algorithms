#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void runTest(int testNum, string s, vector<vector<int>> queries, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.maxActiveSections(s, queries);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string sStr = "\"" + s + "\"";
    if (sStr.length() > 20) {
        sStr = sStr.substr(0, 17) + "...\"";
    }
    
    // Format queries output
    string qStr = "[";
    for (size_t i = 0; i < min(queries.size(), (size_t)3); ++i) {
        qStr += "[" + to_string(queries[i][0]) + "," + to_string(queries[i][1]) + "]";
        if (i + 1 < queries.size()) qStr += ", ";
    }
    if (queries.size() > 3) qStr += "...";
    qStr += "]";
    
    // Format expected/result output
    string expStr = "[";
    for (size_t i = 0; i < min(expected.size(), (size_t)3); ++i) {
        expStr += to_string(expected[i]);
        if (i + 1 < expected.size()) expStr += ",";
    }
    if (expected.size() > 3) expStr += "...";
    expStr += "]";
    
    string resStr = "[";
    for (size_t i = 0; i < min(result.size(), (size_t)3); ++i) {
        resStr += to_string(result[i]);
        if (i + 1 < result.size()) resStr += ",";
    }
    if (result.size() > 3) resStr += "...";
    resStr += "]";
    
    cout << left << setw(6)  << testId 
         << setw(20) << sStr
         << setw(24) << qStr
         << setw(16) << expStr
         << setw(16) << resStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: ";
        for (int x : expected) cout << x << " ";
        cout << "\n     Got:      ";
        for (int x : result) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 176 - Maximize Active Section with Trade II Test Suite  \n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(20) << "String s" 
         << setw(24) << "Queries" 
         << setw(16) << "Expected" 
         << setw(16) << "Actual" 
         << "Status\n";
    cout << string(94, '-') << "\n";

    // Test Case 1: Example 1
    runTest(1, "01", {{0, 1}}, {1});

    // Test Case 2: Example 2
    runTest(2, "0100", {{0, 3}, {0, 2}, {1, 3}, {2, 3}}, {4, 3, 1, 1});

    // Test Case 3: Example 3
    runTest(3, "1000100", {{1, 5}, {0, 6}, {0, 4}}, {6, 7, 2});

    // Test Case 4: Example 4
    runTest(4, "01010", {{0, 3}, {1, 4}, {1, 3}}, {4, 4, 2});

    // Test Case 5: Single element '0'
    runTest(5, "0", {{0, 0}}, {0});

    // Test Case 6: Single element '1'
    runTest(6, "1", {{0, 0}}, {1});

    // Test Case 7: All 0s
    runTest(7, "00000", {{0, 4}, {1, 3}}, {0, 0});

    // Test Case 8: All 1s
    runTest(8, "11111", {{0, 4}, {1, 3}}, {5, 5});

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
