#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMarks(vector<int>& l, vector<int>& r, vector<int>& rank) {
        int n = l.size();
        
        // Step 1: Precompute Prefix Sums of Interval Sizes
        // pref[i] stores the cumulative count of marks in intervals 0 through i
        vector<long long> pref(n, 0);
        for (int i = 0; i < n; ++i) {
            long long len = static_cast<long long>(r[i]) - l[i] + 1;
            pref[i] = (i == 0 ? len : pref[i - 1] + len);
        }

        // Step 2: Process Rank Queries via Binary Search
        vector<int> result;
        result.reserve(rank.size());

        for (int R : rank) {
            // Find the first interval whose cumulative marks reach or exceed rank R
            auto it = lower_bound(pref.begin(), pref.end(), static_cast<long long>(R));
            int idx = distance(pref.begin(), it);

            // Cumulative count of marks before this interval
            long long prev_pref = (idx > 0 ? pref[idx - 1] : 0LL);

            // Calculate mark based on the starting value and 1-based offset
            int mark = l[idx] + static_cast<int>(R - prev_pref - 1);
            result.push_back(mark);
        }

        // Step 3: Return Answer
        return result;
    }

    // Alias to support potential alternative driver function naming
    vector<int> findMarks(vector<int>& l, vector<int>& r, vector<int>& rank) {
        return getMarks(l, r, rank);
    }
};
