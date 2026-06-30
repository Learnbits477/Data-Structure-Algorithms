#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string chooseSwap(string &s) {
        int n = s.size();
        
        // Step 1 — Track First Occurrences
        vector<int> first(26, -1);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) first[idx] = i;
        }
        
        string ans = s;
        
        // Step 2 — Find First Swappable Character
        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a';
            int best = -1;
            
            for (int ch = 0; ch < cur; ch++) {
                if (first[ch] != -1 && first[ch] > i) {
                    best = ch;
                    break;
                }
            }
            
            // Step 3 — Perform Swap and Return
            if (best != -1) {
                char a = 'a' + best;
                char b = 'a' + cur;
                
                for (char &c : ans) {
                    if (c == a) c = b;
                    else if (c == b) c = a;
                }
                
                return ans;
            }
        }
        
        return ans;
    }
};
