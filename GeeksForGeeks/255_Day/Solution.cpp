#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperation(int n) {
        // Step: 01 - Initialize operation counter
        int operations = 0;

        // Step: 02 - Greedily reduce n backwards to 0
        while (n > 0) {
            // Step: 03 - If n is even, divide by 2; else subtract 1
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n -= 1;
            }
            operations++;
        }

        // Step: 04 - Return the total count of operations
        return operations;
    }

    int minOperationBitwise(int n) {
        // Step: 01 - Handle base case
        if (n <= 0) return 0;

        // Step: 02 - Calculate bit length and number of set bits
        int setBits = 0;
        int bitLength = 0;
        int temp = n;

        while (temp > 0) {
            if (temp & 1) {
                setBits++;
            }
            bitLength++;
            temp >>= 1;
        }

        // Step: 03 - Formula: (bitLength - 1 divisions) + (setBits subtractions)
        return (bitLength - 1) + setBits;
    }

    int minOperationDP(int n) {
        // Step: 01 - Handle small values directly
        if (n <= 0) return 0;
        if (n == 1) return 1;

        // Step: 02 - Allocate DP table for bottom-up calculation
        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        // Step: 03 - Transition states from 2 up to n
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }

        // Step: 04 - Return optimal operations for n
        return dp[n];
    }

    int minOperations(int n) {
        // Step: 01 - Alias wrapper for compatibility
        return minOperation(n);
    }
};
