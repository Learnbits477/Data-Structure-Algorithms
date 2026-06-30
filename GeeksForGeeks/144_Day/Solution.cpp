#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastDigit(string& a, string& b) {
        // Step 1 — Handle Base Cases and Exponent Zero
        if (b == "0") return 1;
        int d = a.back() - '0';
        if (d == 0) return 0;

        // Step 2 — Compute Exponent Modulo 4
        int rem = 0;
        for (char c : b) {
            rem = (rem * 10 + (c - '0')) % 4;
        }
        int exp = (rem == 0) ? 4 : rem;

        // Step 3 — Compute Last Digit using Power Cycle
        int res = 1;
        for (int i = 0; i < exp; ++i) {
            res = (res * d) % 10;
        }

        return res;
    }
};
