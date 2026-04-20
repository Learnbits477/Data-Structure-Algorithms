#include <iostream>
#include <vector>

class Solution {
public:
    int derangeCount(int n) {
        // Base cases
        if (n == 1) return 0;
        if (n == 2) return 1;

        // Iterative DP variables to maintain O(1) space
        long long prev2 = 0; // Represents D(n-2)
        long long prev1 = 1; // Represents D(n-1)
        long long current = 0;

        for (int i = 3; i <= n; i++) {
            // Apply the recurrence relation
            current = (long long)(i - 1) * (prev1 + prev2);
            
            // Move pointers forward
            prev2 = prev1;
            prev1 = current;
        }

        return (int)current;
    }
};
