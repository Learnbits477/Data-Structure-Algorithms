#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, vector<int>& nums, int k, int expected) {
    Solution sol;
    int result = sol.largestInteger(nums, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    // Create string representation of nums
    string numsStr = "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        numsStr += to_string(nums[i]);
        if (i != nums.size() - 1) numsStr += ",";
    }
    numsStr += "]";

    if (numsStr.length() > 17) {
        numsStr = numsStr.substr(0, 14) + "...";
    }

    cout << left << setw(6)  << testId 
         << setw(20) << numsStr
         << setw(10) << to_string(k)
         << setw(15) << to_string(result)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🎲 Find the Largest Almost Missing Integer — Test Suite\n";
    cout << "※ ========================================================== ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(20) << "nums" 
         << setw(10) << "k" 
         << setw(15) << "Result" 
         << "Status\n";
    cout << string(62, '-') << "\n";

    // Test 1: Example 1
    vector<int> nums1 = {3, 9, 2, 1, 7};
    runTest(1, nums1, 3, 7);

    // Test 2: Example 2
    vector<int> nums2 = {3, 9, 7, 2, 1, 7};
    runTest(2, nums2, 4, 3);

    // Test 3: Example 3
    vector<int> nums3 = {0, 0};
    runTest(3, nums3, 1, -1);

    // Test 4: Custom case k == n
    vector<int> nums4 = {5, 2, 8, 1};
    runTest(4, nums4, 4, 8);

    // Test 5: Custom case k = 1
    vector<int> nums5 = {1, 2, 2, 3, 4, 4};
    runTest(5, nums5, 1, 3);

    cout << "※ ========================================================== ※\n";
    cout << "                  🎉 All Tests Executed!             \n\n";

    return 0;
}
