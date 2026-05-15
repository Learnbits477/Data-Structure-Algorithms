#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ",");
    }
    cout << "]";
}

void runTest(int testId, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.findMin(nums);
    
    cout << "Test Case " << testId << ": ";
    printVector(nums);
    cout << " | Expected: " << expected << " | Result: " << result;
    
    if (result == expected) {
        cout << " ✅ PASSED" << endl;
    } else {
        cout << " ❌ FAILED" << endl;
    }
}

int main() {
    cout << "\n🔢 [153. Find Minimum in Rotated Sorted Array] — Test Suite\n";
    cout << "---------------------------------------------------------\n";

    // Example 1
    runTest(1, {3, 4, 5, 1, 2}, 1);

    // Example 2
    runTest(2, {4, 5, 6, 7, 0, 1, 2}, 0);

    // Example 3
    runTest(3, {11, 13, 15, 17}, 11);

    // Extra case: Single element
    runTest(4, {10}, 10);

    // Extra case: Not rotated
    runTest(5, {1, 2, 3, 4, 5}, 1);

    // Extra case: Rotated once
    runTest(6, {5, 1, 2, 3, 4}, 1);

    cout << "---------------------------------------------------------\n";
    cout << "Testing Completed! 🚀\n" << endl;

    return 0;
}
