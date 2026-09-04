#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        if (n == 0 || m <= 0) return 0;

        // If m >= n, bird can visit all trees in the circle
        long long total_sum = 0;
        for (int x : arr) {
            total_sum += x;
        }
        if (m >= n) {
            return (int)total_sum;
        }

        // Initialize sliding window of size m
        long long curr_sum = 0;
        for (int i = 0; i < m; i++) {
            curr_sum += arr[i];
        }

        long long max_sum = curr_sum;

        // Slide the window across all n starting positions
        for (int i = 0; i < n; i++) {
            curr_sum = curr_sum - arr[i] + arr[(i + m) % n];
            max_sum = max(max_sum, curr_sum);
        }

        return (int)max_sum;
    }

    // Aliases for compatibility with various driver formats
    int maxFruit(vector<int>& arr, int m) {
        return maxFruits(arr, m);
    }

    int maxTotalFruits(vector<int>& arr, int m) {
        return maxFruits(arr, m);
    }

    int birdAndMaxFruitGathering(vector<int>& arr, int m) {
        return maxFruits(arr, m);
    }
};
