#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        // Step 1: Precompute the 2D Prefix Sum Matrix
        vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = mat[i - 1][j - 1] 
                                + prefixSum[i - 1][j] 
                                + prefixSum[i][j - 1] 
                                - prefixSum[i - 1][j - 1];
            }
        }
        
        int maxSum = INT_MIN;
        
        // Step 2: Iterate and Find the Maximum Subgrid Sum
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                int currentSum = prefixSum[i][j] 
                               - prefixSum[i - k][j] 
                               - prefixSum[i][j - k] 
                               + prefixSum[i - k][j - k];
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};
