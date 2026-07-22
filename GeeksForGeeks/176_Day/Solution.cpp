#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(vector<int>& arr) {
        int n = arr.size();
        vector<int> tail;
        
        for (int x : arr) {
            // Since we need a strictly increasing sequence,
            // we use lower_bound to find the first element >= x.
            auto it = lower_bound(tail.begin(), tail.end(), x);
            if (it == tail.end()) {
                tail.push_back(x);
            } else {
                *it = x;
            }
        }
        
        // The LIS length is tail.size().
        // Minimum deletions = n - LIS length.
        return n - tail.size();
    }
};
