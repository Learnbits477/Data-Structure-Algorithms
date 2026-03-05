#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        vector<int> count(26, 0);
        int l = 0, r = 0;
        int max_len = -1;
        int unique_count = 0;
        
        while (r < s.length()) {
            if (count[s[r] - 'a'] == 0) {
                unique_count++;
            }
            count[s[r] - 'a']++;
            
            while (unique_count > k) {
                count[s[l] - 'a']--;
                if (count[s[l] - 'a'] == 0) {
                    unique_count--;
                }
                l++;
            }
            
            if (unique_count == k) {
                max_len = max(max_len, r - l + 1);
            }
            
            r++;
        }
        
        return max_len;
    }
};

int main() {
    // Hardcoded test case for local testing
    // (Only the Solution class is needed for GeeksforGeeks submission)
    Solution ob;
    
    string s1 = "aabacbebebe";
    int k1 = 3;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output: " << ob.longestKSubstr(s1, k1) << endl << endl;

    string s2 = "aaaa";
    int k2 = 2;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output: " << ob.longestKSubstr(s2, k2) << endl;

    return 0;
}
