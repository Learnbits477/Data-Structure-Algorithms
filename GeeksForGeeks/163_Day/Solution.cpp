#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKdivPairs(vector<int>& arr, int k) {
        // Step 1: Remainder Frequency Array Initialization
        vector<int> freq(k, 0);
        long long count = 0;
        
        // Step 2: Single Pass Processing
        for (int x : arr) {
            int rem = x % k;
            if (rem < 0) rem += k;
            int target = (k - rem) % k;
            count += freq[target];
            freq[rem]++;
        }
        
        // Step 3: Return Results
        return (int)count;
    }

    int countKdivPairs(vector<int>& arr, int n, int k) {
        return countKdivPairs(arr, k);
    }
};
