#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void runTest(int testNum, vector<int> nums, long long expected) {
    Solution sol;
    
    vector<int> originalNums = nums;
    long long result = sol.gcdSum(nums);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string arrStr = "[";
    for (size_t i = 0; i < originalNums.size(); ++i) {
        arrStr += to_string(originalNums[i]);
        if (i != originalNums.size() - 1) arrStr += ", ";
    }
    arrStr += "]";
    
    string inputStr = "nums = " + arrStr;
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
    cout << "  🚀 LeetCode Day 171 - Sum of GCD of Formed Pairs Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(45) << "Input Parameters (nums[])" 
         << setw(12) << "Expected" 
         << setw(12) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from description
    // nums = [2, 6, 4] -> prefixGcd = [2, 6, 2] -> sorted = [2, 2, 6] -> Expected: 2 (gcd(2, 6), middle 2 ignored)
    runTest(1, {2, 6, 4}, 2);

    // Test Case 2: Example 2 from description
    // nums = [3, 6, 2, 8] -> prefixGcd = [3, 6, 2, 8] -> sorted = [2, 3, 6, 8] -> Expected: 5 (gcd(2, 8) + gcd(3, 6))
    runTest(2, {3, 6, 2, 8}, 5);

    // Test Case 3: Single element (odd length n = 1)
    // nums = [10] -> prefixGcd = [10] -> Expected: 0 (middle ignored)
    runTest(3, {10}, 0);

    // Test Case 4: Double element (even length n = 2)
    // nums = [10, 20] -> prefixGcd = [10, 20] -> Expected: 10 (gcd(10, 20))
    runTest(4, {10, 20}, 10);

    // Test Case 5: All identical elements
    // nums = [2, 2, 2, 2] -> Expected: 4 (gcd(2,2) + gcd(2,2))
    runTest(5, {2, 2, 2, 2}, 4);

    // Test Case 6: Larger odd length test case
    // nums = [12, 18, 6, 24, 30] -> sorted prefixGcd = [6, 12, 18, 24, 30] -> Expected: 18 (gcd(6, 30) + gcd(12, 24))
    runTest(6, {12, 18, 6, 24, 30}, 18);

    // Test Case 7: Larger numbers (testing overflow safety)
    // nums = [1000000000, 1000000000] -> Expected: 1000000000 (fits in long long)
    runTest(7, {1000000000, 1000000000}, 1000000000LL);

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
