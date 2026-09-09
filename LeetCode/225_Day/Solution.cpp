#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Step 1: Calculate total commas formatted in all numbers in [1, n]
    // Uses threshold decomposition: each tier (10^3, 10^6, 10^9, ...) adds 1 comma
    // for all numbers >= that threshold.
    long long countCommas(long long n) {
        long long total = 0;
        long long threshold = 1000; // First comma appears at 1,000

        // Step 2: Iterate through each threshold tier
        while (threshold <= n) {
            total += (n - threshold + 1);

            // Prevent integer overflow when advancing threshold
            if (threshold > LLONG_MAX / 1000) {
                break;
            }
            threshold *= 1000;
        }

        return total;
    }
};
