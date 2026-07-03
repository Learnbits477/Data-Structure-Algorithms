#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToIncreaseLCSBy1(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        // Step 1 — Precompute Prefix DP (L1)
        // L1[i][j] stores the LCS of s1[0...i-1] and s2[0...j-1]
        vector<vector<int>> L1(n1 + 2, vector<int>(n2 + 2, 0));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    L1[i][j] = L1[i - 1][j - 1] + 1;
                } else {
                    L1[i][j] = max(L1[i - 1][j], L1[i][j - 1]);
                }
            }
        }

        // Step 2 — Precompute Suffix DP (L2)
        // L2[i][j] stores the LCS of s1[i...n1-1] and s2[j...n2-1]
        vector<vector<int>> L2(n1 + 2, vector<int>(n2 + 2, 0));
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    L2[i][j] = L2[i + 1][j + 1] + 1;
                } else {
                    L2[i][j] = max(L2[i + 1][j], L2[i][j + 1]);
                }
            }
        }

        // Step 3 — Map Character Occurrences
        // Store all 0-based indices for every lowercase English letter in s2
        vector<vector<int>> positions(26);
        for (int j = 0; j < n2; j++) {
            positions[s2[j] - 'a'].push_back(j);
        }

        // Step 4 — Evaluate All Valid Insertions
        int original_LCS = L1[n1][n2];
        int ways = 0;

        for (int i = 0; i <= n1; i++) {
            for (char c = 'a'; c <= 'z'; c++) {

                // Check if matching c with any occurrence p in s2 yields a valid LCS increment
                bool possible = false;
                for (int p : positions[c - 'a']) {
                    if (L1[i][p] + L2[i][p + 1] == original_LCS) {
                        possible = true;
                        break;
                    }
                }

                if (possible) {
                    ways++;
                }
            }
        }

        return ways;
    }
};
