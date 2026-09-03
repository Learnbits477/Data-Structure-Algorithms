#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = INT_MAX;
        bool has_odd = false;

        // Step 1: Find the minimum value and check for the presence of odd numbers
        for (int x : nums1) {
            if (x < min_val) {
                min_val = x;
            }
            if (x % 2 != 0) {
                has_odd = true;
            }
        }

        // Step 2: Apply the parity decision rule
        // - If minimum element is odd: we can always make all elements odd
        // - If minimum element is even: we can only succeed if all elements are even
        if (min_val % 2 != 0) {
            return true;
        }

        return !has_odd;
    }

    // Aliases for compatibility with platform driver signatures
    bool canConstruct(vector<int>& nums1) {
        return uniformArray(nums1);
    }

    bool constructUniformParityArray(vector<int>& nums1) {
        return uniformArray(nums1);
    }
};
