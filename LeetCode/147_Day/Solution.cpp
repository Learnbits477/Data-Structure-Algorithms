#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfArrays(int n, int l, int r) {
        int MOD = 1e9 + 7;
        int m = r - l + 1;
        if (m <= 1) return 0;
        
        // Step 1: Setup Base Arrays
        vector<long long> dp_up(m, 0);
        vector<long long> dp_down(m, 0);
        
        // Step 2: Base Case (Length 2)
        for (int v = 0; v < m; ++v) {
            dp_up[v] = v;
            dp_down[v] = m - 1 - v;
        }
        
        // Step 3: Fill DP Table (Length 3 to n)
        for (int i = 3; i <= n; ++i) {
            vector<long long> next_up(m, 0);
            vector<long long> next_down(m, 0);
            
            // next_up[v] = sum_{u < v} dp_down[u]
            long long sum_down = 0;
            for (int v = 0; v < m; ++v) {
                next_up[v] = sum_down;
                sum_down = (sum_down + dp_down[v]) % MOD;
            }
            
            // next_down[v] = sum_{u > v} dp_up[u]
            long long sum_up = 0;
            for (int v = m - 1; v >= 0; --v) {
                next_down[v] = sum_up;
                sum_up = (sum_up + dp_up[v]) % MOD;
            }
            
            dp_up = move(next_up);
            dp_down = move(next_down);
        }
        
        // Step 4: Compute Total Answer
        long long ans = 0;
        for (int v = 0; v < m; ++v) {
            ans = (ans + dp_up[v] + dp_down[v]) % MOD;
        }
        
        return ans;
    }
};
