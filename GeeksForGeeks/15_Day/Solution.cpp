#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long calculateCost(const vector<int>& h, const vector<int>& cost, int targetH) {
        long long totalCost = 0;
        for (size_t i = 0; i < h.size(); ++i) {
            totalCost += (long long)abs(h[i] - targetH) * cost[i];
        }
        return totalCost;
    }

    long long minCost(vector<int>& h, vector<int>& cost) {
        int low = INT_MAX, high = INT_MIN;
        for (int val : h) {
            low = min(low, val);
            high = max(high, val);
        }

        while (high - low > 2) {
            int m1 = low + (high - low) / 3;
            int m2 = high - (high - low) / 3;
            
            long long cost1 = calculateCost(h, cost, m1);
            long long cost2 = calculateCost(h, cost, m2);

            if (cost1 < cost2) {
                high = m2;
            } else {
                low = m1;
            }
        }

        long long ans = LLONG_MAX;
        for (int i = low; i <= high; ++i) {
            ans = min(ans, calculateCost(h, cost, i));
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> h1 = {1, 2, 3};
    vector<int> cost1 = {10, 100, 1000};
    cout << "Test 1: " << sol.minCost(h1, cost1) << " Expected: 120" << endl;

    // Example 2
    vector<int> h2 = {7, 1, 5};
    vector<int> cost2 = {1, 1, 1};
    cout << "Test 2: " << sol.minCost(h2, cost2) << " Expected: 6" << endl;

    return 0;
}
