#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimal O(N) Wormhole Teleportation Portal Approach
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pairPos(n, 0);
        stack<int> st;

        // Step 1: Precompute matching parenthesis pairs (wormhole portals)
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pairPos[i] = j;
                pairPos[j] = i;
            }
        }

        // Step 2: Traverse string using wormhole teleportation
        string result = "";
        result.reserve(n);
        int curr = 0;
        int dir = 1;

        while (curr < n && curr >= 0) {
            if (s[curr] == '(' || s[curr] == ')') {
                // Jump to the paired bracket and flip traversal direction
                curr = pairPos[curr];
                dir = -dir;
            } else {
                result += s[curr];
            }
            curr += dir;
        }

        return result;
    }
};
