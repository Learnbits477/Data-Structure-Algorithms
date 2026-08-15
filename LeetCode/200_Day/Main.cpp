#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.longestSubsequence(nums);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(12) << to_string(nums.size())
         << setw(10) << to_string(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 3702. Longest Subsequence With Non-Zero Bitwise XOR — Test Suite\n";
    cout << "※ ================================================ ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(12) << "N (size)" 
         << setw(10) << "Result" 
         << "Status\n";
    cout << string(52, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {1, 2, 3}, 2);

    // Test 2: Example 2
    runTest(2, {2, 3, 4}, 3);

    // Test 3: All zeros
    runTest(3, {0, 0, 0}, 0);

    // Test 4: Two equal elements
    runTest(4, {5, 5}, 1);

    // Test 5: Single element non-zero
    runTest(5, {7}, 1);

    // Test 6: Single element zero
    runTest(6, {0}, 0);

    // Test 7: Alternating elements
    runTest(7, {1, 1, 1, 1}, 3);

    cout << "※================================================ ※\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
