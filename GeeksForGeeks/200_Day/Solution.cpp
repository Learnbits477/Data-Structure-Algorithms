#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWithout(int n, int d) {
        // Step 1: Handle non-positive edge cases
        if (n <= 0) return 0;

        // Step 2: Convert n to string and precompute powers of 9
        string S = to_string(n);
        int L = S.length();

        vector<int> pow9(11, 1);
        for (int i = 1; i <= 10; ++i) {
            pow9[i] = pow9[i - 1] * 9;
        }

        int count = 0;

        // Step 3: Count valid numbers with length k < L
        for (int k = 1; k < L; ++k) {
            if (d == 0) {
                count += pow9[k];
            } else {
                count += 8 * pow9[k - 1];
            }
        }

        // Step 4: Count valid numbers of length L that are <= n
        bool match = true;
        for (int i = 0; i < L; ++i) {
            int digit = S[i] - '0';

            int c = 0;
            if (i == 0) {
                // Range [1, digit - 1]
                if (digit > 1) {
                    c = digit - 1;
                    if (d >= 1 && d <= digit - 1) {
                        c--;
                    }
                }
            } else {
                // Range [0, digit - 1]
                if (digit > 0) {
                    c = digit;
                    if (d >= 0 && d <= digit - 1) {
                        c--;
                    }
                }
            }

            int rem = L - 1 - i;
            count += c * pow9[rem];

            if (digit == d) {
                match = false;
                break;
            }
        }

        // Step 5: Include exact match if n itself contains no digit d
        if (match) {
            count += 1;
        }

        return count;
    }

    // Aliases for GFG driver signature compatibility
    int countNoD(int n, int d) {
        return countWithout(n, d);
    }

    int count(int n, int d) {
        return countWithout(n, d);
    }

    int numberCount(int n, int d) {
        return countWithout(n, d);
    }

    int countNumbers(int n, int d) {
        return countWithout(n, d);
    }
};
