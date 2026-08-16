#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, vector<int> stones, bool expected) {
    Solution sol;
    bool result = sol.stoneGameIX(stones);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string arrStr = "[";
    for (size_t i = 0; i < stones.size(); ++i) {
        arrStr += to_string(stones[i]);
        if (i + 1 < stones.size()) arrStr += ", ";
    }
    arrStr += "]";

    cout << left << setw(6)  << testId 
         << setw(26) << arrStr
         << setw(10) << (result ? "true" : "false")
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << (expected ? "true" : "false") << "\n"
             << "     Got:      " << (result ? "true" : "false") << "\n";
    }
}

int main() {
    cout << "\n🎮 2029. Stone Game IX — Test Suite\n";
    cout << "※ ======================================================== ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(26) << "Stones" 
         << setw(10) << "Result" 
         << "Status\n";
    cout << string(56, '-') << "\n";

    runTest(1, {2, 1}, true);
    runTest(2, {2}, false);
    runTest(3, {5, 1, 2, 4, 3}, false);
    runTest(4, {1, 1, 1, 3}, true);
    runTest(5, {1, 1, 3}, false);
    runTest(6, {1, 2, 3, 3}, true);
    runTest(7, {2, 2, 2, 6}, true);
    runTest(8, {2, 2, 6}, false);

    cout << "※ ======================================================== ※\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
