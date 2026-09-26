#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Core function to find the minimum cost to buy pizzas with total area at least x
    int minCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        if (x <= 0) return 0;

        // dp[i] stores the minimum cost required to obtain at least i sq units of pizza
        vector<int> dp(x + 1, 0);

        for (int i = 1; i <= x; ++i) {
            // Option 1: Buy a Small pizza (area s, cost cs)
            int costSmall = dp[max(0, i - s)] + cs;

            // Option 2: Buy a Medium pizza (area m, cost cm)
            int costMedium = dp[max(0, i - m)] + cm;

            // Option 3: Buy a Large pizza (area l, cost cl)
            int costLarge = dp[max(0, i - l)] + cl;

            // Optimal choice is the minimum cost among the three pizza types
            dp[i] = min({costSmall, costMedium, costLarge});
        }

        return dp[x];
    }

    // Platform alias methods
    int findMinimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        return minCost(x, s, m, l, cs, cm, cl);
    }

    int getMinCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        return minCost(x, s, m, l, cs, cm, cl);
    }

    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        return minCost(x, s, m, l, cs, cm, cl);
    }

    int pizzaMania(int x, int s, int m, int l, int cs, int cm, int cl) {
        return minCost(x, s, m, l, cs, cm, cl);
    }
};
