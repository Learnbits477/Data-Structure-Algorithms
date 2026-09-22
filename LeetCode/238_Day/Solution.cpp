#include <bits/stdc++.h>
using namespace std;

#ifndef SEGMENT_TREE_NODE_3525
#define SEGMENT_TREE_NODE_3525
struct Node {
    int remain[5] = {0}; // remain[r]: number of prefixes with product % k == r
    int prod = 1;        // total product of elements in the segment modulo k
};
#endif

class SegmentTree {
public:
    explicit SegmentTree(const vector<int>& nums, int k)
        : n(nums.size()), k(k), tree(4 * nums.size()) {
        build(nums, 0, 0, n - 1);
    }

    // Updates nums[idx] to val % k
    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    // Range query returning merged Node for interval [i, j]
    Node query(int i, int j) const {
        return query(0, 0, n - 1, i, j);
    }

private:
    const int n;
    const int k;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) const {
        Node node;
        node.prod = (left.prod * right.prod) % k;
        for (int i = 0; i < k; ++i) {
            node.remain[i] = left.remain[i];
        }
        for (int i = 0; i < k; ++i) {
            node.remain[(i * left.prod) % k] += right.remain[i];
        }
        return node;
    }

    void build(const vector<int>& nums, int treeIndex, int lo, int hi) {
        if (lo == hi) {
            tree[treeIndex].remain[nums[lo]] = 1;
            tree[treeIndex].prod = nums[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(nums, 2 * treeIndex + 1, lo, mid);
        build(nums, 2 * treeIndex + 2, mid + 1, hi);
        tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
    }

    void update(int treeIndex, int lo, int hi, int idx, int val) {
        if (lo == hi) {
            for (int r = 0; r < k; ++r) {
                tree[treeIndex].remain[r] = 0;
            }
            tree[treeIndex].remain[val] = 1;
            tree[treeIndex].prod = val;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (idx <= mid) {
            update(2 * treeIndex + 1, lo, mid, idx, val);
        } else {
            update(2 * treeIndex + 2, mid + 1, hi, idx, val);
        }
        tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
    }

    Node query(int treeIndex, int lo, int hi, int i, int j) const {
        if (i <= lo && hi <= j) {
            return tree[treeIndex];
        }
        int mid = lo + (hi - lo) / 2;
        if (j <= mid) {
            return query(2 * treeIndex + 1, lo, mid, i, j);
        }
        if (i > mid) {
            return query(2 * treeIndex + 2, mid + 1, hi, i, j);
        }
        return merge(query(2 * treeIndex + 1, lo, mid, i, j),
                     query(2 * treeIndex + 2, mid + 1, hi, i, j));
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        // Step: 01 - Pre-normalize all array elements modulo k
        for (int& num : nums) {
            num %= k;
        }

        // Step: 02 - Initialize Segment Tree over array [0, n - 1]
        const int n = nums.size();
        SegmentTree tree(nums, k);

        // Step: 03 - Prepare result buffer for queries
        vector<int> ans;
        ans.reserve(queries.size());

        // Step: 04 - Process each query sequentially
        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1] % k;
            int start = q[2];
            int x = q[3];

            // Step: 05 - Apply point update at index to persist for remaining queries
            tree.update(idx, val);

            // Step: 06 - Execute range query for active suffix elements starting from start
            Node res = tree.query(start, n - 1);

            // Step: 07 - Extract prefix count having product % k == x
            ans.push_back(res.remain[x]);
        }

        // Step: 08 - Return x-value results for all queries
        return ans;
    }

    // Alias method aligned with problem title
    vector<int> findXValue(vector<int>& nums, int k, vector<vector<int>>& queries) {
        return resultArray(nums, k, queries);
    }
};
