#include <iostream>

class Solution {
  public:
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
