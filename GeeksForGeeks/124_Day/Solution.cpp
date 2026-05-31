#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeSumofConsec(int n) {
        // Step 1: Check if the Number is a Power of 2
        // Step 2: Bitwise Trick
        // Step 3: Return Result
        return (n & (n - 1)) != 0;
    }
};
