#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // Step 1: Sort the Candies in descending order
        sort(cost.rbegin(), cost.rend());
        
        int totalCost = 0;
        
        // Step 2 & 3: Iterate Greedily and Accumulate Cost
        for (int i = 0; i < cost.size(); i++) {
            // We get every 3rd candy for free (0-indexed: index 2, 5, 8...)
            if ((i + 1) % 3 != 0) {
                totalCost += cost[i];
            }
        }
        
        // Step 4: Return Result
        return totalCost;
    }
};
