#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

// -----------------------------------------------------------
//  Segment Tree
// -----------------------------------------------------------

class SegmentTree {
    int n;
    vector<long long> tree; // tree[node] = LCM of its range

    // Merge two child nodes into the parent.
    long long merge(long long left, long long right) {
        return lcm(left, right);
    }

    // ---- Internal recursive methods ----

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node,     start,   mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            // Leaf node — apply the update directly
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node,     start,   mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        // Recompute LCM from children after the path is updated
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(int node, int start, int end, int l, int r) {
        // No overlap
        if (r < start || end < l) return 1LL; // identity for LCM

        // Total overlap
        if (l <= start && end <= r) return tree[node];

        // Partial overlap — recurse into both children
        int mid = (start + end) / 2;
        long long leftLCM  = query(2 * node,     start,   mid, l, r);
        long long rightLCM = query(2 * node + 1, mid + 1, end, l, r);
        return merge(leftLCM, rightLCM);
    }

public:
    // Construct the segment tree from the given array.
    explicit SegmentTree(const vector<int>& arr) {
        n = (int)arr.size();
        tree.assign(4 * n, 1LL);
        build(arr, 1, 0, n - 1);
    }

    // Point update: set arr[idx] = val.
    void update(int idx, long long val) {
        update(1, 0, n - 1, idx, val);
    }

    // Range LCM query over [l, r].
    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

// -----------------------------------------------------------
//  Solution class (GFG-compatible interface)
// -----------------------------------------------------------

class Solution {
public:
    /**
     * Process all queries on the given array.
     *
     * @param arr     The initial array (0-indexed).
     * @param queries Each query is a vector of 3 integers:
     *                  Type 1 → [1, index, value]   (update)
     *                  Type 2 → [2, L, R]            (LCM range query)
     * @return        A vector of long long containing answers to
     *                all Type-2 queries, in order.
     */
    vector<long long> RangeLCMQuery(vector<int>& arr,
                                   vector<vector<int>>& queries) {
        SegmentTree seg(arr);
        vector<long long> result;

        for (auto& q : queries) {
            if (q[0] == 1) {
                // Update: set arr[q[1]] = q[2]
                seg.update(q[1], (long long)q[2]);
            } else {
                // Query: LCM of arr[q[1]..q[2]]
                result.push_back(seg.query(q[1], q[2]));
            }
        }
        return result;
    }
};
