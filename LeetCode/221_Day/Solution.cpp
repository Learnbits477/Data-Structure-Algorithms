#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // Step 1: Precompute suffix minimums
        vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_min[i] = min(nums[i], suffix_min[i + 1]);
        }

        // Step 2: Traverse left-to-right tracking prefix maximum
        int prefix_max = nums[0];
        for (int i = 0; i < n; i++) {
            prefix_max = max(prefix_max, nums[i]);
            long long instability_score = (long long)prefix_max - suffix_min[i];
            if (instability_score <= k) {
                return i;
            }
        }

        return -1;
    }

    // Aliases for compatibility with various driver formats
    int firstStableIndex(vector<int>& nums, int k) {
        return smallestStableIndex(nums, k);
    }

    int minStableIndex(vector<int>& nums, int k) {
        return smallestStableIndex(nums, k);
    }
};
