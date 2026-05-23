#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        // Step 1: Initialize Count and Size
        int count = 0;
        int n = nums.size();

        // Step 2: Count Circular Break Points
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // Step 3: Verify Rotated Sorted Property
        return count <= 1;
    }
};
