#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Core function to evaluate bracket pairs in string s using knowledge table
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Step 1: Pre-populate hash table with key-value mappings
        unordered_map<string, string> dict;
        dict.reserve(knowledge.size());
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }

        // Step 2: Single-pass scan through s
        string result = "";
        result.reserve(s.length());

        string key = "";
        bool insideBracket = false;

        for (char c : s) {
            if (c == '(') {
                insideBracket = true;
                key.clear();
            } else if (c == ')') {
                insideBracket = false;
                auto it = dict.find(key);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
            } else {
                if (insideBracket) {
                    key += c;
                } else {
                    result += c;
                }
            }
        }

        return result;
    }

    // Platform alias methods
    string evaluateBracketPairs(string s, vector<vector<string>>& knowledge) {
        return evaluate(s, knowledge);
    }
};
