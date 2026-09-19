#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to compute LCS length in O(min(|s1|, |s2|)) auxiliary space
    int computeLCS(const string &s1, const string &s2) {
        int n = s1.size();
        int m = s2.size();

        // Ensure m <= n to minimize row buffer size
        if (n < m) {
            return computeLCS(s2, s1);
        }

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }

public:
    int findMinCost(string s1, string s2, int costS1, int costS2) {
        // Step: 01 - Find length of Longest Common Subsequence
        int lcsLength = computeLCS(s1, s2);

        // Step: 02 - Determine number of characters deleted from each string
        int delS1 = static_cast<int>(s1.size()) - lcsLength;
        int delS2 = static_cast<int>(s2.size()) - lcsLength;

        // Step: 03 - Calculate total deletion cost
        return (delS1 * costS1) + (delS2 * costS2);
    }
};
