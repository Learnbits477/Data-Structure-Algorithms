#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to calculate (base^exp) in O(log exp) time
    long long power(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }

public:
    int maxProduct(int n) {
        // Step 1 — Handle base cases where n < 4
        if (n == 2) return 1;
        if (n == 3) return 2;

        // Step 2 — Compute quotient and remainder when n is divided by 3
        int count3 = n / 3;
        int remainder = n % 3;

        // Step 3 — Optimize the division of 3s and calculate powers using binary exponentiation
        if (remainder == 1) {
            return power(3, count3 - 1) * 4;
        } else if (remainder == 2) {
            return power(3, count3) * 2;
        } else {
            return power(3, count3);
        }
    }
};
