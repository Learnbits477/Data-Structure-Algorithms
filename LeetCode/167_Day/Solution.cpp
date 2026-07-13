#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> res;

        // Step 1: Iterate over Candidates' Lengths
        for (int len = 2; len <= 9; ++len) {
            // Step 2: Slide Window for Each Starting Index
            for (int start = 0; start <= 9 - len; ++start) {
                // Step 3: Verify Range & Accumulate
                int num = stoi(digits.substr(start, len));
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }

        return res;
    }
};
