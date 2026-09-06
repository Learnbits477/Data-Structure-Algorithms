#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Main function: Calculates the sum of bitwise AND of all pairs (i < j)
    long long pairAndSum(vector<int>& arr) {
        int n = arr.size();
        long long total_sum = 0;

        // Iterate through all 32 bits
        for (int k = 0; k < 32; k++) {
            long long count = 0;
            for (int i = 0; i < n; i++) {
                if ((arr[i] >> k) & 1) {
                    count++;
                }
            }
            // Number of pairs where both elements have the k-th bit set
            long long pairs = (count * (count - 1)) / 2;
            total_sum += pairs * (1LL << k);
        }

        return total_sum;
    }

    // Driver compatibility aliases
    long long pairAndSum(int n, long long arr[]) {
        vector<int> a(arr, arr + n);
        return pairAndSum(a);
    }

    long long pairAndSum(int n, int arr[]) {
        vector<int> a(arr, arr + n);
        return pairAndSum(a);
    }

    long long sumOfProducts(vector<int>& arr) {
        return pairAndSum(arr);
    }

    long long sumOfPairwiseAND(vector<int>& arr) {
        return pairAndSum(arr);
    }
};
