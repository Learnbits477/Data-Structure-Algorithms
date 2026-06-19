#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> optimalArray(int n, vector<int>& arr) {
        if (n == 0) return {};
        vector<int> res(n, 0);

        // Step 1 — Initialize Variables
        int mid = 0;
        long long leftSum = arr[0];
        long long rightSum = 0;

        // Step 2 — Loop and Shift Transitions
        for (int i = 1; i < n; ++i) {
            if (i % 2 != 0) {
                // If i is odd, mid does not change. The new element falls to the right side.
                rightSum += arr[i];
            } else {
                // If i is even, mid moves to mid + 1. 
                // The element at new_mid transitions from the right partition to the left.
                int new_mid = mid + 1;
                leftSum += arr[new_mid];
                rightSum += arr[i] - arr[new_mid];
                mid = new_mid;
            }

            // Step 3 — Compute Prefix Operations
            long long ops = (2LL * mid + 1 - i) * arr[mid] - leftSum + rightSum;
            res[i] = (int)ops;
        }

        return res;
    }

    // Overloaded function to handle variations in the GFG template signature
    vector<int> optimalArray(vector<int>& arr) {
        return optimalArray(arr.size(), arr);
    }
};
