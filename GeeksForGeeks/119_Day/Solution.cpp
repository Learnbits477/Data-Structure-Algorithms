#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minToggle(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Initialize State Variables
        // oneCount tracks the number of 1s seen so far.
        // toggles tracks the minimum toggles needed for the scanned prefix.
        int oneCount = 0;
        int toggles = 0;
        
        // Step 2: Traverse the Array
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                oneCount++;
            } else {
                // If the element is 0, we can either:
                // 1. Toggle it to 1 (cost increases by 1)
                // 2. Toggle all previous 1s to 0s (cost becomes oneCount)
                toggles = min(toggles + 1, oneCount);
            }
        }
        
        // Step 3: Return the Result
        return toggles;
    }
};
