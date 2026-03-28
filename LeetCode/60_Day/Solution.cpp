#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '\0');
        char next_char = 'a';

        for (int i = 0; i < n; ++i) {
            if (s[i] == '\0') {
                if (next_char > 'z') return "";
                for (int j = i; j < n; ++j) {
                    if (lcp[i][j] > 0) s[j] = next_char;
                }
                next_char++;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] == '\0') return "";
        }

        vector<vector<int>> computed_lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == s[j]) {
                    computed_lcp[i][j] = 1 + computed_lcp[i + 1][j + 1];
                } else {
                    computed_lcp[i][j] = 0;
                }
                if (computed_lcp[i][j] != lcp[i][j]) return "";
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> lcp = {{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}};
    cout << "Result: " << sol.findTheString(lcp) << endl;
    return 0;
}
