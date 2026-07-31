#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        // Step 1: Count letter frequencies
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        // Step 2: Sort frequencies in descending order
        sort(freq.rbegin(), freq.rend());

        // Step 3: Calculate the minimum pushes
        int total_pushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) {
                break;
            }
            total_pushes += freq[i] * (i / 8 + 1);
        }

        // Step 4: Return the result
        return total_pushes;
    }
};
