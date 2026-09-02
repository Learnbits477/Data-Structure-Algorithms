#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // Step 1: Analyze parity invariant
        // - If all numbers are even, nums2 = nums1 gives all even.
        // - If all numbers are odd, nums2 = nums1 gives all odd.
        // - If mixed parity, choosing an odd number O allows every even number E
        //   to become odd via E - O = odd, resulting in all odd numbers.
        
        // Step 2: Unconditionally return true since a valid configuration is always possible
        return true;
    }

    // Aliases for compatibility
    bool canConstruct(vector<int>& nums1) {
        return uniformArray(nums1);
    }

    bool constructUniformParityArray(vector<int>& nums1) {
        return uniformArray(nums1);
    }
};
