#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();

        // Step 1 — Build Element-to-Index Map for b
        unordered_map<int, int> valToIndex;
        for (int i = 0; i < m; i++) {
            valToIndex[b[i]] = i;
        }

        // Step 2 — Filter and Map Array a
        vector<int> a_prime;
        for (int i = 0; i < n; i++) {
            if (valToIndex.find(a[i]) != valToIndex.end()) {
                a_prime.push_back(valToIndex[a[i]]);
            }
        }

        // Step 3 — Compute the LIS of a'
        vector<int> temp;
        for (int idx : a_prime) {
            auto it = lower_bound(temp.begin(), temp.end(), idx);
            if (it == temp.end()) {
                temp.push_back(idx);
            } else {
                *it = idx;
            }
        }

        // Step 4 — Calculate and Return the Minimum Operations
        int L = temp.size();
        return n + m - 2 * L;
    }
};
