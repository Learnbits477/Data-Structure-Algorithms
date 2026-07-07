#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        // Step 1 — Separate and Boundary Initialization
        vector<int> rows;
        vector<int> cols;
        
        rows.reserve(k + 2);
        cols.reserve(k + 2);
        
        // Add virtual boundaries at the start and end of dimensions
        rows.push_back(0);
        rows.push_back(n + 1);
        cols.push_back(0);
        cols.push_back(m + 1);
        
        // Step 2 — Extract Blocked Coordinates
        for (int i = 0; i < k; ++i) {
            rows.push_back(arr[i][0]);
            cols.push_back(arr[i][1]);
        }
        
        // Step 3 — Sort Indices
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        
        // Step 4 — Calculate Maximum Gaps
        int maxRowGap = 0;
        for (size_t i = 1; i < rows.size(); ++i) {
            maxRowGap = max(maxRowGap, rows[i] - rows[i - 1] - 1);
        }
        
        int maxColGap = 0;
        for (size_t i = 1; i < cols.size(); ++i) {
            maxColGap = max(maxColGap, cols[i] - cols[i - 1] - 1);
        }
        
        // Step 5 — Compute Largest Area
        return maxRowGap * maxColGap;
    }
};
