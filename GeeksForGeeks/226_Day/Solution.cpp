#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    // Step 1: Divisibility check & coprime factor pair counting for GCD = x and LCM = y
    int pairCount(int x, int y) {
        // Step 1: LCM must be divisible by GCD
        if (y % x != 0) {
            return 0;
        }

        // Step 2: Calculate quotient n = y / x
        int n = y / x;
        int count = 0;

        // Step 3: Iterate through all divisors up to sqrt(n)
        for (int i = 1; 1LL * i * i <= n; i++) {
            if (n % i == 0) {
                int j = n / i;

                // Step 3.1: Check if factors i and j are coprime
                if (gcd(i, j) == 1) {
                    if (i == j) {
                        count += 1;
                    } else {
                        count += 2; // (i*x, j*x) and (j*x, i*x)
                    }
                }
            }
        }

        // Step 4: Return total valid pairs
        return count;
    }

    // Aliases for compatibility
    int countPairs(int x, int y) {
        return pairCount(x, y);
    }
};
