#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    int gcdOfOddEvenSums(int n) {
        // Step 1: Simplify Mathematically
        // Establishing sumOdd = n^2 and sumEven = n(n + 1)
        long long sumOdd = (long long)n * n;
        long long sumEven = (long long)n * (n + 1);

        // Step 2: Apply Coprimality
        // Consecutive integers n and n+1 are coprime, meaning GCD(n, n+1) = 1.
        // Therefore, GCD(n^2, n(n+1)) = n * GCD(n, n+1) = n.
        // We compute standard GCD to explicitly verify the mathematical relation.
        long long gcdVal = gcd(sumOdd, sumEven);

        // Step 3: Return Result
        return gcdVal;
    }
};
