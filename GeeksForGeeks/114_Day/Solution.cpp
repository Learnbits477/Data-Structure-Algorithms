#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBitSet(int n) {
        // Step 1: Check Edge Cases
        if (n == 0) {
            return false;
        }

        // Step 2: Perform Bitwise Check
        // If all bits are set, n & (n + 1) will be 0.
        return (n & (n + 1)) == 0;
    }
};
