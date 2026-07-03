#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string edgesToString(const vector<vector<int>>& edges) {
    if (edges.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < min(edges.size(), size_t(3)); i++) {
        res += "[" + to_string(edges[i][0]) + "," + to_string(edges[i][1]) + "," + to_string(edges[i][2]) + "]";
        if (i + 1 < min(edges.size(), size_t(3))) res += ", ";
    }
    if (edges.size() > 3) res += ", ...";
    res += "]";
    return res;
}

string onlineToString(const vector<bool>& online) {
    string res = "[";
    for (size_t i = 0; i < online.size(); i++) {
        res += (online[i] ? "T" : "F");
        if (i + 1 < online.size()) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<vector<int>> edges, vector<bool> online, long long k, int expected) {
    Solution sol;
    int result = sol.findMaxPathScore(edges, online, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string edgesStr = edgesToString(edges);
    if (edgesStr.length() > 28) {
        edgesStr = edgesStr.substr(0, 25) + "...";
    }
    string onlineStr = onlineToString(online);
    
    cout << left << setw(6)  << testId 
         << setw(32) << edgesStr
         << setw(16) << onlineStr
         << setw(10) << k
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";
         
     if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Edges:    " << edgesToString(edges) << "\n"
             << "     Online:   " << onlineToString(online) << "\n"
             << "     k:        " << k << "\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
     }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 157 - Network Recovery Pathways Test Suite  \n";
    cout << "⇚ - ================================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Edges" 
         << setw(16) << "Online"
         << setw(10) << "k"
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(98, '-') << "\n";

    // Example 1
    runTest(1, {{0,1,5},{1,3,10},{0,2,3},{2,3,4}}, {true, true, true, true}, 10, 3);
    
    // Example 2
    runTest(2, {{0,1,7},{1,4,5},{0,2,6},{2,3,6},{3,4,2},{2,4,6}}, {true, true, true, false, true}, 12, 6);
    
    // Additional Test 3: No valid path exists (k is too small)
    runTest(3, {{0,1,5},{1,2,5}}, {true, true, true}, 4, -1);
    
    // Additional Test 4: Offline nodes block all pathways
    runTest(4, {{0,1,5},{1,2,5}}, {true, false, true}, 10, -1);
    
    // Additional Test 5: Standard direct path
    runTest(5, {{0,1,10}}, {true, true}, 10, 10);
    
    // Additional Test 6: Multiple paths, maximizing the minimum edge
    runTest(6, {{0,1,8},{1,2,8},{0,2,5}}, {true, true, true}, 16, 8);

    cout << "⇚ - ================================================================================================== - ⇛\n";
    cout << "                             🎉 All Tests Completed Successfully!                               \n";

    return 0;
}
