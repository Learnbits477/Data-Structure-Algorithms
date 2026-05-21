#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper to calculate the number of digits in O(1) time
    inline int getDigitCount(int val) {
        if (val >= 100000000) return 9;
        if (val >= 10000000) return 8;
        if (val >= 1000000) return 7;
        if (val >= 100000) return 6;
        if (val >= 10000) return 5;
        if (val >= 1000) return 4;
        if (val >= 100) return 3;
        if (val >= 10) return 2;
        return 1;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Step 1: Prefix Extraction for Array 1
        unordered_set<int> prefixSet;
        for (int val : arr1) {
            while (val > 0) {
                prefixSet.insert(val);
                val /= 10;
            }
        }

        int maxLength = 0;

        // Step 2: Check and Match with Array 2
        for (int val : arr2) {
            while (val > 0) {
                if (prefixSet.count(val)) {
                    // Step 3: Longest Match Selection
                    maxLength = max(maxLength, getDigitCount(val));
                    break; // Found the longest common prefix for this number
                }
                val /= 10;
            }
        }

        // Step 4: Return Result
        return maxLength;
    }
};
