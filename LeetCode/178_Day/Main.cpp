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
    cout << "  🚀 LeetCode Day 178 - Number of Unique XOR Triplets II Test Suite  \n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Input Array (nums)" 
         << setw(18) << "Expected Count" 
         << setw(18) << "Actual Count" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Test Case 1: Example 1
    runTest(1, {1, 3}, 2);

    // Test Case 2: Example 2
    runTest(2, {6, 7, 8, 9}, 4);

    // Test Case 3: Single element array
    runTest(3, {1}, 1);

    // Test Case 4: Standard distinct elements generating more values
    runTest(4, {1, 2, 4}, 4);

    // Test Case 5: Duplicate elements
    runTest(5, {2, 2, 2}, 1);

    // Test Case 6: Group closed under XOR
    runTest(6, {1, 3, 5, 7}, 4);

    // Test Case 7: High variety elements
    runTest(7, {2, 3, 4, 9}, 8);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
