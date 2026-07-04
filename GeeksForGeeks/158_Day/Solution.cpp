#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubstring(string s) {
        int n = s.length();

        // Step 1 — Initialize Arrays and Offset Variables
        vector<int> freq(2 * n + 5, 0);
        freq[0 + n] = 1;
        long long ans = 0;
        int current_P = 0;
        int C = 0;

        // Step 2 — Iterate Through the String
        for (int k = 0; k < n; k++) {
            
            // Step 3 — Apply Constant Time State Transitions
            if (s[k] == '1') {
                C = C + freq[current_P + n];
                current_P = current_P + 1;
                ans += C;
                freq[current_P + n]++;
            } else {
                current_P = current_P - 1;
                C = C - freq[current_P + n];
                ans += C;
                freq[current_P + n]++;
            }
        }

        // Step 4 — Return the Result
        return ans;
    }
};
