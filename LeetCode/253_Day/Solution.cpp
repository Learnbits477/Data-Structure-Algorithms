#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int index, int openCount, int remL, int remR, string& curr,
             unordered_set<string>& uniqueResults, const string& s) {
        // Step: 01 - Base case reached at string boundary
        if (index == (int)s.length()) {
            if (remL == 0 && remR == 0 && openCount == 0) {
                uniqueResults.insert(curr);
            }
            return;
        }

        char c = s[index];

        // Step: 02 - Explore branch removing opening or closing parenthesis
        if (c == '(' && remL > 0) {
            dfs(index + 1, openCount, remL - 1, remR, curr, uniqueResults, s);
        } else if (c == ')' && remR > 0) {
            dfs(index + 1, openCount, remL, remR - 1, curr, uniqueResults, s);
        }

        // Step: 03 - Explore branch retaining current character if balance invariant holds
        curr.push_back(c);
        int newOpen = openCount + (c == '(' ? 1 : (c == ')' ? -1 : 0));
        if (newOpen >= 0) {
            dfs(index + 1, newOpen, remL, remR, curr, uniqueResults, s);
        }
        curr.pop_back();
    }

    bool isValidString(const string& str) {
        // Step: 01 - Check non-negative prefix balance and zero net balance
        int balance = 0;
        for (char c : str) {
            if (c == '(') balance++;
            else if (c == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        // Step: 01 - Compute exact count of misplaced opening and closing brackets
        int remL = 0, remR = 0;
        for (char c : s) {
            if (c == '(') {
                remL++;
            } else if (c == ')') {
                if (remL > 0) {
                    remL--;
                } else {
                    remR++;
                }
            }
        }

        // Step: 02 - Execute bounded depth-first backtracking search
        unordered_set<string> uniqueResults;
        string curr = "";
        dfs(0, 0, remL, remR, curr, uniqueResults, s);

        // Step: 03 - Return collected unique valid bracket sequences
        vector<string> result(uniqueResults.begin(), uniqueResults.end());
        return result;
    }

    vector<string> removeInvalidParenthesesBFS(string s) {
        // Step: 01 - Handle degenerate empty input string
        if (s.empty()) return {""};

        // Step: 02 - Initialize queue and visited set for level-order exploration
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);
        bool found = false;

        // Step: 03 - Traverse level by level until minimal removal level is found
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string curr = q.front();
                q.pop();

                if (isValidString(curr)) {
                    result.push_back(curr);
                    found = true;
                }

                if (!found) {
                    for (int j = 0; j < (int)curr.length(); ++j) {
                        if (curr[j] != '(' && curr[j] != ')') continue;
                        if (j > 0 && curr[j] == curr[j - 1]) continue;

                        string nextStr = curr.substr(0, j) + curr.substr(j + 1);
                        if (visited.find(nextStr) == visited.end()) {
                            visited.insert(nextStr);
                            q.push(nextStr);
                        }
                    }
                }
            }
            if (found) break;
        }

        // Step: 04 - Return valid expressions found at shallowest depth
        return result.empty() ? vector<string>{""} : result;
    }
};
