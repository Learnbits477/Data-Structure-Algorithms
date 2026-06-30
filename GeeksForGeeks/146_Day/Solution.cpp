#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        // Step 1 — Initialize Pointers
        int left = 0, right = n - 1;
        int ans = 0;

        // Step 2 — Compute Area and Shrink Window
        while (left < right) {
            int width = right - left - 1;
            int h = min(height[left], height[right]);
            ans = max(ans, h * width);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        // Step 3 — Return Maximum Area
        return ans;
    }
};
