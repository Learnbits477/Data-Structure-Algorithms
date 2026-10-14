#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findRollOut(string &s, vector<int> &roll) {
        // Step: 01 - Initialize difference array with size n + 1
        int n = static_cast<int>(s.size());
        vector<int> diff(n + 1, 0);

        // Step: 02 - Record interval boundary increments and decrements
        for (int k : roll) {
            diff[0]++;
            if (k < n) {
                diff[k]--;
            }
        }

        // Step: 03 - Compute prefix sum and apply modular circular shifts
        int currentRolls = 0;
        for (int i = 0; i < n; i++) {
            currentRolls += diff[i];
            int shift = (currentRolls % 26 + 26) % 26;
            s[i] = static_cast<char>('a' + (s[i] - 'a' + shift) % 26);
        }

        // Step: 04 - Return updated string
        return s;
    }

    string findRollOutSuffix(string s, vector<int> &roll) {
        // Step: 01 - Count frequencies of prefix roll lengths
        int n = static_cast<int>(s.size());
        vector<int> count(n, 0);

        for (int k : roll) {
            if (k >= 1 && k <= n) {
                count[k - 1]++;
            }
        }

        // Step: 02 - Propagate rolls backwards using suffix accumulation
        int runningRolls = 0;
        for (int i = n - 1; i >= 0; i--) {
            runningRolls += count[i];
            int shift = (runningRolls % 26 + 26) % 26;
            s[i] = static_cast<char>('a' + (s[i] - 'a' + shift) % 26);
        }

        // Step: 03 - Return modified string
        return s;
    }

    string rollCharacters(string &s, vector<int> &roll) {
        // Step: 01 - Delegate to primary findRollOut solver
        return findRollOut(s, roll);
    }
};
