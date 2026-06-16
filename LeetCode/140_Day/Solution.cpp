#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        // Step 1 — Initialize result string
        string res = "";
        
        // Step 2 — Iterate through characters
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                // Step 2.1 — Lowercase English letter
                res += c;
            } else if (c == '*') {
                // Step 2.2 — Asterisk (*)
                if (!res.empty()) {
                    res.pop_back();
                }
            } else if (c == '#') {
                // Step 2.3 — Hash (#)
                res += res;
            } else if (c == '%') {
                // Step 2.4 — Percent (%)
                reverse(res.begin(), res.end());
            }
        }
        
        // Step 3 — Return result
        return res;
    }
};
