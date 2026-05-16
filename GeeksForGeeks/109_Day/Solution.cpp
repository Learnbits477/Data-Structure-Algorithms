#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findSmallest(vector<int> &arr) {
        // Step 1: Sort the Array
        sort(arr.begin(), arr.end());

        // Step 2: Initialize Tracking Variable
        long long res = 1;

        // Step 3: Iterate and Expand
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > res) {
                return res;
            }
            
            res += arr[i];
        }

        // Step 4: Final Result
        return res;
    }
};
