#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // Step 1: Sort the Array
        sort(arr.begin(), arr.end());
        
        // Step 2: Initialize first element
        arr[0] = 1;
        
        // Step 3: Apply Adjacent Constraints
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        
        // Step 4: Return Result
        return arr[n - 1];
    }
};
