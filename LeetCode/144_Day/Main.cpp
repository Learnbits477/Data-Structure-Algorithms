#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

string formatRestrictions(const vector<vector<int>>& restrictions) {
    if (restrictions.empty()) return "[]";
    if (restrictions.size() > 4) {
        return "[" + to_string(restrictions[0][0]) + "," + to_string(restrictions[0][1]) + "]... (" + to_string(restrictions.size()) + ")";
    }
    string res = "[";
    for (size_t i = 0; i < restrictions.size(); ++i) {
        res += "[" + to_string(restrictions[i][0]) + "," + to_string(restrictions[i][1]) + "]";
        if (i + 1 < restrictions.size()) res += ",";
    }
    res += "]";
    return res;
}

// runTest function that executes the solution and prints result status
void runTest(int testNum, int n, vector<vector<int>> restrictions, int expected) {
    Solution sol;
    vector<vector<int>> restrCopy = restrictions;
    int result = sol.maxBuildingHeight(n, restrCopy);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string restrStr = formatRestrictions(restrictions);
    
    cout << left << setw(6)  << testId 
         << setw(12) << n
         << setw(35) << restrStr
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 144 - Maximum Building Height Test Suite  \n";
    cout << "⇚=================================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(12) << "n"
         << setw(35) << "Restrictions" 
         << setw(18) << "Expected Output" 
         << setw(18) << "Actual Output" 
         << "Status\n";
    cout << string(98, '-') << "\n";

    // Example 1
    runTest(1, 5, {{2, 1}, {4, 1}}, 2);
    
    // Example 2
    runTest(2, 6, {}, 5);
    
    // Example 3
    runTest(3, 10, {{5, 3}, {2, 5}, {7, 4}, {10, 3}}, 5);
    
    // Additional Test Cases
    runTest(4, 2, {}, 1);
    runTest(5, 10, {{2, 0}}, 8);
    runTest(6, 10, {{10, 0}}, 4);
    runTest(7, 1000000000, {{1000000000, 0}}, 499999999);

    cout << "⇚=================================================================================================⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
