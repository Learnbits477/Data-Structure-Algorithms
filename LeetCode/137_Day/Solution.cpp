#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        
        // Step 1: Iterate over each word
        for (const string& word : words) {
            int weight = 0;
            
            // Step 2: Calculate word weight
            for (char c : word) {
                weight += weights[c - 'a'];
            }
            
            // Step 3: Map weight modulo 26
            int rem = weight % 26;
            char mapped_char = 'z' - rem;
            
            // Step 4: Accumulate and return
            ans += mapped_char;
        }
        
        return ans;
    }
};
