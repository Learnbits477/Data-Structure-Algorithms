#include <iostream>
#include <vector>
#include <algorithm>
#include "Solution.cpp"

using namespace std;

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

void runTest(int testNum, vector<int> nums, int expected) {
    Solution sol;
    cout << "🧪 Test Case " << testNum << ": ";
    printVector(nums);
    cout << "\n";
    
    int result = sol.findMin(nums);
    
    if (result == expected) {
        cout << "   ✅ PASSED (Result: " << result << ")\n";
    } else {
        cout << "   ❌ FAILED (Expected: " << expected << ", Got: " << result << ")\n";
    }
    cout << "-------------------------------------------\n";
}

int main() {
    cout << "\n🔢 [Find Minimum in Rotated Sorted Array II] — Test Suite\n";
    cout << "===========================================\n";

    // Example 1: nums = [1,3,5]
    runTest(1, {1, 3, 5}, 1);

    // Example 2: nums = [2,2,2,0,1]
    runTest(2, {2, 2, 2, 0, 1}, 0);

    // Additional Case: All same
    runTest(3, {1, 1, 1, 1}, 1);

    // Additional Case: Pivot with duplicates
    runTest(4, {3, 3, 1, 3}, 1);

    // Additional Case: Large rotation
    runTest(5, {10, 1, 10, 10, 10}, 1);

    cout << "\n🚀 All tests completed!\n";
    
    return 0;
}
