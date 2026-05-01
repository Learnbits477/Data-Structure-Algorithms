#include <iostream>
#include <vector>
#include <numeric>
#include <climits>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Compute F(0) and total sum in one pass
        long long F = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            F   += (long long)i * nums[i];
            sum += nums[i];
        }

        // Step 2: Apply recurrence F(k) = F(k-1) + sum - n * nums[n-k]
        long long maxF = F;
        for (int k = 1; k < n; k++) {
            F = F + sum - (long long)n * nums[n - k];
            maxF = max(maxF, F);
        }

        return (int)maxF;
    }
};
