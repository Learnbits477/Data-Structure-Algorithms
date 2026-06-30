#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Step 1 — Initialize Binary Search Bounds
        long long low = 0, high = 100000, ans = 0;
        
        // Step 2 — Perform Binary Search
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sum = mid * (mid + 1) * (2 * mid + 1) / 6;
            
            // Step 3 — Update Answer and Boundary
            if (sum <= p) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // Step 4 — Return Answer
        return ans;
    }
};
