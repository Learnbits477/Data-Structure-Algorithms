#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;

        // Flatten the 2D grid into a 1D array
        vector<int> nums;
        nums.reserve(total);
        for (auto& row : grid)
            for (int val : row)
                nums.push_back(val);

        // Verify feasibility: all elements must have the same remainder mod x
        int rem = nums[0] % x;
        for (int v : nums)
            if (v % x != rem)
                return -1;

        // Sort to find the median efficiently
        sort(nums.begin(), nums.end());

        // The median minimises the sum of absolute differences
        int median = nums[total / 2];

        // Count total operations needed
        long long ops = 0;
        for (int v : nums)
            ops += abs(v - median) / x;

        return (int)ops;
    }
};
