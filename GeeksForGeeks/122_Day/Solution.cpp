#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    int memo[101][901];
    string s;

    int solve(int idx, int prevSum) {
        if (idx == n) return 1;

        if (memo[idx][prevSum] != -1)
            return memo[idx][prevSum];

        int curSum = 0;
        int count  = 0;

        for (int j = idx; j < n; j++) {
            curSum += s[j] - '0';

            if (curSum < prevSum)
                continue;

            count += solve(j + 1, curSum);
        }

        return memo[idx][prevSum] = count;
    }

public:
    int validGroups(string& str) {
        s = str;
        n = (int)s.size();
        memset(memo, -1, sizeof(memo));
        return solve(0, 0);
    }
};
