#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> result;
        int n = arr.size();
        
        // Step 1: Initialize Traversal State
        int start = 0;
        int levelSize = 1;
        
        while (start < n) {
            // Step 2: Extract and Sort Level Elements
            int end = min(start + levelSize, n);
            vector<int> levelElements;
            for (int i = start; i < end; i++) {
                levelElements.push_back(arr[i]);
            }
            sort(levelElements.begin(), levelElements.end());
            result.push_back(levelElements);
            
            // Step 3: Transition to the Next Level
            start = end;
            levelSize *= 2;
        }
        
        return result;
    }
};
