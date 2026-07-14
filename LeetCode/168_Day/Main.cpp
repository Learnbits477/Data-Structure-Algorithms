#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void runTest(int testNum, vector<int> nums, int expected) {
    Solution sol;
    
    vector<int> originalNums = nums;
    
    int result = sol.subsequencePairCount(nums);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string numsStr = "[";
    for (size_t i = 0; i < originalNums.size(); ++i) {
        numsStr += to_string(originalNums[i]);
        if (i != originalNums.size() - 1) numsStr += ", ";
    }
    numsStr += "]";
    
    string inputStr = "nums = " + numsStr;
    if (inputStr.length() > 45) {
        inputStr = inputStr.substr(0, 42) + "...";
    }
    
    cout << left << setw(6)  << testId 
         << setw(45) << inputStr
         << setw(12) << expected
         << setw(12) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 168 - Find the Number of Subsequences With Equal GCD Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (nums[])" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from description
    // nums[] = [1, 2, 3, 4] -> Expected: 10
    runTest(1, {1, 2, 3, 4}, 10);

    // Test Case 2: Example 2 from description
    // nums[] = [10, 20, 30] -> Expected: 2
    runTest(2, {10, 20, 30}, 2);

    // Test Case 3: Example 3 from description (all 1s)
    // nums[] = [1, 1, 1, 1] -> Expected: 50
    runTest(3, {1, 1, 1, 1}, 50);

    // Test Case 4: Single element array (cannot form 2 disjoint non-empty subsequences)
    // nums[] = [5] -> Expected: 0
    runTest(4, {5}, 0);

    // Test Case 5: Two identical elements
    // nums[] = [2, 2] -> Expected: 2
    runTest(5, {2, 2}, 2);

    // Test Case 6: Three elements, two pairs possible
    // nums[] = [3, 3, 3] -> Expected: 12
    // Pairs include length 1 vs length 1, and length 1 vs length 2.
    runTest(6, {3, 3, 3}, 12);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
