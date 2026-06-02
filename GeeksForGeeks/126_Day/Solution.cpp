#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // Step 1: Sort the Array
        sort(arr.begin(), arr.end());
        
        // Step 2: Initialize Variables
        int sum = 0;
        int n = arr.size();
        
        // Step 3: Iterate Backwards
        for (int i = n - 1; i > 0; i--) {
            // Step 4: Check Valid Pair
            if (arr[i] - arr[i - 1] < k) {
                // Step 5: Add to Sum and Skip
                sum += arr[i] + arr[i - 1];
                i--; // Decrement i to skip the paired element
            }
        }
        
        // Step 6: Return Result
        return sum;
    }
};
