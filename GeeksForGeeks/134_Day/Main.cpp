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
void runTest(int testNum, vector<int> arr, int expected) {
    string arrStr = vectorToString(arr);
    
    Solution sol;
    int result = sol.binarySearchable(arr);
    
    cout << "Test Case " << testNum << ":\n";
    cout << "  Input:    arr = " << arrStr << "\n";
    cout << "  Expected: " << expected << "\n";
    cout << "  Output:   " << result << "\n";
    
    if (result == expected) {
        cout << "  Status:   ✅ PASSED\n\n";
    } else {
        cout << "  Status:   ❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Binary Searchable Count — Test Suite\n";
    cout << "========================================================\n" << endl;
    
    // GFG Example 1
    runTest(1, {1, 3, 2}, 2);
    
    // GFG Example 2
    runTest(2, {2, 1, 3, 5, 4, 6}, 4);
    
    // Additional Edge Cases
    runTest(3, {}, 0);                             // Empty array
    runTest(4, {10}, 1);                           // Single element
    runTest(5, {1, 2, 3, 4, 5}, 5);                // Fully sorted array (all elements searchable)
    runTest(6, {5, 4, 3, 2, 1}, 1);                // Reverse sorted array (only mid '3' searchable)
    runTest(7, {2, 1, 3, 4, 6, 5}, 4);              // Trace from description: 5 is not searchable, 2, 3, 4, 6 are.
    runTest(8, {1, 2, 5, 4, 3, 6, 7}, 5);          // 1, 2, 6, 7 are searchable; 4 is mid of [5,4,3] hence searchable. Total = 5.
    
    return 0;
}
