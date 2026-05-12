#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) < (b[1] - b[0]);
        });

        int ans = 0;
        for (int i = 0; i < (int)tasks.size(); ++i) {
            int actual  = tasks[i][0];
            int minimum = tasks[i][1];
            ans = max(ans + actual, minimum);
        }
        return ans;
    }
};
