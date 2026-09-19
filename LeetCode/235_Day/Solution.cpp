#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Step: 01 - Project (clamp) the circle center onto the axis-aligned rectangle
        int nearestX = max(x1, min(xCenter, x2));
        int nearestY = max(y1, min(yCenter, y2));

        // Step: 02 - Compute delta between the circle center and the nearest point
        int dx = nearestX - xCenter;
        int dy = nearestY - yCenter;

        // Step: 03 - Verify if squared Euclidean distance is within squared radius
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};
