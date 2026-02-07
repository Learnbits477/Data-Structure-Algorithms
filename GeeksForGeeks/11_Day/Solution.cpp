#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& arr) {
        int n = arr.size();
        long long sum_elements = 0;
        long long curr_val = 0;

        for (int i = 0; i < n; ++i) {
            sum_elements += arr[i];
            curr_val += (long long)i * arr[i];
        }

        long long max_val = curr_val;
        for (int i = 1; i < n; ++i) {
            curr_val = curr_val + sum_elements - (long long)n * arr[n - i];
            max_val = max(max_val, curr_val);
        }

        return max_val;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {3, 1, 2, 8};
    cout << "Test Case 1: Input: [3, 1, 2, 8]" << endl;
    cout << "Expected Output: 29" << endl;
    cout << "Actual Output: " << sol.maxSum(arr1) << endl;
    cout << "-----------------" << endl;

    // Example 2
    vector<int> arr2 = {1, 2, 3};
    cout << "Test Case 2: Input: [1, 2, 3]" << endl;
    cout << "Expected Output: 8" << endl;
    cout << "Actual Output: " << sol.maxSum(arr2) << endl;
    cout << "-----------------" << endl;
    
    // Example 3
    vector<int> arr3 = {4, 13};
    cout << "Test Case 3: Input: [4, 13]" << endl;
    cout << "Expected Output: 13" << endl;
    cout << "Actual Output: " << sol.maxSum(arr3) << endl;
    cout << "-----------------" << endl;

    return 0;
}
