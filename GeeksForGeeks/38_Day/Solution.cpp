#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // Alias to handle different platform requirements
    string smallestWindow(string s, string p) {
        return minWindow(s, p);
    }

    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string minWindow(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();
        
        if (len_s < len_p) {
            return "";
        }

        vector<int> hash_p(256, 0);
        vector<int> hash_s(256, 0);

        for (int i = 0; i < len_p; i++) {
            hash_p[p[i]]++;
        }

        int start = 0, start_index = -1, min_len = INT_MAX;
        int count = 0;

        for (int j = 0; j < len_s; j++) {
            hash_s[s[j]]++;

            // If string's current char matches with pattern's char count
            if (hash_p[s[j]] != 0 && hash_s[s[j]] <= hash_p[s[j]]) {
                count++;
            }

            // If all characters are matched
            if (count == len_p) {
                // Try to minimize the window
                while (hash_s[s[start]] > hash_p[s[start]] || hash_p[s[start]] == 0) {
                    if (hash_s[s[start]] > hash_p[s[start]]) {
                        hash_s[s[start]]--;
                    }
                    start++;
                }

                // Update minimum window length
                int len_window = j - start + 1;
                if (min_len > len_window) {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }

        if (start_index == -1) {
            return "";
        }

        return s.substr(start_index, min_len);
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string s1 = "timetopractice";
    string p1 = "toc";
    cout << "Input: s = \"" << s1 << "\", p = \"" << p1 << "\"\n";
    cout << "Output: \"" << sol.smallestWindow(s1, p1) << "\"\n\n";

    // Example 2
    string s2 = "zoomlazapzo";
    string p2 = "oza";
    cout << "Input: s = \"" << s2 << "\", p = \"" << p2 << "\"\n";
    cout << "Output: \"" << sol.smallestWindow(s2, p2) << "\"\n\n";

    // Example 3
    string s3 = "zoom";
    string p3 = "zooe";
    cout << "Input: s = \"" << s3 << "\", p = \"" << p3 << "\"\n";
    cout << "Output: \"" << sol.smallestWindow(s3, p3) << "\"\n";

    return 0;
}
