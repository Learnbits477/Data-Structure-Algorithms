#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {8, -8, 9, -9, 10, -11, 12};
    cout << "Example 1:\n";
    cout << "Input: arr = [8, -8, 9, -9, 10, -11, 12]\n";
    cout << "Output: " << sol.maxCircularSum(arr1) << "\n";
    cout << "Expected: 22\n\n";

    // Example 2
    vector<int> arr2 = {10, -3, -4, 7, 6, 5, -4, -1};
    cout << "Example 2:\n";
    cout << "Input: arr = [10, -3, -4, 7, 6, 5, -4, -1]\n";
    cout << "Output: " << sol.maxCircularSum(arr2) << "\n";
    cout << "Expected: 23\n\n";

    // Example 3
    vector<int> arr3 = {5, -2, 3, 4};
    cout << "Example 3:\n";
    cout << "Input: arr = [5, -2, 3, 4]\n";
    cout << "Output: " << sol.maxCircularSum(arr3) << "\n";
    cout << "Expected: 12\n\n";
    
    // Additional Edge Case
    vector<int> arr4 = {-3, -2, -1};
    cout << "Edge Case (All Negative):\n";
    cout << "Input: arr = [-3, -2, -1]\n";
    cout << "Output: " << sol.maxCircularSum(arr4) << "\n";
    cout << "Expected: -1\n\n";

    return 0;
}
