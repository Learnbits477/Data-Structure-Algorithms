#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost, int w) {
        int n = cost.size();
        const int INF = INT_MAX;
        vector<int> dp(w + 1, INF);
        dp[0] = 0;

        for (int j = 1; j <= w; j++) {
            for (int i = 0; i < n && (i + 1) <= j; i++) {
                if (cost[i] == -1) continue;
                if (dp[j - (i + 1)] == INF) continue;
                dp[j] = min(dp[j], cost[i] + dp[j - (i + 1)]);
            }
        }

        return (dp[w] == INF) ? -1 : dp[w];
    }
};
