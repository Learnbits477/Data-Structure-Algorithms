#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to calculate the sum of digits of a given number
    int getDigitSum(int val) {
        int sum = 0;
        while (val > 0) {
            sum += val % 10;
            val /= 10;
        }
        return sum;
    }

public:
    // Step 1: Find the number in [1, n] with maximum digit sum (largest number in case of ties)
    int findMax(int n) {
        // Baseline: evaluate n itself
        int bestNum = n;
        int maxSum = getDigitSum(n);

        string s = to_string(n);
        int m = s.length();

        // Step 2: Greedily evaluate candidates formed by decrementing digit at position i
        // and setting all trailing digits (i+1 to m-1) to '9'
        for (int i = 0; i < m; i++) {
            if (s[i] == '0') continue; // Cannot decrement '0' without borrowing

            string candStr = s;
            candStr[i] = candStr[i] - 1;
            for (int j = i + 1; j < m; j++) {
                candStr[j] = '9';
            }

            int candVal = stoi(candStr);
            int curSum = getDigitSum(candVal);

            // Step 3: Update best number based on higher sum or larger value upon tie
            if (curSum > maxSum) {
                maxSum = curSum;
                bestNum = candVal;
            } else if (curSum == maxSum) {
                bestNum = max(bestNum, candVal);
            }
        }

        return bestNum;
    }

    // Aliases for compatibility
    int maxDigitSum(int n) {
        return findMax(n);
    }

    int findMaxDigitSum(int n) {
        return findMax(n);
    }
};
