#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Step 1: Compute prefix sums of stone values
        vector<int> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }

        // Step 2: Initialize DP with the base case (all stones merged)
        int dp = pref[n - 1];

        // Step 3: Transition backward from n - 2 down to 1
        for (int i = n - 2; i >= 1; --i) {
            dp = max(dp, pref[i] - dp);
        }

        // Step 4: Return the optimal score difference
        return dp;
    }
};
