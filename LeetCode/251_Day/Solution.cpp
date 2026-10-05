#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        // Step: 01 - Initialize score accumulator and nesting depth tracker
        int score = 0;
        int depth = 0;
        int n = s.length();

        // Step: 02 - Traverse string computing powers of 2 for primitive leaves
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                if (s[i - 1] == '(') {
                    score += (1 << depth);
                }
            }
        }

        // Step: 03 - Return final accumulated parenthesis score
        return score;
    }

    int scoreOfParenthesesStack(string s) {
        // Step: 01 - Initialize stack with base scope score
        stack<int> st;
        st.push(0);

        // Step: 02 - Process parentheses simulating nested context frames
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int innerScore = st.top();
                st.pop();
                int scoreContribution = max(2 * innerScore, 1);
                st.top() += scoreContribution;
            }
        }

        // Step: 03 - Return root level evaluated score
        return st.top();
    }
};
