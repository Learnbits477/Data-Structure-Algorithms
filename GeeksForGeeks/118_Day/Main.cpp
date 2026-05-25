#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

// Helper function to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

// Test runner function
void runTest(int testId, int start, int end, vector<int> arr, bool expected) {
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Range: [" << start << ", " << end << "]\n";
    cout << "   Input Array: ";
    printVector(arr);
    cout << "\n";

    Solution solver;
    // Make a copy since the solution modifies the array in-place
    vector<int> arrCopy = arr;
    bool actual = solver.checkElements(start, end, arrCopy);
    
    cout << "   Expected Result: " << (expected ? "true" : "false") << "\n";
    cout << "   Actual Result:   " << (actual ? "true" : "false") << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 118] Elements in the Range — Test Suite 🚀\n";
    
    // Example 1: Range [2, 5], all elements are present
    runTest(1, 2, 5, {1, 4, 5, 2, 7, 8, 3}, true);
    
    // Example 2: Range [2, 6], 6 is missing
    runTest(2, 2, 6, {1, 4, 5, 2, 7, 8, 3}, false);
    
    // Example 3: Range size is larger than array size
    runTest(3, 1, 5, {2, 3, 4}, false);
    
    // Example 4: Range [1, 1], element present
    runTest(4, 1, 1, {3, 2, 1}, true);

    // Example 5: Range [1, 1], element missing
    runTest(5, 5, 5, {3, 2, 1}, false);

    // Example 6: Large range and array with multiple out-of-range elements
    runTest(6, 10, 15, {10, 11, 12, 13, 14, 15, 100, 200}, true);

    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
