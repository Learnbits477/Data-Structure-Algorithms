#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long getGcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Step 1: Redundancy Pruning
        sort(coins.begin(), coins.end());
        vector<int> filtered;
        for (int c : coins) {
            bool redundant = false;
            for (int f : filtered) {
                if (c % f == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) {
                filtered.push_back(c);
            }
        }

        int m = filtered.size();
        int totalSubsets = (1 << m);

        // Step 2: Precompute Subset LCMs & Signs (PIE)
        vector<pair<long long, int>> subsets;
        subsets.reserve(totalSubsets);

        for (int mask = 1; mask < totalSubsets; ++mask) {
            long long curLcm = 1;
            int bitCount = 0;
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    bitCount++;
                    curLcm = (curLcm / getGcd(curLcm, (long long)filtered[i])) * filtered[i];
                }
            }
            int sign = (bitCount % 2 == 1) ? 1 : -1;
            subsets.push_back({curLcm, sign});
        }

        // Helper lambda to count reachable amounts <= x using PIE
        auto countValid = [&](long long x) -> long long {
            long long count = 0;
            for (size_t idx = 0; idx < subsets.size(); ++idx) {
                long long lcmVal = subsets[idx].first;
                int sign = subsets[idx].second;
                count += sign * (x / lcmVal);
            }
            return count;
        };

        // Step 3: Binary Search on Answer
        long long low = 1;
        long long high = (long long)filtered[0] * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countValid(mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Step 4: Return Answer
        return ans;
    }
};
