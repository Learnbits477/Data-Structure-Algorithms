#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBuildingHeight(int n, vector<vector<int>>& restrictions) {
        // Step 1: Setup and Sort Restrictions
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Step 2: Forward Propagation (Left-to-Right Pass)
        for (int i = 1; i < m; ++i) {
            restrictions[i][1] = min(restrictions[i][1], 
                                     restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));
        }

        // Step 3: Backward Propagation (Right-to-Left Pass)
        for (int i = m - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], 
                                     restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        }

        int max_height = 0;

        // Step 4: Compute Maximum Height Between Adjacent Restrictions
        for (int i = 1; i < m; ++i) {
            int id1 = restrictions[i - 1][0];
            int h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0];
            int h2 = restrictions[i][1];
            
            // Using long long to prevent potential integer overflow during sum
            int peak = (static_cast<long long>(h1) + h2 + (id2 - id1)) / 2;
            max_height = max(max_height, peak);
        }

        // Step 5: Handle the Trailing Buildings
        int last_id = restrictions[m - 1][0];
        int last_h = restrictions[m - 1][1];
        max_height = max(max_height, last_h + (n - last_id));

        // Step 6: Return Result
        return max_height;
    }
};
