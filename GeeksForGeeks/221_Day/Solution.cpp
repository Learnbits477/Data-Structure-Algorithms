#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        unordered_map<int, int> dp;
        dp.reserve(n);
        int max_len = 1;

        for (int x : arr) {
            int len = 1;
            auto it1 = dp.find(x - 1);
            if (it1 != dp.end()) {
                len = max(len, it1->second + 1);
            }
            auto it2 = dp.find(x + 1);
            if (it2 != dp.end()) {
                len = max(len, it2->second + 1);
            }
            dp[x] = max(dp[x], len);
            max_len = max(max_len, dp[x]);
        }

        return max_len;
    }

    // Aliases for compatibility with various driver formats
    int longestSubseq(vector<int>& arr) {
        return longestSubsequence(arr);
    }

    int longestSubsequence(int n, vector<int>& arr) {
        return longestSubsequence(arr);
    }

    int longestSubsequence(int n, int a[]) {
        vector<int> arr(a, a + n);
        return longestSubsequence(arr);
    }
};
