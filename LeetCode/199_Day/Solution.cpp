#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        // Step 1: Initialize Frequency Array and Pointers
        vector<int> freq(26, 0);
        int left = 0;
        int max_len = 0;
        int n = s.length();

        // Step 2: Expand Window using Right Pointer
        for (int right = 0; right < n; ++right) {
            freq[s[right] - 'a']++;

            // Step 3: Shrink Window when any character exceeds 2 occurrences
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            // Step 4: Track Maximum Substring Length
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
