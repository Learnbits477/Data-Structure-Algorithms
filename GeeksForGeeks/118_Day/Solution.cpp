#include <iostream>
using namespace std;

class Solution {
public:
    bool checkElements(int start, int end, vector<int> &arr) {
        int n = arr.size();
        int rangeSize = end - start + 1;

        // Step 1: Handle Base Condition
        // If the range contains more elements than the array, it cannot contain all of them.
        if (rangeSize > n) {
            return false;
        }

        // Step 2: Cycle Sort Elements
        // Rearrange elements such that any element x in [start, end] is placed at index x - start.
        for (int i = 0; i < n; i++) {
            while (arr[i] >= start && arr[i] <= end) {
                int correctIdx = arr[i] - start;
                // If it's already in the correct position, we break to prevent infinite loops.
                if (arr[correctIdx] == arr[i]) {
                    break;
                }
                swap(arr[i], arr[correctIdx]);
            }
        }

        // Step 3: Validate the Range
        // Check if every index i in the range [0, rangeSize - 1] contains the element start + i.
        for (int i = 0; i < rangeSize; i++) {
            if (arr[i] != start + i) {
                return false;
            }
        }

        return true;
    }
};
