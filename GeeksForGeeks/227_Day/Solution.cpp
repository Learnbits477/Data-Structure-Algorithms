#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    // Step 1 & 2: Calculate GCD of differences and count all its positive divisors
    int sameMod(vector<int> &arr) {
        int n = arr.size();
        if (n <= 1) {
            return -1; // Single element leaves same remainder for all positive k
        }

        // Step 1: Calculate the overall GCD of absolute differences relative to arr[0]
        int g = 0;
        for (int i = 1; i < n; i++) {
            g = gcd(g, abs(arr[i] - arr[0]));
        }

        // Step 2: If all elements are equal, differences are 0, so infinitely many k exist
        if (g == 0) {
            return -1;
        }

        // Step 3: Count total positive divisors of g in O(sqrt(g))
        int count = 0;
        for (int d = 1; 1LL * d * d <= g; d++) {
            if (g % d == 0) {
                if (d * d == g) {
                    count += 1;
                } else {
                    count += 2;
                }
            }
        }

        return count;
    }

    // Aliases for compatibility across multiple problem naming conventions
    int countK(vector<int> &arr) {
        return sameMod(arr);
    }

    int equalRemainders(vector<int> &arr) {
        return sameMod(arr);
    }

    int kModulus(vector<int> &arr) {
        return sameMod(arr);
    }
};
