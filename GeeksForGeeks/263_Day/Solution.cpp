#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isItPossible(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // Step: 01 - Verify equal length constraint
        if (n != m) {
            return false;
        }

        int i = 0;
        int j = 0;

        // Step: 02 - Scan both strings skipping empty positions
        while (i < n && j < m) {
            while (i < n && s1[i] == '#') {
                i++;
            }
            while (j < m && s2[j] == '#') {
                j++;
            }

            // Step: 03 - Check if either pointer has reached string termination
            if (i == n && j == m) {
                return true;
            }
            if (i == n || j == m) {
                return false;
            }

            // Step: 04 - Validate character identity and directional movement bounds
            if (s1[i] != s2[j]) {
                return false;
            }
            if (s1[i] == 'A' && i < j) {
                return false;
            }
            if (s1[i] == 'B' && i > j) {
                return false;
            }

            i++;
            j++;
        }

        // Step: 05 - Ensure remaining characters in both strings are strictly empty spaces
        while (i < n) {
            if (s1[i] != '#') {
                return false;
            }
            i++;
        }
        while (j < m) {
            if (s2[j] != '#') {
                return false;
            }
            j++;
        }

        // Step: 06 - Return true when all transformation invariants hold
        return true;
    }

    int isItPossible(string s1, string s2, int m, int n) {
        // Step: 01 - Delegate to primary conversion solver
        return isItPossible(s1, s2) ? 1 : 0;
    }

    bool canBeConverted(string s1, string s2) {
        // Step: 01 - Forward alias to primary isItPossible solver
        return isItPossible(s1, s2);
    }

    bool canBeConvertedVector(string s1, string s2) {
        // Step: 01 - Verify length and extract non-empty tokens with indices
        if (s1.length() != s2.length()) {
            return false;
        }

        vector<pair<char, int>> v1, v2;
        for (int i = 0; i < (int)s1.length(); ++i) {
            if (s1[i] != '#') {
                v1.push_back({s1[i], i});
            }
        }
        for (int j = 0; j < (int)s2.length(); ++j) {
            if (s2[j] != '#') {
                v2.push_back({s2[j], j});
            }
        }

        // Step: 02 - Compare token sequences and validate positional inequalities
        if (v1.size() != v2.size()) {
            return false;
        }

        for (size_t k = 0; k < v1.size(); ++k) {
            if (v1[k].first != v2[k].first) {
                return false;
            }
            if (v1[k].first == 'A' && v1[k].second < v2[k].second) {
                return false;
            }
            if (v1[k].first == 'B' && v1[k].second > v2[k].second) {
                return false;
            }
        }

        // Step: 03 - Return true upon matching all extracted token constraints
        return true;
    }
};
