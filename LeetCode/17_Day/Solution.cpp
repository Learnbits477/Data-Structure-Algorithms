#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        // Case 1: 1 distinct character
        // Just find longest contiguous segment of same char
        if (n > 0) {
            int currentLen = 1;
            maxLen = 1; // At least one character is balanced if string not empty
            for (int i = 1; i < n; ++i) {
                if (s[i] == s[i-1]) {
                    currentLen++;
                } else {
                    currentLen = 1;
                }
                maxLen = max(maxLen, currentLen);
            }
        } else {
             return 0;
        }

        // Case 2: 2 distinct characters
        // We check pairs (a,b), (b,c), (a,c)
        // Treat the 3rd char as a separator
        auto solve2 = [&](char c1, char c2) {
            int len = 0;
            // Balance: count(c1) - count(c2)
            // Map balance -> first index
            unordered_map<int, int> seen;
            int bal = 0;
            seen[0] = -1;
            
            for (int i = 0; i < n; ++i) {
                if (s[i] != c1 && s[i] != c2) {
                    // Reset
                    seen.clear();
                    seen[0] = i; // logically conceptually start new substring at i+1
                    bal = 0;
                    continue;
                }
                
                if (s[i] == c1) bal++;
                else bal--; // s[i] == c2
                
                if (seen.count(bal)) {
                    len = max(len, i - seen[bal]);
                } else {
                    seen[bal] = i;
                }
            }
            return len;
        };

        maxLen = max(maxLen, solve2('a', 'b'));
        maxLen = max(maxLen, solve2('b', 'c'));
        maxLen = max(maxLen, solve2('a', 'c'));

        // Case 3: 3 distinct characters
        // We want a substring where ca == cb == cc
        // Track diffs: (ca - cb) and (cb - cc)
        // Only valid if substring contains a, b, and c? 
        // Logic: if non-empty and ca=cb=cc, then ca, cb, cc > 0.
        // So just finding max length with equal counts is sufficient.
        
        map<pair<int, int>, int> seen3;
        int ca = 0, cb = 0, cc = 0;
        seen3[{0, 0}] = -1;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else if (s[i] == 'c') cc++;
            
            int diff1 = ca - cb;
            int diff2 = cb - cc;
            
            if (seen3.count({diff1, diff2})) {
                maxLen = max(maxLen, i - seen3[{diff1, diff2}]);
            } else {
                seen3[{diff1, diff2}] = i;
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string s1 = "abbac";
    cout << "Input: " << s1 << " | Output: " << sol.longestBalanced(s1) << " | Expected: 4" << endl;

    // Example 2
    string s2 = "aabcc";
    cout << "Input: " << s2 << " | Output: " << sol.longestBalanced(s2) << " | Expected: 3" << endl;

    // Example 3
    string s3 = "aba";
    cout << "Input: " << s3 << " | Output: " << sol.longestBalanced(s3) << " | Expected: 2" << endl;

    // Custom
    // "aaaa" -> 4 (Case 1)
    string s4 = "aaaa";
    cout << "Input: " << s4 << " | Output: " << sol.longestBalanced(s4) << " | Expected: 4" << endl;
    
    // "abc" -> 3 (Case 3)
    string s5 = "abc";
    cout << "Input: " << s5 << " | Output: " << sol.longestBalanced(s5) << " | Expected: 3" << endl;

    return 0;
}
