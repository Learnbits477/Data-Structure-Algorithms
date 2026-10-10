#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // Step: 01 - Combine total operation budget
        long long totalK = (long long)k1 + k2;
        int n = nums1.size();
        int maxDiff = 0;

        // Step: 02 - Find maximum absolute difference
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }

        // Step: 03 - Handle zero maximum difference edge case
        if (maxDiff == 0) {
            return 0;
        }

        // Step: 04 - Populate frequency bucket array for differences
        vector<int> freq(maxDiff + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[abs(nums1[i] - nums2[i])]++;
        }

        // Step: 05 - Greedily flatten largest differences using bucket sweep
        for (int v = maxDiff; v >= 1; v--) {
            if (freq[v] == 0) {
                continue;
            }

            if (totalK >= freq[v]) {
                totalK -= freq[v];
                freq[v - 1] += freq[v];
                freq[v] = 0;
            } else {
                freq[v - 1] += totalK;
                freq[v] -= totalK;
                totalK = 0;
                break;
            }
        }

        // Step: 06 - Accumulate sum of squared differences
        long long minSquaredSum = 0;
        for (int v = 1; v <= maxDiff; v++) {
            if (freq[v] > 0) {
                minSquaredSum += (long long)freq[v] * v * v;
            }
        }

        // Step: 07 - Return computed minimum squared sum
        return minSquaredSum;
    }

    long long minSumSquareDiffBinarySearch(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // Step: 01 - Combine total operations and extract differences
        long long totalK = (long long)k1 + k2;
        int n = nums1.size();
        vector<int> diffs(n);
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            diffs[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diffs[i]);
        }

        // Step: 02 - Binary search for optimal upper ceiling threshold
        int low = 0, high = maxDiff;
        int threshold = maxDiff;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long operationsNeeded = 0;

            for (int d : diffs) {
                if (d > mid) {
                    operationsNeeded += (d - mid);
                }
            }

            if (operationsNeeded <= totalK) {
                threshold = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Step: 03 - Adjust values to threshold and consume remaining operations
        long long remainingK = totalK;
        for (int& d : diffs) {
            if (d > threshold) {
                remainingK -= (d - threshold);
                d = threshold;
            }
        }

        // Step: 04 - Decrement items at threshold with leftover budget
        if (threshold > 0) {
            for (int& d : diffs) {
                if (d == threshold && remainingK > 0) {
                    d--;
                    remainingK--;
                }
            }
        }

        // Step: 05 - Calculate sum of squared differences
        long long ans = 0;
        for (int d : diffs) {
            ans += (long long)d * d;
        }

        // Step: 06 - Return final minimized result
        return ans;
    }
};
