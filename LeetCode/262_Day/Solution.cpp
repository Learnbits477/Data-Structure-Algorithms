#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static const int MOD = 1000000007;

    struct SegmentTree {
        int n;
        vector<long long> sum_sq;
        vector<long long> sum_val;
        vector<long long> lazy;

        SegmentTree(int size) {
            n = size;
            sum_sq.assign(4 * n, 0);
            sum_val.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void apply(int u, int l, int r, long long v) {
            long long len = (r - l + 1) % MOD;
            long long v_sq = (v * v) % MOD;

            sum_sq[u] = (sum_sq[u] + 2LL * v % MOD * sum_val[u] % MOD + v_sq * len % MOD) % MOD;
            sum_val[u] = (sum_val[u] + v * len % MOD) % MOD;
            lazy[u] = (lazy[u] + v) % MOD;
        }

        void pushDown(int u, int l, int r) {
            if (lazy[u] != 0) {
                int mid = l + (r - l) / 2;
                apply(2 * u, l, mid, lazy[u]);
                apply(2 * u + 1, mid + 1, r, lazy[u]);
                lazy[u] = 0;
            }
        }

        void pushUp(int u) {
            sum_sq[u] = (sum_sq[2 * u] + sum_sq[2 * u + 1]) % MOD;
            sum_val[u] = (sum_val[2 * u] + sum_val[2 * u + 1]) % MOD;
        }

        void update(int u, int l, int r, int ql, int qr, long long val) {
            if (ql <= l && r <= qr) {
                apply(u, l, r, val);
                return;
            }
            pushDown(u, l, r);
            int mid = l + (r - l) / 2;
            if (ql <= mid) {
                update(2 * u, l, mid, ql, qr, val);
            }
            if (qr > mid) {
                update(2 * u + 1, mid + 1, r, ql, qr, val);
            }
            pushUp(u);
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        // Step: 01 - Initialize segment tree to manage range additions and squared sums
        SegmentTree tree(n);

        // Step: 02 - Allocate lookup table to record the most recent index of each value
        int maxVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
        }
        vector<int> lastPos(maxVal + 1, -1);

        long long totalSum = 0;

        // Step: 03 - Iterate over each right boundary of the subarray
        for (int j = 0; j < n; ++j) {
            int prev = lastPos[nums[j]];

            // Step: 04 - Increment distinct count for all start positions after previous occurrence
            tree.update(1, 0, n - 1, prev + 1, j, 1);

            // Step: 05 - Add total sum of squared distinct counts ending at index j
            totalSum = (totalSum + tree.sum_sq[1]) % MOD;

            // Step: 06 - Update the last seen position of the current element
            lastPos[nums[j]] = j;
        }

        // Step: 07 - Return accumulated total distinct count sum of squares modulo 10^9+7
        return (totalSum % MOD + MOD) % MOD;
    }

    int sumCountsBruteForce(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;

        // Step: 01 - Iterate over each starting index i
        for (int i = 0; i < n; ++i) {
            unordered_set<int> seen;
            // Step: 02 - Expand right boundary j and update distinct count
            for (int j = i; j < n; ++j) {
                seen.insert(nums[j]);
                long long d = seen.size();
                total = (total + d * d) % MOD;
            }
        }

        // Step: 03 - Return brute force computed distinct sum of squares
        return total;
    }
};
