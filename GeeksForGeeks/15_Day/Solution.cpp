#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Helper function to calculate the total cost to make all towers reach 'targetH'
    long long calculateCost(const vector<int>& h, const vector<int>& cost, int targetH) {
        long long totalCost = 0;
        for (size_t i = 0; i < h.size(); ++i) {
            totalCost += (long long)abs(h[i] - targetH) * cost[i];
        }
        return totalCost;
    }

    // Main function to find the minimum cost to equalize heights
    long long minCost(vector<int>& h, vector<int>& cost) {
        int low = INT_MAX, high = INT_MIN;
        
        // Find the absolute minimum and maximum heights among all towers.
        // The optimal equalized height must lie in the range [low, high].
        for (int val : h) {
            low = min(low, val);
            high = max(high, val);
        }

        // The cost function is a convex function. We can use Ternary Search
        // to find the minimum of this convex function.
        while (high - low > 2) {
            int m1 = low + (high - low) / 3;
            int m2 = high - (high - low) / 3;
            
            long long cost1 = calculateCost(h, cost, m1);
            long long cost2 = calculateCost(h, cost, m2);

            // If cost at m1 is less than cost at m2, the minimum lies to the left of m2
            if (cost1 < cost2) {
                high = m2;
            } 
            // Otherwise, the minimum lies to the right of m1
            else {
                low = m1;
            }
        }

        // When the search space is reduced to <= 3 elements, 
        // find the minimum by evaluating all remaining possibilities.
        long long ans = LLONG_MAX;
        for (int i = low; i <= high; ++i) {
            ans = min(ans, calculateCost(h, cost, i));
        }
        
        return ans;
    }
};
