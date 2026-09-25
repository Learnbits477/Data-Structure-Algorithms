#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Parses an expression: Expr -> Term (',' Term)*
    // Evaluates the union of all comma-separated terms
    vector<string> parseExpr(const string& s, int& pos) {
        set<string> resultSet;

        while (pos < static_cast<int>(s.length())) {
            // Parse the next concatenated term
            vector<string> term = parseTerm(s, pos);
            for (const string& word : term) {
                resultSet.insert(word);
            }

            // If a comma follows, consume it to continue the union
            if (pos < static_cast<int>(s.length()) && s[pos] == ',') {
                pos++; // Consume ','
            } else {
                break; // End of Expr (either '}' or end-of-string)
            }
        }

        return vector<string>(resultSet.begin(), resultSet.end());
    }

    // Parses a term: Term -> Factor+
    // Evaluates Cartesian product (concatenation) of adjacent factors
    vector<string> parseTerm(const string& s, int& pos) {
        // Neutral identity element for string Cartesian product is {""}
        vector<string> current = {""};

        while (pos < static_cast<int>(s.length()) && (isalpha(s[pos]) || s[pos] == '{')) {
            vector<string> factor = parseFactor(s, pos);

            // Compute Cartesian product between current and next factor
            set<string> nextSet;
            for (const string& prefix : current) {
                for (const string& suffix : factor) {
                    nextSet.insert(prefix + suffix);
                }
            }

            current.assign(nextSet.begin(), nextSet.end());
        }

        return current;
    }

    // Parses a factor: Factor -> Word | '{' Expr '}'
    vector<string> parseFactor(const string& s, int& pos) {
        if (s[pos] == '{') {
            pos++; // Consume opening '{'
            vector<string> subExpr = parseExpr(s, pos);
            if (pos < static_cast<int>(s.length()) && s[pos] == '}') {
                pos++; // Consume closing '}'
            }
            return subExpr;
        } else {
            // Extract continuous run of lowercase alphabetic characters
            string word = "";
            while (pos < static_cast<int>(s.length()) && isalpha(s[pos])) {
                word += s[pos++];
            }
            return {word};
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;
        vector<string> result = parseExpr(expression, pos);
        // std::set naturally keeps elements sorted and unique
        sort(result.begin(), result.end());
        return result;
    }

    // Platform alias methods
    vector<string> expand(string expression) {
        return braceExpansionII(expression);
    }
};
