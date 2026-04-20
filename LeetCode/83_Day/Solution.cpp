#include <vector>
#include <algorithm>


class Solution {
public:
    int maxDistance(std::vector<int>& colors) {
        int n = colors.size();
        int dist1 = 0;
        int dist2 = 0;

        // Choice 1: The furthest house from the start (index 0) with a different color
        for (int j = n - 1; j > 0; j--) {
            if (colors[j] != colors[0]) {
                dist1 = j; // distance = j - 0
                break;
            }
        }

        // Choice 2: The furthest house from the end (index n-1) with a different color
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                dist2 = (n - 1) - i;
                break;
            }
        }

        return std::max(dist1, dist2);
    }
};
