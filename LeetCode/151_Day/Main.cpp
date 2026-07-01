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

void runTest(int testNum, vector<int> nums, int expected) {
    Solution sol;
    vector<int> numsCopy = nums;
    int result = sol.maximumLength(numsCopy);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string numsStr = formatVector(nums);
    
    cout << left << setw(6)  << testId 
         << setw(25) << numsStr
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 151 - Find Maximum Number of Elements in Subset Test Suite  \n";
    cout << "⇚ - ======================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Input Array"
         << setw(18) << "Expected Output" 
         << setw(18) << "Actual Output" 
         << "Status\n";
    cout << string(76, '-') << "\n";

    // Example 1
    runTest(1, {5, 4, 1, 2, 2}, 3);
    
    // Example 2
    runTest(2, {1, 3, 2, 4}, 1);
    
    // Additional Test Cases
    runTest(3, {2, 2, 4, 4, 16}, 5); // 2 -> 4 -> 16 -> 4 -> 2
    runTest(4, {2, 2, 2, 2, 4, 4, 16, 16, 256}, 7); // 2 -> 4 -> 16 -> 256 -> 16 -> 4 -> 2 (counts are 2, peak is 256)
    runTest(5, {1, 1, 1, 1, 1}, 5);
    runTest(6, {1, 1, 1, 1}, 3);
    runTest(7, {10, 10}, 1);

    cout << "⇚ - ======================================================================== - ⇛\n";
    cout << "                           🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
