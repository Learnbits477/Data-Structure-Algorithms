#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Step 1 — Calculate Minute Hand Position
        double minute_angle = minutes * 6.0;

        // Step 2 — Calculate Hour Hand Position
        double hour_angle = (hour % 12) * 30.0 + minutes * 0.5;

        // Step 3 — Compute the Angle Difference
        double diff = abs(hour_angle - minute_angle);

        // Step 4 — Return the Smaller Angle
        return min(diff, 360.0 - diff);
    }
};
