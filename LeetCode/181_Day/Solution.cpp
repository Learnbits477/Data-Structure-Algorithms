#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Step 1: Initialize Max Trackers
        int max1 = 0;
        int max2 = 0;

        // Step 2: Single Pass Evaluation
        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }

        // Step 3: Compute Product
        return (max1 - 1) * (max2 - 1);
    }
};
