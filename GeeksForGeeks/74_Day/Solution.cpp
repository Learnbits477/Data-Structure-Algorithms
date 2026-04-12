#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * @brief Counts the number of strictly increasing subarrays of size >= 2.
     * 
     * The approach involves scanning the array to find segments of strictly increasing 
     * elements. For a segment of length L, the number of subarrays of length >= 2 
     * is given by the formula: (L * (L - 1)) / 2.
     * 
     * @param arr The input array of integers.
     * @return long long The total count of strictly increasing subarrays.
     */
    long long countIncreasing(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;
        
        long long totalCount = 0;
        long long currentLen = 1;

        for (int i = 0; i < n - 1; i++) {
            // Check if the next element is strictly greater than the current element
            if (arr[i+1] > arr[i]) {
                currentLen++;
            } else {
                // If it's not increasing, calculate subarrays for the previous segment
                if (currentLen >= 2) {
                    totalCount += (currentLen * (currentLen - 1)) / 2;
                }
                currentLen = 1; // Reset length for the next segment
            }
        }
        
        // Add subarrays for the last segment
        if (currentLen >= 2) {
            totalCount += (currentLen * (currentLen - 1)) / 2;
        }

        return totalCount;
    }
};
