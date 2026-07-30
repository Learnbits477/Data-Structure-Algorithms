#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubsetXOR(vector<int> &arr) {
        // Step 1: Initialize the Basis Array
        vector<int> basis(32, 0);

        // Step 2: Build the Basis
        for (int x : arr) {
            for (int i = 31; i >= 0; i--) {
                if ((x >> i) & 1) {
                    if (basis[i] == 0) {
                        basis[i] = x;
                        break;
                    }
                    x ^= basis[i];
                }
            }
        }

        // Step 3: Find the Maximum Subset XOR
        int max_xor = 0;
        for (int i = 31; i >= 0; i--) {
            if ((max_xor ^ basis[i]) > max_xor) {
                max_xor ^= basis[i];
            }
        }

        // Step 4: Return the Result
        return max_xor;
    }
};
