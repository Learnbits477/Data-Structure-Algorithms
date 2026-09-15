#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper to check if s[l...r] is a palindrome
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        // dp[i] represents the maximum non-overlapping palindromes in prefix s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // Option 1: Do not pick a palindrome ending at s[i - 1]
            dp[i] = dp[i - 1];

            // Option 2: Check for a valid palindrome of length k ending at s[i - 1]
            if (i >= k && isPalindrome(s, i - k, i - 1)) {
                dp[i] = max(dp[i], dp[i - k] + 1);
            }

            // Option 3: Check for a valid palindrome of length k + 1 ending at s[i - 1]
            if (i >= k + 1 && isPalindrome(s, i - k - 1, i - 1)) {
                dp[i] = max(dp[i], dp[i - k - 1] + 1);
            }
        }

        return dp[n];
    }
};
