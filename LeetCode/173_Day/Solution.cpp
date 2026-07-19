#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        // Step 1: Track Last Occurrences
        vector<int> last_idx(26, -1);
        for (int i = 0; i < s.length(); i++) {
            last_idx[s[i] - 'a'] = i;
        }

        // Step 2: Initialize helpers
        vector<bool> seen(26, false);
        string result = "";

        // Step 3: Process characters
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // If character is already in the stack, skip it
            if (seen[c - 'a']) {
                continue;
            }

            // Pop elements from the stack if they are larger than the current character
            // and appear again later in the string
            while (!result.empty() && result.back() > c && last_idx[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }

            // Add current character to stack and mark it as seen
            result.push_back(c);
            seen[c - 'a'] = true;
        }

        return result;
    }
};
