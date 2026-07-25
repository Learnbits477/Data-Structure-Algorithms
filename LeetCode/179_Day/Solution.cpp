#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0;
        int max2 = 0;
        
        // Step 1: Extract digits and track the two largest digits
        while (n > 0) {
            int digit = n % 10;
            if (digit > max1) {
                max2 = max1;
                max1 = digit;
            } else if (digit > max2) {
                max2 = digit;
            }
            n /= 10;
        }
        
        // Step 2: Return the product of the two largest digits
        return max1 * max2;
    }
};
