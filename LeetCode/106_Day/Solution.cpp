#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> delta(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int lo = min(nums[i], nums[n - 1 - i]);
            int hi = max(nums[i], nums[n - 1 - i]);

            delta[1 + lo]   -= 1;
            delta[lo + hi]  -= 1;

            delta[lo + hi + 1] += 1;

            delta[limit + hi + 1] += 1;
        }

        int total = n;
        int ans   = n;

        for (int T = 2; T <= 2 * limit; ++T) {
            total += delta[T];
            ans = min(ans, total);
        }

        return ans;
    }
};
