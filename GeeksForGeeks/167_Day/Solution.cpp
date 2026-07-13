#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Cycle Detection
        vector<bool> visited(n, false);
        vector<int> max_power(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int curr = i;
                int len = 0;
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = arr[curr] - 1; // 1-based indexing in arr[]
                    len++;
                }
                
                // Step 2: Prime Power Factorization
                int temp = len;
                for (int d = 2; d * d <= temp; ++d) {
                    if (temp % d == 0) {
                        int count = 0;
                        while (temp % d == 0) {
                            count++;
                            temp /= d;
                        }
                        max_power[d] = max(max_power[d], count);
                    }
                }
                if (temp > 1) {
                    max_power[temp] = max(max_power[temp], 1);
                }
            }
        }

        // Step 3: LCM Product Modulo Calculation
        long long ans = 1;
        long long MOD = 1000000007LL;
        
        for (int p = 2; p <= n; ++p) {
            if (max_power[p] > 0) {
                long long term = 1;
                for (int i = 0; i < max_power[p]; ++i) {
                    term = (term * p) % MOD;
                }
                ans = (ans * term) % MOD;
            }
        }
        
        return (int)ans;
    }
};
