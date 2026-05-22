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

void runTest(int testId, vector<int> nums, int target, int expected) {
    Solution solver;
    
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input Array:  ";
    printVector(nums);
    cout << "\n   Target:       " << target << "\n";
    
    int actual = solver.search(nums, target);
    cout << "   Expected:     " << expected << "\n";
    cout << "   Actual:       " << actual << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 115] Search in Rotated Sorted Array — Test Suite 🚀\n";
    
    // Example 1
    runTest(1, {4, 5, 6, 7, 0, 1, 2}, 0, 4);
    
    // Example 2
    runTest(2, {4, 5, 6, 7, 0, 1, 2}, 3, -1);
    
    // Example 3
    runTest(3, {1}, 0, -1);
    
    // Example 4: Single element match
    runTest(4, {1}, 1, 0);

    // Example 5: Small array rotated
    runTest(5, {5, 1, 3}, 5, 0);

    // Example 6: Small array rotated (target at end)
    runTest(6, {5, 1, 3}, 3, 2);

    // Example 7: Two elements rotated
    runTest(7, {3, 1}, 1, 1);

    // Example 8: Target not in rotated array
    runTest(8, {3, 5, 1}, 2, -1);
    
    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
