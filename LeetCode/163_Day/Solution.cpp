#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Step 1: Component Labels Initialization
        vector<int> comp(n, 0);
        int curr_comp = 0;
        
        // Step 2: Contiguous Grouping Pass
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                curr_comp++;
            }
            comp[i] = curr_comp;
        }
        
        // Step 3: Query Processing
        vector<bool> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }
        
        return ans;
    }
};
