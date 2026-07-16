#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    long long gcdSum(vector<int>& nums) {
        // Step 1: Initialize helper variables
        int n = nums.size();
        vector<int> prefixGcd(n);
        int max_val = 0;

        // Step 2: Construct the prefixGcd array
        for (int i = 0; i < n; ++i) {
            max_val = max(max_val, nums[i]);
            prefixGcd[i] = gcd(nums[i], max_val);
        }

        // Step 3: Sort the prefixGcd array
        sort(prefixGcd.begin(), prefixGcd.end());

        // Step 4: Pair elements and sum their GCDs
        long long totalSum = 0;
        int left = 0;
        int right = n - 1;

        while (left < right) {
            totalSum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return totalSum;
    }
};
