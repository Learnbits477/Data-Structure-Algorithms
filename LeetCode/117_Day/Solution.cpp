#include <iostream>
using namespace std;

class Solution {
private:
    int solve(int i, const vector<int>& arr, int d, vector<int>& dp) {
        // Step 2: DFS with Memoization
        if (dp[i] != -1) {
            return dp[i];
        }

        int ans = 1;
        int n = arr.size();

        // Scan Right
        for (int x = 1; x <= d; ++x) {
            int j = i + x;
            if (j >= n || arr[j] >= arr[i]) {
                break;
            }
            ans = max(ans, 1 + solve(j, arr, d, dp));
        }

        // Scan Left
        for (int x = 1; x <= d; ++x) {
            int j = i - x;
            if (j < 0 || arr[j] >= arr[i]) {
                break;
            }
            ans = max(ans, 1 + solve(j, arr, d, dp));
        }

        return dp[i] = ans;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        // Step 1: Initialize DP Cache
        vector<int> dp(n, -1);

        int max_visited = 0;
        // Step 3: Find Global Maximum
        for (int i = 0; i < n; ++i) {
            max_visited = max(max_visited, solve(i, arr, d, dp));
        }

        return max_visited;
    }
};
