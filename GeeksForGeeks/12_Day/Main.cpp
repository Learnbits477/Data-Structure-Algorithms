#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {-2, 6, -3, -10, 0, 2};
    cout << "Example 1:\n";
    cout << "Input: arr = [-2, 6, -3, -10, 0, 2]\n";
    cout << "Output: " << sol.maxProduct(arr1) << "\n";
    cout << "Expected: 180\n\n";

    // Example 2
    vector<int> arr2 = {-1, -3, -10, 0, 6};
    cout << "Example 2:\n";
    cout << "Input: arr = [-1, -3, -10, 0, 6]\n";
    cout << "Output: " << sol.maxProduct(arr2) << "\n";
    cout << "Expected: 30\n\n";
    
    // Example 3
    vector<int> arr3 = {2, 3, 4};
    cout << "Example 3:\n";
    cout << "Input: arr = [2, 3, 4]\n";
    cout << "Output: " << sol.maxProduct(arr3) << "\n";
    cout << "Expected: 24\n\n";

    return 0;
}
