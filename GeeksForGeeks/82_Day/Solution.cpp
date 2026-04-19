#include <iostream>

class Solution {
  public:
    /**
     * @brief Checks if y is a power of x.
     * 
     * Logic:
     * 1. Any number to the power of 0 is 1. So if y == 1, return true.
     * 2. If x == 1, then x^n is always 1. Since y != 1 (from step 1), it's false.
     * 3. Repeatedly divide y by x while y is divisible by x.
     * 4. If y reaches 1, then it is a power of x.
     * 
     * @param x The base number.
     * @param y The number to check.
     * @return true If y is a power of x.
     * @return false Otherwise.
     */
    int isPower(int x, int y) {
        // Base case: x^0 = 1
        if (y == 1) {
            return 1;
        }

        // Base case: 1^n = 1. If y is not 1, it's not a power of 1.
        if (x == 1) {
            return 0;
        }

        // Keep dividing y by x as long as y is divisible
        while (y > 1 && y % x == 0) {
            y /= x;
        }

        // If we reach 1, then y was a power of x
        return (y == 1);
    }
};
