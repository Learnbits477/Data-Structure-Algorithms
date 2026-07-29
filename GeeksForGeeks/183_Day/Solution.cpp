#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubsets(vector<int>& arr) {
        // Step 1: Populate the Hash Set
        unordered_set<int> num_set(arr.begin(), arr.end());
        int subsets = 0;

        // Step 2: Iterate through the Array Elements
        for (int x : arr) {
            // Step 3: Identify the Start of a Subsequence
            if (num_set.find(x - 1) == num_set.end()) {
                subsets++;
            }
        }

        // Step 4: Return the Count
        return subsets;
    }
};

