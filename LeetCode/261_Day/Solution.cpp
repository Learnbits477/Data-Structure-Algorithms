#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int noConseBits(int n) {
        // Step: 01 - Iterate from highest 32-bit position down to bit index 2
        for (int i = 31; i >= 2; --i) {
            // Step: 02 - Check if current bit and two adjacent lower bits are set
            bool bitI = (n & (1U << i)) != 0;
            bool bitI1 = (n & (1U << (i - 1))) != 0;
            bool bitI2 = (n & (1U << (i - 2))) != 0;

            // Step: 03 - Unset the lowest bit of the triplet to minimize loss
            if (bitI && bitI1 && bitI2) {
                n &= ~(1U << (i - 2));
            }
        }

        // Step: 04 - Return final integer with no 3 consecutive set bits
        return n;
    }

    int noConseBitsCounter(int n) {
        // Step: 01 - Track count of consecutive set bits from MSB to LSB
        int consecutiveOnes = 0;

        // Step: 02 - Process bits individually from position 31 down to 0
        for (int i = 31; i >= 0; --i) {
            if ((n & (1U << i)) != 0) {
                consecutiveOnes++;
                // Step: 03 - If third consecutive 1 is reached, unset it and reset count
                if (consecutiveOnes == 3) {
                    n &= ~(1U << i);
                    consecutiveOnes = 0;
                }
            } else {
                consecutiveOnes = 0;
            }
        }

        // Step: 04 - Return resolved integer
        return n;
    }

    int noConseBitsArray(int n) {
        // Step: 01 - Extract 32 bits into an array
        vector<int> bits(32, 0);
        for (int i = 0; i < 32; ++i) {
            if ((n & (1U << i)) != 0) {
                bits[i] = 1;
            }
        }

        // Step: 02 - Detect triplets from MSB to LSB and unset the rightmost bit
        for (int i = 31; i >= 2; --i) {
            if (bits[i] == 1 && bits[i - 1] == 1 && bits[i - 2] == 1) {
                bits[i - 2] = 0;
            }
        }

        // Step: 03 - Reconstruct integer value from modified bits
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            if (bits[i] == 1) {
                result |= (1U << i);
            }
        }

        return result;
    }

    // Aliases to support varying platform naming conventions
    int maxValue(int n) {
        return noConseBits(n);
    }

    int no_consecutive_ones(int n) {
        return noConseBits(n);
    }
};
