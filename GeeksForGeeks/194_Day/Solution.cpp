#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestZigzag(int n, vector<vector<int>>& mat) {
        // Step 1: Handle Edge Cases
        if (n == 0) return 0;
        if (n == 1) return mat[0][0];

        // Step 2: Initialize DP State
        vector<int> dp = mat[0];

        // Step 3: Iterate Through Subsequent Rows
        for (int i = 1; i < n; ++i) {
            int max1 = -1, max2 = -1;
            int maxCol1 = -1;

            for (int j = 0; j < n; ++j) {
                if (dp[j] > max1) {
                    max2 = max1;
                    max1 = dp[j];
                    maxCol1 = j;
                } else if (dp[j] > max2) {
                    max2 = dp[j];
                }
            }

            vector<int> next_dp(n);
            for (int j = 0; j < n; ++j) {
                int bestPrev = (j == maxCol1) ? max2 : max1;
                next_dp[j] = mat[i][j] + bestPrev;
            }
            
            dp = move(next_dp);
        }

        // Step 4: Extract Answer
        int result = 0;
        for (int j = 0; j < n; ++j) {
            result = max(result, dp[j]);
        }
        return result;
    }

    int largestZigZag(int n, vector<vector<int>>& mat) {
        return largestZigzag(n, mat);
    }
    
    int largestZigzag(vector<vector<int>>& mat) {
        return largestZigzag(mat.size(), mat);
    }
    
    int largestZigZag(vector<vector<int>>& mat) {
        return largestZigzag(mat.size(), mat);
    }
    
    int zigzagSequence(vector<vector<int>>& mat) {
        return largestZigzag(mat.size(), mat);
    }
};