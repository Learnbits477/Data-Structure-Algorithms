#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int longestSubstr(string& s, int k) {
        int n = s.length();
        vector<int> count(26, 0);
        int max_count = 0;
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < n; right++) {
            // Increment the count of the character at the right pointer
            count[s[right] - 'A']++;
            
            // Update the maximum count of any single character in the current window
            max_count = max(max_count, count[s[right] - 'A']);
            
            // If the remaining characters in the window exceed k, shrink the window
            if (right - left + 1 - max_count > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            // Update the maximum window length encountered so far
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};
