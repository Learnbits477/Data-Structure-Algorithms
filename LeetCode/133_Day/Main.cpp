#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

string vectorToString(const vector<int>& arr) {
    string res = "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        res += to_string(arr[i]);
        if (i < arr.size() - 1) {
            res += ", ";
        }
    }
    res += "]";
    return res;
}

// Function to run a single test case
void runTest(int testNum, vector<int> nums, int k, long long expected) {
    string numsStr = vectorToString(nums);
    
    Solution sol;
    long long result = sol.maxTotalValue(nums, k);
    
    cout << "Test Case " << testNum << ":\n";
    cout << "  Input:    nums = " << numsStr << ", k = " << k << "\n";
    cout << "  Expected: " << expected << "\n";
    cout << "  Output:   " << result << "\n";
    
    if (result == expected) {
        cout << "  Status:   ✅ PASSED\n\n";
    } else {
        cout << "  Status:   ❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Maximum Total Subarray Value I — Test Suite\n";
    cout << "========================================================\n" << endl;
    
    // LeetCode Example 1
    runTest(1, {1, 3, 2}, 2, 4);
    
    // LeetCode Example 2
    runTest(2, {4, 2, 5, 1}, 3, 12);
    
    // Additional Edge Cases
    runTest(3, {10}, 5, 0);                             // Single element array (diff is 0)
    runTest(4, {1, 10}, 100000, 900000);                // Large k value (check for integer overflow)
    runTest(5, {5, 4, 3, 2, 1}, 1, 4);                  // Strictly decreasing array
    runTest(6, {1, 1, 1, 1}, 10, 0);                    // All identical elements
    runTest(7, {1000000000, 0}, 10000, 10000000000000LL); // Large elements difference
    
    return 0;
}
