#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        // Step 1 — String Conversion
        string s_val = to_string(n);
        long long x = 0;
        long long sum_digits = 0;
        
        // Step 2 — Traversal and Filtering
        for (char c : s_val) {
            if (c != '0') {
                int digit = c - '0';
                x = x * 10 + digit;
                sum_digits += digit;
            }
        }
        
        // Step 3 — Multiply and Return
        return x * sum_digits;
    }
};
