#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Quick parity exit: odd length strings cannot be valid
        if (s.length() % 2 != 0) {
            return false;
        }

        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } else {
                // If stack is empty or doesn't match current closer
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }

    /**
     * @brief High-performance zero-allocation variant using a vector/array stack.
     */
    bool isValidFast(string s) {
        if (s.length() % 2 != 0) return false;

        vector<char> st;
        st.reserve(s.length());

        for (char c : s) {
            switch (c) {
                case '(': st.push_back(')'); break;
                case '{': st.push_back('}'); break;
                case '[': st.push_back(']'); break;
                default:
                    if (st.empty() || st.back() != c) return false;
                    st.pop_back();
                    break;
            }
        }

        return st.empty();
    }

    /**
     * @brief Classic variant with opener stack and closer lookup.
     */
    bool isValidClassic(string s) {
        if (s.length() % 2 != 0) return false;

        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
