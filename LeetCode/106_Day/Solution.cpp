#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------
//  Solution — Minimum Moves to Make Array Complementary
//
//  Key Insight: Difference Array over Target Sum T
//  ─────────────────────────────────────────────────────────
//  For a pair (a, b) with lo = min(a,b), hi = max(a,b),
//  the minimum moves needed to make a+b = T is:
//
//    • T in [2,       lo]         → 2 moves  (must change both)
//    • T in [lo+1,    lo+hi-1]   → 1 move   (change smaller)
//    • T = lo+hi                  → 0 moves  (already perfect)
//    • T in [lo+hi+1, limit+hi]  → 1 move   (change larger)
//    • T in [limit+hi+1, 2*limit] → 2 moves (must change both)
//
//  Instead of iterating T for every pair (O(n·limit)), we use
//  a DIFFERENCE ARRAY to record cost changes at breakpoints:
//
//    delta[lo+1]       -= 1   (cost: 2 → 1)
//    delta[lo+hi]      -= 1   (cost: 1 → 0)
//    delta[lo+hi+1]    += 1   (cost: 0 → 1)
//    delta[limit+hi+1] += 1   (cost: 1 → 2)
//
//  Start with total = n  (n/2 pairs × 2 moves each).
//  Apply prefix sum over [2, 2*limit]; track the minimum.
//
//  Time  : O(n + limit)
//  Space : O(limit)
// -----------------------------------------------------------

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> delta(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int lo = min(nums[i], nums[n - 1 - i]);
            int hi = max(nums[i], nums[n - 1 - i]);

            delta[1 + lo]   -= 1;
            delta[lo + hi]  -= 1;

            delta[lo + hi + 1] += 1;

            delta[limit + hi + 1] += 1;
        }

        int total = n;
        int ans   = n;

        for (int T = 2; T <= 2 * limit; ++T) {
            total += delta[T];
            ans = min(ans, total);
        }

        return ans;
    }
};
