#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        
        // Step 1: Loop Through Patterns
        for (const string& pattern : patterns) {
            // Step 2: Substring Search
            if (word.find(pattern) != string::npos) {
                // Step 3: Increment Count
                ans++;
            }
        }
        
        // Step 4: Return Answer
        return ans;
    }
};
