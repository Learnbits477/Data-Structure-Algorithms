#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        // Step: 01 - Compute total sum of all stones using 64-bit integer
        long long totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }

        // Step: 02 - Compute maximum ascending slope heights from the left
        vector<int> left(n);
        left[0] = 1;
        for (int i = 1; i < n; ++i) {
            left[i] = min(arr[i], left[i - 1] + 1);
        }

        // Step: 03 - Compute maximum descending slope heights from the right
        vector<int> right(n);
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            right[i] = min(arr[i], right[i + 1] + 1);
        }

        // Step: 04 - Determine the maximum possible pyramid peak height across all centers
        int maxPeak = 0;
        for (int i = 0; i < n; ++i) {
            int peakAtI = min(left[i], right[i]);
            maxPeak = max(maxPeak, peakAtI);
        }

        // Step: 05 - Minimum cost is total sum minus preserved pyramid sum (maxPeak^2)
        long long minCost = totalSum - (1LL * maxPeak * maxPeak);

        return static_cast<int>(minCost);
    }

    // Platform alias method
    int minCost(vector<int>& arr) {
        return formPyramid(arr);
    }

    int pyramidForm(vector<int>& arr) {
        return formPyramid(arr);
    }
};
