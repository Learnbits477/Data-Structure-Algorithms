#include <bits/stdc++.h>
using namespace std;

class Solution {
    int MOD = 1e9 + 7;
    
    // Matrix multiplication
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int sz = A.size();
        vector<vector<long long>> C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i) {
            for (int k = 0; k < sz; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < sz; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    
    // Vector multiplication: A * X
    vector<long long> multiply(const vector<vector<long long>>& A, const vector<long long>& X) {
        int sz = A.size();
        vector<long long> Y(sz, 0);
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                Y[i] = (Y[i] + A[i][j] * X[j]) % MOD;
            }
        }
        return Y;
    }
    
    // Matrix power: A^p
    vector<vector<long long>> power(vector<vector<long long>> A, long long p) {
        int sz = A.size();
        vector<vector<long long>> res(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i) res[i][i] = 1;
        while (p > 0) {
            if (p & 1) res = multiply(res, A);
            A = multiply(A, A);
            p >>= 1;
        }
        return res;
    }

public:
    int numOfArrays(int n, int l, int r) {
        // Step 1: Set up the State Vector
        int m = r - l + 1;
        if (m <= 1) return 0;
        
        int sz = 2 * m;
        
        // Step 2: Base Case (Length 2)
        vector<long long> X2(sz, 0);
        for (int v = 0; v < m; ++v) {
            X2[v] = v;
            X2[m + v] = m - 1 - v;
        }
        
        if (n == 2) {
            long long ans = 0;
            for (int i = 0; i < sz; ++i) ans = (ans + X2[i]) % MOD;
            return ans;
        }
        
        // Step 3: Build the Transition Matrix T
        vector<vector<long long>> T(sz, vector<long long>(sz, 0));
        for (int v = 0; v < m; ++v) {
            for (int u = 0; u < v; ++u) {
                T[v][m + u] = 1;
            }
            for (int u = v + 1; u < m; ++u) {
                T[m + v][u] = 1;
            }
        }
        
        // Step 4: Compute Matrix Power and Multiplication
        vector<vector<long long>> T_pow = power(T, n - 2);
        vector<long long> Xn = multiply(T_pow, X2);
        
        long long ans = 0;
        for (int i = 0; i < sz; ++i) {
            ans = (ans + Xn[i]) % MOD;
        }
        return ans;
    }
};
