#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexiString(string& s) {
        // Step: 01 - Handle base case of empty or single character string
        int n = s.length();
        if (n <= 1) return s;

        // Step: 02 - Concatenate string with itself to handle cyclic rotations
        string S = s + s;
        int i = 0, j = 1, k = 0;

        // Step: 03 - Compare rotations starting at i and j with offset k
        while (i < n && j < n && k < n) {
            if (S[i + k] == S[j + k]) {
                k++;
            } else if (S[i + k] > S[j + k]) {
                // Step: 04 - Skip suboptimal start positions from i to i + k
                i = i + k + 1;
                if (i <= j) i = j + 1;
                k = 0;
            } else {
                // Step: 05 - Skip suboptimal start positions from j to j + k
                j = j + k + 1;
                if (j <= i) j = i + 1;
                k = 0;
            }
        }

        // Step: 06 - Extract and return the lexicographically smallest rotation
        int startIdx = min(i, j);
        return S.substr(startIdx, n);
    }

    string lexiString(const string& s) {
        string temp = s;
        return lexiString(temp);
    }

    string boothMinRotation(const string& s) {
        // Step: 01 - Handle base case
        int n = s.length();
        if (n <= 1) return s;

        // Step: 02 - Initialize failure table on doubled string
        string S = s + s;
        vector<int> f(2 * n, -1);
        int k = 0;

        // Step: 03 - Compute failure function and update minimal rotation candidate
        for (int j = 1; j < 2 * n; ++j) {
            int i = f[j - k - 1];
            while (i != -1 && S[j] != S[k + i + 1]) {
                if (S[j] < S[k + i + 1]) {
                    k = j - i - 1;
                }
                i = f[i];
            }
            if (i == -1 && S[j] != S[k + i + 1]) {
                if (S[j] < S[k + i + 1]) {
                    k = j;
                }
                f[j - k] = -1;
            } else {
                f[j - k] = i + 1;
            }
        }

        // Step: 04 - Return minimal rotation substring
        return S.substr(k, n);
    }

    string minRotation(string s) {
        return lexiString(s);
    }
};
