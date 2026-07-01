#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();

        // Step 1 — Handle Base Cases and Initialize States
        if (n == 1) return arr[0];

        int max_no_del = arr[0];
        int max_one_del = arr[0];
        int overall_max = arr[0];

        // Step 2 — Single Pass DP State Transition
        for (int i = 1; i < n; i++) {
            // Update max_one_del using previous step's states
            max_one_del = max(max_no_del, max_one_del + arr[i]);
            
            // Update max_no_del (standard Kadane's ending at index i)
            max_no_del = max(arr[i], max_no_del + arr[i]);
            
            // Update the global maximum subarray sum found so far
            overall_max = max({overall_max, max_no_del, max_one_del});
        }

        // Step 3 — Return Results
        return overall_max;
    }
};
