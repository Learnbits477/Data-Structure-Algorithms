#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Step 1: Find the longest prefix of target that can be formed by characters in s
        int L = 0;
        vector<int> prefix_count = count;
        while (L < n) {
            int char_idx = target[L] - 'a';
            if (prefix_count[char_idx] > 0) {
                prefix_count[char_idx]--;
                L++;
            } else {
                break;
            }
        }

        int start_i = L;
        if (L == n) {
            prefix_count[target[n - 1] - 'a']++;
            start_i = n - 1;
        }

        // Step 2: Find the largest divergence index from start_i down to 0
        for (int i = start_i; i >= 0; --i) {
            int target_char_idx = target[i] - 'a';

            for (int c = target_char_idx + 1; c < 26; ++c) {
                if (prefix_count[c] > 0) {
                    string result = target.substr(0, i);
                    result += (char)('a' + c);
                    prefix_count[c]--;

                    // Step 3: Append all remaining characters in ascending order
                    for (int rem = 0; rem < 26; ++rem) {
                        while (prefix_count[rem] > 0) {
                            result += (char)('a' + rem);
                            prefix_count[rem]--;
                        }
                    }
                    return result;
                }
            }

            if (i > 0) {
                prefix_count[target[i - 1] - 'a']++;
            }
        }

        // Step 4: Return empty string if no valid permutation exists
        return "";
    }
};
