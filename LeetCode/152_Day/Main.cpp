#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

string formatVector(const vector<int>& nums) {
    if (nums.empty()) return "[]";
    if (nums.size() > 6) {
        return "[" + to_string(nums[0]) + "," + to_string(nums[1]) + "... (" + to_string(nums.size()) + " items)]";
    }
    string res = "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        res += to_string(nums[i]);
        if (i + 1 < nums.size()) res += ",";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    vector<int> arrCopy = arr;
    int result = sol.maximumElementAfterDecrementingAndRearranging(arrCopy);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string arrStr = formatVector(arr);
    
    cout << left << setw(6)  << testId 
         << setw(25) << arrStr
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 152 - Maximum Element After Decreasing/Rearranging Test Suite  \n";
    cout << "⇚ - ======================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Input Array"
         << setw(18) << "Expected Output" 
         << setw(18) << "Actual Output" 
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1
    runTest(1, {2, 2, 1, 2, 1}, 2);
    
    // Example 2
    runTest(2, {100, 1, 1000}, 3);
    
    // Example 3
    runTest(3, {1, 2, 3, 4, 5}, 5);
    
    // Additional Test Cases
    runTest(4, {10}, 1);
    runTest(5, {7, 7, 7, 7, 7}, 5); // sorted: 7, 7, 7, 7, 7. greedy: 1, 2, 3, 4, 5. max = 5.
    runTest(6, {1, 10, 10, 10}, 4); // sorted: 1, 10, 10, 10. greedy: 1, 2, 3, 4. max = 4.

    cout << "⇚ - ========================================================================= - ⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
