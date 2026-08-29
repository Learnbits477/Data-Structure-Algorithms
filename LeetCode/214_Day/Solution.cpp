#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        if (n <= 1) return nums;

        // Step 1: Pair each element with its original index
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }

        // Step 2: Sort elements in ascending order by value
        sort(sorted_nums.begin(), sorted_nums.end());

        // Step 3: Identify connected components
        // Elements belong to the same component if and only if consecutive sorted differences <= limit
        vector<int> result(n);
        int L = 0;
        while (L < n) {
            int R = L + 1;
            while (R < n && sorted_nums[R].first - sorted_nums[R - 1].first <= limit) {
                R++;
            }

            // Component spans [L, R - 1] in sorted_nums
            // Extract the original indices of this component
            vector<int> indices;
            indices.reserve(R - L);
            for (int i = L; i < R; ++i) {
                indices.push_back(sorted_nums[i].second);
            }

            // Sort indices in ascending order to greedily assign smallest values to smallest positions
            sort(indices.begin(), indices.end());

            // Assign values to sorted indices
            for (size_t i = 0; i < indices.size(); ++i) {
                result[indices[i]] = sorted_nums[L + i].first;
            }

            L = R;
        }

        return result;
    }
};
