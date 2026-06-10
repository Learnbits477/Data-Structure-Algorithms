#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int count = 0;

    void solve(const vector<int>& arr, int l, int r, int min_val, int max_val) {
        if (l > r) {
            return;
        }

        int mid = l + (r - l) / 2;

        // Step 2: Check constraints for arr[mid]
        if (arr[mid] >= min_val && arr[mid] <= max_val) {
            count++;
        }

        // Step 3: Recursive search for left and right halves with updated constraints
        solve(arr, l, mid - 1, min_val, min(max_val, arr[mid] - 1));
        solve(arr, mid + 1, r, max(min_val, arr[mid] + 1), max_val);
    }

public:
    int binarySearchable(vector<int> arr) {
        // Step 1: Initialize recursive search
        count = 0;
        int n = arr.size();
        if (n == 0) return 0;

        solve(arr, 0, n - 1, INT_MIN, INT_MAX);

        return count;
    }
};
