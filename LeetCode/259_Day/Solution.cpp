#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // Step: 01 - Compute size and subtraction slot count
        int n = static_cast<int>(nums.size());
        int mid = n / 2;

        // Step: 02 - Convert each element into its square
        for (int i = 0; i < n; i++) {
            long long val = nums[i];
            nums[i] = static_cast<int>(val * val);
        }

        // Step: 03 - Sort the squared elements in ascending order
        sort(nums.begin(), nums.end());

        // Step: 04 - Accumulate alternating sum with smallest mid elements subtracted
        long long score = 0;
        for (int i = 0; i < n; i++) {
            if (i < mid) {
                score -= nums[i];
            } else {
                score += nums[i];
            }
        }

        // Step: 05 - Return maximum alternating score
        return score;
    }

    long long maxAlternatingSumQuickSelect(vector<int>& nums) {
        // Step: 01 - Determine array size and negative partition index
        int n = static_cast<int>(nums.size());
        int mid = n / 2;

        // Step: 02 - Partition elements using nth_element by squared value
        nth_element(nums.begin(), nums.begin() + mid, nums.end(), [](int a, int b) {
            return 1LL * a * a < 1LL * b * b;
        });

        // Step: 03 - Calculate alternating score across the linear partition
        long long score = 0;
        for (int i = 0; i < n; i++) {
            long long square = 1LL * nums[i] * nums[i];
            if (i < mid) {
                score -= square;
            } else {
                score += square;
            }
        }

        // Step: 04 - Return computed partition score
        return score;
    }

    long long maximumAlternatingSumOfSquares(vector<int>& nums) {
        // Step: 01 - Delegate to primary maxAlternatingSum implementation
        return maxAlternatingSum(nums);
    }
};
