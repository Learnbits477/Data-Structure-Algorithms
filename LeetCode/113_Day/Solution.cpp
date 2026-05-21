#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // Step 1: Setup Tracking Variables
        int n = A.size();
        vector<int> freq(n + 1, 0);
        int common_count = 0;
        vector<int> C(n);

        // Step 2: Traverse Both Arrays
        for (int i = 0; i < n; i++) {
            // Step 3: Update Frequency and Check Common Elements
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                common_count++;
            }

            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                common_count++;
            }

            // Step 4: Populate Result
            C[i] = common_count;
        }

        // Step 5: Return Result
        return C;
    }
};
