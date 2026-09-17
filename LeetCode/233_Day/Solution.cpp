#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = static_cast<int>(arr.size());
        const int INF = 1e9;
        
        // min_len[i] stores the minimum length of a valid subarray ending at or before index i
        vector<int> min_len(n, INF);

        int window_sum = 0;
        int left = 0;
        int ans = INF;

        // Step: 01 - Iterate right pointer through the array
        for (int right = 0; right < n; ++right) {
            window_sum += arr[right];

            // Shrink the window while sum exceeds target
            while (window_sum > target && left <= right) {
                window_sum -= arr[left];
                left++;
            }

            // Carry forward the best minimum length seen so far
            if (right > 0) {
                min_len[right] = min_len[right - 1];
            }

            // Step: 02 - If current window equals target, check for previous non-overlapping match
            if (window_sum == target) {
                int curr_len = right - left + 1;

                if (left > 0 && min_len[left - 1] != INF) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }

                // Update prefix minimum length with the current valid subarray
                min_len[right] = min(min_len[right], curr_len);
            }
        }

        // Step: 03 - Return minimum combined length, or -1 if no pair exists
        return ans >= INF ? -1 : ans;
    }
};
