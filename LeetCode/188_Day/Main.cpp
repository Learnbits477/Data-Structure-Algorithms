#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const vector<int>& stoneValue, const string& expected) {
    Solution sol;
    vector<int> stonesCopy = stoneValue;
    string result = sol.stoneGameIII(stonesCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string previewStr = "[";
    for (size_t i = 0; i < stoneValue.size(); i++) {
        previewStr += to_string(stoneValue[i]);
        if (i < stoneValue.size() - 1) previewStr += ",";
    }
    previewStr += "]";
    if (previewStr.length() > 22) {
        previewStr = previewStr.substr(0, 19) + "...]";
    }

    cout << left << setw(6)  << testId 
         << setw(24) << previewStr
         << setw(12) << result
         << setw(12) << expected
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎮 Stone Game III — Test Suite\n";
    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "Stone Values" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(64, '-') << "\n";

    runTest(1, {1, 2, 3, 7}, "Bob");
    runTest(2, {1, 2, 3, -9}, "Alice");
    runTest(3, {1, 2, 3, 6}, "Tie");
    runTest(4, {1, 2, 3, 4, 5}, "Bob");
    runTest(5, {-1, -2, -3}, "Tie");
    runTest(6, {-1, -2, -3, -4}, "Tie");

    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
