#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool balancePan(int a, int b) {
        // Step: 01 - Handle base 2 where binary representation is always balanceable
        if (a == 2) {
            return true;
        }

        // Step: 02 - Use 64-bit integer to prevent overflow during addition
        long long currentB = b;
        long long base = a;

        // Step: 03 - Process balanced base reduction while target weight remains positive
        while (currentB > 0) {
            long long rem = currentB % base;

            // Step: 04 - Check modular residue for valid balanced base coefficients
            if (rem == 0) {
                currentB /= base;
            } else if (rem == 1) {
                currentB = (currentB - 1) / base;
            } else if (rem == base - 1) {
                currentB = (currentB + 1) / base;
            } else {
                return false;
            }
        }

        // Step: 05 - Return true as target weight reached zero in balanced base
        return true;
    }

    bool balancePanRecursive(int a, int b) {
        // Step: 01 - Base case where target weight is zero
        if (b == 0) {
            return true;
        }

        // Step: 02 - Base case for binary system
        if (a == 2) {
            return true;
        }

        // Step: 03 - Compute residue modulo base
        long long rem = (long long)b % a;

        // Step: 04 - Recurse based on balanced base digit
        if (rem == 0 || rem == 1) {
            return balancePanRecursive(a, b / a);
        } else if (rem == a - 1) {
            return balancePanRecursive(a, (b + 1) / a);
        }

        // Step: 05 - Return false for invalid residue
        return false;
    }

    bool canBalance(int a, int b) {
        // Step: 01 - Alias wrapper for balancePan
        return balancePan(a, b);
    }

    bool isPossible(int a, int b) {
        // Step: 01 - Alias wrapper for balancePan
        return balancePan(a, b);
    }
};
