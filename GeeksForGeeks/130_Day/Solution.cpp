#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numOfWays(int n, int m) {
        // Step 1: Calculate Total Squares
        long long totalSquares = (long long)n * m;
        
        // Step 2: Calculate Total Placements
        long long totalWays = totalSquares * (totalSquares - 1);
        
        // Step 3: Calculate Attacking Configurations
        long long attackingWays = 0;
        
        // Horizontal L-shapes (2 rows, 3 cols)
        if (n >= 2 && m >= 3) {
            attackingWays += 4LL * (n - 1) * (m - 2);
        }
        
        // Vertical L-shapes (3 rows, 2 cols)
        if (n >= 3 && m >= 2) {
            attackingWays += 4LL * (n - 2) * (m - 1);
        }
        
        // Step 4: Compute Valid Ways
        long long validWays = totalWays - attackingWays;
        
        return validWays;
    }
};
