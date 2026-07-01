#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Step 1: Count Character Frequencies
        vector<int> freq(26, 0);
        for (char c : text) {
            freq[c - 'a']++;
        }
        
        // Step 2: Extract Relevant Counts
        int b = freq['b' - 'a'];
        int a = freq['a' - 'a'];
        int l = freq['l' - 'a'] / 2;
        int o = freq['o' - 'a'] / 2;
        int n = freq['n' - 'a'];
        
        // Step 3: Return Bottleneck Minimum
        return min({b, a, l, o, n});
    }
};
