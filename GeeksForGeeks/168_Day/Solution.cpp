#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Initialize Target
        int target = 0;
        
        // Step 2: Backward Propagation
        for (int i = n - 1; i >= 0; --i) {
            target = (target + arr[i] + 1) / 2;
        }
        
        // Step 3: Return Initial Value
        return target;
    }
};
