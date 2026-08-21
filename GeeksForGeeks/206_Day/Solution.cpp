#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int transform(string s1, string s2) {
        // Step 1: Length & Feasibility Check
        if (s1.length() != s2.length()) {
            return -1;
        }

        // Step 2: Anagram Validation using Frequency Array
        int freq[256] = {0};
        for (int k = 0; k < (int)s1.length(); k++) {
            freq[(unsigned char)s1[k]]++;
            freq[(unsigned char)s2[k]]--;
        }
        for (int k = 0; k < 256; k++) {
            if (freq[k] != 0) {
                return -1;
            }
        }

        // Step 3: Greedy Backward Matching (Two Pointers)
        int i = (int)s1.length() - 1;
        int j = (int)s2.length() - 1;
        int operations = 0;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                // Characters match in suffix, keep in place
                i--;
                j--;
            } else {
                // Character in s1 must be moved to the front
                operations++;
                i--;
            }
        }

        // Step 4: Return Result
        return operations;
    }
};
