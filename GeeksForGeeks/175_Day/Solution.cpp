#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIndexDifference(string &s) {
        int n = s.length();
        
        // Store the last occurrence index of each character 'a' through 'z'
        vector<int> last_occ(26, -1);
        for (int i = 0; i < n; ++i) {
            last_occ[s[i] - 'a'] = i;
        }
        
        // Find the first occurrence of character 'a'
        int first_a = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                first_a = i;
                break;
            }
        }
        
        // If character 'a' is not present in string s, return -1
        if (first_a == -1) return -1;
        
        // Array to store the minimum reachable index for each character
        vector<int> min_reach(26, -1);
        min_reach[0] = first_a;
        
        for (int c = 1; c < 26; ++c) {
            int prev_min = min_reach[c - 1];
            if (prev_min == -1) {
                break; // Character c-1 is unreachable, so c cannot be reached
            }
            // Find the first occurrence of character c at index > prev_min
            for (int i = prev_min + 1; i < n; ++i) {
                if (s[i] - 'a' == c) {
                    min_reach[c] = i;
                    break;
                }
            }
        }
        
        int max_diff = -1;
        
        // Check character 'a' (c = 0) as a potential terminal state
        if (last_occ[1] < first_a) {
            max_diff = max(max_diff, 0);
        }
        
        // Check characters 'b' through 'z' (c = 1..25)
        for (int c = 1; c < 26; ++c) {
            if (min_reach[c] != -1) {
                // Check if last_occ[c] has no character (c + 1) appearing after it
                bool is_terminal = (c == 25) || (last_occ[c + 1] < last_occ[c]);
                if (is_terminal) {
                    max_diff = max(max_diff, last_occ[c] - first_a);
                }
            }
        }
        
        return max_diff;
    }

    // Alias for compatibility
    int maxIndexDiff(string &s) {
        return maxIndexDifference(s);
    }
};
