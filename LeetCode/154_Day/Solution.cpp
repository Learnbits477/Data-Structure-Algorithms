#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        // Step 1: Initialize Trackers
        vector<int> last(3, -1);
        int ans = 0;
        int n = s.length();
        
        // Step 2: Traverse the String
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
            int min_idx = min({last[0], last[1], last[2]});
            ans += min_idx + 1;
        }
        
        // Step 3: Return Result
        return ans;
    }
};
