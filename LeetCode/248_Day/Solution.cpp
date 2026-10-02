#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(int n, int open, int close, string& current, vector<string>& result) {
        // Step: 01 - Base case: add valid combination when current length reaches 2 * n
        if (static_cast<int>(current.length()) == 2 * n) {
            result.push_back(current);
            return;
        }

        // Step: 02 - Add opening parenthesis if open count is less than n
        if (open < n) {
            current.push_back('(');
            backtrack(n, open + 1, close, current, result);
            current.pop_back();
        }

        // Step: 03 - Add closing parenthesis if close count is less than open count
        if (close < open) {
            current.push_back(')');
            backtrack(n, open, close + 1, current, result);
            current.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        // Step: 01 - Handle non-positive n edge case
        vector<string> result;
        if (n <= 0) return result;

        // Step: 02 - Pre-allocate string buffer to size 2 * n
        string current;
        current.reserve(2 * n);

        // Step: 03 - Start recursive backtracking with 0 open and 0 close brackets
        backtrack(n, 0, 0, current, result);

        // Step: 04 - Return all generated valid combinations
        return result;
    }

    vector<string> generateParenthesisDP(int n) {
        // Step: 01 - Handle non-positive n edge case
        if (n <= 0) return {};

        // Step: 02 - Initialize DP table with base case dp[0] = {""}
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};

        // Step: 03 - Build combinations using Catalan decomposition
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k < i; ++k) {
                for (const string& left : dp[k]) {
                    for (const string& right : dp[i - 1 - k]) {
                        dp[i].push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        // Step: 04 - Return combinations of length 2 * n
        return dp[n];
    }

    vector<string> generateParenthesisBFS(int n) {
        // Step: 01 - Handle non-positive n edge case
        if (n <= 0) return {};

        struct State {
            string str;
            int open;
            int close;
        };

        // Step: 02 - Initialize BFS queue with empty string state
        queue<State> q;
        q.push({"", 0, 0});
        vector<string> result;

        // Step: 03 - Process states level-by-level
        while (!q.empty()) {
            State curr = q.front();
            q.pop();

            if (static_cast<int>(curr.str.length()) == 2 * n) {
                result.push_back(curr.str);
                continue;
            }

            if (curr.open < n) {
                q.push({curr.str + "(", curr.open + 1, curr.close});
            }
            if (curr.close < curr.open) {
                q.push({curr.str + ")", curr.open, curr.close + 1});
            }
        }

        // Step: 04 - Return all completed combinations
        return result;
    }
};
