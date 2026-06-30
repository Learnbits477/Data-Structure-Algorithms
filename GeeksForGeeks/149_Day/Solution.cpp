#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, int last, int num, int len, vector<int> &ans) {
        if (len == n) {
            ans.push_back(num);
            return;
        }

        for (int d = last + 1; d <= 9; d++) {
            solve(n, d, num * 10 + d, len + 1, ans);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> ans;

        if (n == 1) {
            for (int i = 0; i <= 9; i++)
                ans.push_back(i);
            return ans;
        }

        if (n > 9) return ans;

        for (int i = 1; i <= 9; i++) {
            solve(n, i, i, 1, ans);
        }

        return ans;
    }
};
