#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubsets(vector<int> &arr) {
        // Step 1: Precompute Prime Masks for Numbers 1-30
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> mask(31, 0);
        for (int i = 2; i <= 30; i++) {
            int temp = i;
            bool square_free = true;
            for (int j = 0; j < 10; j++) {
                int p = primes[j];
                if (temp % (p * p) == 0) {
                    square_free = false;
                    break;
                }
                if (temp % p == 0) {
                    mask[i] |= (1 << j);
                }
            }
            if (!square_free) {
                mask[i] = -1;
            }
        }

        // Step 2: Count Frequencies of Each Number
        vector<long long> freq(31, 0);
        int cnt1 = 0;
        for (int x : arr) {
            if (x == 1) {
                cnt1++;
            } else if (x >= 2 && x <= 30) {
                freq[x]++;
            }
        }

        long long MOD = 1e9 + 7;
        
        // Step 3: Initialize the DP Array
        vector<long long> dp(1024, 0);
        dp[0] = 1; // Base case: empty subset with product 1 (mask 0)

        // Step 4: Build the DP Table
        for (int x = 2; x <= 30; x++) {
            if (freq[x] == 0 || mask[x] == -1) {
                continue;
            }
            
            vector<long long> next_dp = dp;
            int x_mask = mask[x];
            long long x_freq = freq[x];

            for (int curr_mask = 0; curr_mask < 1024; curr_mask++) {
                if ((curr_mask & x_mask) == 0) {
                    next_dp[curr_mask | x_mask] = (next_dp[curr_mask | x_mask] + dp[curr_mask] * x_freq) % MOD;
                }
            }
            dp = move(next_dp);
        }

        // Step 5: Sum up the valid subsets (mask > 0)
        long long ans = 0;
        for (int m = 1; m < 1024; m++) {
            ans = (ans + dp[m]) % MOD;
        }

        // Step 6: Handle occurrences of '1's
        long long power_of_2 = 1;
        for (int i = 0; i < cnt1; i++) {
            power_of_2 = (power_of_2 * 2) % MOD;
        }
        ans = (ans * power_of_2) % MOD;

        // Step 7: Return the Result
        return (int)ans;
    }
};
