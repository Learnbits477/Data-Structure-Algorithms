#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

// Helper to convert vector to string representation (e.g. "[9, 5, 3, 10, 10, 12, 14]")
string vectorToString(const vector<int>& vec) {
    string res = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        res += to_string(vec[i]);
        if (i < vec.size() - 1) {
            res += ", ";
        }
    }
    res += "]";
    return res;
}

// Function to run a single test case
void runTest(int testNum, vector<int> nums, int pivot, const vector<int>& expected) {
    string inputStr = vectorToString(nums);
    string expectedStr = vectorToString(expected);
    
    Solution sol;
    vector<int> result = sol.pivotArray(nums, pivot);
    string resultStr = vectorToString(result);
    
    cout << "Test Case " << testNum << ":\n";
    cout << "  Input:    nums = " << inputStr << ", pivot = " << pivot << "\n";
    cout << "  Expected: " << expectedStr << "\n";
    cout << "  Output:   " << resultStr << "\n";
    
    if (result == expected) {
        cout << "  Status:   ✅ PASSED\n\n";
    } else {
        cout << "  Status:   ❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Partition Array According to Given Pivot — Test Suite\n";
    cout << "========================================================\n" << endl;
    
    // LeetCode Example 1
    runTest(1, {9, 12, 5, 10, 14, 3, 10}, 10, {9, 5, 3, 10, 10, 12, 14});
    
    // LeetCode Example 2
    runTest(2, {-3, 4, 3, 2}, 2, {-3, 2, 4, 3});
    
    // Additional Edge Cases
    runTest(3, {5}, 5, {5});                                             // Single element
    runTest(4, {1, 2, 3, 4, 5}, 3, {1, 2, 3, 4, 5});                     // Already sorted
    runTest(5, {5, 4, 3, 2, 1}, 3, {2, 1, 3, 5, 4});                     // Reversed order (relative order preserved)
    runTest(6, {9, 9, 9}, 9, {9, 9, 9});                                 // All elements equal to pivot
    runTest(7, {3, 1, 2, 2, 4}, 2, {1, 2, 2, 3, 4});                     // Multiple pivots
    
    return 0;
}
