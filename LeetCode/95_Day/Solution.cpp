#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGood(i)) {
                count++;
            }
        }
        return count;
    }

  private:
    bool isGood(int num) {
        bool hasDiff = false;
        while (num > 0) {
            int digit = num % 10;
            // Invalid digits: 3, 4, 7
            if (digit == 3 || digit == 4 || digit == 7) {
                return false;
            }
            // Digits that change after rotation: 2, 5, 6, 9
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                hasDiff = true;
            }
            num /= 10;
        }
        return hasDiff;
    }
};
