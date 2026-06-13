#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int computeValue(int n) {
        long long fact_2n = 1;
        long long fact_n = 1;

        for (int i = 1; i <= 2 * n; i++) {
            fact_2n = (fact_2n * i) % MOD;
            if (i == n) {
                fact_n = fact_2n;
            }
        }

        long long denom = (fact_n * fact_n) % MOD;
        long long denom_inv = modInverse(denom);

        long long ans = (fact_2n * denom_inv) % MOD;

        return ans;
    }
};
