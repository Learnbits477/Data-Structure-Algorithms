#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, vector<int> nums, int k, int expected) {
    Solution sol;
    int result = sol.maxSubarrayLength(nums, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    cout << left << setw(6)  << testId 
         << setw(10) << to_string(nums.size())
         << setw(8)  << to_string(k)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Longest Subarray With K Frequency — Test Suite\n";
    cout << "⇐ - ================================ - ⇒\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(10) << "Size (N)" 
         << setw(8)  << "K" 
         << "Status\n";
    cout << string(40, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {1, 2, 3, 1, 2, 3, 1, 2}, 2, 6);

    // Test 2: Example 2
    runTest(2, {1, 2, 1, 2, 1, 2, 1, 2}, 1, 2);

    // Test 3: Example 3
    runTest(3, {5, 5, 5, 5, 5, 5, 5}, 4, 4);

    // Test 4: Single element
    runTest(4, {1}, 1, 1);

    // Test 5: All unique elements
    runTest(5, {1, 2, 3, 4, 5}, 1, 5);

    cout << "⇐ - ================================ - ⇒\n";
    cout << "          🎉 All Tests Executed!             \n\n";

    return 0;
}
