#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findIndex(string str) {
        int n = str.length();
        
        // Step 1: Count total closing brackets
        int total_closing = 0;
        for (char c : str) {
            if (c == ')') {
                total_closing++;
            }
        }
        
        int open_count = 0;
        int close_count = 0;
        
        // Step 2: Iterate to find the equal point
        for (int k = 0; k <= n; ++k) {
            if (open_count == (total_closing - close_count)) {
                return k;
            }
            
            if (k < n) {
                if (str[k] == '(') {
                    open_count++;
                } else if (str[k] == ')') {
                    close_count++;
                }
            }
        }
        
        return -1;
    }
};
