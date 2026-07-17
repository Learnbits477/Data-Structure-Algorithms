#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Initialize Prefix and Suffix Arrays
        vector<int> leftMax(n), leftMin(n), rightMax(n), rightMin(n);

        // Step 2: Compute Left Max and Min Subarray Sums (Kadane's Prefix Scan)
        int curr_max = arr[0];
        leftMax[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            curr_max = max(arr[i], curr_max + arr[i]);
            leftMax[i] = max(leftMax[i - 1], curr_max);
        }

        int curr_min = arr[0];
        leftMin[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            curr_min = min(arr[i], curr_min + arr[i]);
            leftMin[i] = min(leftMin[i - 1], curr_min);
        }

        // Step 3: Compute Right Max and Min Subarray Sums (Kadane's Suffix Scan)
        curr_max = arr[n - 1];
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            curr_max = max(arr[i], curr_max + arr[i]);
            rightMax[i] = max(rightMax[i + 1], curr_max);
        }

        curr_min = arr[n - 1];
        rightMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            curr_min = min(arr[i], curr_min + arr[i]);
            rightMin[i] = min(rightMin[i + 1], curr_min);
        }

        // Step 4: Calculate the Maximum Absolute Difference
        int max_diff = 0;
        for (int i = 0; i < n - 1; ++i) {
            max_diff = max(max_diff, abs(leftMax[i] - rightMin[i + 1]));
            max_diff = max(max_diff, abs(leftMin[i] - rightMax[i + 1]));
        }

        return max_diff;
    }
};
