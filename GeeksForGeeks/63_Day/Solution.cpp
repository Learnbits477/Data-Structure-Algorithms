#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Buy Stock with Transaction Fee
 * Source: https://www.geeksforgeeks.org/problems/buy-stock-with-transaction-fee/1
 * 
 * Approach: Dynamic Programming
 * We maintain two states:
 * 1. hold: Maximum profit we can have if we currently hold a stock.
 * 2. notHold: Maximum profit we can have if we do not hold a stock.
 * 
 * Transitions for day i:
 * hold[i] = max(hold[i-1], notHold[i-1] - arr[i])
 * notHold[i] = max(notHold[i-1], hold[i-1] + arr[i] - k)
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1) (since we only need the previous day's states)
 */

class Solution {
public:
    long long maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return 0;

        // hold: max profit if we have a stock in hand
        // notHold: max profit if we don't have a stock in hand
        long long hold = -arr[0];
        long long notHold = 0;

        for (int i = 1; i < n; i++) {
            // Update notHold: either we stay notHold, or we sell the stock we hold
            long long prevNotHold = notHold;
            notHold = max(notHold, hold + arr[i] - k);
            
            // Update hold: either we stay holding, or we buy a new stock using profit from notHold
            hold = max(hold, prevNotHold - arr[i]);
        }

        return notHold;
    }
};

int main() {
    // Example 1
    vector<int> arr1 = {6, 1, 7, 2, 8, 4};
    int k1 = 2;
    Solution sol;
    cout << "Example 1 Output: " << sol.maxProfit(arr1, k1) << " (Expected: 8)" << endl;

    // Example 2
    vector<int> arr2 = {7, 1, 5, 3, 6, 4};
    int k2 = 1;
    cout << "Example 2 Output: " << sol.maxProfit(arr2, k2) << " (Expected: 5)" << endl;

    return 0;
}
