#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kSubstr(string s, int k) {
        int n = s.length();
        // Step 1: Check Divisibility
        if (n % k != 0) {
            return false;
        }

        // Step 2: Partition and Count Frequencies
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i += k) {
            freq[s.substr(i, k)]++;
        }

        // Step 3: Analyze Substring Frequencies
        if (freq.size() == 1) {
            return true;
        }

        if (freq.size() > 2) {
            return false;
        }

        // If there are exactly 2 unique substrings, one must have frequency 1
        for (auto const& it : freq) {
            if (it.second == 1) {
                return true;
            }
        }

        return false;
    }
};
