#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int reverseNumber(int n) {
        long long res = 0;
        while (n > 0) {
            res = res * 10 + (n % 10);
            n /= 10;
        }
        return (int)res;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int minDistance = INT_MAX;
        unordered_map<int, int> lastSeenRev; // maps reverse(nums[i]) to index i

        for (int j = 0; j < n; ++j) {
            // Check if current nums[j] was the reverse of any previous nums[i]
            if (lastSeenRev.count(nums[j])) {
                minDistance = min(minDistance, j - lastSeenRev[nums[j]]);
            }
            
            // Store the current nums[j]'s reverse to be matched by a future nums[k]
            int rev = reverseNumber(nums[j]);
            lastSeenRev[rev] = j;
        }

        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};
