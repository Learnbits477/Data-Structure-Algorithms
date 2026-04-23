#include <vector>
using namespace std;

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        long long totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }

        // If total sum is odd, it's impossible to split into two equal integer sums
        if (totalSum % 2 != 0) {
            return false;
        }

        long long currentSum = 0;
        long long target = totalSum / 2;

        for (int x : arr) {
            currentSum += x;
            if (currentSum == target) {
                return true;
            }
            // If currentSum exceeds target, no point in continuing as all elements are positive
            if (currentSum > target) {
                return false;
            }
        }

        return false;
    }
};
