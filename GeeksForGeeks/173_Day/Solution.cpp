#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        
        // Step 1: Precompute left_dec
        // left_dec[i] stores the leftmost index we can reach from i by moving left non-increasingly.
        vector<int> left_dec(n);
        left_dec[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[i - 1]) {
                left_dec[i] = left_dec[i - 1];
            } else {
                left_dec[i] = i;
            }
        }

        // Step 2: Precompute right_inc
        // right_inc[i] stores the rightmost index we can reach from i by moving right non-decreasingly.
        vector<int> right_inc(n);
        right_inc[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1]) {
                right_inc[i] = right_inc[i + 1];
            } else {
                right_inc[i] = i;
            }
        }

        // Step 3: Answer Queries in O(1)
        // A subarray arr[l...r] is a mountain if the non-decreasing climb from l
        // overlaps or meets with the non-increasing descent to r.
        vector<bool> result;
        result.reserve(queries.size());
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            if (right_inc[l] >= left_dec[r]) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        return result;
    }
};
