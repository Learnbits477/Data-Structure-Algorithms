#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        // Augment string with '1' at both ends
        string t = "1" + s + "1";
        
        vector<int> ones;
        vector<int> zeros;
        
        int len = t.length();
        int i = 0;
        
        // Parse alternating blocks of '1's and '0's
        while (i < len) {
            int o_cnt = 0;
            while (i < len && t[i] == '1') {
                o_cnt++;
                i++;
            }
            ones.push_back(o_cnt);
            
            if (i >= len) break;
            
            int z_cnt = 0;
            while (i < len && t[i] == '0') {
                z_cnt++;
                i++;
            }
            zeros.push_back(z_cnt);
        }
        
        int original_ones = 0;
        for (char c : s) {
            if (c == '1') original_ones++;
        }
        
        int k = ones.size();
        // If there are fewer than 3 blocks of '1's, no internal block of '1's
        // surrounded by '0's exists to perform a trade.
        if (k < 3) {
            return original_ones;
        }
        
        // Find the maximum gain from merging zeros[j-1] and zeros[j]
        // around internal ones block j (1 <= j <= k - 2)
        int max_gain = 0;
        for (int j = 1; j <= k - 2; ++j) {
            int gain = zeros[j - 1] + zeros[j];
            max_gain = max(max_gain, gain);
        }
        
        return original_ones + max_gain;
    }

    // Alias for compatibility
    int maxActiveSections(string s) {
        return maxActiveSectionsAfterTrade(s);
    }
};
