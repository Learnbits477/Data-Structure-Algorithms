#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        // Step 1: Initialize Frequency or Presence Trackers
        // Two boolean arrays of size 26 to track if lowercase/uppercase letters are present.
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        
        // Step 2: Mark Character Presence
        // Iterate through the word and record lowercase and uppercase characters.
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = true;
            } else if (c >= 'A' && c <= 'Z') {
                upper[c - 'A'] = true;
            }
        }
        
        // Step 3: Count and Return Special Characters
        // Count how many letters appear in both lowercase and uppercase forms.
        int specialCount = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) {
                specialCount++;
            }
        }
        
        return specialCount;
    }
};
