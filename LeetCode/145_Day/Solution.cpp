#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Step 1: Sort Costs
        sort(costs.begin(), costs.end());
        
        // Step 2: Initialize Count
        int count = 0;
        
        // Step 3: Buy Ice Cream Bars
        for (int cost : costs) {
            if (coins >= cost) {
                coins -= cost;
                count++;
            } else {
                break;
            }
        }
        
        // Step 4: Return Result
        return count;
    }
};
