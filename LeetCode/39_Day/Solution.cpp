#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        
        int diff1 = 0, diff2 = 0;
        int ans = INT_MAX;
        
        for (int i = 0; i < 2 * n; ++i) {
            char current_char = s[i % n];
            char alt1 = (i % 2 == 0) ? '1' : '0';
            char alt2 = (i % 2 == 0) ? '0' : '1';
            
            if (current_char != alt1) ++diff1;
            if (current_char != alt2) ++diff2;
            
            // If window size exceeds n, remove the leftmost element from counts
            if (i >= n) {
                char old_char = s[(i - n) % n];
                char old_alt1 = ((i - n) % 2 == 0) ? '1' : '0';
                char old_alt2 = ((i - n) % 2 == 0) ? '0' : '1';
                
                if (old_char != old_alt1) --diff1;
                if (old_char != old_alt2) --diff2;
            }
            
            // Once the window size is exactly n, we can record the minimum flips
            if (i >= n - 1) {
                ans = min({ans, diff1, diff2});
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string s1 = "111000";
    cout << "Input: s = \"111000\"" << endl;
    cout << "Output: " << sol.minFlips(s1) << endl; // Expected: 2
    
    // Example 2
    string s2 = "010";
    cout << "\nInput: s = \"010\"" << endl;
    cout << "Output: " << sol.minFlips(s2) << endl; // Expected: 0
    
    // Example 3
    string s3 = "1110";
    cout << "\nInput: s = \"1110\"" << endl;
    cout << "Output: " << sol.minFlips(s3) << endl; // Expected: 1
    
    return 0;
}
