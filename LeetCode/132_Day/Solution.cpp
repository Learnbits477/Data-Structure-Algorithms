#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // Step 1: Initialize Pointers & Variables
        int n = nums.size();
        vector<int> ans(n);
        int left = 0;
        int right = n - 1;
        
        // Step 2: Dual-Pass Execution
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            if (nums[i] < pivot) {
                ans[left++] = nums[i];
            }
            if (nums[j] > pivot) {
                ans[right--] = nums[j];
            }
        }
        
        // Step 3: Populate Pivot Values
        while (left <= right) {
            ans[left++] = pivot;
        }
        
        return ans;
    }
};
