#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k1 = 3;
    cout << "Test Case 1:\n";
    cout << "Input: arr = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3\nOutput: ";
    vector<int> result1 = sol.maxOfSubarrays(arr1, k1);
    for (int val : result1) {
        cout << val << " ";
    }
    cout << "\nExpected: 3 3 4 5 5 5 6\n\n";

    // Test Case 2
    vector<int> arr2 = {5, 1, 3, 4, 2};
    int k2 = 1;
    cout << "Test Case 2:\n";
    cout << "Input: arr = [5, 1, 3, 4, 2], k = 1\nOutput: ";
    vector<int> result2 = sol.maxOfSubarrays(arr2, k2);
    for (int val : result2) {
        cout << val << " ";
    }
    cout << "\nExpected: 5 1 3 4 2\n\n";

    return 0;
}
