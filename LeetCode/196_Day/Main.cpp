#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.missingInteger(nums);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    // Format input as string for representation
    string inputStr = "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        inputStr += to_string(nums[i]) + (i + 1 < nums.size() ? "," : "");
    }
    inputStr += "]";
    if (inputStr.length() > 28) {
        inputStr = inputStr.substr(0, 25) + "...";
    }

    cout << left << setw(6)  << testId 
         << setw(30) << inputStr
         << setw(10) << to_string(result)
         << setw(10) << to_string(expected)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n💎 Smallest Missing Integer Greater Than Sequential Prefix Sum — Test Suite\n";
    cout << "⇚ - ========================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(30) << "Input (nums)" 
         << setw(10) << "Result" 
         << setw(10) << "Expected" 
         << "Status\n";
    cout << string(66, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {1, 2, 3, 2, 5}, 6);

    // Test 2: Example 2
    runTest(2, {3, 4, 5, 1, 12, 14, 13}, 15);

    // Test 3: Trivial case (single element)
    runTest(3, {5}, 6);

    // Test 4: Sequential elements but not starting sequentially
    runTest(4, {5, 4, 3}, 6);

    // Test 5: Fully sequential array
    runTest(5, {1, 2, 3, 4, 5}, 15);

    // Test 6: Gap elements
    runTest(6, {1, 2, 5, 6, 7, 3}, 4);

    cout << "⇚ - ========================================================== - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
