#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool areIsomorphic(string s1, string s2) {
        if (s1.length() != s2.length()) return false;

        unordered_map<char, char> s1ToS2, s2ToS1;

        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1[i], c2 = s2[i];

            if (s1ToS2.count(c1)) {
                if (s1ToS2[c1] != c2) return false;
            } else {
                s1ToS2[c1] = c2;
            }

            if (s2ToS1.count(c2)) {
                if (s2ToS1[c2] != c1) return false;
            } else {
                s2ToS1[c2] = c1;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;

    // Test case 1: expected true
    cout << "aab, xxy -> " << (obj.areIsomorphic("aab", "xxy") ? "true" : "false") << endl;

    // Test case 2: expected false
    cout << "aab, xyz -> " << (obj.areIsomorphic("aab", "xyz") ? "true" : "false") << endl;

    // Test case 3: expected false
    cout << "abc, xxz -> " << (obj.areIsomorphic("abc", "xxz") ? "true" : "false") << endl;

    return 0;
}
