#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int totalDegree = 0;
        int n = s.length();

        // Step 1: Iterate through each character with 1-based indexing
        for (int i = 0; i < n; ++i) {
            // Position in reversed alphabet: 'a' = 26, 'b' = 25, ..., 'z' = 1
            int revAlphabetPos = 'z' - s[i] + 1;
            int stringPos = i + 1;

            // Step 2: Accumulate product of reversed alphabet position and 1-based string index
            totalDegree += revAlphabetPos * stringPos;
        }

        return totalDegree;
    }
};
