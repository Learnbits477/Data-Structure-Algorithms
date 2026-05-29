#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        // Step 1: Initialise running minimum
        int minVal = INT_MAX;

        // Step 2: Iterate over every element
        for (int num : nums) {
            // Step 3: Compute digit sum
            int digitSum = 0;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }

            // Step 4: Update running minimum
            minVal = min(minVal, digitSum);
        }

        // Step 5: Return result
        return minVal;
    }
};
