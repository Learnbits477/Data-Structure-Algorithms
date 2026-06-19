#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // Step 1: Initialize current altitude and maximum altitude
        int current_altitude = 0;
        int max_altitude = 0;

        // Step 2: Traverse the net gain in altitude for each point
        for (int g : gain) {
            // Step 3: Update the current altitude by adding the gain
            current_altitude += g;
            
            // Step 4: Keep track of the maximum altitude reached so far
            max_altitude = max(max_altitude, current_altitude);
        }

        // Step 5: Return the highest altitude of a point
        return max_altitude;
    }
};
