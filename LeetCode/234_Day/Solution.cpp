#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Step: 01 - Record first and last occurrence for each character in the string
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) {
                first[c] = i;
            }
            last[c] = i;
        }

        // Step: 02 - Determine valid candidate intervals starting from each character's first index
        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int L = first[i];
            int R = last[i];
            bool isValid = true;

            // Expand interval [L, R] to cover all occurrences of any enclosed characters
            for (int j = L; j <= R; ++j) {
                int c = s[j] - 'a';
                // If an included character appears before L, L cannot be the start of a valid minimal substring
                if (first[c] < L) {
                    isValid = false;
                    break;
                }
                R = max(R, last[c]);
            }

            if (isValid) {
                intervals.push_back({L, R});
            }
        }

        // Step: 03 - Sort candidate intervals by finish position R in ascending order.
        // For intervals ending at the same R, prioritize larger L (shorter length first).
        sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first > b.first;
        });

        // Step: 04 - Greedily select non-overlapping intervals (Activity Selection Problem)
        vector<string> result;
        int lastEnd = -1;

        for (const auto &interval : intervals) {
            int L = interval.first;
            int R = interval.second;

            if (L > lastEnd) {
                result.push_back(s.substr(L, R - L + 1));
                lastEnd = R;
            }
        }

        return result;
    }
};
