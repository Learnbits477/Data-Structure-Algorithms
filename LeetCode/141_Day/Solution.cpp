#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> sizes(n);
        long long current_len = 0;
        
        // Step 1 — Forward Pass: Compute and store string lengths
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                if (current_len > 0) {
                    current_len--;
                }
            } else if (s[i] == '#') {
                current_len *= 2;
            } else if (s[i] == '%') {
                // Keep length unchanged
            } else {
                current_len++;
            }
            sizes[i] = current_len;
        }
        
        // Step 2 — Boundary Check
        if (k >= current_len || k < 0) {
            return '.';
        }
        
        // Step 3 — Reverse Pass: Trace index k backwards
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '*') {
                continue;
            } else if (s[i] == '#') {
                if (k >= sizes[i] / 2) {
                    k -= sizes[i] / 2;
                }
            } else if (s[i] == '%') {
                k = sizes[i] - 1 - k;
            } else {
                if (k == sizes[i] - 1) {
                    return s[i];
                }
            }
        }
        return '.';
    }
};
