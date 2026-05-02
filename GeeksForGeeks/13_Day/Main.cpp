#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {5, 1, 2, 3, 4};
    cout << "Example 1:\n";
    cout << "Input: arr = [5, 1, 2, 3, 4]\n";
    cout << "Output: " << sol.findKRotation(arr1) << "\n";
    cout << "Expected: 1\n\n";

    // Example 2
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Example 2:\n";
    cout << "Input: arr = [1, 2, 3, 4, 5]\n";
    cout << "Output: " << sol.findKRotation(arr2) << "\n";
    cout << "Expected: 0\n\n";
    
    // Additional Edge Case
    vector<int> arr3 = {2, 3, 4, 5, 1};
    cout << "Edge Case:\n";
    cout << "Input: arr = [2, 3, 4, 5, 1]\n";
    cout << "Output: " << sol.findKRotation(arr3) << "\n";
    cout << "Expected: 4\n\n";

    return 0;
}
