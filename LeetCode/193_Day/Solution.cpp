#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // Step 1: Precompute Suffix Array
        // suffix[j] stores the maximum index in word1 such that the suffix
        // word2[j...m-1] can be matched to a subsequence of word1 starting
        // at suffix[j] with 0 mismatches.
        vector<int> suffix(m + 1, -1);
        suffix[m] = n;
        
        int idx = n - 1;
        for (int j = m - 1; j >= 0; j--) {
            while (idx >= 0 && word1[idx] != word2[j]) {
                idx--;
            }
            suffix[j] = idx;
            if (idx >= 0) {
                idx--;
            }
        }
        
        // Step 2: Greedy Matching with Two Pointers
        vector<int> indices;
        int prev_idx = -1;
        bool changed = false;
        
        for (int j = 0; j < m; j++) {
            int i = prev_idx + 1;
            while (i < n) {
                if (word1[i] == word2[j]) {
                    indices.push_back(i);
                    prev_idx = i;
                    break;
                } else if (!changed && suffix[j + 1] > i) {
                    indices.push_back(i);
                    prev_idx = i;
                    changed = true;
                    break;
                }
                i++;
            }
            if (i == n) {
                return {};
            }
        }
        
        return indices;
    }
};
