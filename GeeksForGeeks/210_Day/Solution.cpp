#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& arr) {
        // Step 1: Initialize variables and DP/frequency array
        int n = arr.size();
        if (n <= 1) return 0;
        vector<int> dp(n + 1, 0);
        int maxConsecutiveLen = 0;

        // Step 2: Compute longest consecutive increasing subsequence
        for (int x : arr) {
            dp[x] = dp[x - 1] + 1;
            maxConsecutiveLen = max(maxConsecutiveLen, dp[x]);
        }

        // Step 3: Return minimum operations required
        return n - maxConsecutiveLen;
    }
};
