#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

// Utility function to print a 1D vector
void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i + 1 < nums.size() ? ", " : "");
    }
    cout << "]";
}

// Test runner function
void runTest(int testId, const vector<int>& nums, bool expected) {
    vector<int> numsCopy = nums;
    Solution solver;
    
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input Array:  ";
    printVector(nums);
    cout << "\n";
    
    bool actual = solver.check(numsCopy);
    cout << "   Expected:     " << (expected ? "true" : "false") << "\n";
    cout << "   Actual:       " << (actual ? "true" : "false") << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 116] Check if Array Is Sorted and Rotated — Test Suite 🚀\n";
    
    // Example 1: Rotated sorted array
    runTest(1, {3, 4, 5, 1, 2}, true);
    
    // Example 2: Unsorted array
    runTest(2, {2, 1, 3, 4}, false);
    
    // Example 3: Sorted array (0 rotation)
    runTest(3, {1, 2, 3}, true);
    
    // Example 4: Single element array
    runTest(4, {1}, true);
    
    // Example 5: Array with all identical elements
    runTest(5, {1, 1, 1}, true);
    
    // Example 6: Rotated sorted array with duplicate elements
    runTest(6, {2, 2, 2, 1, 2}, true);
    
    // Example 7: Unsorted array with duplicate elements
    runTest(7, {3, 1, 2, 2, 1}, false);
    
    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
