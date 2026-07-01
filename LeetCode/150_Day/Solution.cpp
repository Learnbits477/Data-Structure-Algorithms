#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct BIT {
        int size;
        vector<int> tree;
        BIT(int n) : size(n), tree(n + 1, 0) {}
        void update(int idx, int val) {
            for (; idx <= size; idx += idx & -idx) {
                tree[idx] += val;
            }
        }
        int query(int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx) {
                sum += tree[idx];
            }
            return sum;
        }
    };
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 1;
        
        // Step 1: Setup Fenwick Tree / Binary Indexed Tree (BIT)
        BIT bit(2 * n + 1);
        long long ans = 0;
        int curr = 0;
        
        // Step 2: Initialize States
        bit.update(0 + offset, 1);
        
        // Step 3: Process Elements
        for (int num : nums) {
            if (num == target) {
                curr++;
            } else {
                curr--;
            }
            ans += bit.query(curr - 1 + offset);
            bit.update(curr + offset, 1);
        }
        
        // Step 4: Return Answer
        return ans;
    }
};
