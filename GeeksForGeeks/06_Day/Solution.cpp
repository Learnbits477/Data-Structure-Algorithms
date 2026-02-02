#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        int totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        int maxSum = arr[0], minSum = arr[0];

        for (int i = 0; i < n; i++) {
            // Kadane's for max subarray sum
            currMaxSum = max(currMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currMaxSum);

            // Kadane's for min subarray sum
            currMinSum = min(currMinSum + arr[i], arr[i]);
            minSum = min(minSum, currMinSum);

            totalSum += arr[i];
        }

        int normalSum = maxSum;
        int circularSum = totalSum - minSum;

        // If all numbers are negative, circularSum would be 0, so return normalSum
        if (minSum == totalSum)
            return normalSum;

        return max(normalSum, circularSum);
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {8, -8, 9, -9, 10, -11, 12};
    cout << "Example 1 Output: " << sol.maxCircularSum(arr1) << " (Expected: 22)" << endl;

    // Example 2
    vector<int> arr2 = {10, -3, -4, 7, 6, 5, -4, -1};
    cout << "Example 2 Output: " << sol.maxCircularSum(arr2) << " (Expected: 23)" << endl;

    // Example 3
    vector<int> arr3 = {5, -2, 3, 4};
    cout << "Example 3 Output: " << sol.maxCircularSum(arr3) << " (Expected: 12)" << endl;
    
    // Additional Test Case: All negative
    vector<int> arr4 = {-3, -2, -1};
    cout << "Example 4 Output: " << sol.maxCircularSum(arr4) << " (Expected: -1)" << endl;

    return 0;
}
