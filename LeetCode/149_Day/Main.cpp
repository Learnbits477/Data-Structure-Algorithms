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

void runTest(int testNum, vector<int> nums, int target, int expected) {
    Solution sol;
    int result = sol.countMajoritySubarrays(nums, target);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string numsStr = formatVector(nums);
    
    cout << left << setw(6)  << testId 
         << setw(25) << numsStr
         << setw(12) << target
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 149 - Count Subarrays with Majority Element I Test Suite  \n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Input Array"
         << setw(12) << "Target" 
         << setw(18) << "Expected Output" 
         << setw(18) << "Actual Output" 
         << "Status\n";
    cout << string(85, '-') << "\n";

    // Example 1
    runTest(1, {1, 2, 2, 3}, 2, 5);
    
    // Example 2
    runTest(2, {1, 1, 1, 1}, 1, 10);
    
    // Example 3
    runTest(3, {1, 2, 3}, 4, 0);
    
    // Additional Test Cases
    runTest(4, {2, 1, 2}, 2, 3);  // [2], [2,1,2], [2] at end
    runTest(5, {1}, 1, 1);
    runTest(6, {1, 2}, 1, 1);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
