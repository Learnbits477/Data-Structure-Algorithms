#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr) {
        if (arr.empty()) return 0;

        long long maxSoFar = arr[0];
        long long minSoFar = arr[0];
        long long result = maxSoFar;

        for (size_t i = 1; i < arr.size(); ++i) {
            long long curr = arr[i];

            // If the current number is negative, maxSoFar and minSoFar swap roles
            // multiplying a negative by a negative makes it positive (large)
            // multiplying a positive by a negative makes it negative (small)
            if (curr < 0) {
                swap(maxSoFar, minSoFar);
            }

            // Update maxSoFar and minSoFar
            maxSoFar = max(curr, maxSoFar * curr);
            minSoFar = min(curr, minSoFar * curr);

            // Update global maximum product found so far
            result = max(result, maxSoFar);
        }

        return result;
    }
};
