// LeetCode 762. Prime Number of Set Bits in Binary Representation
// Difficulty: Easy | Bit Manipulation, Math

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Primes <= 20: {2,3,5,7,11,13,17,19}
        // Encode them in a bitmask for O(1) primality check
        int primeMask = (1<<2)|(1<<3)|(1<<5)|(1<<7)|(1<<11)|(1<<13)|(1<<17)|(1<<19);
        
        int count = 0;
        for (int num = left; num <= right; num++) {
            int bits = __builtin_popcount(num);
            if ((primeMask >> bits) & 1) {
                count++;
            }
        }
        return count;
    }
};

// ─── Test Driver ───────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Example 1
    cout << "Example 1: " << sol.countPrimeSetBits(6, 10) << endl;  // Expected: 4

    // Example 2
    cout << "Example 2: " << sol.countPrimeSetBits(10, 15) << endl; // Expected: 5

    // Edge cases
    cout << "Edge (1,1): " << sol.countPrimeSetBits(1, 1) << endl;   // 1 -> 1 set bit, not prime -> 0
    cout << "Edge (2,2): " << sol.countPrimeSetBits(2, 2) << endl;   // 2 -> 1 set bit, not prime -> 0
    cout << "Edge (3,3): " << sol.countPrimeSetBits(3, 3) << endl;   // 3 -> 2 set bits, prime -> 1

    return 0;
}
