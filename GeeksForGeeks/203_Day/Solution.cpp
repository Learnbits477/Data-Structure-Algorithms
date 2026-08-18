#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compress(string s) {
        int n = s.length();
        if (n == 0) return "";
        
        // Step 1: Compute Z-array
        vector<int> Z(n, 0);
        int L = 0, R = 0;
        for (int i = 1; i < n; i++) {
            if (i > R) {
                L = R = i;
                while (R < n && s[R - L] == s[R]) R++;
                Z[i] = R - L;
                R--;
            } else {
                int k = i - L;
                if (Z[k] < R - i + 1) {
                    Z[i] = Z[k];
                } else {
                    L = i;
                    while (R < n && s[R - L] == s[R]) R++;
                    Z[i] = R - L;
                    R--;
                }
            }
        }
        
        string ans = "";
        
        // Step 2: Backward Traversal
        int i = n - 1;
        while (i >= 0) {
            // Step 3: Greedy Compression
            if (i % 2 == 1 && Z[i / 2 + 1] >= (i + 1) / 2) {
                // Step 4: Append & Jump
                ans += '*';
                i /= 2;
            } else {
                ans += s[i];
                i--;
            }
        }
        
        // Step 5: Reverse Output
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
