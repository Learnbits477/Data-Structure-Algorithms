#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long int minProductSubset(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        int count_neg = 0;
        int count_zero = 0;
        int max_neg = INT_MIN;
        int min_pos = INT_MAX;
        long long prod = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                count_zero++;
                continue;
            }

            if (arr[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, arr[i]);
            } else {
                min_pos = min(min_pos, arr[i]);
            }

            prod *= arr[i];
        }

        // Case 1: No negative elements
        if (count_neg == 0) {
            if (count_zero > 0) return 0;
            return min_pos;
        }

        // Case 2: Odd count of negative elements
        if (count_neg % 2 != 0) {
            return prod;
        }

        // Case 3: Even count of negative elements (> 0)
        return prod / max_neg;
    }

    // Aliases for GFG driver signature compatibility
    long long int findMinProduct(vector<int>& arr) {
        return minProductSubset(arr);
    }

    int minProduct(vector<int>& arr) {
        return (int)minProductSubset(arr);
    }

    long long int minProduct(vector<int>& arr, int n) {
        return minProductSubset(arr);
    }

    int minProd(vector<int>& arr) {
        return (int)minProductSubset(arr);
    }

    long long int minProd(vector<int>& arr, int n) {
        return minProductSubset(arr);
    }
};
