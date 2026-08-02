#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(int n, int m) {
        vector<vector<int>> relations(m + 1);
        
        for (int curr = 1; curr <= m; ++curr) {
            for (int d = 1; d * d <= curr; ++d) {
                if (curr % d == 0) {
                    relations[curr].push_back(d);
                    if (d * d != curr) {
                        relations[curr].push_back(curr / d);
                    }
                }
            }
            for (int mult = 2 * curr; mult <= m; mult += curr) {
                relations[curr].push_back(mult);
            }
            
            sort(relations[curr].begin(), relations[curr].end());
            relations[curr].erase(unique(relations[curr].begin(), relations[curr].end()), relations[curr].end());
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int j = 1; j <= m; ++j) {
            dp[1][j] = 1;
        }
        
        for (int i = 2; i <= n; ++i) {
            for (int curr = 1; curr <= m; ++curr) {
                for (int prev : relations[curr]) {
                    dp[i][curr] += dp[i - 1][prev];
                }
            }
        }
        
        int total = 0;
        for (int j = 1; j <= m; ++j) {
            total += dp[n][j];
        }
        
        return total;
    }
};
