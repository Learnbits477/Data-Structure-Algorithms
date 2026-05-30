#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        // Step 1: Find max coordinate; set right sentinel
        int maxX = 0;
        for (auto& q : queries) maxX = max(maxX, q[1]);
        int sentinel = maxX + 1, N = sentinel;

        // Step 2: BIT for prefix maximum (gap keyed at its right endpoint)
        vector<int> bit(N + 2, 0);

        auto bitUpdate = [&](int pos, int val) {
            for (int i = pos + 1; i < (int)bit.size(); i += i & -i)
                bit[i] = max(bit[i], val);
        };

        auto bitQuery = [&](int pos) -> int {
            int res = 0;
            for (int i = pos + 1; i > 0; i -= i & -i)
                res = max(res, bit[i]);
            return res;
        };

        // Step 3: Pre-place all type-1 obstacles (we process in reverse)
        set<int> obs = {0, sentinel};
        for (auto& q : queries)
            if (q[0] == 1) obs.insert(q[1]);

        // Step 4: Initialise BIT with gaps between consecutive obstacles
        for (auto it = next(obs.begin()); it != obs.end(); ++it)
            bitUpdate(*it, *it - *prev(it));

        // Step 5: Process queries in reverse; type-1 becomes removal (gaps only grow)
        vector<bool> results;
        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            auto& q = queries[i];
            if (q[0] == 2) {
                int x = q[1], sz = q[2];
                auto it = obs.upper_bound(x); --it;
                int prevObs = *it;
                results.push_back(max(x - prevObs, bitQuery(prevObs)) >= sz);
            } else {
                auto it = obs.find(q[1]);
                int p = *std::prev(it), n = *std::next(it);
                bitUpdate(n, n - p);
                obs.erase(it);
            }
        }

        reverse(results.begin(), results.end());
        return results;
    }
};
