#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int calculateWaviness(int n) {
        // Step 2: Handle Small Numbers
        if (n < 100) return 0;
        
        int count = 0;
        // Step 3: Digit Extraction Initialization
        int right = n % 10;
        n /= 10;
        int mid = n % 10;
        n /= 10;
        
        // Step 4: Shift and Compare
        while (n > 0) {
            int left = n % 10;
            
            // Step 5: Peak and Valley Check
            if (mid > left && mid > right) {
                count++;
            } else if (mid < left && mid < right) {
                count++;
            }
            
            // Step 6: Shift Pointers
            right = mid;
            mid = left;
            n /= 10;
        }
        
        return count;
    }

public:
    int totalWaviness(int num1, int num2) {
        int total_waviness = 0;
        
        // Step 1: Iterate Through the Range
        for (int i = num1; i <= num2; ++i) {
            // Step 7: Accumulate
            total_waviness += calculateWaviness(i);
        }
        
        return total_waviness;
    }
};
