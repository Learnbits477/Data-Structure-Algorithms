#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubstring(string s) {
        // Step 1: Variable Initialization
        int max_sum = -1;
        int current_sum = 0;
        
        // Step 2: Iterate through the string
        for (char c : s) {
            // Step 3: Value Mapping
            int val = (c == '0') ? 1 : -1;
            
            // Step 4: Update Running Sum
            current_sum += val;
            
            // Step 5: Update Maximum Sum
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
            
            // Step 6: Reset Negative Sums
            if (current_sum < 0) {
                current_sum = 0;
            }
        }
        
        // Step 7: Return Result
        return max_sum;
    }
};
