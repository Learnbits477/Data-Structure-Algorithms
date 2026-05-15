#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Initialize Pointers
        int low = 0, high = n - 1;
        
        // Step 2: Binary Search Loop
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Check Right Half: If nums[mid] > nums[high], min is in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            // Check Left Half: Otherwise, min is at mid or in the left half
            else {
                high = mid;
            }
        }
        
        // Step 3: Return Result
        return nums[low];
    }
};
