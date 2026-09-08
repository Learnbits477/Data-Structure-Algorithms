#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Step 1 & 2: Calculate total commas formatted in all numbers in [1, n]
    int countCommas(int n) {
        // Numbers with fewer than 4 digits (1 to 999) contain 0 commas
        if (n < 1000) {
            return 0;
        }

        // For n <= 10^5, each number in [1000, n] contains exactly 1 comma
        return n - 999;
    }

    // General method that supports arbitrarily large n (e.g. n >= 10^6, 10^9)
    long long countCommasExtended(long long n) {
        long long total = 0;
        long long threshold = 1000;

        while (n >= threshold) {
            total += (n - threshold + 1);
            if (threshold > LLONG_MAX / 1000) break;
            threshold *= 1000;
        }

        return total;
    }
};
