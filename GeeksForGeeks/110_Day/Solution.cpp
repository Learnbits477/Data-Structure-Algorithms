#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        // Step 1: Initialize an Empty Result Vector (Stack)
        vector<int> res;

        // Step 2: Iterate Through the Input Array
        for (int x : arr) {
            // Step 3: Compare Signs with the Stack Top
            if (!res.empty()) {
                int top = res.back();
                // Determine if they have opposite signs: one non-negative, one negative
                if ((top >= 0 && x < 0) || (top < 0 && x >= 0)) {
                    res.pop_back(); // Pop if they have different signs
                } else {
                    res.push_back(x); // Push if they have the same sign
                }
            } else {
                res.push_back(x); // Push to empty stack
            }
        }

        // Step 4: Return the Result
        return res;
    }
};
