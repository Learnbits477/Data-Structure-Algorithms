#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        // Step 1: Find Global Minimum and Maximum
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        long long min_val = *min_it;
        long long max_val = *max_it;

        // Step 2: Calculate Maximum Subarray Value
        long long max_diff = max_val - min_val;

        // Step 3: Multiply by k
        return max_diff * k;
    }
};
