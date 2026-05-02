#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // Helper function to generate all possible subset sums for a given array segment
    void getSubsetSums(int start, int end, const vector<int>& arr, vector<long long>& sums) {
        int n = end - start + 1;
        // There are 2^n possible subsets
        for (int i = 0; i < (1 << n); i++) {
            long long sum = 0;
            for (int j = 0; j < n; j++) {
                // If the j-th bit is set, include arr[start + j] in the subset
                if (i & (1 << j)) {
                    sum += arr[start + j];
                }
            }
            sums.push_back(sum);
        }
    }

public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return k == 0 ? 1 : 0;
        
        vector<long long> leftSums, rightSums;
        
        int mid = n / 2;
        
        // Generate all subset sums for the left half
        getSubsetSums(0, mid - 1, arr, leftSums);
        
        // Generate all subset sums for the right half
        getSubsetSums(mid, n - 1, arr, rightSums);
        
        // Sort the right half's sums to allow binary searching
        sort(rightSums.begin(), rightSums.end());
        
        long long count = 0;
        
        // For each sum in the left half, find how many times the required remainder appears in the right half
        for (long long sum : leftSums) {
            long long target = (long long)k - sum;
            
            // equal_range returns a pair of iterators representing the range of elements equal to the target
            auto range = equal_range(rightSums.begin(), rightSums.end(), target);
            count += (range.second - range.first);
        }
        
        return count;
    }
};
