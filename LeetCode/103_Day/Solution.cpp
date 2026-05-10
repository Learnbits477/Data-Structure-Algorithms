#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        // Base case: 0 jumps to start at the first index
        dp[0] = 0;
        
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                // Check if index i was reachable from 0
                if (dp[i] != -1) {
                    long long diff = (long long)nums[j] - nums[i];
                    // Jump condition: -target <= nums[j] - nums[i] <= target
                    if (diff >= -target && diff <= target) {
                        dp[j] = max(dp[j], dp[i] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};
