#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCharGap(string s) {
        int n = s.length();
        
        // Step 1 — Initialize Arrays and Offset Variables
        vector<int> firstOccur(26, -1);
        int maxGap = -1;
        
        // Step 2 — Iterate Through the String
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            
            // Step 3 — Apply Constant Time State Transitions
            if (firstOccur[idx] == -1) {
                firstOccur[idx] = i;
            } else {
                int gap = i - firstOccur[idx] - 1;
                maxGap = max(maxGap, gap);
            }
        }
        
        // Step 4 — Return the Result
        return maxGap;
    }
};
