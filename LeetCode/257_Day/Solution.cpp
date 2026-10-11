#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        // Step: 01 - Determine array size and initialize accumulator
        int n = nums.size();
        int totalSum = 0;

        // Step: 02 - Iterate through all 1-indexed positions
        for (int i = 0; i < n; i++) {
            // Step: 03 - Check if 1-indexed position divides n
            if (n % (i + 1) == 0) {
                totalSum += nums[i] * nums[i];
            }
        }

        // Step: 04 - Return accumulated sum of squares
        return totalSum;
    }

    int sumOfSquaresDivisors(vector<int>& nums) {
        // Step: 01 - Determine array size and initialize sum
        int n = nums.size();
        int totalSum = 0;

        // Step: 02 - Enumerate divisor pairs up to square root of n
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                // Step: 03 - Add square of element at divisor index d
                totalSum += nums[d - 1] * nums[d - 1];

                // Step: 04 - Add paired divisor element if distinct
                int complement = n / d;
                if (complement != d) {
                    totalSum += nums[complement - 1] * nums[complement - 1];
                }
            }
        }

        // Step: 05 - Return total sum of squares from divisors
        return totalSum;
    }
};
