#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> count(26, 0);
            int maxFreq = 0;
            int distinctCount = 0;
            
            for (int j = i; j < n; ++j) {
                int charIdx = s[j] - 'a';
                if (count[charIdx] == 0) {
                    distinctCount++;
                }
                count[charIdx]++;
                maxFreq = max(maxFreq, count[charIdx]);
                
                int currentLen = j - i + 1;
                if (distinctCount * maxFreq == currentLen) {
                    maxLen = max(maxLen, currentLen);
                }
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string s1 = "abbac";
    cout << "Test 1: " << sol.longestBalanced(s1) << " Expected: 4" << endl;
    
    // Example 2
    string s2 = "zzabccy";
    cout << "Test 2: " << sol.longestBalanced(s2) << " Expected: 4" << endl;
    
    // Example 3
    string s3 = "aba";
    cout << "Test 3: " << sol.longestBalanced(s3) << " Expected: 2" << endl;
    
    return 0;
}
