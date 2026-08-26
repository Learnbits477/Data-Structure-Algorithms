#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // Step 1: Collect all indices where s[i] == '1'
        vector<int> ones;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }

        // Step 2: If total 1's is less than k, return empty string
        if ((int)ones.size() < k) {
            return "";
        }

        // Step 3: Find the shortest and lexicographically smallest beautiful substring
        string result = "";
        for (int i = 0; i + k - 1 < (int)ones.size(); ++i) {
            int left = ones[i];
            int right = ones[i + k - 1];
            string sub = s.substr(left, right - left + 1);

            if (result.empty() || sub.length() < result.length() || 
               (sub.length() == result.length() && sub < result)) {
                result = sub;
            }
        }

        // Step 4: Return optimal beautiful substring
        return result;
    }
};
