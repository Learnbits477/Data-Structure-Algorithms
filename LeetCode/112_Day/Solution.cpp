#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Initialize Two Pointers
        int i = 0, j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Step 2: Traverse and Compare
        while (i < n1 && j < n2) {
            // Step 3: Handle Match
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
            // Step 4: Advance Pointers
            else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        // Step 5: Return Default
        return -1;
    }
};
