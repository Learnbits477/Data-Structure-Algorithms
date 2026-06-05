#include <bits/stdc++.h>
using namespace std;

class Solution {
    pair<long long, long long> memo[20][2][2][11][11];
    string s;

    // Step 3: Recursive Subproblem (Waviness Calculation)
    pair<long long, long long> dfs(int idx, bool tight, bool leading_zero, int prev, int prev_prev) {
        // Base case: Reached the end of the number
        if (idx == s.length()) return {1, 0};
        
        // Step 5: Memoization Check
        if (memo[idx][tight][leading_zero][prev][prev_prev].first != -1) {
            return memo[idx][tight][leading_zero][prev][prev_prev];
        }
        
        int limit = tight ? s[idx] - '0' : 9;
        long long total_count = 0;
        long long total_wav = 0;
        
        for (int d = 0; d <= limit; d++) {
            bool new_lz = leading_zero && (d == 0);
            int new_prev = new_lz ? 10 : d;
            int new_prev_prev = new_lz ? 10 : prev;
            
            long long added = 0;
            // Determine if the newly formed triplet constitutes a peak or a valley
            if (!leading_zero && prev != 10 && prev_prev != 10) {
                if ((prev_prev < prev && prev > d) || (prev_prev > prev && prev < d)) {
                    added = 1;
                }
            }
            
            auto res = dfs(idx + 1, tight && (d == limit), new_lz, new_prev, new_prev_prev);
            
            // Step 4: Combinatorial Accumulation
            total_count += res.first;
            total_wav += res.second + added * res.first;
        }
        
        return memo[idx][tight][leading_zero][prev][prev_prev] = {total_count, total_wav};
    }

    // Step 1: Digit DP Framework
    long long solve(long long num) {
        if (num < 100) return 0; // Numbers < 100 have 0 waviness
        
        s = to_string(num);
        
        // Initialize 5D memoization table for the current limit
        for(int i = 0; i < s.length(); ++i)
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 2; ++k)
                    for(int l = 0; l < 11; ++l)
                        for(int m = 0; m < 11; ++m)
                            memo[i][j][k][l][m] = {-1, -1};
        
        // Step 2: State Initialization
        return dfs(0, true, true, 10, 10).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
