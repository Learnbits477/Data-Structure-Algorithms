#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {1, 0, 1};
    int k1 = 1;
    cout << "Example 1:\n";
    cout << "Input: arr = [1, 0, 1], k = 1\n";
    cout << "Output: " << sol.maxOnes(arr1, k1) << "\n";
    cout << "Expected: 3\n\n";

    // Example 2
    vector<int> arr2 = {1, 0, 0, 1, 0, 1, 0, 1};
    int k2 = 2;
    cout << "Example 2:\n";
    cout << "Input: arr = [1, 0, 0, 1, 0, 1, 0, 1], k = 2\n";
    cout << "Output: " << sol.maxOnes(arr2, k2) << "\n";
    cout << "Expected: 5\n\n";

    // Example 3
    vector<int> arr3 = {1, 1};
    int k3 = 2;
    cout << "Example 3:\n";
    cout << "Input: arr = [1, 1], k = 2\n";
    cout << "Output: " << sol.maxOnes(arr3, k3) << "\n";
    cout << "Expected: 2\n\n";

    // Example 4 (All Zeros Edge Case)
    vector<int> arr4 = {0, 0, 0};
    int k4 = 1;
    cout << "Example 4 (All zeros):\n";
    cout << "Input: arr = [0, 0, 0], k = 1\n";
    cout << "Output: " << sol.maxOnes(arr4, k4) << "\n";
    cout << "Expected: 1\n\n";

    return 0;
}
