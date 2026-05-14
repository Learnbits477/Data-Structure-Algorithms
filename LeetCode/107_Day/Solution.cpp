#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        if (nums.empty()) return false;

        // Step 1: Find the maximum value which represents our 'n'
        int max_val = *max_element(nums.begin(), nums.end());

        // Step 2: A good array must have exactly n + 1 elements
        if (nums.size() != max_val + 1) {
            return false;
        }

        // Step 3: Count frequencies
        vector<int> freq(max_val + 1, 0);
        for (int num : nums) {
            // If we see a number out of bounds (which shouldn't happen 
            // given the size check, but just in case), return false
            if (num > max_val || num <= 0) return false;
            freq[num]++;
        }

        // Step 4: Verify frequencies
        for (int i = 1; i < max_val; ++i) {
            if (freq[i] != 1) {
                return false;
            }
        }

        // The maximum value must appear exactly twice
        if (freq[max_val] != 2) {
            return false;
        }

        return true;
    }
};
