#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        
        // Step 1: Loop Through Starting Positions
        for (int i = 0; i < n; ++i) {
            // Step 2: Track Target Counts
            int target_count = 0;
            
            // Step 3: Expand Subarray
            for (int j = i; j < n; ++j) {
                if (nums[j] == target) {
                    target_count++;
                }
                int len = j - i + 1;
                if (target_count * 2 > len) {
                    ans++;
                }
            }
        }
        
        // Step 4: Return Count
        return ans;
    }
};
