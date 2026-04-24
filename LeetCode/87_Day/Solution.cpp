#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left_count = 0;
        int right_count = 0;
        int underscore_count = 0;

        for (char move : moves) {
            if (move == 'L') {
                left_count++;
            } else if (move == 'R') {
                right_count++;
            } else {
                underscore_count++;
            }
        }

        return abs(left_count - right_count) + underscore_count;
    }
};
