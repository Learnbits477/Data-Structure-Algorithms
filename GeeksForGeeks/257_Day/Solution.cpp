#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void mergeTwoParts(vector<int>& arr) {
        // Step: 01 - Handle base case for empty or single-element array
        int n = arr.size();
        if (n <= 1) {
            return;
        }

        // Step: 02 - Locate the break point separating the two sorted halves
        int mid = -1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                mid = i;
                break;
            }
        }

        // Step: 03 - Return early if array is already fully sorted
        if (mid == -1) {
            return;
        }

        // Step: 04 - Merge the two sorted subarrays using two pointers
        vector<int> merged(n);
        int i = 0, j = mid + 1, k = 0;

        while (i <= mid && j < n) {
            if (arr[i] <= arr[j]) {
                merged[k++] = arr[i++];
            } else {
                merged[k++] = arr[j++];
            }
        }

        // Step: 05 - Copy remaining elements from the first half
        while (i <= mid) {
            merged[k++] = arr[i++];
        }

        // Step: 06 - Copy remaining elements from the second half
        while (j < n) {
            merged[k++] = arr[j++];
        }

        // Step: 07 - Write merged elements back into the original array
        arr = move(merged);
    }

    void mergeTwoPartsInplace(vector<int>& arr) {
        // Step: 01 - Handle base case for small array sizes
        int n = arr.size();
        if (n <= 1) {
            return;
        }

        // Step: 02 - Locate break point in array
        int mid = -1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                mid = i;
                break;
            }
        }

        // Step: 03 - Perform in-place merge if break point exists
        if (mid != -1) {
            inplace_merge(arr.begin(), arr.begin() + mid + 1, arr.end());
        }
    }

    void sortHalves(vector<int>& arr) {
        // Step: 01 - Alias wrapper for mergeTwoParts
        mergeTwoParts(arr);
    }

    void sortTwoParts(vector<int>& arr) {
        // Step: 01 - Alias wrapper for mergeTwoParts
        mergeTwoParts(arr);
    }

    void sortHalfSorted(vector<int>& arr) {
        // Step: 01 - Alias wrapper for mergeTwoParts
        mergeTwoParts(arr);
    }
};
