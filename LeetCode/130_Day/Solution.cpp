#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        // Step 1: Calculate Total Sum
        int rightSum = 0;
        for (int num : nums) {
            rightSum += num;
        }
        
        // Step 2: Initialize Answer Array
        int leftSum = 0;
        vector<int> answer(nums.size());
        
        // Step 3: Iterate and Compute Differences
        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i]; // Remove current element from right sum
            answer[i] = abs(leftSum - rightSum);
            leftSum += nums[i];  // Add current element to left sum
        }
        
        // Step 4: Return Result
        return answer;
    }
};
