#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Step 1: Initialize Search Range
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            // Step 2: Calculate Midpoint and Check Match
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Step 3: Check If Left Half is Sorted
            if (nums[low] <= nums[mid]) {
                // If target lies within the sorted left half range
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Step 4: Check If Right Half is Sorted
            else {
                // If target lies within the sorted right half range
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
