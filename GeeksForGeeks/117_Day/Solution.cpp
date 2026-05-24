#include <iostream>
using namespace std;

class Solution {
public:
    int coin(vector<int> &arr) {
        // Step 1: Initialize Two Pointers
        int left = 0;
        int right = arr.size() - 1;

        // Step 2: Compare and Narrow Down
        while (left < right) {
            // Step 3: Shift Pointers Based on Greedy Strategy
            if (arr[left] >= arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        // Step 4: Return Last Coin
        return arr[left];
    }
};
