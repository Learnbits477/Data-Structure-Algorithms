#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                // Clockwise distance from startIndex to i
                int clockwise = (i - startIndex + n) % n;
                // Counter-clockwise distance
                int counter   = n - clockwise;
                minDist = min(minDist, min(clockwise, counter));
            }
        }

        return (minDist == INT_MAX) ? -1 : minDist;
    }
};
