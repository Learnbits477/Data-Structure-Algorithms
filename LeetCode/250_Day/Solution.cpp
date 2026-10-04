#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // Step: 01 - Initialize minimum and maximum possible open bracket bounds
        int low = 0;
        int high = 0;

        // Step: 02 - Iterate through each character and update interval bounds
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else {
                low--;
                high++;
            }

            // Step: 03 - Validate that closing brackets do not exceed total openings
            if (high < 0) {
                return false;
            }

            // Step: 04 - Clamp lower bound to prevent non-viable negative open counts
            if (low < 0) {
                low = 0;
            }
        }

        // Step: 05 - Return whether a balanced state of zero open brackets is reachable
        return low == 0;
    }

    bool checkValidStringTwoStacks(string s) {
        // Step: 01 - Initialize index stacks for open parentheses and asterisks
        stack<int> openIndices;
        stack<int> starIndices;
        int n = s.length();

        // Step: 02 - Scan string and pair closing brackets with openings or asterisks
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openIndices.push(i);
            } else if (s[i] == '*') {
                starIndices.push(i);
            } else {
                if (!openIndices.empty()) {
                    openIndices.pop();
                } else if (!starIndices.empty()) {
                    starIndices.pop();
                } else {
                    return false;
                }
            }
        }

        // Step: 03 - Pair remaining open brackets with asterisks appearing after them
        while (!openIndices.empty() && !starIndices.empty()) {
            if (openIndices.top() > starIndices.top()) {
                return false;
            }
            openIndices.pop();
            starIndices.pop();
        }

        // Step: 04 - Return true if all open brackets were matched
        return openIndices.empty();
    }

    bool checkValidStringDP(string s) {
        // Step: 01 - Initialize DP memoization table
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));

        // Step: 02 - Define recursive search helper with memoization
        auto dfs = [&](auto& self, int idx, int openCount) -> bool {
            if (openCount < 0) return false;
            if (idx == n) return openCount == 0;
            if (memo[idx][openCount] != -1) return memo[idx][openCount];

            bool valid = false;
            if (s[idx] == '(') {
                valid = self(self, idx + 1, openCount + 1);
            } else if (s[idx] == ')') {
                valid = self(self, idx + 1, openCount - 1);
            } else {
                valid = self(self, idx + 1, openCount + 1) ||
                        self(self, idx + 1, openCount - 1) ||
                        self(self, idx + 1, openCount);
            }

            return memo[idx][openCount] = valid;
        };

        // Step: 03 - Execute search from index 0 with 0 open brackets
        return dfs(dfs, 0, 0);
    }
};
