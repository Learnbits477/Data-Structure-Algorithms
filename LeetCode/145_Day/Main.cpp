#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

string formatCosts(const vector<int>& costs) {
    if (costs.empty()) return "[]";
    if (costs.size() > 6) {
        return "[" + to_string(costs[0]) + "," + to_string(costs[1]) + "... (" + to_string(costs.size()) + " items)]";
    }
    string res = "[";
    for (size_t i = 0; i < costs.size(); ++i) {
        res += to_string(costs[i]);
        if (i + 1 < costs.size()) res += ",";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<int> costs, int coins, int expected) {
    Solution sol;
    vector<int> costsCopy = costs;
    int result = sol.maxIceCream(costsCopy, coins);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string costsStr = formatCosts(costs);
    
    cout << left << setw(6)  << testId 
         << setw(25) << costsStr
         << setw(12) << coins
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 145 - Maximum Ice Cream Bars Test Suite  \n";
    cout << "⇚=======================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Costs"
         << setw(12) << "Coins" 
         << setw(18) << "Expected Output" 
         << setw(18) << "Actual Output" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Example 1
    runTest(1, {1, 3, 2, 4, 1}, 7, 4);
    
    // Example 2
    runTest(2, {10, 6, 8, 7, 7, 8}, 5, 0);
    
    // Example 3
    runTest(3, {1, 6, 3, 1, 2, 5}, 20, 6);
    
    // Additional Test Cases
    runTest(4, {5, 10, 20}, 4, 0);
    runTest(5, {1, 1, 1, 1}, 3, 3);
    runTest(6, {1, 2, 3}, 100, 3);

    cout << "⇚=======================================================================================⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
