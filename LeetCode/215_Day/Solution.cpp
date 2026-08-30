#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Handle Base Cases
        if (n <= 2) {
            return n;
        }

        // Step 2: Find Indices of Min and Max elements in a single pass
        int min_idx = 0;
        int max_idx = 0;
        for (int k = 1; k < n; ++k) {
            if (nums[k] < nums[min_idx]) {
                min_idx = k;
            }
            if (nums[k] > nums[max_idx]) {
                max_idx = k;
            }
        }

        // Step 3: Order Indices so i <= j
        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);

        // Step 4: Compute Candidate Deletions for the three strategies
        // Option 1: Remove both elements from the front
        int both_front = j + 1;

        // Option 2: Remove both elements from the back
        int both_back = n - i;

        // Option 3: Remove i from front and j from back
        int both_sides = (i + 1) + (n - j);

        // Step 5: Return the minimum of all three options
        return min({both_front, both_back, both_sides});
    }
};
