#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        // Step: 01 - Build character inverted index to store sorted 0-based positions
        vector<int> pos[26];
        int sLen = s.length();
        for (int i = 0; i < sLen; ++i) {
            pos[s[i] - 'a'].push_back(i);
        }

        // Step: 02 - Initialize tracking for longest and lexicographically smallest match
        string best = "";

        // Step: 03 - Iterate through each word in the dictionary
        for (const string &word : d) {
            int wLen = word.length();
            int bLen = best.length();

            // Step: 04 - Prune words that cannot improve upon the current best match
            if (wLen < bLen || (wLen == bLen && word >= best)) {
                continue;
            }

            // Step: 05 - Validate if word is a subsequence of s via binary search
            int currIdx = -1;
            bool isSubseq = true;

            for (char c : word) {
                const vector<int> &indices = pos[c - 'a'];
                auto it = upper_bound(indices.begin(), indices.end(), currIdx);
                if (it == indices.end()) {
                    isSubseq = false;
                    break;
                }
                currIdx = *it;
            }

            // Step: 06 - Update best candidate when a valid subsequence qualifies
            if (isSubseq) {
                best = word;
            }
        }

        // Step: 07 - Return optimal dictionary word (or empty string if none found)
        return best;
    }
};
