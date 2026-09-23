#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        // Step: 01 - Compute total sum of all elements using 64-bit integer
        long long totalSum = 0;
        for (int val : nums) {
            totalSum += val;
        }

        // Step: 02 - Handle edge cases where total sum is less than or exactly equal to x
        if (totalSum < x) {
            return -1;
        }
        if (totalSum == x) {
            return n;
        }

        // Step: 03 - Target sum for the remaining contiguous subarray
        long long target = totalSum - x;
        int maxLen = -1;
        long long currentSum = 0;
        int left = 0;

        // Step: 04 - Sliding window to find maximum length subarray with sum == target
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];

            // Step: 05 - Shrink window from the left while current sum exceeds target
            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                ++left;
            }

            // Step: 06 - Record max window length when exact target sum is achieved
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // Step: 07 - Return min operations (n - maxLen), or -1 if no valid subarray found
        return (maxLen == -1) ? -1 : (n - maxLen);
    }
};
