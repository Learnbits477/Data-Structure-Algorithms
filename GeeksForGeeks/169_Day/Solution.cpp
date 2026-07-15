#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitonic(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        // Step 1: Initialize Variables
        int inc = 1;
        int dec = 1;
        int equal_run = 1;
        int inc_at_peak = 1;
        int max_len = 1;

        // Step 2: Traverse and Identify Trends
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                // Case A: Increasing
                if (dec > 1) {
                    // Transition from decreasing to increasing: inherit preceding equal elements
                    inc = equal_run + 1;
                    dec = 1;
                } else {
                    inc = inc + 1;
                }
                equal_run = 1;
                max_len = max(max_len, inc);
            } 
            else if (arr[i] < arr[i - 1]) {
                // Case B: Decreasing
                if (dec == 1) {
                    // Transition from increasing to decreasing: record peak length
                    inc_at_peak = inc;
                    dec = 2;
                } else {
                    dec = dec + 1;
                }
                inc = 1;
                equal_run = 1;
                max_len = max(max_len, inc_at_peak + dec - 1);
            } 
            else {
                // Case C: Flat/Equal
                equal_run = equal_run + 1;
                inc = inc + 1;
                if (dec > 1) {
                    dec = dec + 1;
                    max_len = max(max_len, inc_at_peak + dec - 1);
                } else {
                    max_len = max(max_len, inc);
                }
            }
        }

        // Step 3: Return Maximum Length
        return max_len;
    }
};
