#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string vecToString(const vector<int>& vec) {
    vector<int> sortedVec = vec;
    sort(sortedVec.begin(), sortedVec.end());
    string s = "[";
    for (size_t i = 0; i < sortedVec.size(); ++i) {
        s += to_string(sortedVec[i]);
        if (i < sortedVec.size() - 1) s += ",";
    }
    s += "]";
    return s;
}

void runTest(int testNum, int n, int k, const vector<vector<int>>& invocations, const vector<int>& expected) {
    Solution sol;
    vector<vector<int>> invCopy = invocations;
    vector<int> result = sol.remainingMethods(n, k, invCopy);
    
    // Sort results to compare and display deterministically
    vector<int> sortedResult = result;
    sort(sortedResult.begin(), sortedResult.end());
    vector<int> sortedExpected = expected;
    sort(sortedExpected.begin(), sortedExpected.end());
    
    bool passed = (sortedResult == sortedExpected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string inputStr = "n=" + to_string(n) + ", k=" + to_string(k);
    string resultStr = vecToString(result);
    if (resultStr.length() > 22) {
        resultStr = resultStr.substr(0, 19) + "...]";
    }
    
    string expectedStr = vecToString(expected);
    if (expectedStr.length() > 22) {
        expectedStr = expectedStr.substr(0, 19) + "...]";
    }
    
    cout << left << setw(6)  << testId 
         << setw(20) << inputStr
         << setw(24) << resultStr
         << setw(24) << expectedStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << vecToString(expected) << "\n"
             << "     Got:      " << vecToString(result) << "\n";
    }
}

int main() {
    cout << "\n🔢 [3310. Remove Methods From Project] — Test Suite\n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(20) << "Params" 
         << setw(24) << "Result" 
         << setw(24) << "Expected" 
         << "Status\n";
    cout << string(86, '-') << "\n";

    runTest(1, 4, 1, {{1, 2}, {0, 1}, {3, 2}}, {0, 1, 2, 3});
    runTest(2, 5, 0, {{1, 2}, {0, 2}, {0, 1}, {3, 4}}, {3, 4});
    runTest(3, 3, 2, {{1, 2}, {0, 1}, {2, 0}}, {});
    runTest(4, 4, 3, {}, {0, 1, 2}); 
    runTest(5, 4, 1, {{1, 2}, {2, 3}}, {0}); 

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
