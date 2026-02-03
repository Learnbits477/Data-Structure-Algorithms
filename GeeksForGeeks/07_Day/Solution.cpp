#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#ifndef SOLUTION_H
#define SOLUTION_H

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }
        return maxProfit;
    }
};

#endif // SOLUTION_H

// Optional: Add a main function for standalone testing if needed
// This block will only be active if compiled directly, not when included in TestSolution
#ifndef SKIP_SOLUTION_MAIN
#include <iostream>
int main() {
    Solution sol;
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
#endif // SKIP_SOLUTION_MAIN

