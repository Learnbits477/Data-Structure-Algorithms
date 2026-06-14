#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exitPoint(vector<vector<int>> mat) {
        int n = mat.size();
        int m = n > 0 ? mat[0].size() : 0;
        // Step 1: Initialization
        // dx and dy correspond to directions: 0 = Right, 1 = Down, 2 = Left, 3 = Up
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int r = 0, c = 0;
        int d = 0; // Starts facing Right
        int last_r = 0, last_c = 0;
        
        // Step 2: Simulation Loop
        // Run until we move out of bounds
        while (r >= 0 && r < n && c >= 0 && c < m) {
            // Cache the current valid coordinates
            last_r = r;
            last_c = c;
            
            // If the current cell is 1, change direction clockwise and update cell to 0
            if (mat[r][c] == 1) {
                d = (d + 1) % 4;
                mat[r][c] = 0;
            }
            
            // Move to the next cell in direction d
            r += dx[d];
            c += dy[d];
        }
        
        // Step 3: Return Result
        // The last valid coordinates before exiting
        return {last_r, last_c};
    }
};
