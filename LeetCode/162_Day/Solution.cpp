#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        int MOD = 1e9 + 7;
        
        // Step 1 — Non-Zero Digits and Indices Filtering
        vector<int> D;
        D.reserve(m);
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                D.push_back(s[i] - '0');
            }
        }
        
        int n_D = D.size();
        
        // Step 2 — Prefix Sum and Hash Precomputation
        vector<long long> P(n_D + 1, 0);
        vector<long long> H(n_D + 1, 0);
        vector<long long> pow10(n_D + 1, 1);
        
        for (int i = 0; i < n_D; ++i) {
            P[i + 1] = P[i] + D[i];
            H[i + 1] = (H[i] * 10 + D[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }
        
        // Step 3 — Query Range Mapping
        vector<int> first_non_zero_idx(m, n_D);
        int current_idx = n_D;
        for (int i = m - 1; i >= 0; --i) {
            if (s[i] != '0') {
                current_idx--;
            }
            first_non_zero_idx[i] = current_idx;
        }
        
        vector<int> last_non_zero_idx(m, -1);
        current_idx = -1;
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                current_idx++;
            }
            last_non_zero_idx[i] = current_idx;
        }
        
        // Step 4 — Constant-Time Query Evaluation
        vector<int> answers;
        answers.reserve(queries.size());
        
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            
            int p = first_non_zero_idx[l];
            int q = last_non_zero_idx[r];
            
            if (p > q) {
                answers.push_back(0);
            } else {
                long long x = (H[q + 1] - H[p] * pow10[q - p + 1]) % MOD;
                if (x < 0) {
                    x += MOD;
                }
                long long sum_digits = P[q + 1] - P[p];
                long long ans = (x * (sum_digits % MOD)) % MOD;
                answers.push_back(ans);
            }
        }
        
        return answers;
    }
};
