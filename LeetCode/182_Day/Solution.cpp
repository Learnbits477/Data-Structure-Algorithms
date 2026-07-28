#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        // Step 1: Character Frequency Count
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Extract the Odd Count Character (Middle)
        string middle = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle = string(1, 'a' + i);
                freq[i]--;
                break; // Since input is guaranteed to be palindromic, at most one character is odd.
            }
        }

        // Step 3: Construct the Halved Prefixes
        string half = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                half += string(freq[i] / 2, 'a' + i);
            }
        }

        // Step 4: Reassemble the Palindrome
        string right = half;
        reverse(right.begin(), right.end());
        return half + middle + right;
    }
};
