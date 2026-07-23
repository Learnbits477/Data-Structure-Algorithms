#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void runTest(int testNum, const vector<int>& nums, int expected) {
    Solution sol;
    vector<int> numsCopy = nums; // pass a copy just in case the solution modifies the vector
    int result = sol.uniqueXorTriplets(numsCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    // Format array output
    string numsStr = "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        numsStr += to_string(nums[i]);
        if (i + 1 < nums.size()) numsStr += ", ";
    }
    numsStr += "]";
    if (numsStr.length() > 30) {
        numsStr = numsStr.substr(0, 27) + "...]";
    }
    
    cout << left << setw(6)  << testId 
         << setw(32) << numsStr
         << setw(18) << expected
         << setw(18) << result
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 177 - Number of Unique XOR Triplets I Test Suite  \n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Input Array (nums)" 
         << setw(18) << "Expected Count" 
         << setw(18) << "Actual Count" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Test Case 1: Example 1
    runTest(1, {1, 2}, 2);

    // Test Case 2: Example 2
    runTest(2, {3, 1, 2}, 4);

    // Test Case 3: n = 1 (minimum constraint)
    runTest(3, {1}, 1);

    // Test Case 4: n = 4 (power of 2)
    runTest(4, {1, 2, 3, 4}, 8);

    // Test Case 5: n = 5
    runTest(5, {5, 2, 1, 4, 3}, 8);

    // Test Case 6: n = 8
    runTest(6, {1, 2, 3, 4, 5, 6, 7, 8}, 16);

    // Test Case 7: Larger value of n
    runTest(7, {9, 2, 3, 4, 5, 6, 7, 8, 1, 10}, 16);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
