#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool canAchieveFrequency(const vector<int>& sortedArr, int targetFreq, int k, const vector<long long>& prefix) {
        // Step: 01 - Verify if target frequency can be formed within operations budget
        for (int i = targetFreq - 1; i < (int)sortedArr.size(); i++) {
            long long windowSum = prefix[i + 1] - prefix[i - targetFreq + 1];
            long long operationsNeeded = 1LL * targetFreq * sortedArr[i] - windowSum;
            if (operationsNeeded <= k) {
                return true;
            }
        }
        return false;
    }

public:
    int maxFrequency(vector<int>& arr, int k) {
        // Step: 01 - Sort elements in ascending order
        sort(arr.begin(), arr.end());

        // Step: 02 - Initialize sliding window state variables
        int left = 0;
        int maxFreq = 0;
        long long windowSum = 0;

        // Step: 03 - Expand right boundary of the sliding window
        for (int right = 0; right < (int)arr.size(); right++) {
            windowSum += arr[right];

            // Step: 04 - Contract left boundary while cost exceeds operation allowance
            while ((1LL * (right - left + 1) * arr[right] - windowSum) > k) {
                windowSum -= arr[left];
                left++;
            }

            // Step: 05 - Update maximum frequency observed
            maxFreq = max(maxFreq, right - left + 1);
        }

        // Step: 06 - Return optimal frequency
        return maxFreq;
    }

    int maxFrequencyBinarySearch(vector<int>& arr, int k) {
        // Step: 01 - Sort input array in ascending order
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        int n = sortedArr.size();

        // Step: 02 - Compute prefix sum array
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + sortedArr[i];
        }

        // Step: 03 - Perform binary search on achievable frequency range
        int low = 1, high = n, ans = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAchieveFrequency(sortedArr, mid, k, prefix)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Step: 04 - Return maximum valid frequency
        return ans;
    }
};
