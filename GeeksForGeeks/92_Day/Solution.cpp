
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();

        // Count total number of 1s — this is the required window size
        int totalOnes = 0;
        for (int x : arr) totalOnes += x;

        // Edge case: no 1s present
        if (totalOnes == 0) return -1;

        // Count 0s in the first window of size totalOnes
        int zerosInWindow = 0;
        for (int i = 0; i < totalOnes; i++) {
            if (arr[i] == 0) zerosInWindow++;
        }

        int minSwaps = zerosInWindow;

        // Slide the window across the rest of the array
        for (int right = totalOnes; right < n; right++) {
            int left = right - totalOnes; // element leaving the window

            // Add the new right element; remove the old left element
            if (arr[right] == 0) zerosInWindow++;
            if (arr[left] == 0)  zerosInWindow--;

            minSwaps = min(minSwaps, zerosInWindow);
        }

        return minSwaps;
    }
};

