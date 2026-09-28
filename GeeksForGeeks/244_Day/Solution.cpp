#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    vector<int> tree;

    // Helper function to calculate GCD using Euclidean algorithm
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    // Build the segment tree where each node stores the GCD of its corresponding segment
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }

    // Point update: Update element at index 'idx' to 'val'
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }

    // Range GCD query: Query the GCD of elements in range [l, r]
    int query(int node, int start, int end, int l, int r) {
        // Complete disjoint / no overlap
        if (r < start || end < l) {
            return 0; // Neutral element for GCD: gcd(x, 0) = x
        }
        // Total overlap
        if (l <= start && end <= r) {
            return tree[node];
        }
        // Partial overlap
        int mid = start + (end - start) / 2;
        int leftGcd = query(2 * node, start, mid, l, r);
        int rightGcd = query(2 * node + 1, mid + 1, end, l, r);
        return gcd(leftGcd, rightGcd);
    }

public:
    // Process all range GCD queries and point updates
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        n = arr.size();
        if (n == 0) return {};

        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);

        vector<int> result;
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 0) {
                // Type 1 Query: [0, l, r] -> Return GCD in range [l, r]
                int l = q[1];
                int r = q[2];
                result.push_back(query(1, 0, n - 1, l, r));
            } else if (type == 1) {
                // Type 2 Query: [1, index, value] -> Update arr[index] to value
                int idx = q[1];
                int val = q[2];
                update(1, 0, n - 1, idx, val);
            }
        }

        return result;
    }
};
