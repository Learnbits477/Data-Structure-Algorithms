#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int canFormPalindrome(string s) {
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] & 1) odd++;
        }
        return odd <= 1;
    }
};
