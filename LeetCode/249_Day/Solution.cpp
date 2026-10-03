#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // Step: 01 - Handle base case for empty or single-character string
        int n = s.length();
        if (n <= 1) return 0;

        int maxLen = 0;
        int left = 0, right = 0;

        // Step: 02 - Perform left-to-right pass tracking bracket balances
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                maxLen = max(maxLen, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        // Step: 03 - Perform right-to-left pass tracking bracket balances
        left = right = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                maxLen = max(maxLen, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        // Step: 04 - Return maximum valid length found
        return maxLen;
    }

    int longestValidParenthesesStack(string s) {
        // Step: 01 - Handle base case
        int n = s.length();
        if (n <= 1) return 0;

        // Step: 02 - Initialize stack with boundary index -1
        stack<int> st;
        st.push(-1);
        int maxLen = 0;

        // Step: 03 - Process characters and compute valid span from stack top
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        // Step: 04 - Return maximum length from stack method
        return maxLen;
    }

    int longestValidParenthesesDP(string s) {
        // Step: 01 - Handle base case
        int n = s.length();
        if (n <= 1) return 0;

        // Step: 02 - Initialize DP array where dp[i] is longest valid ending at i
        vector<int> dp(n, 0);
        int maxLen = 0;

        // Step: 03 - Fill DP table for closing parentheses
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    int prevValid = (i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0;
                    dp[i] = dp[i - 1] + prevValid + 2;
                }
                maxLen = max(maxLen, dp[i]);
            }
        }

        // Step: 04 - Return maximum length from DP method
        return maxLen;
    }
};
