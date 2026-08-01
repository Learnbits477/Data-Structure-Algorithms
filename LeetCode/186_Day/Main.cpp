#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, const vector<int>& nums, bool expected) {
    Solution sol;
    vector<int> numsCopy = nums;
    bool result = sol.predictTheWinner(numsCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string previewStr = "[";
    for (size_t i = 0; i < nums.size(); i++) {
        previewStr += to_string(nums[i]);
        if (i < nums.size() - 1) previewStr += ",";
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
    cout << "\n🎮 Predict the Winner — Test Suite\n";
    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(24) << "Input Array" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(64, '-') << "\n";

    runTest(1, {1, 5, 2}, false);
    runTest(2, {1, 5, 233, 7}, true);
    runTest(3, {10}, true);
    runTest(4, {1, 100}, true);
    runTest(5, {1, 2, 99, 1}, true);
    runTest(6, {1, 100, 2}, false);
    runTest(7, {5, 5, 5, 5}, true);

    cout << "⇚ - ======================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
