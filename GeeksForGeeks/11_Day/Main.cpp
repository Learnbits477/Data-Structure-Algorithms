#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {3, 1, 2, 8};
    cout << "Example 1:\n";
    cout << "Input: arr = [3, 1, 2, 8]\n";
    cout << "Output: " << sol.maxSum(arr1) << "\n";
    cout << "Expected: 29\n\n";

    // Example 2
    vector<int> arr2 = {1, 2, 3};
    cout << "Example 2:\n";
    cout << "Input: arr = [1, 2, 3]\n";
    cout << "Output: " << sol.maxSum(arr2) << "\n";
    cout << "Expected: 8\n\n";
    
    // Example 3
    vector<int> arr3 = {4, 13};
    cout << "Example 3:\n";
    cout << "Input: arr = [4, 13]\n";
    cout << "Output: " << sol.maxSum(arr3) << "\n";
    cout << "Expected: 13\n\n";

    return 0;
}
