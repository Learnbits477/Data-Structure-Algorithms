#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // Step 1: Calculate Frequency & Find Maximum Value
        int maxNum = 0;
        for (int num : nums) {
            maxNum = max(maxNum, num);
        }

        vector<long long> freq(maxNum + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Count Divisor Multiples
        vector<long long> countDivisor(maxNum + 1, 0);
        for (int i = 1; i <= maxNum; ++i) {
            for (int j = i; j <= maxNum; j += i) {
                countDivisor[i] += freq[j];
            }
        }

        // Step 3: Count Exact GCD Pairs (Inclusion-Exclusion via Harmonic Sieve)
        vector<long long> countGcdPair(maxNum + 1, 0);
        for (int g = maxNum; g >= 1; --g) {
            long long c = countDivisor[g];
            countGcdPair[g] = c * (c - 1) / 2;
            for (int multiple = 2 * g; multiple <= maxNum; multiple += g) {
                countGcdPair[g] -= countGcdPair[multiple];
            }
        }

        // Step 4: Compute Prefix Sums of GCD Pairs
        vector<long long> prefixCount(maxNum + 1, 0);
        for (int i = 1; i <= maxNum; ++i) {
            prefixCount[i] = prefixCount[i - 1] + countGcdPair[i];
        }

        // Step 5: Answer Queries via Binary Search (upper_bound)
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            auto it = upper_bound(prefixCount.begin(), prefixCount.end(), q);
            ans.push_back(distance(prefixCount.begin(), it));
        }

        return ans;
    }
};
