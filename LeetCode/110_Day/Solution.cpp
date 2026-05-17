#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int curr) {
        // Step 1: Base Cases and Out-of-Bounds Check
        if (curr < 0 || curr >= arr.size() || arr[curr] < 0) {
            return false;
        }

        // Step 2: Success Check
        if (arr[curr] == 0) {
            return true;
        }

        // Step 3: Mark as Visited (In-place negation)
        int val = arr[curr];
        arr[curr] = -arr[curr];

        // Step 4: Recursive Exploration
        bool forwardJump = canReach(arr, curr + val);
        bool backwardJump = canReach(arr, curr - val);

        // Step 5: Return Result
        return forwardJump || backwardJump;
    }
};
