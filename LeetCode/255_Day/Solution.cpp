#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        // Step: 01 - Initialize tracking variables
        int insertions = 0;
        int openCount = 0;
        int n = s.length();

        // Step: 02 - Process characters using lookahead pair grouping
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                openCount++;
            } else {
                // Step: 03 - Check if current ')' has an immediate partner ')'
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // Consume the matching consecutive ')'
                } else {
                    insertions++; // Missing the second ')', insert it
                }

                // Step: 04 - Match the '))' pair with an earlier '(' if available
                if (openCount > 0) {
                    openCount--;
                } else {
                    insertions++; // Missing '(', insert it before '))'
                }
            }
        }

        // Step: 05 - Each unmatched '(' requires two consecutive ')'
        insertions += openCount * 2;

        // Step: 06 - Return minimum insertions needed
        return insertions;
    }

    int minInsertionsDemandDriven(string s) {
        // Step: 01 - Initialize insertion counter and needed closing demand
        int res = 0;
        int neededRight = 0;

        // Step: 02 - Process characters sequentially
        for (char c : s) {
            if (c == '(') {
                // Step: 03 - If an earlier '(' had only one matching ')', fix it before opening another
                if (neededRight % 2 == 1) {
                    res++;         // Insert missing ')'
                    neededRight--; // Close that pair
                }
                neededRight += 2; // Each '(' demands two ')'
            } else {
                neededRight--;
                // Step: 04 - If closing demand goes negative, an unmatched ')' occurred
                if (neededRight < 0) {
                    res++;         // Insert '('
                    neededRight += 2; // Inserted '(' demands 2 ')', one is satisfied by this char
                }
            }
        }

        // Step: 05 - Add remaining unsatisfied right closing demand
        return res + neededRight;
    }
};
