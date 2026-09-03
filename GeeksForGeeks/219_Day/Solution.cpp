#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // prev0: max diff sum ending at index i-1 where arr[i-1] was kept as original
        // prev1: max diff sum ending at index i-1 where arr[i-1] was replaced with 1
        int prev0 = 0;
        int prev1 = 0;

        for (int i = 1; i < n; i++) {
            // Case 0: Current element arr[i] remains original arr[i]
            int curr0 = max(prev0 + abs(arr[i] - arr[i - 1]),
                            prev1 + abs(arr[i] - 1));

            // Case 1: Current element arr[i] is replaced with 1
            int curr1 = max(prev0 + abs(1 - arr[i - 1]),
                            prev1 + abs(1 - 1));

            prev0 = curr0;
            prev1 = curr1;
        }

        return max(prev0, prev1);
    }

    // Aliases for compatibility
    int maximumAdjacentDiff(vector<int>& arr) {
        return maxDiffSum(arr);
    }

    int maxAdjacentDiff(vector<int>& arr) {
        return maxDiffSum(arr);
    }

    int maxAdjacentDiffsSum(vector<int>& arr) {
        return maxDiffSum(arr);
    }

    int maximumDifference(vector<int>& arr) {
        return maxDiffSum(arr);
    }
};
