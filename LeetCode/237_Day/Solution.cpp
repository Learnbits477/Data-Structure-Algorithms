#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        // dp[r]: number of subarrays ending at the previous element with product % k == r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);
            int numMod = num % k;

            // Start a single-element subarray with current element
            newDp[numMod]++;

            // Extend all subarrays ending at the previous position
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int nextRem = (static_cast<long long>(r) * numMod) % k;
                    newDp[nextRem] += dp[r];
                }
            }

            // Accumulate the counts for all subarrays ending at this index
            for (int r = 0; r < k; ++r) {
                ans[r] += newDp[r];
            }

            dp = move(newDp);
        }

        return ans;
    }

    // Alias method for problem title alignment
    vector<long long> findXValue(vector<int>& nums, int k) {
        return resultArray(nums, k);
    }
};
