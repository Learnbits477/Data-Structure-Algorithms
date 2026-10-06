#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        // Step: 01 - Initialize counters for open parentheses pool and required closing moves
        int openCount = 0;
        int closeMoves = 0;

        // Step: 02 - Traverse string updating balance and tracking unmatched brackets
        for (char c : s) {
            if (c == '(') {
                openCount++;
            } else {
                if (openCount > 0) {
                    openCount--;
                } else {
                    closeMoves++;
                }
            }
        }

        // Step: 03 - Return total moves needed for unclosed openers and unmatched closers
        return closeMoves + openCount;
    }

    int minAddToMakeValidStack(string s) {
        // Step: 01 - Initialize character stack to track unmatched parenthesis symbols
        stack<char> st;

        // Step: 02 - Process parentheses popping valid pairs and retaining violations
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }

        // Step: 03 - Return total residual elements remaining in the stack
        return st.size();
    }
};
