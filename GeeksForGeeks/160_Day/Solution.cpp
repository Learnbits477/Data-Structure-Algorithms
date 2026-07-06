#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        
        // Step 1 — Initialize Pointers and Sum Accumulators
        int i = 0, j = 0;
        int sumA = 0, sumB = 0;
        int totalSum = 0;
        
        // Step 2 — Traverse Both Arrays Simultaneously
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                sumA += a[i];
                i++;
            } else if (b[j] < a[i]) {
                sumB += b[j];
                j++;
            } else {
                // Common element reached (intersection point)
                totalSum += max(sumA, sumB) + a[i];
                sumA = 0;
                sumB = 0;
                i++;
                j++;
            }
        }
        
        // Step 3 — Process Remaining Elements
        while (i < n) {
            sumA += a[i];
            i++;
        }
        
        while (j < m) {
            sumB += b[j];
            j++;
        }
        
        totalSum += max(sumA, sumB);
        
        // Step 4 — Return the Final Sum
        return totalSum;
    }
};
