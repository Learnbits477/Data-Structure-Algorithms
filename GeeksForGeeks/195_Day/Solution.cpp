#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTasks(int n, vector<int>& h, vector<int>& l) {
        // Step 1: Handle Edge Cases
        if (n == 0) return 0;
        if (n == 1) return max(h[0], l[0]);

        // Step 2: Initialize DP State
        int prev2 = 0;
        int prev1 = max(h[0], l[0]);

        // Step 3: Iterate Through Subsequent Days
        for (int i = 1; i < n; ++i) {
            int curr = max(h[i] + prev2, l[i] + prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        // Step 4: Extract Answer
        return prev1;
    }

    int maxTasks(vector<int>& h, vector<int>& l) {
        return maxTasks(h.size(), h, l);
    }

    int maxTask(int n, vector<int>& h, vector<int>& l) {
        return maxTasks(n, h, l);
    }

    int maxTask(vector<int>& h, vector<int>& l) {
        return maxTasks(h.size(), h, l);
    }
};
