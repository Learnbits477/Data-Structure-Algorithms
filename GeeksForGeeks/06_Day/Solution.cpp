#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        int totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        int maxSum = arr[0], minSum = arr[0];

        for (int i = 0; i < n; i++) {
            // Kadane's for max subarray sum
            currMaxSum = max(currMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currMaxSum);

            // Kadane's for min subarray sum
            currMinSum = min(currMinSum + arr[i], arr[i]);
            minSum = min(minSum, currMinSum);

            totalSum += arr[i];
        }

        int normalSum = maxSum;
        int circularSum = totalSum - minSum;

        // If all numbers are negative, circularSum would be 0, so return normalSum
        if (minSum == totalSum)
            return normalSum;

        return max(normalSum, circularSum);
    }
};
