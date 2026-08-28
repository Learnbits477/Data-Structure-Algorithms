#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;

        // Base cases: costs for picking each choice at the first row (row 0)
        int prev0 = mat[0][0];
        int prev1 = mat[0][1];
        int prev2 = mat[0][2];

        // Transition through each subsequent row
        for (int i = 1; i < n; ++i) {
            // If we choose option 0 at row i, previous choice must be option 1 or 2
            int curr0 = mat[i][0] + min(prev1, prev2);

            // If we choose option 1 at row i, previous choice must be option 0 or 2
            int curr1 = mat[i][1] + min(prev0, prev2);

            // If we choose option 2 at row i, previous choice must be option 0 or 1
            int curr2 = mat[i][2] + min(prev0, prev1);

            // Update previous states for the next iteration
            prev0 = curr0;
            prev1 = curr1;
            prev2 = curr2;
        }

        // The minimum cost will be the minimum of the three possible ending choices
        return min({prev0, prev1, prev2});
    }
};
