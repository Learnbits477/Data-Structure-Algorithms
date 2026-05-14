#include <bits/stdc++.h>
using namespace std;

class Solution {
    void computeLPSArray(const vector<int>& pat, int M, vector<int>& lps) {
        int len = 0;
        lps[0] = 0; // lps[0] is always 0
        int i = 1;

        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else { // pat[i] != pat[len]
                if (len != 0) {
                    len = lps[len - 1];
                } else { // if len == 0
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    vector<int> search(vector<int>& a, vector<int>& b) {
        vector<int> result;
        int N = a.size();
        int M = b.size();

        // Edge case: if pattern is empty, nothing to search
        if (M == 0) return result;

        // Step 1: Preprocess pattern b[] to build LPS array ─
        vector<int> lps(M);
        computeLPSArray(b, M, lps);

        // Step 2 & 3: Pattern matching process 
        int i = 0; // index for a[]
        int j = 0; // index for b[]
        
        while (i < N) {
            if (b[j] == a[i]) {
                j++;
                i++;
            }

            if (j == M) {
                // Found a match, add the starting index to the result
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < N && b[j] != a[i]) {
                // Step 4: Handle mismatch 
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i = i + 1;
                }
            }
        }

        return result;
    }
};
