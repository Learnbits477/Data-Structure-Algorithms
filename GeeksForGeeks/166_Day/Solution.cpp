#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAmount(vector<int>& arr, int k) {
        // Step 1: Sort and Prepare Baseline
        sort(arr.begin(), arr.end(), greater<int>());
        arr.push_back(0);

        // Step 2: Initialize Profit and Loop variables
        long long totalAmount = 0;
        long long MOD = 1000000007LL;
        int n = arr.size() - 1;

        for (int i = 0; i < n; ++i) {
            if (k <= 0) break;

            // Step 3: Calculate Available Tickets in the Current Batch
            long long diff = arr[i] - arr[i + 1];
            if (diff == 0) continue;

            long long count = i + 1;
            long long avail = count * diff;

            // Step 4: Greedy Sell & Update
            if (k >= avail) {
                long long term = (1LL * (arr[i] + arr[i + 1] + 1) * diff) / 2;
                long long batchProfit = (1LL * count * (term % MOD)) % MOD;
                totalAmount = (totalAmount + batchProfit) % MOD;
                k -= avail;
            } else {
                long long q = k / count;
                long long r = k % count;

                long long term1 = (1LL * (2 * arr[i] - q) * (q + 1)) / 2;
                long long profit1 = (1LL * r * (term1 % MOD)) % MOD;

                long long term2 = (1LL * (2 * arr[i] - q + 1) * q) / 2;
                long long profit2 = (1LL * (count - r) * (term2 % MOD)) % MOD;

                totalAmount = (totalAmount + profit1 + profit2) % MOD;
                k = 0;
                break;
            }
        }

        // Step 5: Return Modulo Result
        return (int)totalAmount;
    }
};
