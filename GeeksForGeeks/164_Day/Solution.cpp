#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCount(int n) {
        // Step 1: Initialize Count
        int count = 0;
        
        // Step 2: Iterate over Number of Terms
        for (long long k = 2; k * (k + 1) / 2 <= n; ++k) {
            
            // Step 3: Check Divisibility Condition
            long long numerator = n - (k * (k - 1) / 2);
            if (numerator % k == 0) {
                count++;
            }
        }
        
        // Step 4: Return Result
        return count;
    }
};
