#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        
        // If the array is not rotated at all
        if (arr[low] <= arr[high]) return 0;

        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If mid element is < the high element,
            // then the minimum element lies in the right half.
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                // Otherwise, the minimum element is in the left half or is mid itself.
                high = mid;
            }
        }
        
        return low;
    }
};

// Driver code to test the solution
int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {5, 1, 2, 3, 4};
    cout << "Example 1 Output: " << sol.findKRotation(arr1) << endl; // Expected: 1

    // Example 2
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Example 2 Output: " << sol.findKRotation(arr2) << endl; // Expected: 0
    
    // Additional Test Case
    vector<int> arr3 = {2, 3, 4, 5, 1};
    cout << "Additional Test Output: " << sol.findKRotation(arr3) << endl; // Expected: 4

    return 0;
}
