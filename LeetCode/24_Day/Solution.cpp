#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, start = 0;
        vector<string> parts;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            // Whenever count hits 0, we've found a top-level special substring
            if (count == 0) {
                // Recursively make the inner part (strip leading '1' and trailing '0')
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                parts.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // Sort in descending order so lexicographically larger parts come first
        sort(parts.begin(), parts.end(), greater<string>());

        string result = "";
        for (auto& p : parts) result += p;
        return result;
    }
};

// ── Test Driver ──────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Example 1
    string s1 = "11011000";
    cout << "Input:  " << s1 << "\n";
    cout << "Output: " << sol.makeLargestSpecial(s1) << "\n"; // Expected: 11100100
    cout << "\n";

    // Example 2
    string s2 = "10";
    cout << "Input:  " << s2 << "\n";
    cout << "Output: " << sol.makeLargestSpecial(s2) << "\n"; // Expected: 10
    cout << "\n";

    // Additional test: already largest
    string s3 = "1111000010100100";
    cout << "Input:  " << s3 << "\n";
    cout << "Output: " << sol.makeLargestSpecial(s3) << "\n";

    return 0;
}
