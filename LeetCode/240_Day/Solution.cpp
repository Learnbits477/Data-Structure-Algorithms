#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to calculate the sum of decimal digits of a non-negative integer
    int computeDigitSum(int val) {
        int sum = 0;
        while (val > 0) {
            sum += val % 10;
            val /= 10;
        }
        return sum;
    }

public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Iterate sequentially from the smallest index 0 to n - 1
        for (int i = 0; i < n; ++i) {
            // Step 2: Compute digit sum for the current element
            if (computeDigitSum(nums[i]) == i) {
                // Step 3: First satisfying index encountered is guaranteed to be the smallest
                return i;
            }
        }

        // Step 4: No index satisfies the given condition
        return -1;
    }

    // Platform alias methods
    int smallestIndexWithDigitSum(vector<int>& nums) {
        return smallestIndex(nums);
    }
};
