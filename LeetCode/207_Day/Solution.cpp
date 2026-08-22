#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sumDigits = 0;
        long long prodDigits = 1;
        int temp = n;

        // Step 1: Extract digits to compute sum and product
        while (temp > 0) {
            int digit = temp % 10;
            sumDigits += digit;
            prodDigits *= digit;
            temp /= 10;
        }

        // Step 2: Combine sum and product
        long long total = sumDigits + prodDigits;

        // Step 3: Check divisibility
        if (total == 0) return false;
        return (n % total == 0);
    }
};
