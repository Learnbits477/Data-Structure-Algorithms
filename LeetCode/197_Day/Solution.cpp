#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // Step 1: State Definition
        int left = 0;
        int max_len = 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        
        // Step 2: Expand the Window
        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;
            
            // Step 3: Shrink the Window on Violation
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            
            // Step 4: Update Result
            max_len = max(max_len, right - left + 1);
        }
        
        // Step 5: Return Result
        return max_len;
    }
};
