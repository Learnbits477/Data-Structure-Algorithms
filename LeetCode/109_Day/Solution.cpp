#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // Step 1: Initialize Pointers
        int low = 0, high = nums.size() - 1;

        // Step 2: Binary Search Loop
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Case 1: Minimum is in the right half
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                // Case 2: Minimum is in the left half
                high = mid;
            } else {
                // Case 3 (Duplicates): Shrink search space
                high--;
            }
        }

        // Step 3: Return Result
        return nums[low];
    }
};
