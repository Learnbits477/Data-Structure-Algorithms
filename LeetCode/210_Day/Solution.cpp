#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // Step 1: Insert all elements into a hash set for O(1) membership lookups
        unordered_set<int> present(nums.begin(), nums.end());

        // Step 2: Test positive multiples of k (k, 2k, 3k, ...) in increasing order
        int multiple = k;
        while (present.count(multiple)) {
            multiple += k;
        }

        // Step 3: Return the smallest missing multiple
        return multiple;
    }
};
