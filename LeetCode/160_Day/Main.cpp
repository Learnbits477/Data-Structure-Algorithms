#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string intervalsToString(const vector<vector<int>>& intervals) {
    string res = "[";
    for (size_t i = 0; i < intervals.size(); ++i) {
        res += "[" + to_string(intervals[i][0]) + "," + to_string(intervals[i][1]) + "]";
        if (i < intervals.size() - 1) res += ",";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<vector<int>> intervals, int expected) {
    Solution sol;
    vector<vector<int>> origIntervals = intervals; 
    int result = sol.removeCoveredIntervals(intervals);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = intervalsToString(origIntervals);
    if (inputStr.length() > 42) {
        inputStr = inputStr.substr(0, 39) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(42) << inputStr
         << setw(15) << expected
         << setw(15) << result
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input: " << intervalsToString(origIntervals) << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 160 - Remove Covered Intervals Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(42) << "Intervals Input" 
         << setw(15) << "Expected" 
         << setw(15) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Example 1
    runTest(1, {{1,4},{3,6},{2,8}}, 2);
    
    // Example 2
    runTest(2, {{1,4},{2,3}}, 1);
    
    // Additional Test 3: Multiple intervals covering each other
    runTest(3, {{1,10},{2,8},{3,6},{4,5}}, 1);
    
    // Additional Test 4: Disjoint intervals (none covered)
    runTest(4, {{1,2},{3,4},{5,6}}, 3);
    
    // Additional Test 5: Duplicate start points with varying end points
    runTest(5, {{1,2},{1,3},{1,4}}, 1);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
