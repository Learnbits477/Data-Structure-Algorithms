#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(vector<int>& arr, int idx, int last_inc, int last_dec, vector<vector<vector<int>>>& dp) {
        int n = arr.size();
        if (idx == n) return 0;

        if (dp[idx][last_inc + 1][last_dec + 1] != -1) {
            return dp[idx][last_inc + 1][last_dec + 1];
        }

        // Option 1: Skip arr[idx] (unselected)
        int res = 1 + solve(arr, idx + 1, last_inc, last_dec, dp);

        // Option 2: Add arr[idx] to the strictly increasing subsequence
        if (last_inc == -1 || arr[idx] > arr[last_inc]) {
            res = min(res, solve(arr, idx + 1, idx, last_dec, dp));
        }

        // Option 3: Add arr[idx] to the strictly decreasing subsequence
        if (last_dec == -1 || arr[idx] < arr[last_dec]) {
            res = min(res, solve(arr, idx + 1, last_inc, idx, dp));
        }

        return dp[idx][last_inc + 1][last_dec + 1] = res;
    }

public:
    // Main function: Minimum elements outside the two subsequences
    int minCount(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        // dp[idx][last_inc + 1][last_dec + 1]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return solve(arr, 0, -1, -1, dp);
    }

    // Platform and driver compatibility overloads
    int minElements(vector<int>& arr) {
        return minCount(arr);
    }

    int minElements(int arr[], int n) {
        vector<int> a(arr, arr + n);
        return minCount(a);
    }

    int minCount(int arr[], int n) {
        vector<int> a(arr, arr + n);
        return minCount(a);
    }

    int minUnselectedElements(vector<int>& arr) {
        return minCount(arr);
    }
};
