#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, vector<int> stoneValue, int expected) {
    Solution sol;
    int result = sol.stoneGameV(stoneValue);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string arrStr = "[";
    for (size_t i = 0; i < stoneValue.size(); ++i) {
        arrStr += to_string(stoneValue[i]);
        if (i + 1 < stoneValue.size()) arrStr += ", ";
    }
    arrStr += "]";

    cout << left << setw(6)  << testId 
         << setw(26) << arrStr
         << setw(12) << to_string(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🪨 1563. Stone Game V — Test Suite\n";
    cout << "※ ======================================================== ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(26) << "Stones Array" 
         << setw(12) << "Result" 
         << "Status\n";
    cout << string(54, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {6, 2, 3, 4, 5, 5}, 18);

    // Test 2: Example 2
    runTest(2, {7, 7, 7, 7, 7, 7, 7}, 28);

    // Test 3: Single stone
    runTest(3, {4}, 0);

    // Test 4: Two stones
    runTest(4, {2, 3}, 2);

    // Test 5: Three stones [1, 2, 4] -> score 4
    runTest(5, {1, 2, 4}, 4);

    cout << "※ ======================================================== ※\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
