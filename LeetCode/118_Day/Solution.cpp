#include <iostream>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        // If the destination is blocked, it's impossible to reach.
        if (s[n - 1] == '1') {
            return false;
        }

        // Step 1: Initialize DP Array
        // dp[i] will store whether index i is reachable from index 0.
        vector<bool> dp(n, false);
        dp[0] = true;

        // Step 2: Traverse using a Sliding Window
        // reachableCount tracks the number of reachable indices in the current window [i - maxJump, i - minJump].
        int reachableCount = 0;
        for (int i = 1; i < n; i++) {
            // Add the newly entering index to the window
            if (i - minJump >= 0 && dp[i - minJump]) {
                reachableCount++;
            }
            // Remove the index that is sliding out of the window
            if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) {
                reachableCount--;
            }

            // Step 3: Check Reachability
            // If we have at least one reachable index in the window and s[i] is '0', then i is reachable.
            if (reachableCount > 0 && s[i] == '0') {
                dp[i] = true;
            }
        }

        // Step 4: Return Destination State
        return dp[n - 1];
    }
};
