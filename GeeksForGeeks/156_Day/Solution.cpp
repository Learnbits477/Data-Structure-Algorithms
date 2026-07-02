#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divisibleByK(vector<int>& arr, int k) {
        int n = arr.size();

        // Step 1 — Apply Pigeonhole Principle Check
        if (n >= k) {
            return true;
        }

        // Step 2 — Initialize DP Table
        vector<bool> dp(k, false);

        // Step 3 — Iterate and Transition States
        for (int x : arr) {
            int rem = x % k;
            vector<bool> next_dp = dp;
            
            // Check if adding the current element to any existing subset sum modulo k yields a new remainder
            for (int j = 0; j < k; j++) {
                if (dp[j]) {
                    next_dp[(j + rem) % k] = true;
                }
            }
            // Mark the single element remainder as reachable
            next_dp[rem] = true;
            dp = next_dp;

            // Early Exit: if we found a non-empty subset sum divisible by k
            if (dp[0]) {
                return true;
            }
        }

        // Step 4 — Return Failure
        return false;
    }
};
