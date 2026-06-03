#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // Step 1: Map Element Indices
        unordered_map<int, vector<int>> indicesMap;
        for (int i = 0; i < arr.size(); ++i) {
            indicesMap[arr[i]].push_back(i);
        }
        
        // Step 2: Process Queries
        vector<int> ans;
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];
            
            // Step 3: Check Existence
            if (indicesMap.find(x) == indicesMap.end()) {
                ans.push_back(0);
                continue;
            }
            
            // Step 4: Binary Search
            const auto& indices = indicesMap[x];
            auto left_it = lower_bound(indices.begin(), indices.end(), l);
            auto right_it = upper_bound(indices.begin(), indices.end(), r);
            
            // Step 5: Calculate Frequency
            ans.push_back(right_it - left_it);
        }
        
        return ans;
    }
};