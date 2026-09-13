#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Step 1: Collect positions of all 1s in both images
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (img1[r][c] == 1) {
                    ones1.push_back({r, c});
                }
                if (img2[r][c] == 1) {
                    ones2.push_back({r, c});
                }
            }
        }

        // Step 2: Handle edge case where no 1s exist in either matrix
        if (ones1.empty() || ones2.empty()) {
            return 0;
        }

        // Step 3: Use a 2D offset frequency grid with bias +n
        // Row and column shifts range from -(n-1) to +(n-1) -> biased to [1, 2n-1]
        int offsetCount[65][65] = {0};
        int maxOverlap = 0;

        // Step 4: Count frequency of each translation vector (r2 - r1, c2 - c1)
        for (const auto& p1 : ones1) {
            for (const auto& p2 : ones2) {
                int dr = p2.first - p1.first + n;
                int dc = p2.second - p1.second + n;

                offsetCount[dr][dc]++;
                if (offsetCount[dr][dc] > maxOverlap) {
                    maxOverlap = offsetCount[dr][dc];
                }
            }
        }

        // Step 5: Return maximum overlap found
        return maxOverlap;
    }
};
