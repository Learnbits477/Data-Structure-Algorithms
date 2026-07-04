#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string roadsToString(const vector<vector<int>>& roads) {
    if (roads.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < min(roads.size(), size_t(3)); i++) {
        res += "[" + to_string(roads[i][0]) + "," + to_string(roads[i][1]) + "," + to_string(roads[i][2]) + "]";
        if (i + 1 < min(roads.size(), size_t(3))) res += ", ";
    }
    if (roads.size() > 3) res += ", ...";
    res += "]";
    return res;
}

void runTest(int testNum, int n, vector<vector<int>> roads, int expected) {
    Solution sol;
    int result = sol.minScore(n, roads);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string roadsStr = roadsToString(roads);
    if (roadsStr.length() > 38) {
        roadsStr = roadsStr.substr(0, 35) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(8)  << n
         << setw(40) << roadsStr
         << setw(14) << expected
         << setw(14) << result
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     n:        " << n << "\n"
             << "     Roads:    " << roadsToString(roads) << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 158 - Minimum Score of a Path Between Two Cities Test Suite  \n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(8)  << "n" 
         << setw(40) << "Roads"
         << setw(14) << "Expected" 
         << setw(14) << "Actual" 
         << "Status\n";
    cout << string(92, '-') << "\n";

    // Example 1
    runTest(1, 4, {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}}, 5);
    
    // Example 2
    runTest(2, 4, {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}}, 2);
    
    // Additional Test 3: Disconnected graph components
    // Node 1 is connected to 2 (dist 10) and 3 (dist 8). Node 4 is connected to 5.
    runTest(3, 5, {{1, 2, 10}, {2, 3, 8}, {4, 5, 2}}, 8);
    
    // Additional Test 4: Single line path
    runTest(4, 3, {{1, 2, 6}, {2, 3, 3}}, 3);
    
    // Additional Test 5: Multiple alternate routes
    runTest(5, 4, {{1, 2, 100}, {2, 3, 200}, {3, 4, 300}, {1, 4, 150}}, 100);

    // Additional Test 6: Cycle with a very small edge distance
    runTest(6, 4, {{1, 2, 20}, {2, 3, 30}, {3, 4, 40}, {2, 4, 1}}, 1);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                             🎉 All Tests Completed Successfully!                               \n";

    return 0;
}
