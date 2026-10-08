#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        // Step: 01 - Initialize result buffer and open counter
        string res = "";
        int opened = 0;

        // Step: 02 - Iterate through characters and filter outermost delimiters
        for (char c : s) {
            if (c == '(') {
                if (opened > 0) {
                    res += c;
                }
                opened++;
            } else {
                opened--;
                if (opened > 0) {
                    res += c;
                }
            }
        }

        // Step: 03 - Return filtered parentheses string
        return res;
    }

    string removeOuterParenthesesDecomposition(string s) {
        // Step: 01 - Initialize accumulation string and boundary pointers
        string res = "";
        int balance = 0;
        int start = 0;

        // Step: 02 - Scan string to locate primitive parentheses partitions
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(') {
                balance++;
            } else {
                balance--;
            }

            // Step: 03 - Extract interior substring when primitive boundary closes
            if (balance == 0) {
                res += s.substr(start + 1, i - start - 1);
                start = i + 1;
            }
        }

        // Step: 04 - Return assembled stripped primitives
        return res;
    }

    string removeOutermostParentheses(string s) {
        // Step: 01 - Alias wrapper for compatibility
        return removeOuterParentheses(s);
    }
};
