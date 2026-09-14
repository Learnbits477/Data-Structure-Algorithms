#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Step 1: Check horizontal (X-axis) 1D interval overlap
        bool xOverlap = (rec1[0] < rec2[2]) && (rec2[0] < rec1[2]);

        // Step 2: Check vertical (Y-axis) 1D interval overlap
        bool yOverlap = (rec1[1] < rec2[3]) && (rec2[1] < rec1[3]);

        // Step 3: Combine both dimensions (positive 2D intersection area)
        return xOverlap && yOverlap;
    }
};
