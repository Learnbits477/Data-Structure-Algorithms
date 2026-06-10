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

// Function to run a single test case and output the result
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
    cout << "\n🔢 Maximum Total Subarray Value II — Test Suite\n";
    cout << "========================================================\n" << endl;
    
    // LeetCode Example 1
    runTest(1, {1, 3, 2}, 2, 4);
    
    // LeetCode Example 2
    runTest(2, {4, 2, 5, 1}, 3, 12);
    
    // Additional Edge Cases
    runTest(3, {10}, 1, 0);                          // Single element array
    runTest(4, {1, 2, 3, 4, 5}, 4, 12);              // Sorted array (values: 4, 3, 3, 2)
    runTest(5, {5, 4, 3, 2, 1}, 4, 12);              // Reversed sorted array
    runTest(6, {1, 10, 2, 9, 3, 8}, 5, 45);          // Alternating values (top 5 values are all 9)
    // Distinct subarrays and values for {1, 10, 2, 9, 3, 8}:
    // [1..10..2..9..3..8] -> max=10, min=1, val=9
    // [10..2..9..3..8] -> max=10, min=2, val=8
    // [1..10..2..9..3] -> max=10, min=1, val=9
    // [2..9..3..8] -> max=9, min=2, val=7
    // [10..2..9..3] -> max=10, min=2, val=8
    // Top 5 values: 9, 9, 8, 8, 7. Sum = 41.
    
    return 0;
}
