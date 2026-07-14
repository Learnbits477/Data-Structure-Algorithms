#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    int MOD = 1e9 + 7;
    vector<int> memo;

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    // Helper method for recursive DP with memoization
    int solve(int i, int g1, int g2, const vector<int>& nums) {
        // Step 2: Recursive DP with Memoization
        // Base case: check if we reached the end of the array
        if (i == n) {
            return (g1 > 0 && g2 > 0 && g1 == g2) ? 1 : 0;
        }

        // Generate the flat index for state (i, g1, g2)
        int state = (i * 201 + g1) * 201 + g2;
        if (memo[state] != -1) {
            return memo[state];
        }

        // Choice 1: Skip the current element
        long long ans = solve(i + 1, g1, g2, nums);

        // Choice 2: Add to Subsequence 1
        int ng1 = (g1 == 0) ? nums[i] : gcd(g1, nums[i]);
        ans = (ans + solve(i + 1, ng1, g2, nums)) % MOD;

        // Choice 3: Add to Subsequence 2
        int ng2 = (g2 == 0) ? nums[i] : gcd(g2, nums[i]);
        ans = (ans + solve(i + 1, g1, ng2, nums)) % MOD;

        return memo[state] = ans;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        
        // Step 1: Initialize Memoization Table
        // Pre-allocate flat 1D vector of size n * 201 * 201 with -1
        memo.assign(n * 201 * 201, -1);

        // Step 3: Start and Return
        // Trigger recursive helper starting from index 0 and empty subsequences
        return solve(0, 0, 0, nums);
    }
};
