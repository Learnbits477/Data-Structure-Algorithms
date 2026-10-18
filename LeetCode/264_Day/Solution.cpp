#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static const int MOD = 1000000007;
    vector<vector<long long>> comb;

    long long dfs(const vector<int>& arr) {
        // Step: 01 - Base case: arrays of size <= 2 have exactly 1 valid configuration
        if (arr.size() <= 2) {
            return 1;
        }

        int root = arr[0];
        vector<int> left;
        vector<int> right;

        // Step: 02 - Partition remaining elements into left and right subtrees
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < root) {
                left.push_back(arr[i]);
            } else {
                right.push_back(arr[i]);
            }
        }

        // Step: 03 - Recursively solve for left and right subtrees
        long long leftWays = dfs(left);
        long long rightWays = dfs(right);

        int L = left.size();
        int R = right.size();

        // Step: 04 - Interleave left and right elements: C(L + R, L)
        long long totalWays = (comb[L + R][L] * leftWays) % MOD;
        totalWays = (totalWays * rightWays) % MOD;

        return totalWays;
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    long long nCrFermat(int n, int r, const vector<long long>& fact, const vector<long long>& invFact) {
        if (r < 0 || r > n) return 0;
        long long num = fact[n];
        long long den = (invFact[r] * invFact[n - r]) % MOD;
        return (num * den) % MOD;
    }

    long long dfsFermat(const vector<int>& arr, const vector<long long>& fact, const vector<long long>& invFact) {
        if (arr.size() <= 2) {
            return 1;
        }

        int root = arr[0];
        vector<int> left;
        vector<int> right;

        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < root) {
                left.push_back(arr[i]);
            } else {
                right.push_back(arr[i]);
            }
        }

        long long leftWays = dfsFermat(left, fact, invFact);
        long long rightWays = dfsFermat(right, fact, invFact);

        int L = left.size();
        int R = right.size();

        long long waysComb = nCrFermat(L + R, L, fact, invFact);
        long long totalWays = (waysComb * leftWays) % MOD;
        totalWays = (totalWays * rightWays) % MOD;

        return totalWays;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return 0;
        }

        // Step: 01 - Precompute Pascal's Triangle combination table
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        // Step: 02 - Compute total identical BST formations using divide and conquer
        long long total = dfs(nums);

        // Step: 03 - Exclude the original permutation and return modulo MOD
        return (int)((total - 1 + MOD) % MOD);
    }

    int numOfWaysFermat(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return 0;
        }

        // Step: 01 - Precompute factorials and inverse factorials using Fermat's Little Theorem
        vector<long long> fact(n + 1, 1);
        vector<long long> invFact(n + 1, 1);

        for (int i = 2; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        invFact[n] = modInverse(fact[n]);
        for (int i = n - 1; i >= 1; --i) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }

        // Step: 02 - Compute combinations via factorials
        long long total = dfsFermat(nums, fact, invFact);

        // Step: 03 - Exclude the original sequence
        return (int)((total - 1 + MOD) % MOD);
    }
};
