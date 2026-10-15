#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // Step: 01 - Determine array size and initialize cumulative sum
        int n = static_cast<int>(nums.size());
        int totalSum = 0;

        // Step: 02 - Fix the left boundary of each subarray
        for (int i = 0; i < n; i++) {
            // Step: 03 - Maintain boolean presence table and running distinct count
            vector<bool> seen(101, false);
            int distinctCount = 0;

            // Step: 04 - Expand right boundary and accumulate square of distinct count
            for (int j = i; j < n; j++) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    distinctCount++;
                }
                totalSum += distinctCount * distinctCount;
            }
        }

        // Step: 05 - Return grand total of squared distinct counts
        return totalSum;
    }

    int sumCountsSet(vector<int>& nums) {
        // Step: 01 - Initialize size and running total
        int n = static_cast<int>(nums.size());
        int totalSum = 0;

        // Step: 02 - For each start position, track distinct elements using unordered_set
        for (int i = 0; i < n; i++) {
            unordered_set<int> distinctSet;
            for (int j = i; j < n; j++) {
                distinctSet.insert(nums[j]);
                int count = static_cast<int>(distinctSet.size());
                totalSum += count * count;
            }
        }

        // Step: 03 - Return aggregated sum
        return totalSum;
    }

    int sumCountsDynamic(vector<int>& nums) {
        // Step: 01 - Initialize tracking structures for last occurrences and subarray counts
        int n = static_cast<int>(nums.size());
        vector<int> lastPos(101, -1);
        vector<int> c(n, 0);
        int totalSum = 0;
        int currentEndingSumOfSquares = 0;

        // Step: 02 - Dynamically maintain distinct counts and square increments
        for (int j = 0; j < n; j++) {
            int val = nums[j];
            int prev = lastPos[val];

            // For all start indices k in (prev, j], distinct count c[k] increases by 1
            for (int k = prev + 1; k <= j; k++) {
                currentEndingSumOfSquares += 2 * c[k] + 1;
                c[k]++;
            }

            lastPos[val] = j;
            totalSum += currentEndingSumOfSquares;
        }

        // Step: 03 - Return total sum of squares
        return totalSum;
    }
};
