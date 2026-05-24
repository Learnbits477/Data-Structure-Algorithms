#include <iostream>
#include <vector>
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
void runTest(int testId, const vector<int>& arr, int d, int expected) {
    vector<int> arrCopy = arr;
    Solution solver;
    
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input Array:  ";
    printVector(arr);
    cout << "\n";
    cout << "   d Value:      " << d << "\n";
    
    int actual = solver.maxJumps(arrCopy, d);
    cout << "   Expected:     " << expected << "\n";
    cout << "   Actual:       " << actual << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 117] Jump Game V — Test Suite 🚀\n";
    
    // Example 1: Standard case from description
    runTest(1, {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12}, 2, 4);
    
    // Example 2: All elements equal (no jumps possible)
    runTest(2, {3, 3, 3, 3, 3}, 3, 1);
    
    // Example 3: Strictly decreasing array, d = 1
    runTest(3, {7, 6, 5, 4, 3, 2, 1}, 1, 7);
    
    // Example 4: Strictly decreasing array, larger d (should still jump sequentially or skip, max sequence is still n)
    runTest(4, {9, 8, 7, 6, 5, 4, 3, 2, 1}, 3, 9);
    
    // Example 5: Interleaved peaks and valleys
    runTest(5, {2, 5, 1, 6, 3, 8}, 1, 3);
    
    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
