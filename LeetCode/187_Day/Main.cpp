#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const vector<int>& piles, bool expected) {
    Solution sol;
    vector<int> pilesCopy = piles;
    bool result = sol.stoneGame(pilesCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string previewStr = "[";
    for (size_t i = 0; i < piles.size(); i++) {
        previewStr += to_string(piles[i]);
        if (i < piles.size() - 1) previewStr += ",";
    }
    previewStr += "]";
    if (previewStr.length() > 22) {
        previewStr = previewStr.substr(0, 19) + "...]";
    }

    cout << left << setw(6)  << testId 
         << setw(24) << previewStr
         << setw(12) << (result ? "true" : "false")
         << setw(12) << (expected ? "true" : "false")
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << (expected ? "true" : "false") << "\n"
             << "     Got:      " << (result ? "true" : "false") << "\n";
    }
}

int main() {
    cout << "\n🎮 Stone Game — Test Suite\n";
    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "Input Array" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(64, '-') << "\n";

    runTest(1, {5, 3, 4, 5}, true);
    runTest(2, {3, 7, 2, 3}, true);
    runTest(3, {1, 2}, true);
    runTest(4, {11, 100, 20, 200}, true);
    runTest(5, {2, 4, 6, 8, 10, 3}, true); 
    runTest(6, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, true); 

    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
