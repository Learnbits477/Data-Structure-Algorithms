#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        // Step 1: Initialize Push Counter
        int total_pushes = 0;
        int n = word.length();

        // Step 2: Iterate through the Characters
        for (int i = 0; i < n; i++) {
            total_pushes += (i / 8) + 1;
        }

        // Step 3: Return the Result
        return total_pushes;
    }
};
