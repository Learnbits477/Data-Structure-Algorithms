/**
 * Maximum Product Subarray
 * https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr) {
        if (arr.empty()) return 0;

        long long maxSoFar = arr[0];
        long long minSoFar = arr[0];
        long long result = maxSoFar;

        for (size_t i = 1; i < arr.size(); ++i) {
            long long curr = arr[i];

            // If current number is negative, maxSoFar and minSoFar swap roles
            if (curr < 0) {
                swap(maxSoFar, minSoFar);
            }

            // Update maxSoFar and minSoFar
            maxSoFar = max(curr, maxSoFar * curr);
            minSoFar = min(curr, minSoFar * curr);

            // Update global result
            result = max(result, maxSoFar);
        }

        return result;
    }
};

// Driver code to test the solution
int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {-2, 6, -3, -10, 0, 2};
    cout << "Maximum product of arr1: " << sol.maxProduct(arr1) << endl; 
    // Expected: 180

    // Example 2
    vector<int> arr2 = {-1, -3, -10, 0, 6};
    cout << "Maximum product of arr2: " << sol.maxProduct(arr2) << endl; 
    // Expected: 30

    // Example 3
    vector<int> arr3 = {2, 3, 4};
    cout << "Maximum product of arr3: " << sol.maxProduct(arr3) << endl; 
    // Expected: 24

    return 0;
}
