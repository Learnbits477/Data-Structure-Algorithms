#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countAlwaysFound(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return n;
        }

        // Step: 01 - Precompute suffix minimum array for O(1) right-side bound lookup
        vector<int> suffMin(n);
        suffMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(suffMin[i + 1], arr[i]);
        }

        // Step: 02 - Traverse from left to right while tracking running maximum
        int runningMax = INT_MIN;
        int alwaysFoundCount = 0;

        for (int i = 0; i < n; ++i) {
            // Step: 03 - Check if current element is greater than all left elements
            bool greaterThanLeft = (arr[i] > runningMax);

            // Step: 04 - Check if current element is smaller than all right elements
            bool smallerThanRight = (i == n - 1) || (arr[i] < suffMin[i + 1]);

            // Step: 05 - Increment count if both partition conditions are satisfied
            if (greaterThanLeft && smallerThanRight) {
                alwaysFoundCount++;
            }

            // Step: 06 - Update running prefix maximum for subsequent indices
            runningMax = max(runningMax, arr[i]);
        }

        // Step: 07 - Return total count of elements guaranteed to be found
        return alwaysFoundCount;
    }

    int countAlwaysFoundPrefixSuffix(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return n;
        }

        // Step: 01 - Build prefix maximum and suffix minimum arrays
        vector<int> prefMax(n), suffMin(n);
        prefMax[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefMax[i] = max(prefMax[i - 1], arr[i]);
        }

        suffMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(suffMin[i + 1], arr[i]);
        }

        // Step: 02 - Count elements strictly between prefix max and suffix min
        int count = 0;
        for (int i = 0; i < n; ++i) {
            bool leftOk = (i == 0 || arr[i] > prefMax[i - 1]);
            bool rightOk = (i == n - 1 || arr[i] < suffMin[i + 1]);
            if (leftOk && rightOk) {
                count++;
            }
        }

        // Step: 03 - Return verified count
        return count;
    }

    int countAlwaysFoundFilter(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) {
            return n;
        }

        // Step: 01 - Filter candidates greater than all preceding elements
        vector<bool> candidate(n, false);
        int maxSoFar = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > maxSoFar) {
                candidate[i] = true;
                maxSoFar = arr[i];
            }
        }

        // Step: 02 - Confirm candidates smaller than all succeeding elements
        int minSoFar = INT_MAX;
        int count = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] < minSoFar) {
                if (candidate[i]) {
                    count++;
                }
                minSoFar = arr[i];
            }
        }

        // Step: 03 - Return total valid searchable elements
        return count;
    }

    // Platform alias methods
    int successfulSearches(vector<int>& arr) {
        return countAlwaysFound(arr);
    }

    int countValidSelections(vector<int>& arr) {
        return countAlwaysFound(arr);
    }
};
