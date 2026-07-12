#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Step 1: Copy and Sort the Original Array
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        // Step 2: Remove Duplicates
        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

        // Step 3: Map Elements to Ranks
        vector<int> result(arr.size());
        for (size_t i = 0; i < arr.size(); ++i) {
            result[i] = lower_bound(sortedArr.begin(), sortedArr.end(), arr[i]) - sortedArr.begin() + 1;
        }

        // Step 4: Return the Transformed Rank Array
        return result;
    }
};
