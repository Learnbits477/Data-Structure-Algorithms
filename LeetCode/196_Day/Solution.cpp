#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // Step 1: Find the longest sequential prefix sum.
        int sum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Step 2: Store all elements of nums in a hash set.
        unordered_set<int> present(nums.begin(), nums.end());

        // Step 3: Find the smallest missing integer >= sum.
        int x = sum;
        while (present.count(x)) {
            x++;
        }

        return x;
    }
};
