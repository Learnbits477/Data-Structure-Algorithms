#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * @class Solution
 * @brief Provides a solution to the Minimum Distance to Type a Word Using Two Fingers problem.
 * 
 * Space-Optimized DP Approach:
 * - Time Complexity: O(N * 26) where N is the length of the word.
 * - Space Complexity: O(26) for the DP table.
 */
class Solution {
public:
    /**
     * @brief Calculates the Manhattan distance between two letters on the specified keyboard.
     * @param a Character code (0-25) for first letter, or 26 for 'Finger not placed'.
     * @param b Character code (0-25) for second letter.
     * @return Minimum distance.
     */
    int getDist(int a, int b) {
        if (a == 26) return 0; // Initial placement is free
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }

    int minimumDistance(string word) {
        int n = word.length();
        if (n <= 2) return 0;

        // dp[j] = min cost to type prefix word[0..i] with:
        // One finger at word[i]
        // Other finger at character j (0-25) or 26 (unplaced)
        vector<int> dp(27, 1e9);
        
        // Base case: First character typed for free
        // Finger 1 is at word[0], Finger 2 is at 26 (unplaced)
        dp[26] = 0;

        for (int i = 0; i < n - 1; ++i) {
            vector<int> next_dp(27, 1e9);
            int curr = word[i] - 'A';
            int target = word[i + 1] - 'A';

            for (int j = 0; j <= 26; ++j) {
                if (dp[j] == 1e9) continue;

                // Option 1: Move finger currently at word[i] to word[i+1]
                // Other finger remains at j
                next_dp[j] = min(next_dp[j], dp[j] + getDist(curr, target));

                // Option 2: Move finger currently at j to word[i+1]
                // Other finger remains at word[i]
                next_dp[curr] = min(next_dp[curr], dp[j] + getDist(j, target));
            }
            dp = move(next_dp);
        }

        int result = 1e9;
        for (int val : dp) result = min(result, val);
        return result;
    }
};
