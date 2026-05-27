#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        // Step 1: Initialize Trackers
        // last_lower stores the last index of each lowercase letter.
        // first_upper stores the first index of each uppercase letter.
        vector<int> last_lower(26, -1);
        vector<int> first_upper(26, -1);
        
        int n = word.length();
        
        // Step 2: Traverse the String
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                last_lower[c - 'a'] = i;
            } else if (c >= 'A' && c <= 'Z') {
                if (first_upper[c - 'A'] == -1) {
                    first_upper[c - 'A'] = i;
                }
            }
        }
        
        // Step 3: Count Special Characters
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (last_lower[i] != -1 && first_upper[i] != -1 && last_lower[i] < first_upper[i]) {
                count++;
            }
        }
        
        return count;
    }
};
