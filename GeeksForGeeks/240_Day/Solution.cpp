#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree (Binary Indexed Tree) maintaining prefix maximums
class FenwickTree {
private:
    int size;
    vector<long long> tree;

public:
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    // Update the prefix maximum at index idx
    void update(int idx, long long val) {
        for (; idx <= size; idx += (idx & -idx)) {
            tree[idx] = max(tree[idx], val);
        }
    }

    // Query maximum value in range [1, idx]
    long long query(int idx) {
        long long maxVal = 0;
        for (; idx > 0; idx -= (idx & -idx)) {
            maxVal = max(maxVal, tree[idx]);
        }
        return maxVal;
    }
};

class Solution {
public:
    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();
        if (n == 0) return 0;

        // Step 1: Pair radius and height for each disc
        vector<pair<int, int>> discs(n);
        vector<int> uniqueH(n);
        for (int i = 0; i < n; ++i) {
            discs[i] = {r[i], h[i]};
            uniqueH[i] = h[i];
        }

        // Step 2: Coordinate compression on disc heights
        sort(uniqueH.begin(), uniqueH.end());
        uniqueH.erase(unique(uniqueH.begin(), uniqueH.end()), uniqueH.end());
        int m = uniqueH.size();

        // Step 3: Sort discs: primary key radius ascending, secondary key height descending
        // Sorting height descending ensures that discs with the same radius cannot stack on one another
        sort(discs.begin(), discs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        // Step 4: Initialize Fenwick tree over compressed height ranks
        FenwickTree ft(m);
        long long maxTotalHeight = 0;

        // Step 5: Process each disc sequentially
        for (const auto& disc : discs) {
            int height = disc.second;

            // Find 1-based rank of current disc's height
            int rank = lower_bound(uniqueH.begin(), uniqueH.end(), height) - uniqueH.begin() + 1;

            // Query maximum chain height with strictly smaller height (rank - 1)
            long long prevBest = ft.query(rank - 1);
            long long currentHeight = prevBest + height;

            // Update Fenwick Tree with the new cumulative stack height
            ft.update(rank, currentHeight);

            maxTotalHeight = max(maxTotalHeight, currentHeight);
        }

        return static_cast<int>(maxTotalHeight);
    }

    // Platform alias methods
    int maxHeight(vector<int>& r, vector<int>& h) {
        return maxStackHeight(r, h);
    }

    int stackingUpDiscs(vector<int>& r, vector<int>& h) {
        return maxStackHeight(r, h);
    }
};
