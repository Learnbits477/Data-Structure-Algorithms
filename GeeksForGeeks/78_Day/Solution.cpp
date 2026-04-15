#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string URLify(string s) {
        string res;

        // Pre-allocate worst-case memory (all spaces → 3x original size)
        res.reserve(s.size() * 3);

        for (char c : s) {
            if (c == ' ')
                res += "%20";
            else
                res += c;
        }

        return res;
    }
};