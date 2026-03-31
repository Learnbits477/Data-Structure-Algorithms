#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem: 3474. Lexicographically Smallest Generated String
 * Source: https://leetcode.com/problems/lexicographically-smallest-generated-string/
 * 
 * Approach:
 * 1. Fill all 'T' constraints. If conflict, return "".
 * 2. For each 'F' index, track the number of '?' (unknowns) and already mismatched characters in the window.
 * 3. Iterate left-to-right to fill '?' greedily with the smallest character ('a', 'b', etc.).
 * 4. A character at index i is forbidden by window j only if it's the last '?' and no other character in the window differs from str2.
 */

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int totalLen = n + m - 1;
        
        string res(totalLen, '?');
        
        // Step 1: Fill all 'T' requirements
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (res[i + j] != '?' && res[i + j] != str2[j]) {
                        return ""; // Conflict
                    }
                    res[i + j] = str2[j];
                }
            }
        }
        
        // Step 2: Track counts of '?' and mismatches for each window
        vector<int> unknownCount(n, 0);
        vector<int> mismatchCount(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (res[i+j] == '?') {
                    unknownCount[i]++;
                } else if (res[i+j] != str2[j]) {
                    mismatchCount[i]++;
                }
            }
            // If window already fully determined as 'F' but matches str2
            if (str1[i] == 'F' && unknownCount[i] == 0 && mismatchCount[i] == 0) {
                return "";
            }
        }
        
        // Step 3: Fill '?' greedily
        for (int i = 0; i < totalLen; i++) {
            if (res[i] != '?') continue;
            
            // Collect forbidden characters from all windows covering index i
            vector<bool> forbidden(26, false);
            for (int j = max(0, i - m + 1); j <= min(n - 1, i); j++) {
                if (str1[j] == 'F' && unknownCount[j] == 1 && mismatchCount[j] == 0) {
                    forbidden[str2[i - j] - 'a'] = true;
                }
            }
            
            // Pick smallest possible char
            char pickedChar = '?';
            for (int k = 0; k < 26; k++) {
                if (!forbidden[k]) {
                    pickedChar = (char)('a' + k);
                    break;
                }
            }
            
            if (pickedChar == '?') return ""; // All 26 letters forbidden
            
            res[i] = pickedChar;
            
            // Update counts for covered windows
            for (int j = max(0, i - m + 1); j <= min(n - 1, i); j++) {
                unknownCount[j]--;
                if (res[i] != str2[i - j]) {
                    mismatchCount[j]++;
                }
            }
        }
        
        // Final verification for 'F' windows (if needed, though logic should cover it)
        // Let's do a simple check.
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (res[i+j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) return "";
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    cout << "Example 1: " << sol.generateString("TFTF", "ab") << " (Expected: ababa)" << endl;
    cout << "Example 2: " << sol.generateString("TFTF", "abc") << " (Expected: )" << endl;
    cout << "Example 3: " << sol.generateString("F", "d") << " (Expected: a)" << endl;
    return 0;
}
